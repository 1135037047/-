#include <iostream>
#include <vector>

using namespace std;

int Yueshu(int num1, int num2) {
	for (int i = num2; i > 0; --i) {
		if (num1 % i == 0 && num2 % i == 0) {
			return i;
		}
	}
	return 0;
}

int main() {
	int res, num;
	while (cin >> num >> res) {
		vector<int> arr(num, 0);
		int i = 0;
		while (i < num) {
			cin >> arr[i];
			if (res >= arr[i]) {
				res += arr[i];
			}
			else {
				res += Yueshu(arr[i], res);
			}
			++i;
		}
		cout << res << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	while (cin >> s) {
		int flag = 1;
		vector<int> arr(256, 0);
		for (auto e : s) {
			++arr[e];
		}
		for (auto e : s) {
			if (arr[e] == 1) {
				cout << e << endl;
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << -1 << endl;
		}
	}
	return 0;
}