#if !defined READ_FILE
#define READ_FILE

#include "Text.h"

#include <fstream>
using namespace std;

class ReadFile
{
public:
	ReadFile();
	ReadFile(const char* file_name);
	ReadFile* createReadFile(const char* file_name);
	void destroyReadFile();
	String* readLine();
	bool eof();
	void close();
private:
   ifstream input_file;
   bool _eof;
   bool closed;
};



#endif
