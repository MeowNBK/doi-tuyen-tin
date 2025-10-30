#include <bits/stdc++.h>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
#define max_n -1ULL

template <typename...Args>
inline void print(Args&&...args) noexcept {
    (cout << ... << args);
}

template <typename...Args>
inline void printl(Args&&...args) noexcept {
    (cout << ... << args);
    cout << endl;
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif

    print("Nhập số n trong khoảng 0 - ", max_n, ": ");
    ull n;
    cin >> n;
    
    auto st = chrono::high_resolution_clock::now();
    ull t = 0;
    while (n) {
        t += n % 10;
        n /= 10;
    }
    auto en = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> du = en - st;

    printl("Tổng: ", t);
    printl("Thời gian chạy: ", du.count(), "ms");
    return 0;
}