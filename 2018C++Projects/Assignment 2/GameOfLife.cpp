#include "GameOfLife.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/*
Default Constructor. Never will be used.
*/
GameOfLife::GameOfLife(){
  rows = 5;
  cols = 5;
  continuation = 1;
  density = .5;
  fOrR = 1;
}

/*
Constrcutor
parameters: int fOrR, int rows, int cols, int continuation
Creates a Object GameOfLife according to the parameters passed in
*/
GameOfLife::GameOfLife(int fOrR,int rows, int cols, int continuation,double density,int gameMode){
  this->fOrR = fOrR;
  this->rows = rows;
  this->cols = cols;
  this->continuation = continuation;
  this->density = density;
  this->gameMode = gameMode;
  if(fOrR == 2){
    generateGridRandom(rows, cols, density, gameMode);
  }
}

/*
Constructor
parameters: int fOrR, string filename, int continuation
Constructor used when the user would like to use information already input in a file
*/
GameOfLife::GameOfLife(int fOR, string fileName, int continuation, int gameMode){
  this->fOrR = fOrR;
  this->continuation = continuation;
  this->gameMode = gameMode;
  ifstream file(fileName);
  if(file.is_open()){
    string line;
    int row,col;
    getline(file,line);
    row = atoi(line.c_str()) + 2;
    getline(file, line);
    col = atoi(line.c_str()) + 2;
    setRows(row);
    setCols(col);
    string gridLines [getRows()];
    for(int i = 0; i < row; i++){
      if(!file.eof()){
        if((i == 0) || (i == row -1)){
          string emptyline = "";
          for(int a = 0; a < getCols(); a++){
            emptyline += "-";
          }
          gridLines[i] = emptyline;
        }
        else{
        getline(file, line);
        gridLines[i] = line;
      }
      }
    }
    generateGridFile(gridLines, gameMode);
  }
}

//specifically prints the grid to a file for better looking prints in the file if the user selects this option

string GameOfLife::printGridToFile(){
  int r = getRows();
  int c = getCols();
  Cell **grid = getGrid2();
  string s = "";
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if((i == 0) || (i == r-1) || (j ==0) || (j == c-1)){
        s = s + "";
        //s = s + grid[i][j].getDOrA();
      }
      else{
        s = s + grid[i][j].getDOrA();
      }
    }
    s = s + "\r\n";
  }
  return s;
}


//getters

/*
grid1 getter method. returns grid1
*/
Cell** GameOfLife::getGrid1(){
  return grid1;
}

/*
grid2 getter method. returns grid2
*/
Cell** GameOfLife::getGrid2(){
  return grid2;
}

/*
gameMode getter method. returns gameMode
*/
int GameOfLife::getGameMode(){
  return gameMode;
}
/*
rows getter method. returns rows
*/
int GameOfLife::getRows(){
  return rows;
}

/*
cols getter method. returns cols
*/
int GameOfLife::getCols(){
  return cols;
}

/*
continuation getter method. returns continuation
*/
int GameOfLife::getContinuation(){
  return continuation;
}

/*
density getter method. returns density
*/
double GameOfLife::getDensity(){
  return density;
}
/*
fOrR getter method. returns fOrR
*/
int GameOfLife::getFOrR(){
  return fOrR;
}

//setters
/*
grid 1 setter method. sets grid 1 to parameter grid
*/
void GameOfLife::setGrid1(Cell **grid){
  grid1 = grid;
}
/*
grid 2 setter method. sets grid 2 to parameter grid
*/
void GameOfLife::setGrid2(Cell **grid){
  grid2 = grid;
}

/*
gameMode setter method. sets gameMode to parameter gameMode
*/
void GameOfLife::setGameMode(int gameMode){
  this->gameMode = gameMode;
}
/*
rows setter method. sets rows to parameter rows
*/
void GameOfLife::setRows(int rows){
  this->rows = rows;
}

/*
cols setter method. sets cols to parameter cols
*/
void GameOfLife::setCols(int cols){
  this->cols = cols;
}
/*
continuation setter method. sets continuation to parameter continuation
*/
void GameOfLife::setContinuation(int continuation){
  this->continuation = continuation;
}
/*
density setter method. sets density to parameter density
*/
void GameOfLife::setDensity(double density){
  this->density = density;
}

/*
end method
parameters: Cell **grid, int r, int c
Checks if all Cells are dead. returns true if all are dead, false otherwise
*/
bool GameOfLife::end(){

  string s = printGrid();
  if(s.find('X') != std::string::npos){
    return true;
  }
  else{
    return false;
  }
 }

 /*
 generateGridRandom method
 parameters: Cell **grid, int r, int c, double denity, int gameMode
 Generates the first inital grid if the user inputs a density and wants a random Grid.
 */
 void GameOfLife::generateGridRandom(int r, int c, double density, int gameMode){
   Cell **grid;
   grid = new Cell *[r];
   for(int i = 0; i < r; i++){
     grid[i] = new Cell[c];
   }
   double rnum = ((double)rand()/(double)RAND_MAX);
     for(int i = 0;i < r; i++){
       for(int j =0; j < c; j++){
         rnum = ((double)rand()/(double)RAND_MAX);
         if((i == 0) || (i == r-1) || (j ==0) || (j == c-1)){
            grid[i][j].setDOrA("-");
            grid[i][j].setAlive(false);
         }
         else{
            if(rnum >= density){
              grid[i][j].setDOrA("-");
              grid[i][j].setAlive(false);
            }
            else{
              grid[i][j].setDOrA("X");
              grid[i][j].setAlive(true);
            }
         }
       }
     }


   setGrid1(grid);
   setGrid2(grid);
 }

 /*
 copyGrid method.
 Basically copies what is in a grid to another grid.
 */
 Cell**  GameOfLife::copyGrid(Cell **grid){
   int r = getRows();
   int c = getCols();
   Cell **gridnew;
   gridnew = new Cell *[r];
   /*
   This makes the field for game of life, making a border 1 array value wide which
   will be a constant dead Cell
   */
   for(int i = 0; i < r; i++){
     gridnew[i] = new Cell[c];
   }

   for(int i = 0; i < r; i++){
     for(int j = 0; j < c; j++){
       gridnew[i][j] = grid[i][j];
     }
   }
   return gridnew;
 }

 /*
 printgrid method.
 Returns a string that represents the grid
 */
 string GameOfLife::printGrid(){
   int r = getRows();
   int c = getCols();
   Cell **grid = getGrid2();
   string s = "";
   for(int i = 0; i < r; i++){
     for(int j = 0; j < c; j++){
       if((i == 0) || (i == r-1) || (j ==0) || (j == c-1)){
         s = s + "";
         //s = s + grid[i][j].getDOrA();
       }
       else{
         s = s + grid[i][j].getDOrA();
       }
     }
     s = s + "\n";
   }
   return s;
 }

 //Starts the game of life and applies the rules of wether an input is dead or alive and the rule sthat follow with the amount of neighbors.

 void GameOfLife::startGame(Cell **grid){
   Cell** newgrid;
   newgrid = copyGrid(grid);
   int neighbors = 0;
   for(int i = 0; i < getRows(); i++){
     for(int j = 0; j < getCols(); j++){
       if((i == 0) || (i == getRows()-1) || (j ==0) || (j == getCols()-1)){
       }
       else{
         grid[i][j].countNeighbors(grid, i, j);
         neighbors = grid[i][j].getNeighbors();
         if(grid[i][j].getNeighbors() > 3){
           newgrid[i][j].setAlive(false);
           newgrid[i][j].setDOrA("-");
           newgrid[i][j].setNeighbors(grid[i][j].getNeighbors());
         }
         else if(grid[i][j].getNeighbors() == 3){
           if(grid[i][j].isAlive() == false){
             newgrid[i][j].setAlive(true);
             newgrid[i][j].setDOrA("X");
             newgrid[i][j].setNeighbors(grid[i][j].getNeighbors());
           }
         }
         else if(grid[i][j].getNeighbors() < 2){
           if(grid[i][j].isAlive() == true){
             newgrid[i][j].setAlive(false);
             newgrid[i][j].setDOrA("-");
             newgrid[i][j].setNeighbors(grid[i][j].getNeighbors());
           }
         }
       }
     }
   }
   setGrid1(copyGrid(newgrid));
   setGrid2(copyGrid(newgrid));
 }

 /*
 generateGridFile generates grid 1 to be what the file has.
 */
 void GameOfLife::generateGridFile(string *s, int gameMode){
   Cell **grid;
   int r = getRows();
   string l = "";
   int c = getCols();
   grid = new Cell *[r];
   for(int i = 0; i < r; i++){
     grid[i] = new Cell[c];
   }
   for(int i = 0; i < r; i++){
     l = s[i];
     for(int j = 0; j < c; j++){
       if(l[j-1] == 'X'){
         grid[i][j].setDOrA("X");
         grid[i][j].setAlive(true);
       }
       else{
         grid[i][j].setDOrA("-");
         grid[i][j].setAlive(false);
       }
     }
   }
   setGrid1(grid);
   setGrid2(grid);
 }

//Code to setup the 2-D array to be able to work in the mirror mode. Corners are relflected and also the sides are reflected as well.

 void GameOfLife::mirror(Cell **grido){
   Cell** grid = copyGrid(grido);
   if(grid[1][1].isAlive() == true){
     grid[0][0].setAlive(true);
     grid[0][0].setDOrA("X");
   }
   else{
     grid[0][0].setAlive(false);
     grid[0][0].setDOrA("-");
   }
   if(grid[1][getCols() - 2].isAlive() == true){
     grid[0][getCols() - 1].setAlive(true);
     grid[0][getCols() - 1].setDOrA("X");
   }
   else{
     grid[0][getCols() - 1].setAlive(false);
     grid[0][getCols() - 1].setDOrA("-");
   }
   if(grid[getRows() - 2][1].isAlive() == true){
     grid[getRows() - 1][0].setAlive(true);
     grid[getRows() - 1][0].setDOrA("X");
   }
   else{
     grid[getRows() - 1][0].setAlive(false);
     grid[getRows() - 1][0].setDOrA("-");
   }
   if(grid[getRows() - 2][getCols() - 2].isAlive() == true){
     grid[getRows() - 1][getCols() - 1].setAlive(true);
     grid[getRows() - 1][getCols() - 1].setDOrA("X");
   }
   else{
     grid[getRows() - 1][getCols() - 1].setAlive(false);
     grid[getRows() - 1][getCols() - 1].setDOrA("-");
   }

   for(int a = 1; a <= getCols() - 2; a++){
     if(grid[a][1].isAlive() == true){
       grid[a][0].setAlive(true);
       grid[a][0].setDOrA("X");
     }
     else{
       grid[a][0].setAlive(false);
       grid[a][0].setDOrA("-");
     }
   }

   for(int b = 1; b <= getRows() - 2; b++){
     if(grid[1][b].isAlive() == true){
       grid[0][b].setAlive(true);
       grid[0][b].setDOrA("X");
     }
     else{
       grid[0][b].setAlive(false);
       grid[0][b].setDOrA("-");
     }
   }

   for(int c = getCols() - 2; c <= getRows() - 2; c++){
     if(grid[getCols() - 2][c].isAlive() == true){
       grid[getCols() - 1][c].setAlive(true);
       grid[getCols() - 1][c].setDOrA("X");
     }
     else{
       grid[getCols() - 1][c].setAlive(false);
       grid[getCols() - 1][c].setDOrA("-");
     }
   }

   for(int d = 1; d <= getCols() - 2; d++){
     if(grid[d][getRows() - 2].isAlive() == true){
       grid[d][getRows() - 1].setAlive(true);
       grid[d][getRows() - 1].setDOrA("X");
     }
     else{
       grid[d][getRows() - 1].setAlive(false);
       grid[d][getRows() - 1].setDOrA("-");
     }
   }
   setGrid1(grid);
   setGrid2(grid);
 }

//Donut method code. called torus for the shape it is modeled to be looked after.

void GameOfLife::torus(Cell** grido){
   int r = getRows();
   int c = getCols();
   Cell** grid = copyGrid(grido);
   for(int a = 0; a < r; a++){
     for(int b = 0; b < c; b++){
       if(a == 0){
         if(((a == 0) && (b == 0)) || ((a == 0) && (b == c - 1))){
           grid[a][b].setDOrA("-");
           grid[a][b].setAlive(false);
         }
         else{
           if((grid[r-1][b]).isAlive() == true){
             grid[a][b].setDOrA("X");
             grid[a][b].setAlive(true);
           }
           else{
             grid[a][b].setDOrA("-");
             grid[a][b].setAlive(false);
           }
         }
       }
       else if(a == r-1){
         if(((a == r-1) && (b == 0)) || ((a == r-1) && (b == c - 1))){
           grid[a][b].setDOrA("-");
           grid[a][b].setAlive(false);
         }
         else{
           if((grid[1][b]).isAlive() == true){
             grid[a][b].setDOrA("X");
             grid[a][b].setAlive(true);
           }
           else{
             grid[a][b].setDOrA("-");
             grid[a][b].setAlive(false);
           }
         }
       }
       else if(b == 0){
         if(((a == 0) && (b == 0)) || ((a == r-1) && (b == 0))){
           grid[a][b].setDOrA("-");
           grid[a][b].setAlive(false);
         }
         else{
           if((grid[a][c-2]).isAlive()){
             grid[a][b].setDOrA("X");
             grid[a][b].setAlive(true);
           }
           else{
             grid[a][b].setDOrA("-");
             grid[a][b].setAlive(false);
           }
         }
       }
       else if(b == c-1){
         if(((a == 0) && (b == c-1)) || ((a == r-1) && (b == r - 1))){
           grid[a][b].setDOrA("-");
           grid[a][b].setAlive(false);
         }
         else{
           if((grid[a][1]).isAlive() == true){
             grid[a][b].setDOrA("X");
             grid[a][b].setAlive(true);
           }
           else{
             grid[a][b].setDOrA("-");
             grid[a][b].setAlive(false);
           }
         }
        }
      }
    }
    setGrid1(grid);
    setGrid2(grid);
  }
