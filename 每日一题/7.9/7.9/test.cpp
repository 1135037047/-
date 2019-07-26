


#if 1
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int main() {
	int n;
	vector<string> arr;
	string s;
	cin >> n;
	if (n < 1) {
		cout << "none";
		return 0;
	}
	int i = 0;
	int flag1 = 1, flag2 = 1;
	while (i++ < n) {
		cin >> s;
		arr.push_back(s);
	}
	i = 0;
	while (i < n - 1) {
		if (arr[i].size() > arr[i + 1].size()) {
			flag1 = 0;
			break;
		}
		i++;
	}
	i = 0;
	while (i < n - 1) {
		if (arr[i] > arr[i + 1]) {
			flag2 = 0;
			break;
		}
		i++;
	}
	if (flag1) {
		if (flag2)
			cout << "both";
		else
			cout << "lengths";
	}
	else {
		if (flag2)
			cout << "lexicographically";
		else
			cout << "none";
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	unsigned int a, b;
	cin >> a >> b;
	unsigned int res = 1;
	for (int i = 2; i <= a&& i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			res *= i;
			a /= i;
			b /= i;
			i = 2;
		}
	}
	cout << a * b * res;
	return 0;
}
#endif