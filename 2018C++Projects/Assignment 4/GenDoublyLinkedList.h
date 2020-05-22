
/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
*/
#ifndef GENDOUBLYLINKEDLIST_H
#define GENDOUBLYLINKEDLIST_H
#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class GenDoublyLinkedList {
    private:

    public:
        unsigned int size;
        ListNode<T> *front;
        ListNode<T> *back;

        GenDoublyLinkedList() {
            size = 0;
            front = NULL;
            back = NULL;
        }

        ~GenDoublyLinkedList() {}

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

        void insertFront(T data){
          ListNode<T> *node = new ListNode<T> (data);

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
        };

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
                return T();
            }
        }

        T getFront() {
            return front->data;
        }

        void printList() {
            ListNode<T> *curr = front;

            while(true) {
                if(curr->next == NULL) {
                    break;
                }

                cout << curr->data << endl;
                curr = curr->next;
            }
        }

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

        bool isEmpty() {
            return(size == 0);
        }

        unsigned int getSize() {
            return size;
        }
;
};

#endif /*GENDOUBLYLINKEDLIST_H */
