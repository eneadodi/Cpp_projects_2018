#include "GenStack.h"

using namespace std;

template <class T>
GenStack<T>::GenStack(){
  size = 50;
  arr = new T[size];
}

template <class T>
GenStack<T>::GenStack(int size){
  arr = new T[size];
  this->size = size;
}

template <class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    cerr << "Nothing in the array" << endl ;
  }
  else{
    top--;
    return arr[top+1];
  }
}

template <class T>
void GenStack<T>::push(T obj){
  if(isFull()){
    resize();
  }
  top++;
  arr[top] = obj;
}

template <class T>
T GenStack<T>::peek(){
  return arr[top];
}

template <class T>
bool GenStack<T>::isFull(){
  return (top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
void GenStack<T>::resize(){
  T resizedStack[] = new T[getSize()*2];
  for(int i = 0; i < size; i ++){
    resizedStack[i] = arr[i];
  }
  setSize(getSize()*2);
  setArr(resizedStack);
}

template <class T>
void GenStack<T>::setTop(int t){
  top = t;
}

template <class T>
int GenStack<T>::getTop(){
  return top;
}

template <class T>
void GenStack<T>::setSize(int s){
  size = s;
}
template <class T>
int GenStack<T>::getSize(){
  return size;
}

template <class T>
void GenStack<T>::setArr(T *a){
  arr = a;
}

template <class T>
T* GenStack<T>::getArr(){
  return arr;
}
