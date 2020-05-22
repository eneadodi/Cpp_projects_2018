#include "Cell.h"
#include <cstdlib>
#include <iostream>
#include "GameOfLife.h"
using namespace std;
/*
Default Constructor for Cell Object. Will be what is mostly used
*/

Cell::Cell(){
  int neighbors = 0;
  dOrA = "-";
  alive = false;
}

/*
Copy Constrcutor for Cell object
*/
Cell::Cell(Cell& orig){
  neighbors = orig.getNeighbors();
  dOrA = orig.getDOrA();
  alive = orig.isAlive();
}

/*
Constructor if boolean is turned in
*/
Cell::Cell(bool a){
  if(a == true){
    alive = true;
    dOrA = "X";
  }
  else{
    alive = false;
    dOrA = "-";
  }
  neighbors = 0;
}

/*
Constructor if string is turned in
*/
Cell::Cell(string s){
  dOrA = s;
  if(dOrA == "X"){
    alive = true;
  }
  else{
    alive = false;
  }
  neighbors = 0;
}

/*
getter method for private variable alive. checks if there is a alive cell at the location
*/
bool Cell::isAlive() {
    return alive;
}

/*
setter method for alive
*/
void Cell::setAlive(const bool& alive) {
    this->alive = alive;
}

/*
getter method for what should the output string be. either - or X
*/
string Cell::getDOrA() {
    return dOrA;
}

/*
setter method for dOrA
*/
void Cell::setDOrA(const string& dOrA) {
    this->dOrA = dOrA;
}

/*
getter method for private varaible neighbors. The amount of neighbors the cell has
*/
int Cell::getNeighbors() {
    return neighbors;
}

/*
setter method for private vairable neighbors
*/
void Cell::setNeighbors(const int& neighbors) {
    this->neighbors = neighbors;
}

/*
Counts how many neighbros are around the Cell.
*/
void Cell::countNeighbors(Cell **grid, int i, int j){
  int counter = 0;
  if(grid[i-1][j].isAlive()){
    counter++;
  }
  if(grid[i-1][j+1].isAlive()){
    counter++;
  }
  if(grid[i-1][j-1].isAlive()){
    counter++;
  }
  if(grid[i][j-1].isAlive()){
    counter++;
  }
  if(grid[i][j+1].isAlive()){
    counter++;
  }
  if(grid[i+1][j-1].isAlive()){
    counter++;
  }
  if(grid[i+1][j].isAlive()){
    counter++;
  }
  if(grid[i+1][j+1].isAlive()){
    counter++;
  }
  setNeighbors(counter);
}
