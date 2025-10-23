#include <bits/stdc++.h>

using namespace std;

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
	int i = 1;
	int end = 100;
	
	start_loop:
	if (!(i <= end)) goto end_loop;
	if (i % 3 == 0) printl(i);
	++i;
	goto start_loop;
	end_loop:
	return 0;
}
