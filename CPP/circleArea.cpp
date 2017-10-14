/*
 * Copyright(c) 2017, HFUT
 * All rights reserved
 * File: circleArea.cpp
 * Author: Lamp
 * Date: 2017.10.03
 * Version: v1.0.1
 */

// According the half len r, calculate the circle area, two digit precision
// parameter: IN: r, digit num
//            Out: first line default two digit, second line denote digit
// Example: 4 1;
// 50.27
// 50.3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float area(float r, short pre)
{
	float are = M_PI*r*r;
	cout << setiosflags(ios::fixed) << setprecision(2)<<are<<endl;
	cout << setiosflags(ios::fixed) << setprecision(pre)<<are<<endl;
}

int main()
{
	/*float r;
	short p;
	cin>>r>>p;
	area(r,p);
	*/
	cout << M_E <<endl;
	cout << acos(double(-1))<<endl;

}
