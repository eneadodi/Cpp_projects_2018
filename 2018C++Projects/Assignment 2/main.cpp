
/*
 * File:   main.cpp
 * Author: Enea Dodi, Kyle Burack
 * id: 2296306
 * Date: September 28 2018
 *
 * Created on September 10, 2018, 12:03 AM
 *This is the game of life program!! The rules instructed are as follows:
 *1. Ask the user if they wish to start with a random configuration, or specify a flatfile
configuration. Prompt appropriately depending on the response.
  2. Ask the user what kind of boundary mode to run in.
  3. Ask the user if they want a brief pause between generations, if they want to have
to press the “enter” key, or if they want to output to a file.
  4. Carry out the simulation
  5. If the simulation is infinite, just keep running. But if the world becomes empty or
stabilizes, the simulation should halt and ask the user to press “enter” to exit the
program.
 */
 #include "Cell.h"
 #include <cstdlib>
 #include <fstream>
 #include <iostream>
 #include<cmath>
 #include <cstring>
 #include <unistd.h>
 #include "time.h"
 #include "GameOfLife.h"
 using namespace std;

 int main(int argc, char** argv) {
   srand((unsigned)time(NULL));
   /*
   Start:
   This part of main basically starts off asking all the user's preferences about
   Conway's Game of Life and creates the class "Simulation" which does all the rest of
   the work.
   */

   int fOrR;
   int cols;
   int rows;
   ofstream outfile;
   double density;
   string input = "";
   int gameMode;
   int continuation;
   ifstream file;
   cout << "Welcome to the Game of Life!" <<endl;
   cout << "Would You like to provide a map file or random assignment?" <<endl;
   cout << "Type '1' if you'd like to provide a map file" <<endl;
   cout << "Type '2' if you'd like a random assignment" <<endl;
   cin >> fOrR;
   if(fOrR == 1){
     cout << "What is the name of the Map File?" << endl;
     cin >> input;
     //setupFile(input);
       cout << "What Mode would you like?" << endl;
       cout << "1) Classic Mode" << endl;
       cout << "2) Doughnut Mode" << endl;
       cout << "3) Mirror Mode" << endl;
       cin >> gameMode;
       if(cin.fail()){
         cerr << "Please enter an integer!" <<endl;
       }
       else if(gameMode > 3){
         cerr << "Please enter an integer between 1-3!"<<endl;
       }
       else{
         cout<< "Would you like:" << endl;
         cout << "1) A Brief Pause between generations" << endl;
         cout << "2) Press 'enter' key for nexr generation" <<endl;
         cout << "3) Output to a file" <<endl;
         cin >> continuation;
         if(cin.fail()){
           cerr << "Please enter an integer!" <<endl;
         }
         else if(continuation > 3){
           cerr << "Please enter an integer between 1-3!" << endl;
         }
       }

  }
   else if(fOrR == 2){
     cout << "How many columns should the array have?" <<endl;
     cin >> cols;
     if(cin.fail()){
       cerr << "Please enter an integer!"<<endl;
     }
     else{
       cout << "How many rows should the array have?" << endl;
       cin >> rows;
       if(cin.fail()){
         cerr << "Please enter an integer!"<<endl;
       }
       else{
         cout << "What Mode would you like?" << endl;
         cout << "1) Classic Mode" << endl;
         cout << "2) Doughnut Mode" << endl;
         cout << "3) Mirror Mode" << endl;
         cin >> gameMode;
         if(cin.fail()){
           cerr << "Please enter an integer!"<<endl;
         }
         else if(gameMode > 3){
           cerr << "Please enter an integer between 1-3!"<<endl;
         }
         else{
           cout<< "Would you like:" << endl;
           cout << "1) A Brief Pause between generations" << endl;
           cout << "2) Press 'enter' key for nexr generation" <<endl;
           cout << "3) Output to a file" <<endl;
           cin >> continuation;
           if(cin.fail()){
             cerr << "Please enter an integer!" <<endl;
           }
           else if(continuation > 3){
             cerr << "Please enter an integer between 1-3!" << endl;
           }
           else{
             cout << "What would you like the inital population density to be? Enter value between 0 and 1"<<endl;
             cin >> density;
             if(cin.fail()){
               cerr << "Please enter a double!" <<endl;
             }
             else if((density > 1) || (density < 0)){
               cerr << "Please enter a double between 0 and 1" <<endl;
             }
           }
         }
       }
     }
   }
   else{
     cout << "Enter either a 1 or 2!" << endl;
   }
   if(continuation == 3){
     string nof = "";
     cout << "What is the name of the file you want it to be out put to";
     cin >> nof;
     outfile.open(nof.c_str());
   }

   /*
   END:
   This part of main basically starts off asking all the user's preferences about
           the work.
   */
   /*
   At this point variables holding the information for
   a) amount of rows (rows)
   b) amount of columns (cols)
   c) method of output (continuation)
   d) density of grid if random configuration
   e) name of file
   f) random assignment or file (fOrR)
   */
   bool endGame;
   int r = rows+2;//Adds two for normal version(to have something represnt empty)
   int c = cols+2;//adds two fro normal version(to have something represent empty)
   if(fOrR == 2){
    GameOfLife simulate(fOrR, r, c, continuation, density,gameMode);
    endGame = true;
    if(continuation == 1){
      while(endGame){
        system("pause");
        if(simulate.getGameMode() == 2){
            simulate.torus(simulate.getGrid1());
        }
        else if(simulate.getGameMode() == 3){
            simulate.mirror(simulate.getGrid1());
        }
        simulate.startGame(simulate.getGrid1());
        cout << simulate.printGrid() <<endl;
        endGame = simulate.end();
      }
    }
    else if(continuation == 2){
      cout << "Press enter to continue" << endl;
      while((cin.get() && endGame == true)){
        if(simulate.getGameMode() == 2){
            simulate.torus(simulate.getGrid1());
        }
        else if(simulate.getGameMode() == 3){
            simulate.mirror(simulate.getGrid1());
        }
        simulate.startGame(simulate.getGrid1());
        cout << simulate.printGrid() <<endl;
        endGame =  simulate.end();
    }
  }
  else{
    while(endGame){
      system("pause");
      if(simulate.getGameMode() == 2){
          simulate.torus(simulate.getGrid1());
      }
      else if(simulate.getGameMode() == 3){
          simulate.mirror(simulate.getGrid1());
      }
      simulate.startGame(simulate.getGrid1());
      outfile << simulate.printGridToFile();
      endGame = simulate.end();
    }
  }
   }
  else{
    endGame = true;
    GameOfLife simulate(fOrR, input, continuation, gameMode);
    if(continuation == 1){
      while(endGame){
        system("pause");
        if(simulate.getGameMode() == 2){
            simulate.torus(simulate.getGrid1());
        }
        else if(simulate.getGameMode() == 3){
            simulate.mirror(simulate.getGrid1());
        }
        simulate.startGame(simulate.getGrid1());
        cout << simulate.printGrid() <<endl;
        endGame = simulate.end();
      }
    }
    else if(continuation == 2){
      cout << "Press enter to continue" << endl;
      while((cin.get() && endGame == true)){
        if(simulate.getGameMode() == 2){
            simulate.torus(simulate.getGrid1());
        }
        else if(simulate.getGameMode() == 3){
            simulate.mirror(simulate.getGrid1());
        }
        simulate.startGame(simulate.getGrid1());
        cout << simulate.printGrid() <<endl;
        endGame = simulate.end();
    }
  }
  else{
    while(endGame == true){
      system("pause");
      if(simulate.getGameMode() == 2){
          simulate.torus(simulate.getGrid1());
      }
      else if(simulate.getGameMode() == 3){
          simulate.mirror(simulate.getGrid1());
      }
      simulate.startGame(simulate.getGrid1());
      outfile << simulate.printGridToFile();
      endGame = simulate.end();
    }
  }
  }
 }
