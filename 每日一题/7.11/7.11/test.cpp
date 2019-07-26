#include <iostream>
#include <string>
#include <vector>
using namespace std;

string GetPwdSecurityLevel(string pPasswordStr) {
	//vector<string> PasswordValue{ "VERY_WEAK","WEAK","AVERAGE","STRONG","VERY_STRONG","SECURE","VERY_SECURE" };
	int res = 0;
	vector<int> arr(5, 0);
	arr[0] = pPasswordStr.size();
	for (int i = 0; i < arr[0]; ++i) {
		if (pPasswordStr[i] >= 'A' && pPasswordStr[i] <= 'Z') {
			arr[1]++;
		}
		if (pPasswordStr[i] >= 'a' && pPasswordStr[i] <= 'z') {
			arr[2]++;
		}
		if (pPasswordStr[i] >= '0' && pPasswordStr[i] <= '9') {
			arr[3]++;
		}
		if ((pPasswordStr[i] >= '!' && pPasswordStr[i] <= '/') || (pPasswordStr[i] >= ':' && pPasswordStr[i] <= '@') || (pPasswordStr[i] >= '[' && pPasswordStr[i] <= '`') || (pPasswordStr[i] >= '{' && pPasswordStr[i] <= '~')) {
			arr[4]++;
		}
	}
	if (arr[0] <= 7) {
		if (arr[0] <= 4) {
			res += 5;
		}
		else {
			res += 10;
		}
	}
	else {
		res += 25;
	}
	if (arr[1] + arr[2] == 0) {
		//什么都不做
	}
	else if (arr[1] && arr[2]) {
		res += 20;
	}
	else {
		res += 10;
	}
	if (arr[3] > 1) {
		res += 20;
	}
	else if (arr[3]) {
		res += 10;
	}
	if (arr[4] > 1) {
		res += 25;
	}
	else if (arr[4]) {
		res += 10;
	}
	if ((arr[1] + arr[2]) && arr[3]) {
		res += 2;
	}
	if ((arr[1] + arr[2]) && arr[3] && arr[4]) {
		res += 3;
	}
	if (arr[1] && arr[2] && arr[3] && arr[4]) {
		res += 5;
	}
	if (res < 25) {
		return "VERY_WEAK";
	}
	if (res < 50) {
		return "WEAK";
	}
	if (res < 60) {
		return "AVERAGE";
	}
	if (res < 70) {
		return "STRONG";
	}
	if (res < 80) {
		return "VERY_STRONG";
	}
	if (res < 90) {
		return "SECURE";
	}
	return "VERY_SECURE";
}

int main() {
	string s;
	cin >> s;
	cout << GetPwdSecurityLevel(s);
	return 0;
}