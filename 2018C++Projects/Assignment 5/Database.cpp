/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Database.cpp
This is the class implementation of the Database object
*/

#include "Database.h"
#include "time.h"
#include <limits>
#include <cstdlib>
//#include <cstdio>
using namespace std;
/*
Default Constructor. Starts the random seed
*/
Database::Database(){
	srand(time(NULL));
}

/*
Destructor
*/
Database::~Database(){

}

/*
getMasterStudent method
gets the Binary Search Tree called masterStudent
*/
GenBinaryTree<Student> Database::getMasterStudent() const{
	return masterStudent;
}

/*
getMasterFaculty method
gets the Binary Search Tree called masterFaculty
*/
GenBinaryTree<Faculty> Database::getMasterFaculty() const{
	return masterFaculty;
}

/*
printAllStudents method.
basically calls the printTree method of GenBinaryTree. Made this method just to be cleaner
*/
void Database::printAllStudents(){
	cout << "-----------------------------------------------ALL STUDENTS-----------------------------------------------" << endl;
	masterStudent.printTree();
	cout << "-----------------------------------------------ALL STUDENTS-----------------------------------------------" << endl << endl;
}

/*
printAllFaculty method.
basically calls the printTree method of GenBinaryTree. Made this method just to be cleaner
*/
void Database::printAllFaculty(){
	cout << "-----------------------------------------------ALL FACULTY-----------------------------------------------" << endl;
	masterFaculty.printTree();
	cout << "-----------------------------------------------ALL FACULTY-----------------------------------------------" << endl << endl;
}

/*
returnStudent method
parameter: unsigned int value
returns Student, the variable stored in a 
TreeNode as its "key". returns a pointer default Student otherwise
*/
Student Database::returnStudent(unsigned int value){
	bool exists = checkStudentExists(value);
	if(exists){
		TreeNode<Student> *ts = masterStudent.getStudent(masterStudent.getRootPointer(),value);
		return ts->key;
	}
	else{
		Student s1;
	  	return s1;
	}
}

/*
returnFaculty method
parameter: usnigned int value
returns a pointer to Faculty object found in the BST with same id.
returns a pointer default Faculty otherwise
*/
Faculty Database::returnFaculty(unsigned int value){
	bool exists = checkFacultyExists(value);
	
	if(exists){
		return (Faculty)masterFaculty.getFaculty(value);
	}
	else{
		Faculty f1;
	  	return f1;
	}
}

/*
findStudentById method
paramter: unsigned int id
outprints the student's info with the id = to the parameter id
if student does not exist, outprints student does not ecist
*/
void Database::findStudentById(unsigned int id){
	Student rStudent = returnStudent(id);
	if(rStudent.getId()==0){
		cout << "Student does not exist in the database" << endl << "please try again with another id" << endl;
	}
	else{
		cout << rStudent << endl;
	}
}

/*
findFacultyById
paramter: unsigne dint id
outprints the faculty's info with the id = to the parameter id
if faculty does not exist, outprints faculty does not ecist
*/
void Database::findFacultyById(unsigned int id){
	Faculty rFaculty = returnFaculty(id);
	if(rFaculty.getId()==0){
		cout << "Faculty does not exist in the database" << endl << "please try again with another id" << endl;
	}
	else{
		cout << rFaculty << endl;
	}
}

/*
printAdvisor 
paramter: unsigned int idStudent
outprints the advisor information if student exists. otherwise states student does not exist
*/
void Database::printAdvisor(unsigned int idStudent){
	Student s = returnStudent(idStudent);
	if(s.getId()==0){
		cout << "Student does not exist in the database" << endl << "please try again with another id" << endl;
	}
	else{
		Faculty rFaculty = returnFaculty(s.getAdvisor());
		cout << rFaculty << endl;
	}
}

/*
printAdvisees
paramter: unsigned int idFaculty
returns all the advisees of faculty. Otherwise states faculty does not exist.
*/
void Database::printAdvisees(unsigned int idFaculty){
	Faculty f = returnFaculty(idFaculty);
	if(f.getId()==0){
		cout << "Faculty does not exist in the database"<< endl;
	}
	else{
		GenDoublyLinkedList<unsigned int> fAdvisees = f.getAdvisees();
		for(int i = 0; i < f.getAdvisees().getSize(); i++){
			cout << returnStudent(fAdvisees.removeFront()) << endl;
		}
	}
}

/*
checkStudentExists method
Completely unecessary method (can jsut use masterStudent.contains(id))
BUT it makes the trail of thoughts simpler. May delete before final version
*/
bool Database::checkStudentExists(unsigned int id){
	bool rbool = masterStudent.contains((int)id);
	return rbool;
}

/*
checkFacultyExists method
Completely unecessary method (can jsut use masterFaculty.contains(id))
BUT it makes the trail of thoughts simpler. May delete before final version
*/
bool Database::checkFacultyExists(unsigned int id){
	bool rbool = masterFaculty.contains((int)id);
	return rbool;
}

/*
addStudent
paramter Student s
adds s to the database. Assigns s its own faculty member randomly.
*/
void Database::addStudent(Student s){
	masterStudent.insert(s);
	studentIds.insertFront(s.getId());
	if(masterFaculty.getSize() == 0){
		return;
	}
	else{
		//ASSIGN FACULTY MEMBER RANDOMLY
	}
	

}

/*
addStudent
paramter Student s, unsigned int idFaculty
adds s to the database. Assigns s its advior as idFaculty (if they exist).
*/
void Database::addStudent(Student s, unsigned int idFaculty){
	bool exists = checkFacultyExists(idFaculty);
	if(exists){
		s.setAdvisor(idFaculty);
		masterStudent.insert(s);

	}
	else{
		cout << "faculty with given id does not exist. Please try again!" << endl;
	}
}

/*
addFaculty
paramter: Faculty f
adds f to the database.
*/
void Database::addFaculty(Faculty f){
	masterFaculty.insert(f);
	facultyIds.insertFront(f.getId());
}

/*
deleteStudent
paramter: unsigned int id
deletes Student with the specified id. Also deletes the student from a faculty's advisees list.
*/
void Database::deleteStudent(unsigned int id){
	bool exists = checkStudentExists(id);
	if(exists){
		unsigned int facultyId = returnStudent(id).getAdvisor();
		removeAdvisee(id, facultyId);
		bool success = masterStudent.deleteNode(returnStudent(id));
		cout << "Student successfully deleted" << endl;
	}
	else{
		cout << "Student does not exist." << endl;
	}
}

/*
deleteFaculty
paramter: unsigned int id
deleted Faculty with specified id. Also gives all of its advisees to other Faculty.
*/
void Database::deleteFaculty(unsigned int id){
	bool exists = checkFacultyExists(id);
	//bool success = masterFaculty.deleteNode(id);
	if(exists){
		Faculty f = returnFaculty(id);
		GenDoublyLinkedList<unsigned int> adviseesprox = f.getAdvisees(); // gets all advisees
		int allf_size = facultyIds.getSize(); // gets amount of faculty
		int allf[allf_size];
		
		for(int i = 0;i < allf_size;i++){
			allf[i] = facultyIds.removeFront();
		}
		int i = 0;
		int ri = rand() % static_cast<int>(allf_size+1);
		while(i < adviseesprox.getSize()){
			if(allf[ri] == id){
				ri = rand() % static_cast<int>(allf_size+1);
			}
			else{
				Faculty ff = returnFaculty(allf[ri]);
				masterFaculty.deleteNode(ff);
				int adviseeid = (int)adviseesprox.removeFront();
				ff.addAdvisee(adviseeid);
				masterFaculty.insert(ff);
				ri = rand() % static_cast<int>(allf_size+1);
				i = i+1;
			}
		}
		masterFaculty.deleteNode(f);
		cout << "Faculty successfully deleted " <<endl;
	}
	else{
		cout << "Faculty does not exist" <<endl;
	}
}

/*
changeAdvisor 
paramters: unsigned int idStudent, unsigned int idFaculty
changes the advisor of the student with the specified id to the new faculty 
with thespecified id,all if they exists. Takes that student also off of 
the old faculty's advisees list.
*/
void Database::changeAdvisor(unsigned int idStudent, unsigned int idFaculty){
	bool containsStudent = checkStudentExists(idStudent);
	bool containsFaculty = 	checkFacultyExists(idFaculty);
	if(!containsStudent){
		cout << "Student does not exist" << endl;
	}
	if(!containsFaculty){
		cout << "Faculty does not exist" << endl;
	}
	else if(containsStudent && containsFaculty){
		Student s = returnStudent(idStudent);
		int oldAdvisor = (int)s.getAdvisor();
		masterStudent.deleteNode(s);
		s.setAdvisor(idFaculty);
		masterStudent.insert(s);
		removeAdvisee(idStudent,oldAdvisor);
	}
}

/*
removeAdvisees
parameters:unsigned int idStudent, unsigned int idFaculty, unsigned int newFacultyId
one of two removeAdvisees methods. This one is if the student's advisor changes.
*/
void Database::removeAdvisee(unsigned int idStudent, unsigned int idFaculty, unsigned int newFacultyId){
	bool containsStudent = checkStudentExists(idStudent);
	bool containsFaculty = 	checkFacultyExists(idFaculty);
	bool containsNewFaculty = checkFacultyExists(newFacultyId);
	if(!containsStudent){
		cout << "Student does not exist" << endl;
		return;
	}
	if(!containsFaculty){
		cout << "Faculty does not exist" << endl;
		return;
	}
	if(!containsNewFaculty){
		cout << "the new faculty does not exist" <<endl;
		return;
	}
	else if(containsStudent && containsFaculty && containsNewFaculty){
		Faculty f  = returnFaculty(idFaculty);
		f.getAdvisees().remove(idStudent);
		masterFaculty.deleteNode(returnFaculty(idFaculty));
		masterFaculty.insert(f);
		changeAdvisor(idStudent, newFacultyId);
		cout << "successfully removed Advisee " << idStudent << " from Faculty ";
		cout << idFaculty << " and gave Advisee new Faculty Advisor " << newFacultyId << endl;
	}
	
}

/*
removeAdvisees
parameters:unsigned int idStudent, unsigned int idFaculty
one of two removeAdvisees methods. 
*/
void Database::removeAdvisee(unsigned int idStudent, unsigned int idFaculty){
	bool containsStudent = checkStudentExists(idStudent);
	bool containsFaculty = 	checkFacultyExists(idFaculty);
	if(!containsStudent){
		cout << "Student does not exist" << endl;
		return;
	}
	if(!containsFaculty){
		cout << "Faculty does not exist" << endl;
		return;
	}
	else if(containsStudent && containsFaculty){
		Faculty f = returnFaculty(idFaculty);
		masterFaculty.deleteNode(f);
		f.getAdvisees().remove(idStudent);
		masterFaculty.insert(f);
	}
	
}

/*
printMenu method
prints the menu that the user decides with
*/
bool Database::printMenu(){
	string s = "******************************MENU**********************************\n";
	s += "1) Print all students and their information (sorted by ascending id)\n";
	s += "2) Print all faculty and their information (sorted by ascending id)\n";
	s += "3) Find & display student information given their id\n";
	s += "4) Find & display faculty information given faculty id\n";
	s += "5) Given a student's id, print the name and info of their\n";
	s += "faculty advisor\n";
	s += "6) Given a faculty id, print ALL the names and info of\n";
	s += "his/her advisees\n";
	s += "7) add a new student\n"; 
	s += "8) Delete a student given the id\n";
	s += "9) Add a new faculty member\n";
	s += "10) Delete a faculty member given the id\n";
	s += "11) Change a student's advisor given the student id and the\n";
	s += "new faculty id\n";
	s += "12) Remove an advisee from a faculty member given the id,\n";
	s += "13) Rollback\n";
	s += "14) Exit\n";
	s += "*****************************MENU*********************************\n\n\n";
	cout << s << endl;
	int input = untilInt(1);
	return doUserChoice(input);
}

/*
method duoUserChoice
returns false if choice is 14, else returns true;
*/
bool Database::doUserChoice(int c){
	int forStudent;
	int forFaculty;
	int otherFaculty;
	Student s;
	Faculty f;
	bool exists;
	switch(c){
		case 1:
			printAllStudents();
			break;
		case 2:
			printAllFaculty();
			break;	
		case 3:
			forStudent = untilInt(3);
			findStudentById(forStudent);
			break;	
		case 4:
			forFaculty = untilInt(4);
			findFacultyById(forFaculty);
			break;	
		case 5:
			forStudent = untilInt(3);
			s = returnStudent(forStudent);
			findFacultyById((int)s.getAdvisor());
			break;	
		case 6:
			forFaculty = untilInt(4);
			printAdvisees(returnFaculty(forFaculty).getId());
			break;	
		case 7:
			historyMasterStudent.enqueue(masterStudent);
			historyMasterFaculty.enqueue(masterFaculty);
			s = createStudent();
			addStudent(s);
			break;	
		case 8:
			historyMasterStudent.enqueue(masterStudent);
			historyMasterFaculty.enqueue(masterFaculty);
			forStudent = untilInt(3);
			deleteStudent(forStudent);
			break;	
		case 9:
			historyMasterStudent.enqueue(masterStudent);
			historyMasterFaculty.enqueue(masterFaculty);
			f = createFaculty();
			addFaculty(f);
			break;	
		case 10:
			historyMasterStudent.enqueue(masterStudent);
			historyMasterFaculty.enqueue(masterFaculty);
			forFaculty = untilInt(4);
			deleteFaculty(forFaculty);
			break;
		case 11:
			historyMasterStudent.enqueue(masterStudent);
			historyMasterFaculty.enqueue(masterFaculty);
			forStudent = untilInt(3);
			forFaculty = untilInt(4);
			changeAdvisor(forStudent,forFaculty);
			break;
		case 12:
			historyMasterStudent.enqueue(masterStudent);
			historyMasterFaculty.enqueue(masterFaculty);
			forStudent = untilInt(3);
			forFaculty = untilInt(4);
			cout << "Do you know the new Faculty who will be the Student's advisor?" << endl;
			cout << "If so, enter it now. Otherwise enter 0" << endl;
			otherFaculty = untilInt(4);
			if(otherFaculty == 0){
				removeAdvisee(forStudent,forFaculty);
			}
			else{
				removeAdvisee(forStudent,forFaculty,otherFaculty);
			}
			break;	
		case 13:
			masterStudent = historyMasterStudent.dequeue();
			masterFaculty = historyMasterFaculty.dequeue();
			break;
		case 14:
			cout << studentIds << endl;
			return false;
		default:
			cout << "Enter an option (int) between 1-14" << endl;
	}
	return true;
}

int Database::untilInt(int version){
    bool valid= false;
    double input = -1;
    string ent;
    if(version ==1){
    	ent = "Enter a number: ";
    }
    else if(version == 2){
    	ent = "Enter an ID: ";
    }else if(version ==3){
    	ent = "Enter a student ID: ";
    }
    else{
    	ent = "Enter a faculty ID: ";
    }
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

double Database::untilDouble(){
	bool valid= false;
    double input = -1;
    string ent = "Enter a number: ";
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
/*
createStudent method
gathers the information from user and returns a student with it.
*/
Student Database::createStudent(){
	string n;
	string y;
	double g;
	string m;
	int idforstudent;
	int idforfaculty;
	bool exists;
	cout << "please enter student name" << endl;
	cin >> n;
	cout << "please enter student year (ex. Freshman, Sophomore, Junior, etc.)" << endl; 
	cin >> y;
	cout << "please enter student GPA. If they dont have a GPA enter 0." << endl;
	g = untilDouble();
	cout << "Please enter student major" << endl;
	cin >> m;
	cout << "please enter student ID number or 0 if you want it to be autogenerated" << endl;
	idforstudent = untilInt(2);
	if(idforstudent == 0){
		//pick random between 20mil and 3mil
	}
	exists = checkStudentExists(idforstudent);
	while(exists){
		cout << "please enter an UNUSED student ID number or 0 if you want it to be autogenerated" << endl;
		idforstudent = untilInt(2);
		if(idforstudent == 0){
		//pick random between 20mil and 3mil
		}
		exists = checkStudentExists(idforstudent);
	}
	cout << "please enter faculty ID number for them to be the student's advisor." << endl;
	cout << "or 0 if you want it to be autogenerated" << endl;
	idforfaculty = untilInt(2);
	if(idforfaculty == 0){
		//find faculty for student.pick random between 1 - BST.maxSize(); give them the student
	}
	exists = checkFacultyExists(idforfaculty);
	while(!exists){
		cout << "please enter a VALID faculty ID number for them to be the student's advisor." << endl;
		cout << "or 0 if you want it to be autogenerated" << endl;
		idforfaculty = untilInt(2);
		if(idforfaculty == 0){
		//find faculty for student.pick random between 1 - BST.maxSize(); give them the student
		}
		exists = checkFacultyExists(idforfaculty);
	}
	Student rs(idforstudent,n,y,m,g,idforfaculty);
	return rs;
}

/*
createFaculty method
gathers the information from user and returns a faculty with it.
*/
Faculty Database::createFaculty(){
	string n;
	string l;
	string d;
	int idforfaculty;
	bool exists;
	cout << "please enter faculty name" << endl;
	cin >> n;
	cout << "please enter faculty level (ex. Assitant Professor, Professor, etc.)" << endl;
	cin >> l;
	cout << "Please enter faculty department" << endl;
	cin >> d;
	cout << "please enter faculty ID or 0 if you want it to be autogenerated" << endl;
	idforfaculty = untilInt(2);
	if(idforfaculty == 0){
		//autogenerate a facult id
	}
	exists = checkFacultyExists(idforfaculty);
	while(exists){
		cout << "please enter an UNUSED faculty ID or 0 if you want it to be autogenerated" << endl;
		idforfaculty = untilInt(2);
		if(idforfaculty == 0){
		//autogenerate a facult id
		}
		exists = checkFacultyExists(idforfaculty);
	}
	Faculty fr(idforfaculty, n, l, d);
	return fr;
}