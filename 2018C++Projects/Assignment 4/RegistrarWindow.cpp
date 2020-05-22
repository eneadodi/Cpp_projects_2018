/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
RegistrarWindow.cpp file
*/

#include "RegistrarWindow.h"

/*Default Constructor
Sets default values of the RegistrarWindow class
*/
RegistrarWindow::RegistrarWindow(){
  isIdle = false;
  timesIdle = 0;
  IdleTime = 0;
}

/*Constructor
Parameters: Student student
Sets default values and also the student
*/
RegistrarWindow::RegistrarWindow(Student &s){
  isIdle = false;
  timesIdle = 0;
  IdleTime = 0;
  student = s;
}


/*Getters and Setters
*/
//Getters
double RegistrarWindow::getIdleTime(){
  return IdleTime;
}
int RegistrarWindow::getTimesIdle(){
  return timesIdle;
}
bool RegistrarWindow::getIsIdle(){
  return isIdle;
  //return isIdle;
}
Student RegistrarWindow::getStudent(){
  return student;
}

//setters
void RegistrarWindow::setIdleTime(const double& it){
  IdleTime = it;
}
void RegistrarWindow::setTimesIdle(const int& ti){
  timesIdle = ti;
}
void RegistrarWindow::setStudent(Student &s){
  student = s;
}
void RegistrarWindow::setIsIdle(const bool& idle){
  isIdle = idle;
}/*
void RegistrarWindow::operator=(const RegistrarWindow& otherwindow){
    this->IdleTime = otherwindow.getIdleTime();
    this->timesIdle = otherwindow.getTimesIdle();
    this->isIdle = otherwindow.getIsIdle();
    this->student = otherwindow.getStudent();
}*/
