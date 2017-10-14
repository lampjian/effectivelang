#pragma message("Start compiling")
#include <cstring>
#include <iostream>

using namespace std;

class String
{
	// << operator
	friend std::ostream& operator << (std::ostream& os, const String& str);
	public:
		// constructor
		String(const char* ch = NULL, int nSize=0)
		{
			if(ch == NULL)
				this->m_chBuf = 0;
			else
			{
				m_chBuf = new char[strlen(ch)+1];
				strcpy(m_chBuf, ch);
			}
			this->m_nSize = nSize;
		}

		~String()
		{
			delete[] m_chBuf;
			m_chBuf = 0;
			m_nSize = 0;
		}

		String(const String& other)
		{
			cout << "Deep copy." << endl;
			this->m_nSize = other.m_nSize;
			// note
			m_chBuf = new char[strlen(other.m_chBuf)+1];
			strcpy(m_chBuf, other.m_chBuf);
		}

		// assignment
		String& operator = (const String& other)
		{
			cout << "Assignment" << endl;
			if(this==&other)
			{
				return *this;
			}
			delete[] m_chBuf;
			m_chBuf = new char[strlen(other.m_chBuf)+1];
			strcpy(m_chBuf, other.m_chBuf);
			return *this;
		}

		String getCh()
		{
			return m_chBuf;
		}

		int getSize()
		{
			return m_nSize;
		}

	private:
		char* m_chBuf;
		int m_nSize;
};

// << implementation
std::ostream& operator << (std::ostream& os, const String& str)
{
	os << str.m_chBuf;
	return os;
}

int main()
{
	String a("is new a.", 10);
	String b(a);

	cout << "a=" << a.getCh() << ",b="<<b.getCh()<<endl;
	cout << "a=" << a.getSize()<<",b="<<b.getSize()<<endl;

	String c("is new c.",20);
	a = c;
	cout << "b=" << b.getCh() << endl;
	cout << "b=" << b.getSize() << endl;
}

#pragma message("End of compiling")
