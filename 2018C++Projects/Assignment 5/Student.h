/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Student.h
This is the header class for the Student object
*/
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <ostream>
#include <string>
using namespace std;

class Student : public Person{
public:
	Student();
	Student(unsigned int id, string name, string level, 
	string major, double GPA, int advisor);
	Student(unsigned int id, string name, string level, 
	string major, double GPA);
	~Student(){};
	string getMajor() const;
	double getGPA() const;
	unsigned int getAdvisor() const;
	void setMajor(string major);
	void setGPA(double GPA);
	void setAdvisor(unsigned int advisor);
	void operator=(const Student& s);
	bool operator!=(const Student& s);
	bool operator!=(int s);
	bool operator<(const Student& s);
	bool operator<(int s);
	bool operator>(const Student& s);
	bool operator>(int s);
	string storeToFile();
private:
	string major;
	double GPA;
	unsigned int advisor;
};

/*
operator ">>" overloader
overloads the >> operator so the correct information
is given when the ">>" operator is used on Student
*/
inline ostream& operator<<(ostream &os, const Student &s){
	os << "ID: " << s.getId() << " Name: " << s.getName() << " Level: "
	<< s.getLevel() << " Major: " << s.getMajor() << " GPA: " << s.getGPA()
	<< " Advisor-ID: " << s.getAdvisor();
	return(os);
}
#endif /* STUDENT_H */