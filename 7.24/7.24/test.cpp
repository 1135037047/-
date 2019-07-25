#include <iostream>
#include <vector>

using namespace std;

void XiPai(vector<int> &arr, int n) {
	vector<int> temp = arr;
	for (int i = 0; i < n; ++i) {
		arr[2 * i] = temp[i];
		arr[2 * i + 1] = temp[i + n];
	}
}

int main() {
	int m;
	cin >> m;
	int k, n, num;
	while (cin >> n >> k) {
		vector<int> arr(2 * n, 0);
		for (int i = 0; i < 2 * n; i += 2) {
			cin >> num;
			arr[i] = num;
		}
		for (int i = 1; i < 2 * n; i += 2) {
			cin >> num;
			arr[i] = num;
		}
		for (int i = 1; i < k; ++i) {
			XiPai(arr, n);
		}
		auto arrit = arr.begin();
		for (; arrit != arr.end() - 1; ++arrit) {
			cout << *arrit << ' ';
		}
		cout << arr[2 * n - 1] << endl;
	}
	return 0;
}		//vector<vector<int>> arr(m, vector<int>(2 * n, 0));



//MP3π‚±ÍŒª÷√
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int num, index, res;
	string s;
	while (cin >> num >> s) {
		vector<int> arr(num + 1, 0);
		int i = 0;
		for (auto &e : arr) {
			e += i;
			++i;
		}
		if (num <= 4) {
			res = 1;
			for (auto e : s) {
				if (e == 'U') {
					--res;
				}
				else {
					++res;
				}
			}
			for (i = 1; i < num; ++i) {
				cout << arr[i] << ' ';
			}
			cout << arr[num] << endl;
			if (res > 0) {
				res = res % num;
				if (res == 0) {
					res = num;
				}
				cout << res << endl;
			}
			else {
				res = num - (0 - res) % num;
				cout << res << endl;
			}
		}
		else {
			int front = 1, back = 4, max_back = arr[num];
			index = 1;
			for (auto e : s) {
				if (e == 'U') {
					if (index == front) {
						if (front == 1) {
							back = max_back;
							front = back - 3;
							index = max_back;
						}
						else {
							front--;
							back--;
							index--;
						}
					}
					else {
						index--;
					}
				}
				else {
					if (index == back) {
						if (back == max_back) {
							front = 1;
							back = 4;
							index = 1;
						}
						else {
							back++;
							front++;
							index++;
						}
					}
					else {
						index++;
					}
				}
			}
			for (i = front; i < back; ++i) {
				cout << i << ' ';
			}
			cout << back << endl;
			cout << index << endl;
		}
	}
	return 0;
}