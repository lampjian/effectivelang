#include <string>
using namespace std;

string CNoviewPDlg::AsciiToUnicode(string szStringA)  
{  
    string str = szStringA.GetBuffer(0);  
    // 预算-缓冲区中宽字节的长度      
    int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);  
    // 给指向缓冲区的指针变量分配内存      
    wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
    // 开始向缓冲区转换字节      
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);  
    wstring ret_str = pUnicode;  
    free(pUnicode);  
    return CString(ret_str.c_str());  
}

string CNoviewPDlg::UnicodeToAscii(string szString)  
{  
    wstring wstr = szString.GetBuffer(0);  
    // 预算-缓冲区中多字节的长度      
    int ansiiLen = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);  
    // 给指向缓冲区的指针变量分配内存      
    char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);  
    // 开始向缓冲区转换字节      
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);  
    string ret_str = pAssii;  
    free(pAssii);  
    return CStringA(ret_str.c_str());  
}  

int main()
{

}
