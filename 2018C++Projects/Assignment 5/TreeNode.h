/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

TreeNode.h
This is the template implementation of the TreeNode class.
TreeNodes will be the Nodes used in the GenBinaryTree class
*/

#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

using namespace std;

template <class T>
class TreeNode{
public: 
  TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
  }
  
  TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
  }
  virtual ~TreeNode(){

  }

  T key;
  TreeNode *left;
  TreeNode *right;

};

#endif /* TREENODE_H */