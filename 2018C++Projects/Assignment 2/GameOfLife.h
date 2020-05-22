/*
 * File:   Cell.h
 * Author: Enea Dodi
 *
 * Created on September 25, 2018, 4:23 AM
 */

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include<cstdlib>
#include<ostream>
#include<fstream>
#include "Cell.h"

using namespace std;

class GameOfLife{
public:
  //constructors
  GameOfLife();
  GameOfLife(int fOrR,int rows, int cols, int continuation,double density,int gameMode);
  GameOfLife(int fOrR, string filename, int continuation,int gameMode);
//  ~GameOfLife();

  //getters
  Cell** getGrid1();
  Cell** getGrid2();
  int getRows();
  int getCols();
  int getContinuation();
  double getDensity();
  int getFOrR();
  int getGameMode();

  //setters
  void setGrid1(Cell **grid);
  void setGrid2(Cell **grid);
  void setRows(int rows);
  void setCols(int cols);
  void setContinuation(int continuation);
  void setDensity(double density);
  void setFOrR(int fOrR);
  void setGameMode(int gameMode);

  //functions
  bool end();
  void generateGridRandom(int r, int c, double density, int gameMode);
  void generateGridFile(string *s, int gameMode);
  Cell** copyGrid(Cell **grid);
  string printGrid();
  string printGridToFile();
  void startGame(Cell **grid);
  void mirror(Cell **grido);
  void torus(Cell **grido);
  //Cell** setupFile(string fileName);
private:
  Cell **grid1;
  Cell **grid2;
  int rows;
  int cols;
  int continuation;
  double density;
  int fOrR;
  int gameMode;
  /*
  At this point variables holding the information for
  a) amount of rows (rows)
  b) amount of columns (cols)
  c) method of output (continuation)
  d) density of grid if random configuration
  e) name of file
  f) random assignment or file (fOrR)
  */

};

#endif /* CELL_H */
