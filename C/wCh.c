#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "printc.c"
/* c undefined behavior for printf and wprintf
 * in the same file. So the result depends on the
 * compiler you use.
 */

int main(int argc,char* argv[]){

	/*
    char *str="中国上海";
    printf("%s\n",str);
    char *locale=setlocale(LC_CTYPE,NULL);
    printf("locale:%s\n",locale);
    */
    char* locale=setlocale(LC_CTYPE,"zh_CN.UTF-8");
    //printf("locale:%s\n",locale);

    wchar_t *wcstr=L"北京您好";
    wprintf(L"wide char string:%ls\n",wcstr);

	void printc();
	printc();

    return 0;
}

