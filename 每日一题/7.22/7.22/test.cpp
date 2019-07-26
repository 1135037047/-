#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1.size() > s2.size()) {
			swap(s1, s2);
		}
		int row = s1.size(), col = s2.size();
		int max = 0, start;
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
		for (int i = 1; i < row + 1; ++i) {
			for (int j = 1; j < col + 1; ++j) {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				if (dp[i][j] > max) {
					max = dp[i][j];
					start = i - max;
				}
			}
		}
		cout << s1.substr(start, max) << endl;
	}
	return 0;
}
