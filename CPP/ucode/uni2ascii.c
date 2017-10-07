#include <wchar.h>
#include <locale.h>
#include "utf8.h"

int main()
{
	setlocale(LC_ALL,"");
	wchar_t wc = L'知';
	/*while(true)
	{
		wc = getwchar();
		if(wc != L'\n')
		{
			// cout << hex << "\\u"<< wc <<endl;
			wprintf(L"%c == \\u%4X\n",wc,wc);
		}
	}*/
	char buffer[100]={};
	wprintf(L"%c==\\u%4x\n",wc,u8_escape_wchar(buffer,100,wc));
	wprintf(L"%c==\\u%4x\n",wc,wc);
	wprintf(L"%c==\\u%4x\n",'a','a');
}

