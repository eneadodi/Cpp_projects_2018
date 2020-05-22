
/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

GenDoublyLinkedList.h
This is the template implementation of the GenDoublyLinkedList class
*/
#ifndef GENDOUBLYLINKEDLIST_H
#define GENDOUBLYLINKEDLIST_H
#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class GenDoublyLinkedList {
    public:
        unsigned int size = 0;
        ListNode<T> *front;
        ListNode<T> *back;

        /*
        Default Constructor
        */
        GenDoublyLinkedList() {
            size = 0;
            front = NULL;
            back = NULL;
        }

        /*
        Destructor
        */
        ~GenDoublyLinkedList() {

        }

        /*
        insertBack method
        inserts value d to the back of the list
        */
        void insertBack(T d) {
            ListNode<T> *node = new ListNode<T>(d);

            //Empty
            if(size == 0) {
                front = node;
            }
            //Not Empty
            else {
                back->next = node;
                node->prev = back;
            }

            back = node;
            ++size;
        }

        /*
        insertFront method
        inserts value "data" to the front of the list
        */
        void insertFront(T data){
          ListNode<T> *node = new ListNode<T>(data);

          if(isEmpty()) //empty ListNode
          {
            back = node;
          }
          else //not empty
          {
            front ->prev = node;
            node-> next = front;
          }
          front = node;
          size++;
        }

        /*
        removeFront method
        removes value at front of the list and returns it.
        */
        T removeFront() {
            if(!isEmpty()) {
                ListNode<T> *node = front;
                //Only Node in List
                if(front->next == NULL) {
                    front = NULL;
                    back = NULL;
                }
                //More than One
                else {
                    front->next->prev = NULL;
                    front = front->next;
                }

                //node->next = NULL;

                T temp = node->data;

                delete node;
                --size;
                return temp;
            }
            else {
                T t;
                return t;
            }
        }

        /*
        getFront method
        returns value at front.
        */
        T getFront() {
            if(getSize() != 0){
                return front->data;
            }
        }

        /*
        getBack method
        returns value at Back of the list
        */
        T getBack() {
            if(getSize() != 0){
                return back->data;
            }
        }

        /*
        printList method
        prints all values in list to the command line.
        */
        void printList() {
            ListNode<T> *curr = front;
            bool continuePrinting = true;
            while(continuePrinting == true) {
                if(curr->next == NULL) {
                    continuePrinting = false;
                }

                cout << curr->data << endl;
                curr = curr->next;
            }
        }

        /*
        deletePos method
        deletes value at position "pos"
        */
        void deletePos(int pos) {
            int index = 0;
            ListNode<T> *curr = front;
            ListNode<T> *prev = front;

            while(index != pos) {
                prev = curr;
                curr = curr->next;
                ++index;
            }

            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            curr->data = NULL;

            --size;
            delete curr;
        }

        /*
        isEmpty method
        checks if list is empty
        */
        bool isEmpty() {
            return(size == 0);
        }

        /*
        getSize method
        returns size of list
        */
        unsigned int getSize() {
            return size;
        }

        /*
        contains method 
        returns true or false if list contains certain value
        */
        bool contains(T value){
            ListNode<T>* curr;
            /*
            NOTE:
            LINE 203 caused problems for me for a total of
            4 hours until i figured it out.
            */
            //cout << front->data << endl;
            curr = front;
            while (curr != NULL){
                if (curr->data == value){
                  return true;
                }else{
                    curr = curr->next;
                }
                
            }
            return false;
        }

        /*
        remove method
        paramter T key.
        deletes node which has the value "key"
        returns true or false if it was sucessful or not
        */
        bool remove (T key){
            ListNode<T> *curr;
            curr = front;

            while (curr->data != key){
                if (curr == NULL){
                    return false;
                }
                curr = curr -> next;
            }//at this point, we have found what we are looking for
            if (curr == front){
                front = curr -> next;
            }
            else{
                curr ->prev->next = curr ->next;
            }
            if (curr == back){
                back = curr -> prev;
            }
            else{
                curr ->next->prev = curr ->prev;
            }

             curr ->next = NULL;
             curr ->prev = NULL;
             --size;

             delete curr;
             return true;
          }

          void clear(){
            bool b = true;
            for(int i = 0; i < size;i++){
                T t = removeFront();
            }
          }
    private:
};

template <class T>
inline ostream& operator<<(ostream &os, const GenDoublyLinkedList<T> &t){
    ListNode<unsigned int> *curr;
    curr = t.front;
    while(curr != NULL){
        os << curr->data << ", ";
        curr = curr->next;
    }
    return(os);
}

#endif /*GENDOUBLYLINKEDLIST_H */
