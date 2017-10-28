// writting to an entire binary way to file
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main () {
  streampos size;
  char * memblock;

  ofstream file ("example.bin", ios::binary|ios::ate);
  if (file.is_open())
  {
    // size = file.tellg();
    size = 1024*64;
    memblock = new char [size];
    if(memblock == NULL)
    {
	cerr << "Not sufficient memory."<<endl;
    	return -1;
    }
    memset(memblock,'^',size);
    // file.seekg (0, ios::beg);
    file.write (memblock, size);
    file.close();

    cout << "the entire file content is in files" << endl;

    delete[] memblock;
  }
  else cout << "Unable to open file" << endl;
  return 0;
}
