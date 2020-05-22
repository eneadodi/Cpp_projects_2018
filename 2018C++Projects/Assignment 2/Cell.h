/*
 * File:   Cell.h
 * Author: Enea Dodi
 *f
 * Created on September 25, 2018, 4:23 AM
 */

#ifndef CELL_H
#define CELL_H
#include<cstdlib>
#include<ostream>
#include<fstream>

using namespace std;

class Cell{
public:
    Cell();
    Cell(Cell& orig);
    Cell(bool a);
    Cell(string s);
    bool isAlive();
    void setAlive(const bool& alive);
    string getDOrA();
    void setDOrA(const string& dOrA);
    int getNeighbors();
    void setNeighbors(const int& neighbors);
    void countNeighbors(Cell **grid,int i, int j);
    void simulate();
    void pause();
    void enter();
    void outputFile(string fileName);
    void standard();
    void donut();
    void mirror();
    bool end();
    Cell** setupFile(string fileName);
private:
    int neighbors;
    string dOrA;
    bool alive;

};

#endif /* CELL_H */
