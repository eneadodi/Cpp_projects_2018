#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>

using namespace std;

template <class T>
class GenStack{
private:
  T *arr;
  int top = 0;
  int size;

public:


  GenStack(){
    size = 50;
    arr = new T[size];
  }


  GenStack(int size){
    arr = new T[size];
    this->size = size;
  }


  T pop(){
    if(isEmpty()){
      cerr << "Nothing in the array" << endl ;
    }
    else{
      top--;
      return arr[top+1];
    }
  }


  void push(T obj){
    if(isFull()){
      // /resize();
    }
    top++;
    arr[top] = obj;
  }


  T peek(){
    return arr[top];
  }


  bool isFull(){
    return (top == size-1);
  }


  bool isEmpty(){
    return (top == -1);
  }


  void resize(){
    T resizedStack[] = new T[getSize()*2];
    for(int i = 0; i < size; i ++){
      resizedStack[i] = arr[i];
    }
    setSize(getSize()*2);
    setArr(resizedStack);
  }


  void setTop(const int& t){
    top = t;
  }


  int getTop(){
    return top;
  }


  void setSize(const int& s){
    size = s;
  }

  int getSize(){
    return size;
  }


  void setArr(T *a){
    arr = a;
  }


  T* getArr(){
    return arr;
  }





};


#endif /* GENSTACK _H */
