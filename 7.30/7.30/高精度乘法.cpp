#include <iostream>
#include <string>
#include <vector>
using namespace std;

string BigS(string s1, string s2) {
	for (auto &e : s1) {
		e -= '0';
	}
	for (auto &e : s2) {
		e -= '0';
	}
	int res,temp = 0;
	int n = s1.size() + s2.size() + 1;
	vector<char> arr1(n, 0);
	for (int i = s2.size() - 1; i >= 0; --i) {
		vector<int> arr(n, 0);
		for (int j = s1.size() - 1; j >= 0; --j) {
			res = s2[i] * s1[j] + arr[i + j + 2];
			arr[i + j + 2] = res % 10;
			arr[i + j + 1] = res / 10;
		}
		for (int k = n - 1; k > 0; --k) {
			res = arr1[k] + arr[k] + temp;
			arr1[k] = res % 10;
			temp = res / 10;
		}
	}
	int i = 0;
	while (arr1[i] == 0)
		++i;
	string s3(&arr1[i],n - i);
	for (auto &e : s3) {
		e += '0';
	}
	return s3;
	//s1.insert('.',s.rbegin() + 1);
}

int main() {
	string n, r;
	int flag;
	while (cin >> n >> r) {
		if (r.size() > 3) {
			r = BigS(r, "628");
		}
		else {
			r = BigS("628", r);
		}
		r.erase(r.size() - 2);
		if (n.size() <= r.size()) {
			flag = 1;
		}
		else if (n == r) {
			flag = 1;
		}
		else {
			flag = 0;
		}

		if (flag) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}