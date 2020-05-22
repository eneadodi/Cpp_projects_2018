/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Person.h
This is the header class for the Person object
*/

#include "Person.h"

using namespace std;

/*
Default constructor
*/
Person::Person(){
	this->id = 0;
	this->name = "joe";
	this->level = "great";
}

/*
Constructor
parameters: unsigned int id, string name, string level
sets id,name,level private variables to their corresponding paramaters.
*/
Person::Person(unsigned int id, string name, string level){
	this->id = id;
	this->name = name;
	this->level = level;
}


//getters
unsigned int Person::getId() const{
	return id;
}

string Person::getName() const{
	return name;
}

string Person::getLevel() const{
	return level;
}
//END OF GETTERS

//setters
void Person::setId(int id){
	this->id = id;
}

void Person::setName(string name){
	this->name = name;
}

void Person::setLevel(string level){
	this->level = level;
}
//END OF SETTERS

/*OPERATOR OVERLOADERS
The next few methods are operator modifiers for
the operators: ==,!=,=,<,>
Basically makes it so when you compare students,
you compare their id.
For the = operator, it makes this Person have the same name,level,and id 
as the paramater one.
NOTE: there are two different methods for each operator
The first version is of using the actual Object
The second version is using an unsigned int 
*/
bool Person::operator==(const Person& p){
	if(p.getId() == this->id){
		return true;
	}
	else{
		return false;
	}
}

bool Person::operator!=(const Person& p){
	if(p.getId() != this->id){
		return true;
	}
	else{
		return false;
	}
}

void Person::operator=(const Person& p){
	this->id = p.getId();
	this->name = p.getName();
	this->level = p.getLevel();
}

bool Person::operator<(const Person& p){
	if(this->id < p.getId()){
		return true;
	}
	else{
		return false;
	}
}

bool Person::operator>(const Person& p){
	if(this->id > p.getId()){
		return true;
	}
	else{
		return false;
	}
}

bool Person::operator==(const unsigned int& p){
	if(p == this->id){
		return true;
	}
	else{
		return false;
	}
}

bool Person::operator!=(const unsigned int& p){
	if(p != this->id){
		return true;
	}
	else{
		return false;
	}
}


bool Person::operator<(const unsigned int& p){
	if(this->id < p){
		return true;
	}
	else{
		return false;
	}
}

bool Person::operator>(const unsigned int& p){
	if(this->id > p){
		return true;
	}
	else{
		return false;
	}
}


/*
END OF OPERATOR OVERLOADERS
*/