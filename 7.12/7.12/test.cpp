#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int num;
	while (cin >> num) {
		int arr[32];
		int size = 0;
		for (int i = 0; num > 0; num /= 2, i++) {
			arr[i] = num % 2;
			size++;
		}
		int count1 = 0, count = 0;
		for (int i = 0; i < size; ++i) {
			if (arr[i]) {
				count1++;
			}
			else {
				if (count1 > count) {
					count = count1;
				}
				count1 = 0;
			}
		}
		if (count1 > count) {
			count = count1;
		}
		cout << count << endl;
	}
	return 0;
}




class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b) {
			if (a > b) {
				a = a / 2;
			}
			else {
				b = b / 2;
			}
		}
		return a;
	}
};