/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Student.cpp
This is the class implementation for the Student object
*/
#include "Student.h"
using namespace std;

/*
default Constructor
*/
Student::Student():Person(){
	this->major = "Buisness";
	this->GPA = 2.75;
	this->advisor = 1;
}

/*
Constructor
paramters: unsigned int id, string name, string level, 
	string major, double GPA, int advisor
sets all private variables to their corresponding parameter
*/
Student::Student(unsigned int id, string name, string level, 
	string major, double GPA, int advisor):Person(id,name,level){
	this->major = major;
	this->GPA = GPA;
	this->advisor = advisor;
}

/*
Constructor
paramters: unsigned int id, string name, string level, 
	string major, double GPA, int advisor
sets all private variables to their corresponding parameters. 
Because advisor was not given, assigns default value.
*/
Student::Student(unsigned int id, string name, string level, 
	string major, double GPA):Person(id,name,level){
	this->major = major;
	this->GPA = GPA;
	this->advisor = 0;
}

/*
GETTERS
*/
string Student::getMajor() const{
	return major;
}

double Student::getGPA() const{
	return GPA;
}

unsigned int Student::getAdvisor() const{
	return advisor;
}
/*
END OF GETTERS
*/

/*
SETTERS
*/
void Student::setMajor(string major){
	this->major = major;
}

void Student::setGPA(double GPA){
	this->GPA = GPA;
}

void Student::setAdvisor(unsigned int advisor){
	this->advisor = advisor;
}
/*
END OF SETTERS
*/

void Student::operator=(const Student& s){
	setId(s.getId());
	setName(s.getName());
	setLevel(s.getLevel());
	setMajor(s.getMajor());
	setGPA(s.getGPA());
	setAdvisor(s.getAdvisor());
}

bool Student::operator!=(const Student& s){
	if(getId() == s.getId()){
		if(getName() == s.getName()){
			if(getLevel() == s.getLevel()){
				if(getMajor() == s.getMajor()){
					if(getGPA() == s.getGPA()){
						if(getAdvisor() == s.getAdvisor()){
							return true;
						}
					}
				}
			}
		}
	}
	return false;

}
bool Student::operator!=(int s){
	if(getId() == s){
		return true;
	}
	return false;
}

bool Student::operator<(int s){
	if(getId() < s){
		return true;
	}
	return false;
}

bool Student::operator<(const Student& s){
	if(getId() < s.getId()){
		return true;
	}
	return false;
}

bool Student::operator>(int s){
	if(getId() > s){
		return true;
	}
	return false;
}

bool Student::operator>(const Student& s){
	if(getId() > s.getId()){
		return true;
	}
	return false;
}

string Student::storeToFile(){
	string ids = to_string(getId());
	string adid = to_string(getAdvisor());
	string gpas = to_string(getGPA());
	string rstring = ids + "||" + getName() + "||" + getLevel() + "||" + getMajor() + "||" + gpas + "||" + adid;
	return rstring;
}
