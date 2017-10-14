#include <iostream>

void test();

int fun1(short x) {
	std::cout << "this is fun1." <<std::endl;
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

int fun4() {
}

float fun5() {
}

int main(int argc, char** argv) {
	std::cout << "Hello world!\n";
	test();
	short a = 0;
	std::cout << "F1:" << fun1(a) << std::endl;
	std::cout << "F2:" << fun2() << std::endl;
	std::cout << "F3:" << fun3() << std::endl;
	std::cout << "F4:" << fun4() << std::endl;
	std::cout << "F5:" << fun5() << std::endl;
}

void test() {
	std::cout << "Test" << std::endl;
}

