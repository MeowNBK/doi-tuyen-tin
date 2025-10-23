#include <bits/stdc++.h>

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

int main() {
    double a, b, c;
    double A, B, C;
    cin >> a >> b >> c;

    // Tim xem day la tam giac gi: thuong, vuong, can

    auto result = calculate(a, b, c);
    A = result[0];
    B = result[1];
    C = result[2];

    if ((a+b>c)&&(b+c>a)&&(a+c>b)) {
        if (is_equal({A, B, C}, 90.0)) {
            printl("Day la tam giac vuong");
        } else if (is_equal(a, b) && is_equal(b, c)) {
            printl("Day la tam giac deu");
        } else if (is_equal(a, b) || is_equal(b, c) || is_equal(c, a)) {
            printl("Day la tam giac can");
        } else {
            printl("Day la tam giac thuong");
        }
    } else {
        printl("Day khong phai tam giac");
    }
    return 0;
}