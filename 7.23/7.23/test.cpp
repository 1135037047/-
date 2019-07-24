#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	while (cin >> s) {
		string s1(s.rbegin(), s.rend());
		cout << s1 << endl;
	}
	return 0;
}

//最大相同字串长度
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		int row = str1.size();
		int col = str2.size();
		int res = 0;
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
		for (int i = 1; i < row + 1; ++i) {
			for (int j = 1; j < col; ++j) {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				if (dp[i][j] > res) {
					res = dp[i][j];
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}