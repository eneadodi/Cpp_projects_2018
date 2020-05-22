#include "SortingAlgorithms.h"
using namespace std;

/*
Default Constructor
*/
SortingAlgorithms::SortingAlgorithms(){

}

/*
Constructor 
Param: string s
Creates the array and size variables according to the file inputted.
*/
SortingAlgorithms::SortingAlgorithms(const string& s){
  srand(time(NULL));
  if(s == "ckvpoky5px.txt"){
    createFile();
    //readFile(defaultName);
  }
  readFile(s);
}

/*
Constructor
sets vals to f, size to s, and RealFile to true
*/
SortingAlgorithms::SortingAlgorithms(double *f, int s){
  *vals = *f;
  size = s;
  RealFile = true;
}

/*
Destructor
*/
SortingAlgorithms::~SortingAlgorithms(){
  delete vals;
}

/*
BubbleSort Algorithm
Bubble sort is the simplest sorting algorithms. Its runtime is O(n^2).
The algorithm is very simple. Simply, every index value is compared to the 
proceding index value. If the proceding is < current, they swap. The algorithm will continue to do that until no values are swapped.
*/
void SortingAlgorithms::BubbleSort(){
  bool dontEnd = true;
  double *rArr;
  int j = 0;
  rArr = copyVals();
  while(dontEnd){
      dontEnd = false;
      j++;
      for(int i = 0 ; i < size; i++){
        if(rArr[i+1] < rArr[i]){
                swap(&rArr[i+1],&rArr[i]);
                dontEnd = true;
        }
      }
  }
  //forProof(rArr)
}

/*
InsertionSort Algorithm
Insertion Sort is also a simple sorting algorithm. Its runtime is as well O(n^2) but if the list is basically sorted, it can run as quick as O(n).
The algorithm is simple. You Iterated through the entire list. If a value
is found in the wrong index (if it was sorted), that value now is compared to preceding index values until it finds a value < than it or reaches index 0. The value is placed there and the other values to its right are moved up.
This algorithm makes a divide in the list, where every value to the left of a "current index" is sorted, and the values to the right are not sorted. 
*/
void SortingAlgorithms::InsertionSort(){
          double *rArr;
          rArr = copyVals();
          int key;
          int marker;
          for(int i = 0; i < size;i++){
              key=rArr[i];
              marker = i-1;
              while((key<rArr[marker]) && (marker>=0)){
                  rArr[marker+1] = rArr[marker];
                  marker = marker-1;
              }
          }
        //forProof(rArr)
}

/*
QuickSort Algorithm
Quick sort is a bit more complex than Insert Sort and Bubble Sort, and its runtime is also significantly better at O(nlog(n)).
It works by picking a pivot element and dividing the array into 3 parts:
* All elements less than pivot
* The pivot
* all elements >= pivot
The 3 parts are created by partiton.
It recurses until the array is sorted. 
Its a divide-and-conquer algorithm which means it splits the list into smaller and smaller parts. 
*/
void SortingAlgorithms::QuickSort(){
    double *rArr;
    rArr = copyVals();
    QuickSortBody(rArr,0, getSize()-1);
    //forProof(rArr)
}

/*
What actually does the work for QuickSort
*/
void SortingAlgorithms::QuickSortBody(double a[], int low,  int high){
    if(low < high){
        int partionIndex = partiton(a,low,high);
        QuickSortBody(a,low,partionIndex-1);
        QuickSortBody(a,partionIndex+1,high);
    }
}

/*
Partiton function
paramters - double a[] : the array to be sorted
          - int low : lowest points to start sorting
          - int high : highest point to start sorting
returns: the index of the partiton after swapping around values left and
right according to their value.
*/
int SortingAlgorithms::partiton(double a[], int low, int high){
    int pivot = a[high];
    int j = low - 1;
    for(int i = low; i < high;i++){
        if(a[i] <= pivot){
            j++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[j+1], &a[high]);
    return j+1;
}

/*
MergeSort algorithm
MergeSort is another sorting, divide-and-conquer, recursive algorithm with
a runtime of O(nlogn). It recursively splits the list into two parts until
the list cannot be broken down anymore and can be solved directly.
*/
void SortingAlgorithms::MergeSort(){
    double *rArr;
    rArr = copyVals();
    MergeSortBody(rArr,0, getSize()-1);
    //forProof(rArr)
}

/*
What actually does the work for MergeSort
*/
void SortingAlgorithms::MergeSortBody(double a[], int low, int high){
    if(low < high){
        int middle = (low+high)/2;
        MergeSortBody(a,low,middle);
        MergeSortBody(a,(middle+1),high);
        Merge(a,low,middle,high);
        //forProof(a)
    }
}

/*
Merge method
Sorts the left and right parts of the list by creating a temporary array
and places the values of the left and right sides iteratively by comparing
the values in the indeces. Then merges the two together. 
*/
void SortingAlgorithms::Merge(double a[], int low, int middle, int high){
    int *temp = new int[high-low+1];
    int left = low;
    int right = middle + 1;
    int kIndex = 0;
    while(left <= middle && right <= high){
        if(a[left] <= a[right]){
            temp[kIndex++] = a[left++];
        }
        else{
            temp[kIndex++] = a[right++];
        }
    }
    while(left <= middle){
        temp[kIndex++] = a[left++];
    }
    while(right <= high){
        temp[kIndex++] = a[right++];
    }
    for(kIndex = 0, left = low; left <= high; ++left, ++kIndex){
        a[left] = temp[kIndex];
    }

    delete []temp;
}

void SortingAlgorithms::compareSortingAlgorithms(){
  if(RealFile){
        clock_t begin = clock();
        BubbleSort();
        clock_t end = clock();
        cout << "****************BubbleSort****************" << endl;
        cout << "Time sort started: " << double(begin) << endl;
        cout << "Time sort ended: " << double(end) << endl;
        cout << "Elapsed time: " << double(end - begin) << endl;
        cout << "****************BubbleSort****************" << endl << endl << endl;

        begin = clock();
        InsertionSort();
        end = clock();

        cout << "*************InsertionSort**************" << endl;
        cout << "Time sort started: " << double(begin) << endl;
        cout << "Time sort ended: " << double(end) << endl;
        cout << "Elapsed time: " << double(end - begin) << endl;
        cout << "*************InsertionSort**************" << endl << endl << endl;


        begin  = clock();
        QuickSort();
        end = clock();

        cout << "**************QuickSort***************" << endl;
        cout << "Time sort started: " << double(begin) << endl;
        cout << "Time sort ended: " << double(end) << endl;
        cout << "Elapsed time: " << double(end - begin) << endl;
        cout << "**************QuickSort***************" << endl << endl << endl;

        begin  = clock();
        MergeSort();
        end = clock();

        cout << "**************MergeSort***************" << endl;
        cout << "Time sort started: " << double(begin) << endl;
        cout << "Time sort ended: " << double(end) << endl;
        cout << "Elapsed time: " << double(end - begin) << endl;
        cout << "**************MergeSort***************" << endl << endl << endl;
  }

}

/*
Swaps the positions of x and y.
*/
void SortingAlgorithms::swap(double *x,double *y){
  double temp = *x;
  *x = *y;
  *y = temp; 
}

//GETTERS AND SETTERS
int SortingAlgorithms::getSize(){
  return size;
}

double* SortingAlgorithms::getVals(){
  return vals;
}

void SortingAlgorithms::setSize(int size){
  this->size = size;
}

void SortingAlgorithms::setVals(double* Newvals,int size){
  this->vals = Newvals;
  this->size = size;
}

//END OF SETTERS AND GETTERS
double* SortingAlgorithms::copyVals(){
  double *rVals = new double[size];
  for(int i = 0; i< getSize();i++){
    rVals[i] = vals[i];
  }
  return rVals;
}

/*Creates a file of random double points between 300 and 5000 points in length
*/
void SortingAlgorithms::createFile(){
  ofstream create(defaultName);
  int i = (int)(rand() % 5000 + 400);
  double randomGenerateNumber;
  create << i << endl;
  for(i; i > 0; i--){
    randomGenerateNumber = (double)rand() / (double)RAND_MAX;
    randomGenerateNumber = 1 + randomGenerateNumber*(10000 - 1);
    create << randomGenerateNumber << endl;
  }
  create.close();
}

/*Reads the values in the file to the array. Must be doubles otherwise they
*/
void SortingAlgorithms::readFile(string s){
    bool RealFile = fileExists(s);
    int i = 0;
    if(RealFile){
      string line;
      file.open(s);
      getline(file,line);
      if(isNumber(line)){
        int size = stoi(line.c_str());
        setSize(size);
        bool realNumber;
        vals = new double[size];
        while(getline(file,line) && i < size){
          realNumber = isNumber(line);
          if(realNumber){
            vals[i] = stod(line.c_str());
          }
          i++;
        }
      }
    }
    else{
      cout << "File does not exist or has incorrect inputs" << endl;
      RealFile = false;
    }
}


