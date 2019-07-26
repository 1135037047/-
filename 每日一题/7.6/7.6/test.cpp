#include <iostream>
#include <string>
using namespace std;



int StrToInt(string str) {
	int n = str.size();
	int res = 0;
	int i = 0;
	int flag = 0;
	if (str[0] == '-') {
		flag = 1;
		i = 1;
	}
	if (str[0] == '+') {
		i = 1;
	}
	for (; i < n; i++) {
		if (str[i] < 48 || str[i] > 57) {
			return 0;
		}
		res += (str[i] - 48) * pow(10, n - i - 1);
	}
	if (flag) {
		res = -res;
	}
	return res;
}

int main() {
	string s;
	while (1) {
		cin >> s;
		cout << StrToInt(s);
	}
	return 0;
}

#if 0
#include <iostream>
using namespace std;

int main() {
	int w, h;
	cin >> w >> h;
	if ((w % 4) == 0 || (h % 4) == 0) {
		cout << (w * h) / 2;
		return 0;
	}
	int arr[4][4] = { {0,0,0,0},{0,1,2,2},{0,2,4,4},{0,2,4,5} };
	int res = (w * h - (w % 4) * (h % 4)) / 2 + arr[w % 4][h % 4];
	cout << res;
	return 0;
}
#endif
