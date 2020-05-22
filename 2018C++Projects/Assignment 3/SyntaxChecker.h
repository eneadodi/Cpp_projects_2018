#ifndef SYNTAXCHECKER_H
#define GAMEOFLIFE_H
#include "GenStack.h"
#include <iostream>
#include <cstdlib>

using namespace std;
/*
template <class T>
struct stackWithLines{
  string obj;
  int lineNumber;
};
*/
class SyntaxChecker{
public:
  //Constructors
  SyntaxChecker();
  SyntaxChecker(string fileinstring);
  //~SyntaxCheker();

  //getters and setters
  GenStack<char> getRealStack();
  void setRealStack(const GenStack<char>& s);
  GenStack<char> getTempStack();
  void setTempStack(const GenStack<char>& s);
  GenStack<int> getLinesStack();
  void setLinesStack(const GenStack<int>& l);
  bool getProperSyntax();
  void setProperSyntax(const bool& a);
  char getRChar();
  void setRChar(const char& s);
  string getRString();
  void setRString(string s);

  //methods
  string checkSyntax();
  void flipSide();
  char flipSide(char s);
  bool correctDelimiter(char a, char b);

private:
  GenStack<char> real;
  GenStack<char> temp;
  GenStack<int> lines;
  bool properSyntax;
  char rchar;
  string rstring = "";
  int line = 0;
  char firstVal;
};
#endif /* SYNTAXCHECKER_H */
