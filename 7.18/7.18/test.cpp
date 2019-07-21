#if 0
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n, count, res;
	while (cin >> n) {
		if (n < 6) {
			cout << 0 << endl;
			continue;
		}
		count = 0;
		for (int i = 6; i <= n; ++i) {
			res = 1;
			for (int j = 2; j <= sqrt(i); ++j) {
				if (i % j == 0) {
					res += j;
					if (j * j != i) {
						res += (i / j);
					}
				}
			}
			if (res == i) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

void aA(string &s) {
	for (auto &e : s) {
		if (e == 'a') {
			e = 'J';
			continue;
		}
		if (e == 'b') {
			e = 'Q';
			continue;
		}
		if (e == 'c') {
			e = 'K';
			continue;
		}
		if (e == 'd') {
			e = 'A';
			continue;
		}
		if (e == 'e') {
			e = '2';
			continue;
		}
		if (e == 'Z') {
			e = '1';
		}
	}
	s.insert(s.find('1') + 1, 1, '0');
}

int main() {
	string s1, s2;
	getline(cin, s1);
	int index = s1.find('-');
	s2 += &s1[index + 1];
	s1.erase(index);
	if (s1.find("joker") != string::npos) {
		if (s1.size() == 5) {
			if (s2 == "JOKER" || s2.size() >= 7) {
				cout << s2 << endl;
				return 0;
			}
			else if (s2.size() > 1) {
				cout << "ERROR" << endl;
				return 0;
			}
			else {
				cout << s1 << endl;
				return 0;
			}
		}
		else {
			cout << s1 << endl;
			return 0;
		}
	}
	if (s1 == "JOKER") {
		if (s2.size() == 7) {
			cout << s2 << endl;
			return 0;
		}
		else if (s2 == "joker" || s2.size() == 1) {
			cout << s1 << endl;
			return 0;
		}
		else {
			cout << "ERROR" << endl;
			return 0;
		}
	}
	if (s2.find("joker") != string::npos) {
		if (s2.size() == 5) {
			if (s1 == "JOKER" || s1.size() >= 7) {
				cout << s1 << endl;
				return 0;
			}
			else if (s1.size() > 1) {
				cout << "ERROR" << endl;
				return 0;
			}
			else {
				cout << s2 << endl;
				return 0;
			}
		}
		else {
			cout << s2 << endl;
			return 0;
		}
	}
	if (s2 == "JOKER") {
		if (s1.size() == 7) {
			cout << s1 << endl;
			return 0;
		}
		else if (s1 == "joker" || s1.size() == 1) {
			cout << s2 << endl;
			return 0;
		}
		else {
			cout << "ERROR" << endl;
			return 0;
		}
	}
	for (auto &e : s1) {
		if (e == 'J') {
			e = 'a';
			continue;
		}
		if (e == 'Q') {
			e = 'b';
			continue;
		}
		if (e == 'K') {
			e = 'c';
			continue;
		}
		if (e == 'A') {
			e = 'd';
			continue;
		}
		if (e == '2') {
			e = 'e';
			continue;
		}
		if (e == '1') {
			e = 'Z';
			s1.erase(s1.find('Z') + 1, 1);
		}
	}
	for (auto &e : s2) {
		if (e == 'J') {
			e = 'a';
			continue;
		}
		if (e == 'Q') {
			e = 'b';
			continue;
		}
		if (e == 'K') {
			e = 'c';
			continue;
		}
		if (e == 'A') {
			e = 'd';
			continue;
		}
		if (e == '2') {
			e = 'e';
			continue;
		}
		if (e == '1') {
			e = 'Z';
			s2.erase(s2.find('Z') + 1, 1);
		}
	}
	if (s1.size() == 7 && s2.size() == 7) {
		if (s1[0] > s2[0]) {
			aA(s1);
			cout << s1 << endl;
			return 0;
		}
		else {
			aA(s2);
			cout << s2 << endl;
			return 0;
		}
	}
	if (s1.size() == 7) {
		aA(s1);
		cout << s1 << endl;
		return 0;
	}
	if (s2.size() == 4) {
		aA(s2);
		cout << s2 << endl;
		return 0;
	}
	if (s1.size() != s2.size()) {
		cout << "ERROR" << endl;
		return 0;
	}
	else {
		if (s1[0] < s2[0]) {
			aA(s2);
			cout << s2 << endl;
			return 0;
		}
		else {
			aA(s1);
			cout << s1 << endl;
			return 0;
		}
	}
	return 0;
}
#endif

#include <assert.h>

void cx(char * p) {
	assert(p != NULL);
}
#include <iostream>
using namespace std;
int main() {
	cout << true << false << endl;
}