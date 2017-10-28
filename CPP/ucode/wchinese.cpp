#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cwchar>

int main(int argc, char* argv[])
{
	// refresh the I/O buffer
	char chs;while((chs=getchar()) != '\n' && chs != EOF);

	printf("wide string:\n");
	// fflush(stdout);
	wchar_t wstr[] = L"中文";
	setlocale(LC_ALL,"zh_CN.UTF-8");
	wprintf(L"%s\n",wstr);
	wprintf(L"%ls\n",wstr);
	wprintf(L"%S\n",wstr);
	
	fflush(stdout);
	printf("normal Chinese string:\n");
	char str[] = "中文";
	printf("%s\n",str);
	printf("%S\n",str);

	printf("wide char:\n");
	fflush(stdout);
	wchar_t wchar = L'学';
	wprintf(L"%C\n",wchar);
	wprintf(L"%c\n",wchar);

	fflush(stdout);
	printf("normal Chinese char:\n");
	char ch = '习';
	printf("%c\n",ch);

	return 0;
}
