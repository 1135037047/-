#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int a1 = s1.size();
		int a2 = s2.size();
		vector<char> arr(max(a1, a2) + 1, 0);
		for (auto &e : s1) {
			e = e - '0';
		}
		for (auto &e : s2) {
			e = e - '0';
		}
		auto it1 = s1.rbegin();
		auto it2 = s2.rbegin();
		int i = arr.size();
		int num;
		while (it1 != s1.rend() && it2 != s2.rend()) {
			num = *it1 + *it2 + arr[i - 1];
			arr[i - 2] = num / 10;
			arr[i - 1] = num % 10;
			--i;
			++it1;
			++it2;
		}
		if (it1 == s1.rend()) {
			while (it2 != s2.rend()) {
				num = *it2 + arr[i - 1];
				arr[i - 2] = num / 10;
				arr[i - 1] = num % 10;
				--i;
				++it2;
			}
		}
		else {
			while (it1 != s1.rend()) {
				num = *it1 + arr[i - 1];
				arr[i - 2] = num / 10;
				arr[i - 1] = num % 10;
				--i;
				++it1;
			}
		}
		for (auto &e : arr) {
			e += '0';
		}
		if (arr[0] == '0') {
			string s3(&arr[1], arr.size() - 1);
			cout << s3 << endl;
		}
		else {
			string s3(&arr[0], arr.size());
			cout << s3 << endl;
		}
	}
	return 0;
}