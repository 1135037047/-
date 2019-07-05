#include <iostream>
#include <string>
using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	string::iterator itor,itor1,itor2;
//	itor = s.begin();
//	int num = 0;
//	while (itor != s.end() - 1) {
//		int count = 1;
//		if (*itor >= 48 && *itor <= 57) {
//			itor2 = itor;
//			while (itor != s.end() - 1 && *(itor + 1) <= 57 && *itor + 1 == *(itor + 1)) {
//				itor++;
//				count++;
//			}
//			if (count > num) {
//				num = count;
//				itor1 = itor2;
//			}
//			if (itor == s.end() - 1) {
//				break;
//			}
//		}
//		itor++;
//	}
//	for (int i = 0; i < num; ++i) {
//		cout << itor1[i];
//	}
//
//	return 0;
//}

#include <vector>


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int array[2][100] = { 0 };
		int count = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			int j = 0;
			while (j < count && array[0][j] != numbers[i]) {
				j++;
			}
			if (j == count) {
				array[0][count] = numbers[i];
				array[1][count]++;
				count++;
			}
			else {
				array[1][j]++;
			}
		}
		for (int i = 0; i < count; ++i) {
			if (array[1][i] > numbers.size() / 2) {
				return array[1][i];
			}
		}
		return 0;
	}
};
int main() {
	Solution s;
	vector<int> a = { 1,1,1,2,2,2,3,3,3,4,4,4,};
	int x = s.MoreThanHalfNum_Solution(a);
	cout << x;
	return 0;
}
