#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	char s1[101], s2[101], s3[201] = {0};
	cin >> s1;
	cin >> s2;
	int count = strlen(s1) + 1;
	for (int i = 0; i <= strlen(s1); i++) {
		strncpy(s3, s1, i);
		strncpy(s3 + i, s2, strlen(s2));
		strncpy(s3 + i + strlen(s2), s1 + i, strlen(s1) - i);
		for (int j = 0; j < strlen(s3); ++j) {
			if (s3[j] != s3[strlen(s3) - 1 - j]) {
				count--;
				break;
			}
		}
	}
	cout << count;
	return 0;
}
#endif

#include <iostream>
using namespace std;

int main() {
	int n;
	int arr[100000] = { 0 };
	cin >> n;
	int i = 0;
	while (i < n) {
		cin >> arr[i++];
	}
	/*long long count = 0, count1 = 0, res = arr[0];

	for (i = 0; i < n; ++i) {
		count = count1 + arr[i];
		count1 = count;
		if (count > res) {
			res = count;
		}
		for (int j = 0; j < n - 1 - i; j++) {
			count -= arr[j];
			count += arr[i + 1 + j];
			if (count > res) {
				res = count;
			}
		}
	}*/
	long long count = 0, res = arr[0];
	for (i = 0; i < n; ++i) {
		count += arr[i];
		if (count > res) {
			res = count;
		}
		if (count < 0) {
			count = 0;
		}
	}
	cout << res;
	return 0;
}