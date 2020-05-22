/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
Student.h file
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <cstdlib>
#include <string>
using namespace std;

class Student{
public:
  //Constrcutors and Destructors
  Student();
  Student(const double& ta, const double& tr);
  //Getters and Setters
  double getTimeArrived() const;
  double getTimeRequired() const;
  double getTimeWaited() const;
  double getTimeLeft() const;
  void setTimeWaited(const double& tw);
  void setTimeArrived(const double& ta);
  void setTimeRequired(const double& tr);
  void setTimeLeft(const double& tl);
  void waiting(const double& wait);
  void TimeAtWindow(const double& time);

  void operator=(const Student& s);
  void operator=(Student *s);
private:
  double timeArrived;
  double timeRequired;
  double timeLeft;
  double timeWaited;
};

#endif //STUDENT_H
