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
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person{
public:
	Person();
	Person(unsigned int id, string name, string level);
	~Person(){};
	unsigned int getId() const;
	string getName() const;
	string getLevel() const;
	void setId(int id);
	void setName(string name);
	void setLevel(string level);
	string toString();
	bool operator==(const Person& p);
	bool operator!=(const Person& p);
	void operator=(const Person& p);
	bool operator<(const Person& p);
	bool operator>(const Person& p);
	bool operator==(const unsigned int& p);
	bool operator!=(const unsigned int& p);
	bool operator<(const unsigned int& p);
	bool operator>(const unsigned int& p);

private:
	unsigned int id;
	string name;
	string level;
};

#endif /* PERSON_H */