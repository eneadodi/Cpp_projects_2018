#include "SyntaxChecker.h"
#include "GenStack.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

SyntaxChecker::SyntaxChecker(){

  setRChar('z');

}
/*
SyntaxChecker::SyntaxCheker(ifstream f){

}
*/

SyntaxChecker::SyntaxChecker(string fileinstring){
  ifstream infile(fileinstring);
  string t = "";
  string temp2 = "";
  bool findleft = true;
  if(infile){
    while(infile.good()){
      line++;
      getline(infile,t);
      for(int i = 0; i < t.length(); i++){
        if(t[i] == '(' ||  t[i] == '{' || t[i] == '[' || t[i] == ')' ||  t[i] == '}' || t[i] == ']'){
          real.push(t[i]);
          lines.push(line);
        }
      }
    }
  }
  else{
    cerr <<  "no file!" <<endl;
  }
}
GenStack<char> SyntaxChecker::getRealStack(){
  return real;
}
void SyntaxChecker::setRealStack(const GenStack<char>& s){
  real = s;
}
GenStack<char> SyntaxChecker::getTempStack(){
  return temp;;
}
void SyntaxChecker::setTempStack(const GenStack<char>& s){
  temp = s;
}

GenStack<int> SyntaxChecker::getLinesStack(){
  return lines;
}

void SyntaxChecker::setLinesStack(const GenStack<int>& l){
  lines = l;
}

bool SyntaxChecker::getProperSyntax(){
  return properSyntax;
}

void SyntaxChecker::setProperSyntax(const bool& a){
  properSyntax = a;
}
char SyntaxChecker::getRChar(){
  return rchar;
}

void SyntaxChecker::setRChar(const char& s){
  if(s == 'z'){
    setRString("Cant make empty constructor sorry!");
  }
  else{
    rchar = s;
  }
}

string SyntaxChecker::getRString(){
  return rstring;
}

void SyntaxChecker::setRString(string s){
  rstring = s;
}
string SyntaxChecker::checkSyntax(){
  char yes;
  int makeshift =  0;
  string str;
  char c = real.pop();
  makeshift = lines.pop();
  char flip;
  char potential;
  flip = flipSide(c);
  while(!real.isEmpty()){
    potential = real.peek();
    if(potential == flip){
      yes = real.pop();
      makeshift = lines.pop();
      while(!temp.isEmpty()){
        real.push(temp.pop());
        if(real.isEmpty()){
          break;
        }
      }
      checkSyntax();
    }
    else{
      temp.push(real.pop());
    }
  }
  if(!temp.isEmpty()){
      string rs = "";
      rs += "was looking for ";
      rs += c;
      rs += "instead found";
      rs += temp.pop();
  }
  else if(temp.isEmpty()){
      return "success!";
  }
  else{
      return str;
  }
}

char SyntaxChecker::flipSide(char s){
  if(s == '('){
    s = ')';
  }
  else if(s == '['){
    s = ']';
  }
  else if(s == '{'){
    s = '}';
  }
  else if(s == ')'){
    s = '(';
  }
  else if(s == '}'){
    s = '{';
  }
  else if(s == ']'){
    s = '[';
  }
  return s;
}
bool SyntaxChecker::correctDelimiter(char a, char b){
  if(a == '(' && b == ')'){
    return true;
  }
  else if(a == '{' && b == '}'){
    return true;
  }
  else if(a == '[' && b == ']'){
    return true;
  }
  else{
    return false;
  }
}

void SyntaxChecker::flipSide(){
  char s = getRChar();
  if(s == '('){
    s = ')';
  }
  if(s == '['){
    s = ']';
  }
  if(s == '{'){
    s = '}';
  }
  if(s == ')'){
    s = '(';
  }
  if(s == '}'){
    s = '{';
  }
  if(s == ']'){
    s = '[';
  }
  setRChar(s);
}
