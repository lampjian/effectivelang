#include<stdio.h>
#include<wchar.h>
#include<locale.h>

void main()
{
	 
    wchar_t wc;
    printf ("Locale is: %s\n", setlocale(LC_ALL,NULL) );
    // setlocale(LC_ALL,"");//设置为本地区域
    // setlocale(LC_ALL,"zh_CN.UTF-8");//设置区域
    printf("Locale set:%s.\n",setlocale(LC_ALL,"zh_CN.UTF-8"));//设置区域
    /*
    while (1) {
        wc = getwchar();
        if(wc != L'\n')
        {
        	// wprintf(L"%c==0X%4X\n",wc,wc);
        	wprintf(L"%c==\\u%4X\n",wc,wc);
		}
    }
    */
    
    while ((wc = getwchar()) != L'\n') {
        if(wc != L'\n')
        {
			// wprintf(L"%lc\n",wc);
			printf("%lc\n",wc);
        	// wprintf(L"%lc == 0X%4X\n",wc,wc);
        	printf("%C == 0X%4X\n",wc,wc);
		}
    }
    char ch;
    printf("ch=%i\n",ch);
    ch = ' ';
    printf("ch=%d\n",ch);
    while((ch=getchar()) != '\n' && ch != EOF);
}
