/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Date: 1/11/2018
Assignment: Data Structures and Algorithms Assignment 4 - Registrar’s Office Simulation
*/
#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

using namespace std;

template <class T>
class ListNode{
    public:
        T data;
        ListNode<T> *next;
        ListNode<T> *prev;

        ListNode() {

        }

        ListNode(T d) {
            data = d;
            next = NULL;
            prev = NULL;
        }

        ~ListNode() {
            if(next != NULL) {
                next = NULL;
                prev = NULL;

                delete next;
                delete prev;
            }
        }
};

#endif /* LISTNODE_H */
