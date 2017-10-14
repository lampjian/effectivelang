#include <iostream>
#include <string>

using    namespace    std;

int main()
{
    cout << "构造函数的测试:" <<endl;
    string    sa = "hello world";
    string    sb(sa);
    string    sc("hello world");
    string    sd(10,'@');
    string    se(sa.begin(),sa.end());
    
	char x=100;
	int y=10;
	cout << x+y <<endl;
	cout << y+x <<endl;
	cout << "x+sa:"<<x+sa <<endl;
	cout << "sa+x:"<<sa+x<<endl;
    cout << sa <<endl;
    cout << sb <<endl;
    cout << sc <<endl;
    cout << sd <<endl;
    cout << se <<endl;

    //只有 C++11 标准才支持 cbegin()  cend() crbegin() 和 crend() 函数
    cout << "遍历器的使用:" << endl;
    /*正序遍历*/
    for( string::iterator p = sa.begin() ; p!= sa.end() ; p++ )
        cout << *p ;
    cout << endl;
    //常量正序遍历
    for( string::const_iterator p = sa.begin() ; p!= sa.end() ; p++ )
        cout << *p ;
    cout << endl;
    //倒序遍历
    for( string::reverse_iterator p = sa.rbegin() ; p!= sa.rend() ; p++ )
        cout << *p ;
    cout << endl;
    //倒序常量遍历
    for( string::const_reverse_iterator p = sa.rbegin() ; p!=sa.rend() ; p++ )
        cout << *p;
    cout << endl;

    cout << "与容量相关的函数的使用:" << endl;
    cout << "size     " << sa.size() << endl;
    cout << "len      "    << sa.length() << endl;
    cout << "capacity " << sa.capacity() << endl;
    cout << "max_size " << sa.max_size() << endl;

    cout << "元素的访问" << endl;
    for(string::size_type i = 0 ; i < sa.length() ; i++ )
        cout << sa.at(i) << " " ;
    cout << endl;

    cout << sa.c_str() <<endl;
    cout <<sa.data() << endl;

    return 0;
}
