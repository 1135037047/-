#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int row = s1.size() + 1;
		int col = s2.size() + 1;
		vector<vector<int>> dp(row, vector<int>(col, 0));
		dp[0][0] = 1;
		for (int i = 1; i < row; ++i) {
			dp[i][0] = dp[i - 1][0] && (s1[i - 1] == '*');
			for (int j = 1; j < col; ++j) {
				if (s1[i - 1] == '*') {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				else {
					dp[i][j] = dp[i - 1][j - 1] && (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?');
				}
			}
		}
		if (dp[row - 1][col - 1]) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}