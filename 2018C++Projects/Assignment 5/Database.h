/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Database.h
This is the header class for the Database object
*/
#ifndef DATABASE_H
#define DATABASE_H
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "Queue.h"
#include "GenBinaryTree.h"
#include "GenDoublyLinkedList.h"
#include <ostream>
#include <string>
using namespace std;

class Database{
public:
	Database();
	~Database();

	Student returnStudent(unsigned int value);
	Faculty returnFaculty(unsigned int value);
	void printAllStudents();
	void printAllFaculty();
	void printAdvisor(unsigned int idStudent);
	void printAdvisees(unsigned int idFaculty);
	bool checkStudentExists(unsigned int id);
	bool checkFacultyExists(unsigned int id);
	void findStudentById(unsigned int id);
	void findFacultyById(unsigned int id);
	void addStudent(Student s, unsigned int idFaculty);
	void addStudent(Student s);
	void addFaculty(Faculty f);
	Student createStudent();
	Faculty createFaculty();
	void deleteStudent(unsigned int id);
	void deleteFaculty(unsigned int id);
	void changeAdvisor(unsigned int idStudent, unsigned int idFaculty);
	void removeAdvisee(unsigned int idStudent, unsigned int idFaculty);
	void removeAdvisee(unsigned int idStudent, unsigned int idFaculty, unsigned int newFacultyId);
	bool printMenu();
	bool doUserChoice(int c);
	int untilInt(int version);
	double untilDouble();
	GenBinaryTree<Student> getMasterStudent() const;
	GenBinaryTree<Faculty> getMasterFaculty() const;

	GenDoublyLinkedList<unsigned int> facultyIds;
	GenDoublyLinkedList<unsigned int> studentIds;
	Queue<GenBinaryTree<Student>> historyMasterStudent;
	Queue<GenBinaryTree<Faculty>> historyMasterFaculty;
private:
	GenBinaryTree<Student> masterStudent;
	GenBinaryTree<Faculty> masterFaculty;
};

#endif /* DATABASE_H */