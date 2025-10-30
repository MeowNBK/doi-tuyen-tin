#include <bits/stdc++.h>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

// --- Định nghĩa kiểu nhanh ---
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// --- Kiểu số nguyên kích thước cố định---
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

// --- Macro tiện ích ngắn gọn ---
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define PB push_back
#define RS reserve

// --- Macro cho vòng lặp ---
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep0(i, n) for (int i = 0; i < (n); ++i)

// --- Các hàm trợ giúp ---

// ===== Các hàm in =====
template <typename...Args>
inline void print(Args&&...args) noexcept {
    (cout << ... << args);
}

template <typename...Args>
inline void printl(Args&&...args) noexcept {
    (cout << ... << args);
    cout << '\n';
}

// template <typename T>
// inline bool is_equal(T&& value, initializer_list<T> options) noexcept {
//     for (const T& option : options) {
//         if (value == option) return true;
//     }
//     return false;
// }

// ===== Các hàm so sánh ==== 
inline bool is_equal(i32 value, initializer_list<i32> options) noexcept {
    for (i32 option : options) {
        if (value == option) return true;
    }
    return false;
}

inline bool is_equal(i64 value, initializer_list<i64> options) noexcept {
    for (i64 option : options) {
        if (value == option) return true;
    }
    return false;
}

inline bool is_equal(u64 value, initializer_list<u64> options) noexcept {
    for (u64 option : options) {
        if (value == option) return true;
    }
    return false;
}

inline bool is_equal(f32 a, f32 b, f32 eps = 1e-6) noexcept {
    return fabs(a - b) <= eps * max({ f32(1.0), fabs(a), fabs(b) });
}

inline bool is_equal(f64 a, f64 b, f64 eps = 1e-9) noexcept {
    return fabs(a - b) <= eps * max({ 1.0, fabs(a), fabs(b) });
}

// --- IO và Encoding ---
inline void set_io(string name = "") noexcept {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    if (!name.empty()) {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);

        cin.tie(nullptr);
    }
}

inline void set_utf8() noexcept {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif
}

// --- Các Lớp tiện ích --- 
class Timer {
private:
    using clock_t = chrono::high_resolution_clock;

    string message_;
    clock_t::time_point start_;
    bool timer_on_;
public:
    Timer(string message = "Exec time: ", bool timer_on = true) noexcept : message_(std::move(message)), start_(clock_t::now()), timer_on_(timer_on) {}
    Timer(const Timer& other) noexcept : message_(other.message_), start_(other.start_), timer_on_(other.timer_on_) {}
    Timer(Timer&& other) noexcept : message_(std::move(other.message_)), start_(std::move(other.start_)), timer_on_(std::move(other.timer_on_)) {}
    inline Timer& operator=(const Timer& other) noexcept {
        if (this == &other) return *this;
        message_ = other.message_;
        start_ = other.start_;
        timer_on_ = other.timer_on_;
        return *this;
    }
    inline Timer& operator=(Timer&& other) noexcept {
        if (this == &other) return *this;
        message_ = other.message_;
        start_ = other.start_;
        timer_on_ = other.timer_on_;

        other.message_ = "";
        other.start_ = {};
        other.timer_on_ = false;
        return *this;
    }
    ~Timer() noexcept {
        if (timer_on_) log();
    }

    inline double elapsed() noexcept {
        auto end = clock_t::now();
        chrono::duration<double, milli> duration = end - start_;

        return duration.count();
    }

    inline const char* unit(double& value) noexcept {
        if (value >= 1.0) return "ms";
        value *= 1000.0;
        if (value >= 1.0) return "µs";
        value *= 1000.0;
        return "ns";
    }

    inline const char* explain_unit(const char* u) {
        if (strcmp(u, "ms") == 0) return "(1ms = 1/10^3 s)";
        if (strcmp(u, "µs") == 0) return "(1µs = 1/10^6 s)";
        if (strcmp(u, "ns") == 0) return "(1ns = 1/10^9 s)";
        return "";
    }

    inline void log() noexcept {
        double value = elapsed();
        const char* time_unit = unit(value);

        printl(message_, fixed, setprecision(3), value, time_unit, ' ', explain_unit(time_unit));
    }

    inline void stop() noexcept {
        if (timer_on_) {
            log();
            timer_on_ = false;
        }
    }

    inline void reset() noexcept {
        start_ = clock_t::now();
    }
};

class boolarray {
public:
    boolarray(size_t size, bool init_value = false) noexcept : data_(nullptr), mask_nums_(0), size_(size) {
        grow(size);
        fill(init_value);
    }
    boolarray(const boolarray& other) noexcept : data_(new uint64_t[other.mask_nums_]), mask_nums_(other.mask_nums_), size_(other.size_) {
        for (size_t i = 0; i < mask_nums_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    boolarray(boolarray&& other) noexcept : data_(other.data_), mask_nums_(other.mask_nums_), size_(other.size_) {
        other.data_ = nullptr;
        other.mask_nums_ = other.size_ = 0;
    }
    inline boolarray& operator=(const boolarray& other) noexcept {
        if (this == &other) return *this;
        mask_nums_ = other.mask_nums_;
        size_ = other.size_;
        delete[] data_;
        data_ = new uint64_t[mask_nums_];
        for (size_t i = 0; i < mask_nums_; ++i) {
            data_[i] = other.data_[i];
        }
        return *this;
    }
    inline boolarray& operator=(boolarray&& other) noexcept {
        if (this == &other) return *this;
        delete[] data_;
        data_ = other.data_;
        mask_nums_ = other.mask_nums_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.mask_nums_ = other.size_ = 0;
        return *this;
    }
    ~boolarray() noexcept { delete[] data_; }

    [[nodiscard]] inline bool get(size_t bit_number) const noexcept {
        size_t index = bit_number / 64;
        size_t bit_pos = bit_number % 64;
        return ((data_[index]) & (1ULL << bit_pos)) != 0;
    }
    inline void set(size_t bit_number, bool value) noexcept {
        size_t index = bit_number / 64;
        size_t bit_pos = bit_number % 64;

        if (value) data_[index] |= (1ULL << bit_pos);
        else data_[index] &= ~(1ULL << bit_pos);
    }
    inline bool operator[](size_t index) const noexcept {
        return get(index);
    }

    inline void fill(bool value) noexcept {
        for (size_t i = 0; i < mask_nums_; ++i) {
            data_[i] = value ? -1ULL : 0ULL;
        }
    }
private:
    inline void grow(size_t new_size) noexcept {
        size_t old_mask = mask_nums_;
        mask_nums_ = (new_size + 63) >> 6;

        if (mask_nums_ < 1) mask_nums_ = 1;
        uint64_t* temp = new uint64_t[mask_nums_];
        if (data_) {
            size_t to_copy = min(mask_nums_, old_mask);
            for (size_t i = 0; i < to_copy; ++i) temp[i] = data_[i];
            for (size_t i = to_copy; i < mask_nums_; ++i) temp[i] = 0ULL;
            delete[] data_;
        } else {
            for (size_t i = 0; i < mask_nums_; ++i) temp[i] = 0ULL;
        }
        data_ = temp;
    }

    uint64_t* data_;
    size_t mask_nums_;
    size_t size_;
};

// --- Phần code chính ---
inline boolarray sieve(ll n) noexcept {
    boolarray a(n + 1, true);
    a.set(0, false);
    a.set(1, false);
    for (ll i = 2; i * i <= n; ++i) {
        if (!a[i]) continue;
        for (ll j = i * i; j <= n; j += i) {
            a.set(j, false);
        }
    }
    return a;
}

inline bool is_super_prime(ll n, const boolarray& snt) noexcept {
    while (n) {
        if (!snt[n]) return false;
        n /= 10;
    }
    return true;
}

int main() {
    set_io();
    set_utf8();
    ll n;
    print("Nhập số cần tính: ");
    cin >> n;

    Timer timer("Thời gian thực thi: ");

    boolarray snt = sieve(n);

    printl(n, " là ", (snt[n] ? "số nguyên tố" : "không phải số nguyên tố"));

    printl("Các siêu nguyên tố từ 2 đến ", n);
    rep(i, 2, n + 1) {
        if (is_super_prime(i, snt)) print(i, ' ');
    }
    printl();

    return 0;
}