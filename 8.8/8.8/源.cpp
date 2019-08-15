// write your code here cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		string s, s1;
		getline(cin, s1);
		int flag = 0;
		for (int i = 0; i < n; ++i) {
			flag = 0;
			getline(cin, s1);
			for (auto e : s1) {
				if (e == ' ' || e == ',') {
					flag = 1;
					break;
				}
			}
			if (i == n - 1) {
				break;
			}
			if (flag) {
				s += '"';
				s += s1;
				s += '"';
				s += ", ";
			}
			else {
				s += s1;
				s += ", ";
			}
		}
		if (flag) {
			s += '"';
			s += s1;
			s += '"';
			cout << s << endl;
		}
		else {
			s += s1;
			cout << s << endl;
		}
	}
	return 0;
}


// write your code here cpp
#include <iostream>

using namespace std;
int main() {
	int n;
	while (cin >> n) {
		uint64_t num1 = 1;
		uint64_t num2 = 2;
		uint64_t temp;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n == 2) {
			cout << 2 << endl;
			continue;
		}
		for (int i = 2; i < n; ++i) {
			temp = num2;
			num2 = num2 + num1;
			num1 = temp;
		}
		cout << num2 << endl;
	}
	return 0;
}