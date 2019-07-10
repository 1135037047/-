#include <iostream>
#include <vector>
using namespace std;

int addAB(int A, int B) {
	// write code here
	int temp;
	while (B != 0) {
		temp = A;
		A = A ^ B;
		B = (B&temp) << 1;
	}
	return A;
}


int main() {

	int a = 2 , b = 2;
	addAB(a, b);
	int m, n;
	cin >> m;

	cin >> n;

	m++;
	n++;
	vector<vector<int>> arr(m, vector<int>(n, 0));
	for (auto &e : arr[0]) {
		e = 1;
	}
	for (int i = 0; i < m; i++) {
		arr[i][0] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
	cout << arr[m - 1][n - 1];
	return 0;
}