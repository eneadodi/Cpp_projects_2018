
/*
Name: Enea Dodi
ID: 2296306
Email: dodi@chapman.edu
Class: Data Structures and Algorithms
Assignment: Assignment 5 - database
Date: Novemeber 25 2018

GenBinaryTree.h
This is the template implementation of the GenBinaryTree class
*/

#ifndef GENBINARYTREE_H
#define GENBINARYTREE_H
#include <iostream>
#include "TreeNode.h"
#include "Student.h"
#include "Person.h"
#include "Faculty.h"
using namespace std;

template <class T>
class GenBinaryTree{
public:

  /*
  Default Constructor
  */
  GenBinaryTree(){
    root = NULL;
  }

  /*
  Destructor
  */
  virtual ~GenBinaryTree(){
  //what do we do here>s
  //my guess would be to iterate and delete>> ill need to research that
  }

  /*
  recPrint method
  parameters: TreeNode<T> *node
  prints out the node information to the command line
  */
  void recPrint(TreeNode<T> *node){
    if(node == NULL)
      return;
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
  }

  string toFile(TreeNode<T> *node){
    tofilestring = "";
    if(node == NULL)
      return tofilestring;
    tofilestring += node->key.storeToFile();
    return tofilestring;
  }
  /*
  print tree method
  calls recPrint on root so whole tree is printed out.
  */
  void printTree(){
    recPrint(root);
  }

  /*
  insert method
  parameter T value
  inserts value according to its key.
  */
  void insert(T& value){
    //check if duplicates exists, if duplicates are not allowed
    TreeNode<T> *node = new TreeNode<T>(value);
    if(isEmpty()){
     root = node;
    }
    else{ // not an empty tree
        TreeNode<T> *current = root;
        TreeNode<T> *parent; //empty node;

        while(true){
          parent = current;
          if(value < current->key){//we go to the left
              current = current->left;
              if(current ==  NULL){//we found insertion point
                parent->left = node;
                break;
              }
          }
          else{//go current
            current = current->right;
            if(current ==  NULL){//we found insertion point
              parent->right = node;
              break;
            }
          }
        }
    }
    ++size;
  }

  /*
  getSuccessor method.
  finds the sucessor if there are 2 children nodes.
  */
  TreeNode<T>* getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d; //should one right. all the way
    TreeNode<T> *current = d->right;

    while(current != NULL){
      sp = successor;
      successor = current;
      current = current->left;
    }
    //decedants of right child
    if(successor != d->right){
      sp->left = successor->right;
      successor->right = d->right;
    }

    return successor;
  }

  /*
  contains method
  parameter: T value
  returns true or false if tree contains the value
  */
  bool contains(T value){
    if(isEmpty()){
      return false;
    }
    else{ // not an empty tree
      TreeNode<T> *current = root;
      while(current->key != value){//begin searching for value
        if(current == NULL){
          return false;
        }
        if(value < current->key){
          current = current->left;
        }
        else{
          current = current->right;
        }
      }
      return true;
    }
  }

    /*
  contains method
  parameter: const unsigned int& value
  returns true or false if tree contains the object = to value
  */
  bool contains(int value){
    int id;
    if(isEmpty()){
      return false;
    }
    TreeNode<T>* temp = root;
    while (temp != NULL) {
        if (temp->key == value) {
            return true;
        }
        else {
            if (temp->key < value) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }
    }
    return false;
  }



  /*
  deleteNode method
  paramter: T k - Node to be deleted
  returns true or false if node was sucessfully deleted or not
  Fixes the tree's architecture if that node has children
  */
  bool deleteNode(T k){
    if (root == NULL){//if no tree exists, return false
      return false;
    }

    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;
    while(curr->key != k){//check to see if node exists.
      //only works if the binary search tree is ordered correctly
      parent = curr;
      if (k < curr->key){ //if id is < current node id
        isLeft = true;
        curr = curr->left;
      }
      else{
        isLeft = false;
        curr = curr->right;
      }
      if (curr == NULL){ //if current dosent point to a real node.
        return false;
      }
    }
    //if the node with key k has no children.
    if(curr->left == NULL && curr->right == NULL){
      if(curr == root){
        root = NULL;
      }
      else if(isLeft){
        parent->left = NULL;
      }
      else{
        parent->right = NULL;
      }
      delete curr;
      --size;
    }
    //if node with key k has 1 child and is left child
    else if(curr->right == NULL){
      if(curr == root)
      {
        root = curr->left;
      }
      else if(isLeft)
      {
        parent->left = curr->left;
      }
      else
      {
        parent->right = curr->left;
      }
      delete curr;
      --size;
    }
    //no left child
    else if(curr->left == NULL){
      if(curr == root)
      {
        root = curr->right;
      }
      else if(isLeft)
      {
        parent->left = curr->right;
      }
      else
      {
        parent->right = curr->right;
      }
      delete curr;
      --size;
    }
    else{ //node to be deleted has two children
      TreeNode<T> *successor = getSuccessor(curr);

      if(curr == root){ //if we are deleting root
        root = successor;
      }
      else if(isLeft){
        parent->left = successor;
      }
      else{
        parent->right = successor;
      }
      successor->left = curr->left;
      delete curr;
      --size;
    }
    return true;
  }

  /*
  deleteRec method
  paramter: T k - value of Node to be deleted. 
  Value is always unique.
  */
  bool deleteRec(T k){
    if(!contains(k)){
      return false;
    }
    else{
      TreeNode<T> *parent = root;
      TreeNode<T> *current = root;
      bool isLeft = true;
      //Now we gotta find the TreeNode<T>
      while(current->key != k){
        parent = current;
        if(k < current->key){
          isLeft = true;
          current = current->left;
        }
        else{
          isLeft= false;
          current = current->right;
        }

        if(current == NULL){
          return false;
        }
      }
      //at this point we found the node that needs to be deleted.

      //node has no children, leaf TreeNode<T>
      if(current->left == NULL && current->right == NULL){
        if(current == root){
          root = NULL;
        }
        else if(isLeft){
          parent->left = NULL;
        }
        else{
          parent->right = NULL;
        }
      }

      //now we gotta checkt he case if the node has one child
      else if(current->right == NULL){//no right child, must be left node
        if(current == root){
          root = current->left;
        }
        else if(isLeft){
          parent->left = current->right;
        }
        else{
          parent->right = current->right;
        }
      }

      else{//node has two children, at the point we begin to cry
          TreeNode<T> *successor  = getSuccessor(current);

          if(current == root)
            root =  successor;
          else if (isLeft)
            parent-> left = successor;
          else{
            parent ->right = successor;

          }
          successor->left = current->left;
      }
      return true;
    }
  }

  /*
  isEmpty method
  Checks if tree is Empty.
  */
  bool isEmpty(){
    return root == NULL;
  }

  /*
  getRoot method
  */
  TreeNode<T> getRoot() const{
    return *root;
  }

  TreeNode<Student>* getStudent(TreeNode<Student>* node,Student value){
    if(node == NULL || node->key == value.getId()){
      return node;
    }
    if(node->key < value){
      return getStudent(node->right, value);
    }

    return getStudent(node->left,value);
  }

  TreeNode<Student>* getStudent(TreeNode<Student>* node,unsigned int value){
    if(node == NULL || node->key == value){
      return node;
    }
    if(node->key < value){
      return getStudent(node->right, value);
    }

    return getStudent(node->left,value);
  }

  Faculty getFaculty(Faculty value){
    TreeNode<Faculty> *current = root;
    while(current->key != value){//begin searching for value
      if(value < current->key){
        current = current->left;
      }
      else{
        current = current->right;
      }
    }
    return current->key;
  }

  Faculty getFaculty(unsigned int& value){
    TreeNode<Faculty> *current = root;
    while(current->key.getId() != value){//begin searching for value
      if(value < current->key.getId()){
        current = current->left;
      }
      else{
        current = current->right;
      }
    }
    return current->key;
  }

  TreeNode<Faculty>* getFaculty(TreeNode<Faculty>* node,unsigned int value){
    if(node == NULL || node->key == value){
      return node;
    }
    if(node->key < value){
      return getFaculty(node->right, value);
    }

    return getFaculty(node->left,value);
  }
  /*
  getRootPointer method
  */
  TreeNode<T>* getRootPointer() const{
    return root;
  }

  /*
  getSize method
  */
  unsigned int getSize() const{
    return size;
  }

private:
  TreeNode<T> *root;
  unsigned int size = 0;
  string tofilestring = "";
};

#endif /* GENBINARYTREE_H */