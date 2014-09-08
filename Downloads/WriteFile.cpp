#include "WriteFile.h"
#include <sstream>
#include <iostream>

using namespace std;

WriteFile::WriteFile(const char* file_name)
{
   this->output_file.open(file_name);
   this->closed = false;

}

WriteFile::WriteFile()
{

}


WriteFile* WriteFile::createWriteFile(const char* file_name)
{
   WriteFile* wf = new WriteFile(file_name);

   return wf;
}

void WriteFile::destroyWriteFile()
{
   close();
   delete this;
}

void WriteFile::close()
{
   if (!this->closed)
   {
      this->output_file.close();
      this->closed = true;
   }
}

void WriteFile::writeLine(String* line)
{
   if (!this->closed && line->length() > 0)
   {
      this->output_file << line->getText() << endl;
   }
   //cout << line->getText();
}
