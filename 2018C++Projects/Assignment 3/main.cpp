#include<cstdlib>
#include<iostream>
#include<fstream>
//#include "IFile.h"
#include "GenStack.h"
#include "SyntaxChecker.h"


int main(int argc, char** argv) {

  string filename = "";
  string filetostring = "";
  string temp = "";
  string rstring = "";
  cin >> filename;
  SyntaxChecker syncheck(filename);
  temp = syncheck.checkSyntax();
  cout <<temp<< endl;
  return 0;
}
