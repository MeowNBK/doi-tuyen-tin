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

    auto st = chrono::high_resolution_clock::now();
    // --- Codes ---
    auto en = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> du = en - st;
    return 0;
}