//#include <iostream>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//
//int main() {
//	int m, n;
//	cin >> m >> n;
//	const int num = n - m + 1;
//	int count = 0;
//	vector<int> arr(num, 100000);
//	arr[0] = 0;
//	for (int i = 0; i < num; ++i) {
//		if (arr[i] != 100000) {
//			count = arr[i] + 1;
//			for (int j = 2; j <= sqrt(i + m); ++j) {
//				if ((i + m) % j == 0) {
//					if (j + i < num && arr[j + i] > count) {
//						arr[j + i] = count;
//					}
//					if ((i + m) / j != j) {
//						if ((((i + m) / j) + i) < num && arr[(((i + m) / j) + i)] > count) {
//							arr[(((i + m) / j) + i)] = count;
//						}
//					}
//				}
//			}
//		}
//	}
//	if (arr[num - 1] == 100000) {
//		cout << -1 << endl;
//	}
//	else {
//		cout << arr[num - 1] << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	vector<char*> arr;
	int temp = 0;
	temp = min(s.find(' ', temp), s.find('"', temp));
	if (s[0] != '"') {
		arr.push_back(&s[0]);
	}
	while (temp != -1) {
		if (s[temp] == ' ') {
			if (s[temp + 1] == '"') {
				s[temp] = '\0';
				temp++;
				continue;
			}
			arr.push_back(&s[temp + 1]);
			s[temp] = '\0';
		}
		if(s[temp] == '"') {
			arr.push_back(&s[temp + 1]);
			temp = s.find('"', temp + 1);
			s[temp] = '\0';
			temp += 1;
		}
		temp = min(s.find(' ', temp), s.find('"', temp));
	}
	cout << arr.size() << endl;
	for (auto e : arr) {
		cout << e << endl;
	}
	return 0;
}