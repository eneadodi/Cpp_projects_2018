/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
Main.cpp file
This is the main file for Assignment 4!
The hypothetical situation I am put it is basically the Student Registar Office
is looking for a simulation to see how many windows they should have open at a time.
The inputs for the simulation will come from a text file.
The instructions given state the follwing:
--The text file will define at what times students arrive and will have
the following format. The first line will be the number of windows open. The next line
will be the time (or clock tick) at which the next students arrive. The next line will be the
number of students that arrive at that time. The following lines will be the amount of
time each student needs at a window. This is followed by the next clock tick, number of
students, etc--
At the end of the simulation, I am suppose to display the following metrics:
1. The mean student wait time.
2. The median student wait time.
3. The longest student wait time.
4. The number of students waiting over 10 minutes
5. The mean window idle time
6. The longest window idle time
7. Number of windows idle for over 5 minutes.
*/

#include "RegistrarWindow.h"
#include "Student.h"
#include "Simulation.h"
#include <fstream>
#include <iostream>
#include "GenDoublyLinkedList.h"
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include "GenQueue.h"
using namespace std;

 int main(int argc, char** argv) {

   GenQueue<Student> studentsInLine;
   string filename;
   string s = "";
   GenQueue<int> allVals;
   GenQueue<int> sizesOfLines;
   cin >> filename;
   ifstream infile;
   infile.open(filename);
   int amountOfWindows = 0;
   int timeTick = 0;
   int numOfStudents = 0;
   bool firstLine = true;
   int val;
   while (infile >> val){
     if(firstLine){
       amountOfWindows = val;
       firstLine = false;
     }else{
       allVals.enqueue(val);
     }
   }
   Student proxStu;
   int size = allVals.getSize();
   double timeNeeded = 0;
   cout << size << " IS THE SIZE HOMIE" << endl;
   while(size > 0){
     timeTick = allVals.dequeue();
     size--;
     numOfStudents = allVals.dequeue();
     sizesOfLines.enqueue(numOfStudents);
     size--;
     for(int i = 0; i < numOfStudents;i++){
       timeNeeded = allVals.dequeue();
       proxStu.setTimeLeft(timeNeeded);
       proxStu.setTimeRequired(timeNeeded);
       proxStu.setTimeArrived(timeTick);
       cout << proxStu.getTimeLeft() << endl;
       size--;
       studentsInLine.enqueue(proxStu);
     }
   }


   Simulation registrarSimulation(studentsInLine,sizesOfLines,amountOfWindows);

 }
