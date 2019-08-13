// write your code here cpp
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int year1, year2, month1, month2, day1, day2;
	vector<int> monarr{ 0,62,28,31,60,31,60,31,62,60,62,30,62 };
	vector<int> y{ 2,3,5,7,11 };
	int res = 0;
	int flag;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) {
		if (IsLeapYear(year2)) {
			++monarr[2];
		}
		if (y.end() != find(y.begin(), y.end(), month2)) {
			res += day2;
		}
		else {
			res += day2 * 2;
		}
		for (int i = 1; i < month2; ++i) {
			res += monarr[i];
		}
		if (IsLeapYear(year2)) {
			--monarr[2];
		}
		if (IsLeapYear(year1)) {
			++monarr[2];
		}
		if (y.end() != find(y.begin(), y.end(), month1)) {
			res -= (day1 - 1);
		}
		else {
			res -= ((day1 - 1) * 2);
		}
		for (int i = 1; i < month1; ++i) {
			res -= monarr[i];
		}
		if (IsLeapYear(year1)) {
			--monarr[2];
		}
		for (int i = year1; i < year2; ++i) {
			if (IsLeapYear(i)) {
				res += 580;
			}
			else {
				res += 579;
			}
		}
		cout << res << endl;
	}
}
#endif

// write your code here cpp
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int temp;
		int num1 = 1;
		int num2 = 1;
		if (n < 2) {
			cout << 1 << endl;
			continue;
		}
		for (int i = 2; i <= n; ++i) {
			temp = num2;
			num2 = num1 + num2;
			num1 = temp;
			num1 %= 1000000;
			num2 %= 1000000;
		}
		printf("%d\n", num2);
	}
	return 0;
}