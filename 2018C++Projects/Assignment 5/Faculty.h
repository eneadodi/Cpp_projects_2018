/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Faculty.h
This is the header class for the Faculty object
*/
#ifndef FACULTY_H
#define FACULTY_H
#include "Person.h"
#include "Student.h"
#include "GenDoublyLinkedList.h"
#include <ostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

class Faculty : public Person{
public:
	Faculty();
	Faculty(unsigned int id, string name, string level, string department);
	~Faculty(){};
	string getDepartment() const;
	GenDoublyLinkedList<unsigned int> getAdvisees() const;
	void setDepartment(string department);
	void setAdvisees(GenDoublyLinkedList<unsigned int> advisees);
	void addAdvisee(Student s);
	void addAdvisee(int val);
	void addAdviseesFromString(string s);
	void removeAdvisee(Student s);
	void operator=(const Faculty& f);
	bool operator!=(const Faculty& f);
	bool operator!=(int s);
	bool operator<(const Faculty& f);
	bool operator<(int s);
	bool operator>(const Faculty& f);
	bool operator>(int s);
	string storeToFile();
	unsigned int charArrayToInt(const char *c);
private:
	string department;
	GenDoublyLinkedList<unsigned int> advisees;
};

/*
"<<" overloader
overloads the "<<" operator to best fit this object.
*/
inline ostream& operator<<(ostream &os, const Faculty &f){
	os << " ID: " << f.getId() << " Name: " << f.getName() << " Level: "
	<< f.getLevel() << " Department: " << f.getDepartment() << " Advisees IDs: ";
	ListNode<unsigned int> *curr;
	curr = f.getAdvisees().front;
	while(curr != NULL){
		os << curr->data << ", ";
		curr = curr->next;
	}
	return(os);
}
#endif /* FACULTY_H */