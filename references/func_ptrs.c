#include <stdio.h>

struct FunctionWrapper {
	int (*func)();
} func1;

int getNum(int i) {
	return i;
}

int (*get_getZero())() {
	return &getNum;
}

int main() {
	func1.func = get_getZero();
	printf("%d\n", get_getZero()(3));	// prints 0
}

