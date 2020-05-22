
/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

ListNode.h
This is the template implementation of the ListNode class
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
