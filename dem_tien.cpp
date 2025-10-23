#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

#define ll uint64_t

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
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	
	ll n;
	cout << "Nhập số tiền: ";
	cin >> n;
	
	n /= 1000;
	
	cout << "Số cách trả tiền: " << count(n) << endl;
	return 0;
}
