#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a_i[10000] = { 0 };
	int i = 0;
	while (i < 3 * n && cin >> a_i[i]) {
		++i;
	}
	sort(a_i,a_i + 3 * n);
	int result = 0;
	for (i = n; i < 3 * n; i += 2) {
		result += a_i[i];
	}
	cout << result << endl;
	return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	int count = 0;
	int i = 0;
	for (; i + count < str1.size(); ++i) {
		int flag = 0;
		for (int j = 0; j < str2.size(); ++j) {
			if (str1[i + count] == str2[j]) {
				count++;
				flag = 1;
				break;
			}
		}
		if (flag) {
			i--;
			continue;
		}
		str1[i] = str1[i + count];
	}
	str1[i] = '0';
	for (int x = 0; x < i; ++x) {
		cout << str1[x];
	}
	return 0;
}