#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char **argv){
    ifstream out;
    string str = "text.txt";
    out.open(str.c_str(), ios::in);
    if(!out.is_open()) 
    {
	cout << "No file opened."<<endl;
	return -1;
    }
    string line;
    while(!out.eof()){
        getline(out,line);
        cout <<line<<endl;
    }
    out.close();
    return 0;
}
