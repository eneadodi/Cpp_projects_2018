/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
Student.cpp file
*/

#include "Student.h"

/*
Default Constructor
Will never be used but good to have
*/
Student::Student(){
  timeArrived = 9;
  timeRequired = 0;
  timeLeft = 0;
  timeWaited = 0;
}

/*
Constructor
Parameters:
  double ta: timeArrived
  double tr: timeRequired for student
*/
Student::Student(const double& ta, const double& tr){
  timeArrived = ta;
  timeRequired = tr;
  timeLeft = tr;
  timeWaited = 0;
}

/*
getters and setters for each variable in class
*/

//Getters
double Student::getTimeArrived() const{
  return timeArrived;
}

double Student::getTimeRequired() const{
  return timeRequired;
}

double Student::getTimeLeft() const{
  return timeLeft;
}

double Student::getTimeWaited() const{
  return timeWaited;
}

//Setters
void Student::setTimeArrived(const double& ta){
 this->timeArrived = ta;
}

void Student::setTimeRequired(const double& tr){
  this->timeRequired = tr;
}

void Student::setTimeWaited(const double& tw){
  this->timeWaited = tw;
}

void Student::setTimeLeft(const double& tl){
  this->timeLeft = tl;
}

/*
toString method
returns a string that specifies the Students:
timeArrived,timeRequired,timeLeft;
*//*

*/
/*TimeAtWindow method
Parameter: double time - How long the Student was at window
*/

void Student::operator=(const Student& s){
  timeArrived = s.getTimeArrived();
  timeLeft = s.getTimeLeft();
  timeRequired = s.getTimeRequired();
  timeWaited = s.getTimeWaited();
}
void Student::operator=(Student *s){
  timeArrived = s->getTimeArrived();
  timeLeft = s->getTimeLeft();
  timeRequired = s->getTimeRequired();
  timeWaited = s->getTimeWaited();
}
void Student::TimeAtWindow(const double& time){
  this->timeLeft -= time;
}

void Student::waiting(const double& wait){
  timeWaited += wait;
}
