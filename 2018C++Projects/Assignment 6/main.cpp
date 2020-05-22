/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 6 - database
Date: Novemeber 25 2018

*/

#include <string>
#include "SortingAlgorithms.h"
#include <limits>
using namespace std;

int untilInt(){
    bool valid= false;
    double input = -1;
    string ent = "Enter either 1 or 2: ";
    do
    {
        cout << ent << flush;
        cin >> input;
        if (cin.good())
        {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            //something went wrong, we reset the buffer's state to good
            cin.clear();
            //and empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input; please enter an integer." << endl;
        }
    } while (!valid);
    if(input < 0)
    	input = input*-1;
    return (int)input;
}

int main(int argc, char** argv){
	cout << "1) enter the name of the text file to be opened" << endl;
	cout << "2) Create a file with randomly generated doubles to be read" << endl;
	int option = -1;
	while(option < 1 || option > 2){
		option = untilInt();
	}
	string s;
	if(option == 1){
		cout << "Please enter the text file name" << endl;
		cin >> s;
	}
	else{
		s = "ckvpoky5px.txt";
	}
	SortingAlgorithms sa(s);
  if(sa.RealFile == true){
	  sa.compareSortingAlgorithms();
  }
}