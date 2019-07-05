#include <iostream>
using namespace std;

int main() {
	int n;
	int A_i[100000] = { 0 };
	cin >> n;
	int i = 0;
	while (i < n) {
		cin >> A_i[i];
		++i;
	}
	int count = 0;
	for (i = 0; i < n;) {
		if (i + 1 == n) {
			count++;
			i++;
		}
		if (i+1 < n && A_i[i] > A_i[i + 1]) {
			while (i + 1 < n &&A_i[i] >= A_i[i + 1]) {
				i++;
			}
			i++;
			count++;
		}
		if (i + 1 < n && A_i[i] < A_i[i + 1]) {
			while (i + 1 < n &&A_i[i] <= A_i[i + 1]) {
				i++;
			}
			i++;
			count++;
		}
		if (i + 1 < n && A_i[i] == A_i[i + 1]) {
			while (i + 1 < n && A_i[i] == A_i[i + 1]) {
				i++;
			}
			if (i + 1 < n && A_i[i] < A_i[i + 1]) {
				while (i + 1 < n && A_i[i] <= A_i[i + 1]) {
					i++;
				}
				i++;
			}
			else {
				while (i + 1 < n && A_i[i] >= A_i[i + 1]) {
					i++;
				}
				i++;
			}
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}


#if 0
#include <iostream>
#include <string>
using namespace std;

void swap(int i,int n,string& s) {
	while (i < n) {
		char temp = s[i];
		s[i] = s[n];
		s[n] = temp;
		i++;
		n--;
	}
}

int main() {
	string s;
	getline(cin, s);
	int n = s.size() - 1;
	int i = 0;
	int a[50];
	swap(0, n, s);
	int count = 0;
	for (; i < n; i++) {
		if (s[i] == ' ') {
			a[count++] = i;
		}
	}
	if (!count) {
		swap(0, n, s);
		cout << s << endl;
		return 0;
	}
	swap(0, a[0] - 1, s);
	for (i = 0; i + 1 < count; ++i) {
		swap(a[i] + 1, a[i + 1] - 1, s);
	}
	swap(a[i] + 1, n, s);
	cout << s << endl;
	return 0;
}
#endif