#include "ReadFile.h"
#include <iostream>
#include <string>

// 6156361477

using namespace std;

ReadFile::ReadFile()
{


}

ReadFile::ReadFile(const char* file_name)
{
    //ReadFile* rf = new ReadFile(file_name);

   this->input_file.open(file_name);
   this->closed = false;
   this->_eof = false;
}
ReadFile* ReadFile::createReadFile(const char* file_name)
{
   ReadFile* rf = new ReadFile();

   return rf;
}

void ReadFile::destroyReadFile()
{
   close();
   delete this;
}

bool ReadFile::eof()
{
   return this->_eof;
}

void ReadFile::close()
{
   if (!this->closed)
   {
      this->input_file.close();
      this->closed = true;
   }
}

String* ReadFile::readLine()
{
   if (this->closed) return NULL;
   if (this->_eof) return NULL;

   string text;
   this->_eof = !(getline(this->input_file, text));

   String* str = new String((const char*) text.c_str());
   //cout << text;
   return str;
}
