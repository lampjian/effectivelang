#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
int main(int argc, char *argv[]) {
	return 0;
}
*/

void test();

int fun1(short x) {
    printf("this is fun1.\n");
    if (x<0) {
        return 0;
    }
    else if(x>0) {
        return 1;
    }
}

int fun2() {
    return 22;
}

int fun3() {
    ;
}

short fun4() {
}

int main() {
    printf("Hello world!\n");
    test();
    // short a = 0;
    printf("F1:%d\n",fun1(0));
    printf("F2:%d\n",fun2());
    printf("F3:%d\n",fun3());
    printf("F4:%d\n",fun4());
}

void test() {
    printf("Test\n");
}

