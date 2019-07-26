#include <iostream>

using namespace std;

int main() {
	int n;
	int num1 = 1, num2 = 1,temp;
	cin >> n;

	while (n >= num2) {
		temp = num2;
		num2 += num1;
		num1 = temp;
	}
	int res1 = num2 - n;
	int res2 = n - num1;
	if (res1 < res2) {
		cout << res1;
	}
	else {
		cout << res2;
	}
	return 0;
}


class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (n % 2) {
			return false;
		}
		std::stack<char> a;
		int i = 0;
		while (i < n) {
			if (A[i] == '(') {
				a.push('(');
				i++;
				continue;
			}
			if (a.empty()) {
				return false;
			}
			if (A[i] == ')') {
				if (a.top() == '(') {
					a.pop();
					i++;
					continue;
				}
				else {
					return false;
				}
			}
			return false;
		}
		return true;
	}
};