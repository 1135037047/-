#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	for (num = 'A'; num <= 'D'; ++num) {
		if (((num != 'A') + (num == 'C') + (num == 'D') + (num != 'D')) == 3) {
			printf("%c\n",num);
		}
	}
	system("pause");
	return 0;
}