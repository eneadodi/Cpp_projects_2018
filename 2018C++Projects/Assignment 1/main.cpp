/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Enea Dodi
 *
 * Created on September 10, 2018, 12:03 AM
 */
 #include "DNAstats.h"
 #include <cstdlib>
 #include <fstream>
 #include <iostream>
 using namespace std;

 int main(int argc, char** argv) {
   string input = "";
   string temp = "";
   string DNAs = "";
   DNAstats DNA_Anal();
   cout << "What is the name of the file with the DNA Sequences?" << endl;
   cin >> input;
   ifstream DNAseqFile;

   DNAseqFile.open(input);
   while(DNAseqFile.good()){
     getline(DNAseqFile,temp);
     DNAs = DNAs + temp + " ";
   }
   DNAs += " ";
   DNAstats DNA_Analyzer(DNAs);
   DNA_Analyzer.toFile();
   DNAseqFile.close();
   return 0;
 }


//figure out how to read line by line
//figure out how to delete anyhting that is not a AGCT
//figure out how to turn that file into a string seperated by spaces
//figure out how to do the Gaussian shit and how to update all the analysis varaibles
