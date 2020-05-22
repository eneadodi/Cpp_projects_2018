/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
Main.cpp file*/

#ifndef QUEUE_H
#define QUEUE_H

#include "GenDoublyLinkedList.h"

template <class T>
class GenQueue{
public:
  GenQueue(){
    size = 0;
  }
  ~GenQueue(){

  }

  void enqueue(T data){
    myQueue.insertBack(data);
    ++size;
  }
  T dequeue(){
    if (getSize() <= 0)
    {
      cout << "unable to remove" << endl;
    }

    T temp = myQueue.front->data;
    myQueue.removeFront();
    --size;
    return temp;
  }

  T peek(){
    if (getSize() <= 0)
    {
      cout << "unable to peek" << endl;
    }
    return myQueue.front->data;
  }


  bool isEmpty()  {
    return (size == 0);
  }

  int getSize(){
    return size;
  }
private:
  int size;
  GenDoublyLinkedList<T> myQueue;
};


#endif
