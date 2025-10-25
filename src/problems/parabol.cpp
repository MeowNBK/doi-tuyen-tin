#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "libs/console.h"

using namespace std;

template <typename...Args>
inline void print(Args&&...args) noexcept {
    ((cout << args << " "), ...);
}

template <typename...Args>
inline void printl(Args&&...args) noexcept {
	((cout << args << " "), ...);
	print("\n");
}

int main() {
    meow::set_utf8();
	
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	ifstream fin("Bai1.inp");
	
	int n;
	fin >> n;
	
	while (n--) {
		float a, b, c, delta, x, x1, x2;
		fin >> a >> b >> c;
		
		cout << "--- Phương trình: " << a << "x2 + " << b << "x + " << c << endl;
		if (a == 0) {
			printl("Không phải phương trình bậc 2");
			continue;
		}
		delta = b*b - 4*a*c;
		
		printl("Delta là", delta);
		
		if (delta > 0) {
			x1 = (-b + sqrt(delta))/(2*a);
			x2 = (-b - sqrt(delta))/(2*a);
			
			printl("Phương trình có 2 nghiệm phân biệt", x1, x2);
		} else if (delta == 0) {
			x = (-b)/(2*a);
			
			printl("Phương trình có một nghiệm kép", x);
			print(x);
		} else {
			printl("Phương trình vô nghiệm");
		}
	}

    return 0;
}