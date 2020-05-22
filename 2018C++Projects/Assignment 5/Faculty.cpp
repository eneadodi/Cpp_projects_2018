/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Faculty.cpp
This is the class implementation for the Faculty object
*/

#include "Faculty.h"

using namespace std;

/*
Default Constructor
*/
Faculty::Faculty():Person(){
	this->department = "Computer Science";
}

/*
Constructor
paramters: unsigned int id, string name, string level, 
	string department
sets private variables equal to their corresponsding parameters
*/
Faculty::Faculty(unsigned int id, string name, string level, 
	string department):Person(id,name,level){
	this->department = department;
}

/*
GETTERS
*/
string Faculty::getDepartment() const{
	return department;
}

GenDoublyLinkedList<unsigned int> Faculty::getAdvisees() const{
	return advisees;
}
/*
END OF GETTERS
*/

/*
SETTERS
*/
void Faculty::setDepartment(string department){
	this->department = department;
}

void Faculty::setAdvisees(GenDoublyLinkedList<unsigned int> advisees){
	int size = advisees.getSize();
	for(int i =0; i < size; i++){
		this->advisees.insertFront(advisees.getFront());
		advisees.removeFront();
	}
}
/*
END OF SETTERS
*/

/*
addAdvisee method
parameter: Student s
Checks if faculty has the current student as an advisee.
If they do, nothing is done, otherwise the student is added
*/
void Faculty::addAdvisee(Student s){
	if(advisees.contains(s.getId())){

	}
	else{
		advisees.insertBack(s.getId());
	}
}

/*
removeAdvisee method
paramter Student s
Removes advisee if they exist
*/
void Faculty::removeAdvisee(Student s){
	if(advisees.contains(s.getId())){
		advisees.remove(s.getId());
	}
}


void Faculty::operator=(const Faculty& f){
	setId(f.getId());
	setName(f.getName());
	setLevel(f.getLevel());
	setDepartment(f.getDepartment());
	setAdvisees(f.getAdvisees());
}

string Faculty::storeToFile(){
	string ids = to_string(getId());
	string rstring = ids + "||" + getName() + "||" + getLevel() + "||" + getDepartment() + "||";
	GenDoublyLinkedList<unsigned int> proxAdvisees = advisees;
	for(int i = 0; i < proxAdvisees.getSize(); i++){
		rstring = rstring + to_string(proxAdvisees.removeFront()) + ",";
	}
	return rstring;
}

void Faculty::addAdviseesFromString(string s){
	//cout << s << endl;
	char *str = &s[0];
	unsigned int idprox;
	char *pch = strtok(str, ",");
	while( pch!= NULL){
		idprox = charArrayToInt(pch);
		//cout << idprox << endl;
		addAdvisee(idprox);
		pch = strtok(NULL, ",");
	}
}

void Faculty::addAdvisee(int val){
	bool ha = advisees.contains(val);
	if(!ha){
		advisees.insertBack(val);
	}
}

/*
charArrayToInt
paramter: const char &c
Was trying to convert using atoi() a char array 
but it wasnt working. Thus, I was in the airplane,
no real way for me to check up how to convert one from another
so i improvized. Probably not the most efficient way to do this
but it works 
*/
unsigned int Faculty::charArrayToInt(const char *c){
	int multiplier = 1000000;
	int rId = 0;
	for(int i = 0; i < 7;i++){
		if(c[i] == '1')
			rId = rId + 1*multiplier;
		else if(c[i] == '2')
			rId = rId + 2*multiplier;
		else if(c[i] == '3')
			rId = rId + 3*multiplier;
		else if(c[i] == '4')
			rId = rId + 4*multiplier;
		else if(c[i] == '5')
			rId = rId + 5*multiplier;
		else if(c[i] == '6')
			rId = rId + 6*multiplier;
		else if(c[i] == '7')
			rId = rId + 7*multiplier;
		else if(c[i] == '8')
			rId = rId + 8*multiplier;
		else if(c[i] == '9')
			rId = rId + 9*multiplier;
		else if(c[i] == '0'){
		}
		multiplier = multiplier/10;
	}
	return rId;
}

bool Faculty::operator!=(const Faculty& f){
	if(getId() == f.getId()){
		if(getName() == f.getName()){
			if(getLevel() == f.getLevel()){
				if(getDepartment() == f.getDepartment()){
					return true;
				}
			}
		}
	}
	return false;

}
bool Faculty::operator!=(int s){
	if(getId() == s){
		return true;
	}
	return false;
}

bool Faculty::operator<(int s){
	if(getId() < s){
		return true;
	}
	return false;
}

bool Faculty::operator<(const Faculty& f){
	if(getId() < f.getId()){
		return true;
	}
	return false;
}

bool Faculty::operator>(int s){
	if(getId() > s){
		return true;
	}
	return false;
}

bool Faculty::operator>(const Faculty& f){
	if(getId() > f.getId()){
		return true;
	}
	return false;
}


