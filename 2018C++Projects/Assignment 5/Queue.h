/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

Queue.h
This is the template class for Queue
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "GenDoublyLinkedList.h"

template <class T>
class Queue{
private:
  int size;
  T myQueue[5];

public:
  Queue(){
    size = 0;
  }
  ~Queue(){

  }

  void enqueue(const T &data){
    if(size > 4){
      setSize(4);
    }
    myQueue[size] = data;
    ++size;
  }

  T dequeue(){
    if (getSize() < 1)
    {
      cout << "unable to remove" << endl;
      cout << "Bad alloc incoming" << endl;
    }
    --size;
    return myQueue[size-1];
  }


  T peek(){
    if (getSize() < 1)
    {
      cout << "unable to peek" << endl;
    }
    return myQueue[size];
  }


  bool isEmpty(){
    return (size == 0);
  };

  int getSize(){
    return size;
  }

  void setSize(int s){
    size = s;
  }
};


#endif