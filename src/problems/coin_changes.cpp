#include <iostream>
#include <cstdint>
#include <array>

#ifdef _WIN32
#include <windows.h>
#endif

using ll = long long;

inline static constexpr int64_t brute_force(int m) noexcept {
    int64_t cnt = 0;
    for (int a = 0; 10 * a <= m; ++a) {
        for (int b = 0; 10 * a + 5 * b <= m; ++b) {
            int R = m - 10 * a - 5 * b;
            cnt += (R / 2) + 1;
        }
    }
    return cnt;
}

inline static constexpr std::array<std::array<int64_t, 4>, 10> initialize() noexcept {
    std::array<std::array<int64_t, 4>, 10> arr{};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[i][j] = brute_force(10 * j + i);
        }
    }
    return arr;
}

inline int64_t count_ways(ll m) noexcept {
    static std::array<std::array<int64_t, 4>, 10> y = initialize();

    int r = static_cast<int>((m % 10 + 10) % 10);
    ll k = (m - r) / 10;

    if (0 <= k && k < 4) {
        return y[r][k];
    }

    ll k0 = k;
    ll k1 = k - 1;
    ll k2 = k - 2;
    ll k3 = k - 3;

    ll term0 = y[r][0] * ( k1 * k2 * k3) / -6;
    ll term1 = y[r][1] * ( k0 * k2 * k3) /  2;
    ll term2 = y[r][2] * ( k0 * k1 * k3) / -2;
    ll term3 = y[r][3] * ( k0 * k1 * k2) /  6;

    return term0 + term1 + term2 + term3;
}

inline ll count(ll m) noexcept { 
    ll A = ll(m/5);
    ll e = m - 2 * ll(m/2);
    ll R = ll((A+1+e)/2);
    ll p1 = (A+1)*m;
    ll p2 = 5*(A*(A+1))/2;
    ll p3 = (A+1);
    return (p1 - p2 - R)/2 + p3;
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif

    ll m;
    std::cout << "Nhập giá trị đầu vào: ";
    if (!(std::cin >> m)) {
        std::cerr << "Nhập không hợp lệ!\n";
        return 1;
    }
    std::cout << count_ways(m) << "\n";
    return 0;
}
