/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
Simulation.h file
*/
#ifndef SIMULATION_H
#define SIMULATION_H

#include "RegistrarWindow.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include "GenDoublyLinkedList.h"
#include <cstdlib>
#include <cmath>
#include <string>
#include "GenQueue.h"
using namespace std;

class Simulation{
public:
  Simulation(GenQueue<Student> studentsInLine, GenQueue<int> studentsAtTimes, int amountOfWindows);
  ~Simulation();

  double calculateMean(double *s, int size);
  double calculateMean(RegistrarWindow *s, int size);
  int findLongest(double *s, int size);
  int findLongest(RegistrarWindow *s, int size);
  double calculateMedian(double *s, int size);
  int studentsOverTen(double *s, int size);
  int windowsOverFive(RegistrarWindow *s, int size);
  void swap(double *xp, double *yp);
  void bubbleSort(double arr[], int n);
private:
};

#endif /* SIMULATION_H*/
