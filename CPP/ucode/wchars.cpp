#include <iostream>
#include <locale>
#include <cstdlib>
#include <cstdio>
#include <clocale>

using namespace std;

// locale loc("chs");//windows下ok

//这段貌似在ubuntu下ok
// locale loc("zh_CN.UTF-8");
//而且还需要在ubuntu的终端中执行：
//sudo locale-gen

int main()
{
	setlocale(LC_ALL,"");
	wchar_t wStr[]=L"这是一段中文";
	//wcout.imbue(loc);
	wcout<<wStr<<endl;
	getchar();
	getchar();
	return 0;
}
