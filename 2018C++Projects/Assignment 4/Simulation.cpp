/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
Simulation.cpp file
*/
#include "Simulation.h"

Simulation::Simulation(GenQueue<Student> studentsInLine, GenQueue<int> studentsAtTimes, int amountOfWindows){
    RegistrarWindow windows[amountOfWindows]; //the actual registrar windows
    Student atWindows[amountOfWindows]; // THE only reason i am using this is because of Segmentation Faults :(
    int amountOfTicks = studentsAtTimes.getSize();
    for(int a = 0; a < amountOfTicks; a++){
      int amountInLine = studentsAtTimes.dequeue();
      GenQueue<double> allStudentsWait;
      // Student atWindow[3]; //array of students at the window
      Student inLine[amountInLine];
       int totalTime = 0;
      double smallest = 0;
      int studentsDealt = 0;
      for(int b = studentsDealt; b < amountInLine;b++){
        inLine[b] = studentsInLine.dequeue();
        cout << inLine[b].getTimeLeft() << endl;
      }
      for(int c = 0; c < amountOfWindows; c++){
        windows[c].setStudent(inLine[c]);
        atWindows[c] = inLine[c];
        cout << windows[c].getStudent().getTimeLeft() <<endl;
        studentsDealt++;
      }
      while(studentsDealt != (amountInLine)){
        smallest = atWindows[0].getTimeLeft();
        for(int d = 0; d < amountOfWindows; d++){
          if(atWindows[d].getTimeLeft() < smallest){
            smallest = atWindows[d].getTimeLeft();
          }
        }
        cout << "the smallest value is" << endl;
        cout << smallest << endl;
        for(int e = 0; e < amountOfWindows; e++){
          atWindows[e].TimeAtWindow(smallest);
        }
        for(int f = studentsDealt; f < amountInLine; f++){
          inLine[f].waiting(smallest);
          cout<< "this student in line waited" << endl;
          cout << inLine[f].getTimeWaited() << endl;
        }
        cout << "first value which was 10 should be 5" << endl;
        cout << atWindows[0].getTimeLeft() << endl;
        for(int g = 0; g < amountOfWindows; g++){
          if(atWindows[g].getTimeLeft() == 0){
            allStudentsWait.enqueue(atWindows[g].getTimeWaited());
            windows[g].setStudent(inLine[studentsDealt]);
            atWindows[g] = inLine[studentsDealt];
            studentsDealt++;
          }
        }
      }
      bool allWindowsEmpty = false;
      while(allWindowsEmpty == false){
        allWindowsEmpty = true;
        for(int h = 0; h < amountOfWindows; h++){
          if(windows[h].getIsIdle() == false){
            allWindowsEmpty = false;
            break;
          }
        }
        if(allWindowsEmpty == false){
          for(int i = 0; i < amountOfWindows; i++){
            if(atWindows[i].getTimeLeft() != 0){
            smallest = atWindows[i].getTimeLeft();
            break;
            }
          }
          for(int j = 0; j < amountOfWindows; j++){
            if(atWindows[j].getTimeLeft() == 0){
            }
            else if(atWindows[j].getTimeLeft() < smallest){
              smallest = atWindows[j].getTimeLeft();
            }
          }
          cout << "the smallest value is" << endl;
          cout << smallest << endl;
          for(int k = 0; k < amountOfWindows; k++){
            if(windows[k].getIsIdle() == true){
              windows[k].setIdleTime(windows[k].getIdleTime() + smallest);
            }
            if(atWindows[k].getTimeLeft() != 0){
              atWindows[k].TimeAtWindow(smallest);
            }
            if(atWindows[k].getTimeLeft() == 0){
              allStudentsWait.enqueue(atWindows[k].getTimeWaited());
              windows[k].setIsIdle(true);
            }
        } 
      }
    }
  for(int l = 0; l < amountOfWindows; l++){
    if(atWindows[l].getTimeLeft() == 0){
      allStudentsWait.enqueue(atWindows[l].getTimeWaited());
      windows[l].setIsIdle(true);
    }
  }
  int allStudentsWaitSize = allStudentsWait.getSize();
  double allWaits[allStudentsWaitSize];
  for(int i = 0; i < allStudentsWaitSize; i++){
    allWaits[i] = allStudentsWait.dequeue();
  }
  cout << "1) The mean wait time for students was: " << calculateMean(allWaits,allStudentsWaitSize) << endl;
  cout << "2) The median wait time for students was: " << calculateMedian(allWaits,allStudentsWaitSize) << endl;
  cout << "3) The longest wait time for students was: " << findLongest(allWaits,allStudentsWaitSize) << endl;
  cout << "4) The number of students waiting over 10 minutes was: " << studentsOverTen(allWaits,allStudentsWaitSize) << endl;
  cout << "5) The mean registrar window idle time was" << calculateMean(windows,amountOfWindows) << endl;
  cout << "6) The longest registrar window idle time was" << findLongest(windows,amountOfWindows) << endl;
  cout << "7) The amount of windows with idle time over 5 was" << windowsOverFive(windows,amountOfWindows) << endl;
}
 }
Simulation::~Simulation(){}

double Simulation::calculateMean(double *s, int size){
  int total = 0;
  for(int i = 0; i < size; i++){
    total += s[i];
  }
  return total/size;
}
double Simulation::calculateMean(RegistrarWindow *s, int size){
  int total = 0;
  for(int i = 0; i < size; i++){
    total += s[i].getIdleTime();
  }
  return total/size;
}

int Simulation::findLongest(double *s, int size){
  int longest = s[0];
  for(int i = 0; i < size; i++){
    if(s[i] > longest){
      longest = s[i];
    }
  }
  return longest;
}

int Simulation::findLongest(RegistrarWindow *s, int size){
  int longest = s[0].getIdleTime();
  for(int i = 0; i < size; i++){
    if(s[i].getIdleTime() > longest){
      longest = s[i].getIdleTime();
    }
  }
  return longest;
}

double Simulation::calculateMedian(double *s, int size){
  bubbleSort(s, size);
  if(size % 2 == 0){
    return (s[size/2] + s[(size/2)+1])/2.0;
  }
  else{
    return s[(size/2)+1];
  }
}
// Got from https://www.geeksforgeeks.org/bubble-sort/
void Simulation::swap(double *xp, double *yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Got from https://www.geeksforgeeks.org/bubble-sort/
void Simulation::bubbleSort(double arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
              swap(&arr[j], &arr[j+1]);
            }
      }
  }
}

int Simulation::studentsOverTen(double *s, int size){
  int counter = 0;
  for(int i = 0; i < size; i++){
    if(s[i] >= 10){
      counter++;
    }
  }
  return counter;
}
int Simulation::windowsOverFive(RegistrarWindow *s, int size){
  int counter = 0;
  for(int i = 0; i < size; i++){
    if(s[i].getIdleTime() >= 5){
      counter++;
    }
  }
  return counter;
}
