#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#if 1

	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int res1 = 0, res2 = 0;
		for (int i = 0; i < n; i++) {
			if (left[i] == 0) {
				res1 += right[i];
			}
			if (right[i] == 0) {
				res2 += left[i];
			}
		}
		res1++;
		res2++;
		int temp1, temp2;
		int i = 0;
		while (left[i] == 0 || right[i] == 0) {
			i++;
		}
		temp1 = left[i];
		temp2 = right[i];
		for (i = 0; i < n; i++) {
			res1 += left[i];
			res2 += right[i];
			if (right[i] != 0 && left[i] != 0) {
				temp1 = min(temp1, left[i]);
				temp2 = min(temp2, right[i]);
			}
		}
		res1 = res1 - temp1 + 1;
		res2 = res2 - temp2 + 1;
		return min(res1, res2);
	}


	int main() {
		vector<int> a{ 0,7,1,6 };
		vector<int> b{ 1,5,0,6 };
		int x = findMinimum(4, a, b);

	}

#endif

#if 0
	class a {
	public:
		int Add() {
			return 1;
		}
		int _g;
		double SA;
		double bs;
};
	class b : virtual public a{
	public:
		int _d;
		int _b;
	};
	 
	int main() {
		//c s;
		//s.a::_a = 1;
		b s;   

		s._b = 2;
		s._d = 3;
		s._g = 4;
		s.SA = 1.0;
		s.bs = 2.0;
		return 0;
	}
#endif
