#include <bits/stdc++.h>
#include "libs/console.h"

using namespace std;

#define ll long long
#define endl '\n'
#define EPSILON 1e-6
#define MEOW_PI 3.141592654

template <typename...Args>
inline void print(Args&&...args) noexcept {
    (cout << ... << args);
}

template <typename...Args>
inline void printl(Args&&...args) noexcept {
    (cout << ... << args);
    cout << endl;
}

inline double to_radian(double x) noexcept {
    return (x * 180.0)/MEOW_PI;
}

inline double to_deg(double x) noexcept {
    return (x * 180.0)/MEOW_PI;
}

inline array<double, 3> calculate(double a, double b, double c) noexcept {
    double A, B, C;

    double cosA = (b*b + c*c - a*a) / (2*b*c);
    double cosB = (a*a + c*c - b*b) / (2*a*c);

    A = acos(cosA);
    B = acos(cosB);

    A = to_deg(A);
    B = to_deg(B);

    C = 180 - A - B;

    return array<double, 3>{ A, B, C };
}

inline bool is_equal(double x, double y) noexcept {
    double diff = x - y;
    return abs(diff) < EPSILON;
}

inline bool is_equal(initializer_list<double> choices, double x) noexcept {
    for (auto c : choices) {
        if (is_equal(c, x)) return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    meow::set_utf8();

    ios::sync_with_stdio(false);

    if (argc < 2) {
        printl("Cần ít nhất 2 đối số");
        return 42;
    }

    ifstream fin(argv[1]);

    double a, b, c;
    double A, B, C;

    int n;

    fin >> n;

    while (n--) {
        fin >> a >> b >> c;

        auto result = calculate(a, b, c);
        A = result[0];
        B = result[1];
        C = result[2];

        if ((a + b > c) && (b + c > a) && (a + c > b)) {
            if (is_equal({A, B, C}, 90.0)) {
                printl("Đây là tam giác vuông");
            } else if (is_equal(a, b) && is_equal(b, c)) {
                printl("Đây là tam giác đều");
            } else if (is_equal(a, b) || is_equal(b, c) || is_equal(c, a)) {
                printl("Đây là tam giác cân");
            } else {
                printl("Đây là tam giác thường");
            }
        } else {
            printl("Đây không phải là tam giác");
        }
    }

    return 0;
}