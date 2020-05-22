
#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <ctime>
using namespace std;

class SortingAlgorithms{
public:
  bool RealFile = true;
  
	SortingAlgorithms();

	SortingAlgorithms(const string& s);

	SortingAlgorithms(double*f, int s);

	~SortingAlgorithms();

	void BubbleSort();
        
	void InsertionSort();
        
	void QuickSort();
  void QuickSortBody(double a[], int low,  int high);
	int partiton(double a[], int low, int high);
                
  void MergeSort();
  void MergeSortBody(double a[], int low, int high);
  void Merge(double a[], int low, int middle, int high);
        
	void createFile();
	void swap(double*x,double*y);
	int getSize();
	double* getVals();
	void printArr();
	void compareSortingAlgorithms();
	void setSize(int size);
	void readFile(string s);
	double* copyVals();
	void setVals(double* Newvals,int size);
private:
	double* vals;
	const string defaultName = "ckvpoky5px.txt";
	ifstream file;
	int size = 0;
	bool fileExists(const string& s){
		if(FILE *file = fopen(s.c_str(), "r")){
			fclose(file);
			return true;
		}
		else{
			return false;
		}
	};
	bool isNumber(const string& s){
		char* end = 0;
		double val = strtod(s.c_str(), &end);
		return (end != s.c_str() && val != HUGE_VAL);
	};
  
  //To show the algorithms are actually sorted.
  void forProof(double *a){
    for(int i = 0; i < size;i++){
      cout << a[i] << endl;
    }
  }
};
#endif /*SORTINGALGORITHMS_H*/