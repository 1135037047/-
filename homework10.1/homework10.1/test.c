#include <stdio.h>
#include <stdlib.h>
int main() {
	int a, b, c, d, e;
	//所有可能的结果
	for (a = 1; a <= 5;++a) {
		for (b = 1; b <= 5; ++b) {
			for (c = 1; c <= 5; ++c) {
				for (d = 1; d <= 5; ++d) {
					for (e = 1; e <= 5; ++e) {
						//所有人判断的结果,一真一假
						if ((b == 2 && a != 3 || b != 2 && a == 3) &&
							(b == 2 && e != 4 || b != 2 && e == 4) && 
							(c == 1 && d != 2 || c != 1 && d == 2) && 
							(c == 5 && d != 3 || c != 5 && d == 3) && 
							(e == 4 && a != 1 || e != 4 && a == 1) &&
							//排除掉a,b,c,d,e数字相同的情况
							a * b * c * d * e == 120) {
							printf("A B C D E \n%d %d %d %d %d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}