// meow_runner.cpp
#include <bits/stdc++.h>
#include <filesystem>
#include <chrono>
#include <cstdlib>
#include <cctype>

#include "third_parties/nlohmann/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;
using namespace std::chrono;

static std::string run_system_cmd(const std::string& cmd) noexcept {
    int return_code = std::system(cmd.c_str());
    return std::to_string(return_code);
}

static bool file_exists(const fs::path& file_path) {
    return fs::exists(file_path) && fs::is_regular_file(file_path);
}

static std::string read_file_trim(const fs::path& file_path) {
    std::ifstream fin(file_path);
    std::ostringstream oss;
    std::string line;
    while (std::getline(fin, line)) {
        while (!line.empty() && std::isspace(line.back())) line.pop_back();
        oss << line << '\n';
    }
    return oss.str();
}

static bool compare_outputs(const fs::path& expected_path, const fs::path& actual_path, std::string& diff_msg) {
    if (!file_exists(expected_path) || !file_exists(actual_path)) {
        diff_msg = "Missing expected or actual file.";
        return false;
    }
    std::string expected = read_file_trim(expected_path);
    std::string actual = read_file_trim(actual_path);
    if (expected == actual) return true;

    std::istringstream expected_stream(expected), actual_stream(actual);
    std::string line_expected, line_actual;
    int line_no = 1;
    while (true) {
        bool bool_expected = bool(std::getline(expected_stream, line_expected));
        bool bool_actual = bool(std::getline(actual_stream, line_actual));
        if (!bool_expected && !bool_actual) break;
        if (line_expected != line_actual) {
            diff_msg = "Difference at line " + std::to_string(line_no) + "\nExpected: \"" + line_expected + "\"\nActual:   \"" + line_actual + "\"";
            return false;
        }
        ++line_no;
    }
    diff_msg = "Outputs differ (but unable to locate exact difference).";
    return false;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <config.json> [--show-cmd]\n";
        return 1;
    }
    fs::path config_path = argv[1];
    bool show_cmd = false;
    if (argc >= 3 && std::string(argv[2]) == std::string("--show-cmd")) show_cmd = true;

    if (!file_exists(config_path)) {
        std::cerr << "Config file not found: " << config_path << "\n";
        return 2;
    }

    // parse JSON
    json config;
    {
        std::ifstream ifs(config_path);
        if (!ifs) { std::cerr << "Can't open config file\n"; return 3; }
        ifs >> config;
    }

    std::string problem = config.value("problem", "unknown");
    std::string compile_cmd = config.value("compile_cmd", "");
    std::string run_cmd_template = config.value("run_cmd", ""); // can use placeholders
    std::string input_mode = config.value("input_mode", "file"); // "file" or "stdin"
    std::string input_file = config.value("input_file", "");
    std::string output_mode = config.value("output_mode", "compare"); // "compare" or "print"
    std::string expected_output_file = config.value("expected_output_file", "");
    int time_limit_ms = config.value("time_limit_ms", 2000); // default 2000ms

    std::cout << "=== MeowRunner: " << problem << " ===\n";

    // 1) Compile
    if (!compile_cmd.empty()) {
        std::cout << "[*] Compiling: " << compile_cmd << " ...\n";
        auto t0 = high_resolution_clock::now();
        int rc = std::system(compile_cmd.c_str());
        auto t1 = high_resolution_clock::now();
        auto ms = duration_cast<milliseconds>(t1 - t0).count();
        if (rc != 0) {
            std::cerr << "[!] Compile failed (rc=" << rc << "), time: " << ms << " ms\n";
            return 4;
        } else {
            std::cout << "[+] Compiled OK (took " << ms << " ms)\n";
        }
    }

    std::string actual_out = config.value("actual_output_file", "runner_actual.out");
    fs::path actual_out_path = actual_out;
    if (file_exists(actual_out_path)) fs::remove(actual_out_path);

    std::ostringstream inner;
    std::string run_cmd = run_cmd_template;
    if (run_cmd.empty()) {
        run_cmd = "./bin/" + problem;
    }
    if (show_cmd) std::cout << "[DBG] base run_cmd: " << run_cmd << "\n";

    if (input_mode == "file") {
        if (input_file.empty()) {
            std::cerr << "[!] input_mode=file but input_file not set\n";
            return 5;
        }
        inner << run_cmd << " < " << input_file << " > " << actual_out;
    } else {
        inner << run_cmd << " > " << actual_out;
    }

    int t_seconds = std::max(1, (time_limit_ms + 999) / 1000);
    std::ostringstream full_cmd;
    full_cmd << "timeout " << t_seconds << "s bash -c '" << inner.str() << "'";

    if (show_cmd) std::cout << "[DBG] full_cmd: " << full_cmd.str() << "\n";

    std::cout << "[*] Running (timeout " << t_seconds << "s)...\n";
    auto t0 = high_resolution_clock::now();
    int rc_run = std::system(full_cmd.str().c_str());
    auto t1 = high_resolution_clock::now();
    long long elapsed_ms = duration_cast<milliseconds>(t1 - t0).count();

    if (rc_run == 124) {
        std::cout << "[!] Program timed out ( >= " << t_seconds << " s )\n";
    } else if (rc_run != 0) {
        std::cout << "[!] Program exited with code " << rc_run << "\n";
    } else {
        std::cout << "[+] Program finished (elapsed " << elapsed_ms << " ms)\n";
    }

    if (output_mode == "compare") {
        if (expected_output_file.empty()) {
            std::cerr << "[!] output_mode=compare but expected_output_file not set\n";
            return 6;
        }
        std::string diff_msg;
        bool ok = compare_outputs(expected_output_file, actual_out, diff_msg);
        if (ok) {
            std::cout << "✅ Correct output!\n";
        } else {
            std::cout << "❌ Wrong output: " << diff_msg << "\n";
            std::cout << "---- expected (trimmed) ----\n" << read_file_trim(expected_output_file);
            std::cout << "---- actual (trimmed) ----\n" << read_file_trim(actual_out);
        }
    } else {
        std::cout << "---- actual output ----\n" << read_file_trim(actual_out);
    }

    std::cout << "=== Done ===\n";
    return 0;
}
