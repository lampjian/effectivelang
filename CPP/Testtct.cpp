// Testct.cpp

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

#include "ClassTemplate.h"

int main()
{
	myClass<int,int> class1(3,5);
	class1.show();

	myClass<int,char> class2(3,'a');
	class2.show();

	myClass<double,int> class3(2.9,10);
	class3.show();

	cout << "Min of 3.0 and 4.5 is:" << min(3.0,4.5)<<endl;
	system("echo PAUSE...");
}
