#if 0
#include <iostream>
using namespace std;

int main() {
	int n[4] = { 0 };
	int a, b, c;
	int i = 0;
	while (i < 4 && cin >> n[i++]);
	b = (n[1] + n[3]) / 2;
	a = (n[0] + n[2]) / 2;
	c = (n[3] - b);
	if (a - b == n[0] && b - c == n[1] &&
		a + b == n[2] && b + c == n[3]) {
		cout << a << ' ' << b << ' ' << c;
	}
	else {
		cout << "No";
	}
	return 0;
}
#endif;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int num;
	int n;
	int i = 0;
	//scanf("%d%*c%d", &num, &n);
	cin >> num >> n;
	if (num < 0) {
		num = -num;
		cout << '-';
	}
	int arr[32];
	
	for (; num > 0; num /= n) {
		arr[i] = num % n;
		i++;
	}
	i -= 1;
	for (; i >= 0; i--) {
		if (arr[i] > 9) {
			cout << (char)(arr[i] + 55);
		}
		else {
			cout << arr[i];
		}
	}
	return 0;
}