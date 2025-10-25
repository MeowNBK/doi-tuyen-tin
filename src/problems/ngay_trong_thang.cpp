#include <iostream>
#include <vector>
#include "libs/console.h"

using namespace std;

int main() {
    meow::set_utf8();
	
	ios_base::sync_with_stdio(0);
	
	int month, year;
	cout << "Nhập vào số tháng và năm ";
	
	cin >> month >> year;
	
	if (month < 0 || month > 12) {
		cout << "Số tháng không phải số tháng trong năm" << endl;
	}
	if (month == 2) {
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
			cout << "Tháng có 29 ngày" << endl;
		} else {
			cout << "Tháng có 28 ngày" << endl;
		}
		return 0;
	}
	vector<bool> full_moon_months = {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
	
	if (full_moon_months[month - 1]) {
		cout << "Tháng có 31 ngày" << endl;
	} else {
		cout << "Tháng có 30 ngày" << endl;
	}
	return 0;
}