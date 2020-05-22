/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Welcome to the main for Assignment 5!
This is essential information of this assignment
*Will be persistent (stored on disk)
*Consists of student and faculty member record. Each
will have their own tree- masterFaculty and masterStudent
*Tree will be sorted on the primary key value of the nodes.
In our case, the IDs.
How program should work:
When program starts, it should check directory for the 
existence of "facultyTable" and "studentTable"
They correspond to the BST data. If they exist, they should
be read, otherwise new empty trees need to be initialized.
Then this menu should appear:
1)Print all students and their information (sorted by ascending id)
2)Print all facult and their information (sorted by ascending id)
3)Find & display student information given their id
4)Find & display faculty information given faculty id
5)Given a student's id, print the name and info of their
faculty advisor
6)Given a faculty id, print ALL the names and info of
his/her advisees
7)add a new student 
8)Delete a student given the id
9)Add a new faculty member
10)Delete a faculty member giben the id
11)Change a student's advisor given the student id and the
new faculty id
12)Remove an advisee from a facult member fiven the id,
13)Rollback
14)Exit
___________________________________
All commands should enforce refrential integrity.
*/

#include <fstream>
#include <iostream>
#include "TreeNode.h"
#include "Student.h"
#include "Faculty.h"
#include "Person.h"
#include "GenBinaryTree.h"
#include "GenDoublyLinkedList.h"
#include "Database.h"
#include "ListNode.h"
#include <cstdlib>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

bool fileExists(const string& s){
	if(FILE *file = fopen(s.c_str(), "r")){
		fclose(file);
		return true;
	}
	else{
		return false;
	}
}


int main(int argc, char** argv){
	Database db;
	string line = "";
	ifstream fileStudent;
	ifstream fileFaculty;
	cout <<" GETS HERE" << endl;
	string studentValues[6];
	string facultyValues[5];
	//GenDoublyLinkedList<int> advisees;
	int i;
	if(fileExists("studentTable.txt")){
		fileStudent.open("studentTable.txt");
		while(getline(fileStudent, line)){
			i = 0;
			char *str = &line[0];
			char *pch;
			pch = strtok(str, "||"); //splits line by '||'
			while( pch!= NULL){
				studentValues[i] = pch;
				i++;
				pch = strtok(NULL, "||");
			}
			Student s(atoi(studentValues[0].c_str()),studentValues[1],
				studentValues[2],studentValues[3],atof(studentValues[4].c_str()),
				atoi(studentValues[5].c_str()));
			//cout << s << endl;
			db.addStudent(s);
			db.printAllStudents();
		}
	}
	if(fileExists("facultyTable.txt")){
		fileFaculty.open("facultyTable.txt");
		while(getline(fileFaculty, line)){
			i = 0;
			char *str = &line[0];
			char *pch;
			pch = strtok(str, "||"); //splits line by '||'
			while( pch!= NULL){
				facultyValues[i] = pch;
				i++;
				pch = strtok(NULL, "||");
			}
			Faculty f(atoi(facultyValues[0].c_str()),facultyValues[1],facultyValues[2],facultyValues[3]);
			string adviseesF = facultyValues[4];
			f.addAdviseesFromString(adviseesF);
			//cout << f << endl;
			db.addFaculty(f);
			db.printAllFaculty();
		}
	}

	bool dontend = true;
	while(dontend){
		dontend = db.printMenu();
	}
	string savedStudents = "";
	for(int i = 0; i < db.getMasterStudent().getSize();i++){
		savedStudents += db.getMasterStudent().toFile(db.getMasterStudent().getStudent(db.getMasterStudent().getRootPointer(),db.studentIds.removeFront()));
		savedStudents += "\r\n";
	}
	string savedFaculty = "";
	for(int i = 0; i < db.getMasterFaculty().getSize();i++){
		savedFaculty += db.getMasterFaculty().toFile(db.getMasterFaculty().getFaculty(db.getMasterFaculty().getRootPointer(),db.facultyIds.removeFront()));
		savedFaculty += "\r\n";
	}
	cout << savedStudents << endl;
	cout << savedFaculty << endl;
	
	ofstream facultyt;
	facultyt.open("facultyTable.txt", ofstream::out | ofstream::trunc);
	facultyt << savedFaculty << endl;
	facultyt.close();

	ofstream studentt;
	studentt.open("studentTable.txt", ofstream::out | ofstream::trunc);
	studentt << savedStudents << endl;
	studentt.close();
	return 0;
}

