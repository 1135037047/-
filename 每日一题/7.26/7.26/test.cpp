#if 0
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		if (gifts.empty()) {
			return 0;
		}
		int num = 1;
		int set = gifts[0];
		for (int i = 1; i < n; ++i) {
			if (gifts[i] == set) {
				++num;
			}
			else {
				--num;
				if (num <= 0) {
					set = gifts[i];
				}
			}
		}
		num = 0;
		for (int i = 0; i < n; ++i) {
			if (gifts[i] == set) {
				++num;
			}
			else {
				--num;
			}
		}
		if (num > 0) {
			return set;
		}
		return 0;
	}
};
#endif
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		int row = str1.size();
		int col = str2.size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
		for (int i = 0; i <= row; ++i) {
			dp[i][0] = i;
		}
		for (int i = 0; i <= col; ++i) {
			dp[0][i] = i;
		}
		for (int i = 1; i <= row; ++i) {
			for (int j = 1; j <= col; ++j) {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
				}
			}
		}
		cout << dp[row][col] << endl;
	}
	return 0;
}