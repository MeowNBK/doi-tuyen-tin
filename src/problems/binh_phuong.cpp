#include <bits/stdc++.h>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

// --- Định nghĩa kiểu ---
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// --- Kiểu số nguyên ---
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

// --- Macro tiện ích ---
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define PB push_back
#define RS reserve

// --- Macro vòng lặp ---
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep0(i, n) for (int i = 0; i < (n); ++i)

// --- Hàm trợ giúp ---
template <typename...Args>
inline void print(Args&&...args) noexcept {
    (cout << ... << args);
}

template <typename...Args>
inline void printl(Args&&...args) noexcept {
    (cout << ... << args);
    cout << '\n';
}

template <typename T>
inline bool is_equal(T&& value, initializer_list<T> options) noexcept {
    for (const T& option : options) {
        if (value == option) return true;
    }
    return false;
}

inline bool is_equal(f32 a, f32 b, float eps = 1e-6) noexcept {
    return fabs(a - b) <= eps * max({ f32(1.0), fabs(a), fabs(b) });
}

inline bool is_equal(f64 a, f64 b, double eps = 1e-9) noexcept {
    return fabs(a - b) <= eps * max({ 1.0, fabs(a), fabs(b) });
}

// --- IO và Encoding
inline void set_io(string name = "") noexcept {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

inline void set_utf8() noexcept {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif
}

// --- Lớp tiện ích --- 
struct Timer {
    string msg;
    chrono::high_resolution_clock::time_point start;
    bool timer_on;
    Timer(string m = "Exec time: ", bool on = true) noexcept : msg(std::move(m)), start(chrono::high_resolution_clock::now()), timer_on(on) {}
    ~Timer() noexcept {
        if (timer_on) printl(msg, sinc(), "ms");
    }

    inline double sinc() noexcept {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;

        return duration.count();
    }
};

int main() {
    set_io();
    set_utf8();

    print("Nhập số cần tính: ");
    ull n;
    cin >> n;

    Timer timer("Thời gian thực thi: ");
    
    rep(i, 2, n + 1) {
        if (!is_equal<ull>(i % 10, { 0, 1, 5, 6 })) continue;
        printl(i);
    }

    return 0;
}