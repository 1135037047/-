#if 0
#include <iostream>
#include <vector>
using namespace std;

bool IsLeapYear(const int& year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int main() {
	int year, month, day;
	while (cin >> year >> month >> day) {
		int res = 0;
		if (year < 0 || month > 12 || month < 0 || day < 0) {
			cout << -1 << endl;
			//return 0;
			continue;
		}
		vector<int> moday{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (IsLeapYear(year)) {
			moday[2] += 1;
		}
		if (day > moday[month]) {
			cout << -1 << endl;
			//return 0;
			continue;
		}
		for (int i = 1; i < month; i++) {
			res += moday[i];
		}
		res += day;
		cout << res << endl;
	}
	return 0;
}
#endif


