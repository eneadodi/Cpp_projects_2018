/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
RegistrarWindow.h file
*/
#ifndef REGISTRARWINDOW_H
#define REGISTRARWINDOW_H

#include <cstdlib>
#include "Student.h"
using namespace std;

class RegistrarWindow{
public:
  //Constructors and Destructors
  RegistrarWindow();
  RegistrarWindow(Student &s);

  //getters and setters;
  double getIdleTime();
  int getTimesIdle();
  bool getIsIdle();
  Student getStudent();

  void setIdleTime(const double& it);
  void setTimesIdle(const int& ti);
  void setStudent(Student &s);
  void setIsIdle(const bool& idle);

//  void operator=(const RegistrarWindow& otherwindow);
private:
  bool isIdle;
  int timesIdle;
  double IdleTime;
  Student student;
};

#endif//REGISTRARWINDOW_H
