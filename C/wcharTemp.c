// 注意，此文档最好采用utf-8编码
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
	//此语句重要，在win7 + vs2012和 ubuntu 12.04测试结果一致
	//只要打印wchar_t字符，均加此语句，至少不会出错，此语句最好在程序初始化处
	setlocale(LC_ALL, "");

	// wprintf和printf最好不能同时使用.
	// 如下使用printf同时打印了char字符串和wchar_t字符串
	// 因此只采用printf是比较好的方法
	wchar_t ws[] = L"国家";
	printf("printf content start: %ls\n", ws);
	printf("content end\n");
	printf("Size of wchar:%i.\n",sizeof(wchar_t));
	printf("Size of ws:%i.\n",sizeof(ws));

	return 0;
}
