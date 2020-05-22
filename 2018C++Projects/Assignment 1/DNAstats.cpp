#include "DNAstats.h"
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<cmath>
#include "time.h"
using namespace std;


/*
The Default Constructor
Makes the DNAstats object
*/
DNAstats::DNAstats(){
  srand(time(NULL));
  standardGaussian = 0; totalLines = 0; mean = 0; counter = 0; sum = 0;
  variance = 0; standardDev = 0; adenine = 0; guanine = 0; thymine = 0;
  cytosine = 0; probA = 0; probG = 0; probT = 0; probC = 0;
  probAA = 0; probAC = 0; probAG = 0; probAT = 0; probCA = 0; probCC = 0;
  probCT = 0; probCG = 0; probTA = 0; probTT = 0; probTC = 0; probTG = 0;
  probGG = 0; probGC = 0; probGT = 0; probGA = 0;
}

/*
Constructor with parameter:
DNAstats
Makes a copy of the parameter DNAstats
*/
DNAstats::DNAstats(DNAstats& orig){
  srand(time(NULL));
  standardGaussian = orig.getGaussian(); totalLines = orig.getTotalLines(); mean = orig.getMean(); counter = orig.getCounter(); sum = orig.getSum();
  variance = orig.getVariance(); standardDev = orig.getStandardDev(); adenine = orig.getAdenine(); guanine = orig.getGuanine(); thymine = orig.getThymine();
  cytosine = orig.getCytosine(); probA = orig.getProbA(); probG = orig.getProbG(); probT = orig.getProbT(); probC = orig.getProbC();
  probAA = orig.getProbAA(); probAC = orig.getProbAC(); probAG = orig.getProbAG(); probAT = orig.getProbAT(); probCA = orig.getProbCA(); probCC = orig.getProbCC();
  probCT = orig.getProbCT(); probCG = orig.getProbCG(); probTA = orig.getProbTA(); probTT = orig.getProbTT(); probTC = orig.getProbTC(); probTG = orig.getProbTG();
  probGG = orig.getProbGG(); probGC = orig.getProbGC(); probGT = orig.getProbGT(); probGA = orig.getProbGA();
}

/*
Constructor with parameter
string DNASequence
sets up all variables in the object according to the string :)
*/
DNAstats::DNAstats(string& DNASequence){
  srand(time(NULL));
  string sequence = cleanLines(DNASequence);
  totalLines = amountOfChar(sequence, ' ');
  sum = ((sequence.length()-2) - totalLines);
  mean = static_cast<double>(sum)/(double)(1.0*totalLines);
  setAllProb(sequence,sum);
  counter = 0;
  setUpVariance(sequence);
  variance = getVariance()/totalLines;
  standardDev = sqrt(getVariance());
  calcStandardGaussian(mean, variance);
}

/*
getter method for variable mean
return double mean
*/
double DNAstats::getMean(){
  return mean;
}

int DNAstats::getTotalLines(){
  return totalLines;
}
/*
setter method for mean
*/
void DNAstats::setMean(const double& m){
  mean = m;
}

/*
getter method for variable getCounter
return int counter
*/
int DNAstats::getCounter(){
  return counter;
}

/*
setter method for variable counter
*/
void DNAstats::setCounter(const double& c){
  counter = c;
}

/*
getter method for variable getSum
return int sum
*/
int DNAstats::getSum(){
  return sum;
}

/*
setter method for variable sum
*/
void DNAstats::setSum(const int& s){
  sum = s;
}

/*
getter method for variable getVariance
return double variance
*/
double DNAstats::getVariance(){
  return variance;
}

/*
setter method for variable Variance
*/
void DNAstats::setVariance(const double& v){
  variance = v;
}

/*
getter method for variable standardDev
return double standardDev
*/
double DNAstats::getStandardDev(){
  return standardDev;
}

/*
setter method for variable standardDev
*/
void DNAstats::setStandardDev(const double& sd){
  standardDev = sd;
}

/*
getter method for variable adenine;
return int adenine
*/
int DNAstats::getAdenine(){
  return adenine;
}

/*
setter method for variable adenine
*/
void DNAstats::setAdenine(const int& a){
  adenine = a;
}

/*
getter method for variable guanine;
return int guanine
*/
int DNAstats::getGuanine(){
  return guanine;
}

/*
setter method for variable guanine
*/
void DNAstats::setGuanine(const int& g){
  guanine = g;
}

/*
getter method for variable Thymine;
return int Thymine
*/
int DNAstats::getThymine(){
  return thymine;
}

/*
setter method for variable thymine
*/
void DNAstats::setThymine(const int& t){
  thymine = t;
}

/*
getter method for variable Cytosine;
return int Cytosine
*/
int DNAstats::getCytosine(){
  return cytosine;
}

/*
setter method for variable cytosine
*/
void DNAstats::setCytosine(const int& c){
  cytosine = c;
}

/*
getter method for variable probA
return double probA
*/
double DNAstats::getProbA(){
  return probA;
}

/*
setter method for variable probA
*/
void DNAstats::setProbA(const double& pa){
  probA = pa;
}

/*
getter method for variable probAA
return double probAA
*/
double DNAstats::getProbAA(){
  return probAA;
}

/*
setter method for variable probAA
*/
void DNAstats::setProbAA(const double& paa){
  probAA = paa;
}

/*
getter method for variable probAC
return double probAC
*/
double DNAstats::getProbAC(){
  return probAC;
}

/*
setter method for variable probAC
*/
void DNAstats::setProbAC(const double& pac){
  probAC = pac;
}

/*
getter method for variable probAG
return double probAG
*/
double DNAstats::getProbAG(){
  return probAG;
}

/*
setter method for variable probAG
*/
void DNAstats::setProbAG(const double& pag){
  probAG = pag;
}

/*
getter method for variable probAT
return double probAT
*/
double DNAstats::getProbAT(){
  return probAT;
}

/*
setter method for variable probAT
*/
void DNAstats::setProbAT(const double& pat){
  probA = pat;
}

/*
getter method for variable probG
return double probG
*/
double DNAstats::getProbG(){
  return probG;
}

/*
setter method for variable probG
*/
void DNAstats::setProbG(const double& pg){
  probG = pg;
}

/*
getter method for variable probGA
return double probGA
*/
double DNAstats::getProbGA(){
  return probGA;
}

/*
setter method for variable probGA
*/
void DNAstats::setProbGA(const double& pga){
  probGA = pga;
}

/*
getter method for variable probGC
return double probGC
*/
double DNAstats::getProbGC(){
  return probGC;
}

/*
setter method for variable probGC
*/
void DNAstats::setProbGC(const double& pgc){
  probGC = pgc;
}

/*
getter method for variable probGT
return double probGT
*/
double DNAstats::getProbGT(){
  return probGT;
}

/*
setter method for variable probGT
*/
void DNAstats::setProbGT(const double& pgt){
  probGT = pgt;
}

/*
getter method for variable probGG
return double probGG
*/
double DNAstats::getProbGG(){
  return probGG;
}

/*
setter method for variable probGG
*/
void DNAstats::setProbGG(const double& pgg){
  probGG = pgg;
}

/*
getter method for variable probC
return double probC
*/
double DNAstats::getProbC(){
  return probC;
}

/*
setter method for variable probC
*/
void DNAstats::setProbC(const double& pc){
  probC = pc;
}

/*
getter method for variable Gaussian
return double Gaussian
*/
double DNAstats::getGaussian(){
  return standardGaussian;
}

/*
setter method for variable standardGaussian
*/
void DNAstats::setGaussian(const double& g){
  standardGaussian = g;
}

/*
getter method for variable probCA
return double probCA
*/
double DNAstats::getProbCA(){
  return probCA;
}

/*
setter method for variable probCA
*/
void DNAstats::setProbCA(const double& pca){
  probCA = pca;
}

/*
getter method for variable probCG
return double probCG
*/
double DNAstats::getProbCG(){
  return probCG;
}

/*
setter method for variable probCG
*/
void DNAstats::setProbCG(const double& pcg){
  probCG = pcg;
}

/*
getter method for variable probCC
return double probCC
*/
double DNAstats::getProbCC(){
  return probCC;
}

/*
setter method for variable probCC
*/
void DNAstats::setProbCC(const double& pcc){
  probCC = pcc;
}

/*
getter method for variable probCT
return double probCT
*/
double DNAstats::getProbCT(){
  return probCT;
}

/*
setter method for variable probCT
*/
void DNAstats::setProbCT(const double& pct){
  probCT = pct;
}

/*
getter method for variable probT
return double probT
*/
double DNAstats::getProbT(){
  return probT;
}

/*
setter method for variable probT
*/
void DNAstats::setProbT(const double& pt){
  probT = pt;
}

/*
getter method for variable probTA
return double probTA
*/
double DNAstats::getProbTA(){
  return probTA;
}

/*
setter method for variable probTA
*/
void DNAstats::setProbTA(const double& pta){
  probTA = pta;
}

/*
getter method for variable probTG
return double probTG
*/
double DNAstats::getProbTG(){
  return probTG;
}

/*
setter method for variable probTG
*/
void DNAstats::setProbTG(const double& ptg){
  probTG = ptg;
}

/*
getter method for variable probTT
return double probTT
*/
double DNAstats::getProbTT(){
  return probTT;
}

/*
setter method for variable probT
*/
void DNAstats::setProbTT(const double& ptt){
  probTT = ptt;
}

/*
getter method for variable probTC
return double probTC
*/
double DNAstats::getProbTC(){
  return probTC;
}

/*
setter method for variable probTC
*/
void DNAstats::setProbTC(const double& ptc){
  probTC = ptc;
}

/*
This void function calculates the probability of all Nucleotides,
pairs of nucleotides, as well as sets the values of private ints:
adenine, guanine, thymine, and cytosine
*/
void DNAstats::setAllProb(const string& s,const int& sum){
  char a;
  char b;
  int tA = 0; int tG = 0; int tC = 0; int tT = 0;
  int tAA = 0; int tAG = 0; int tAC = 0; int tAT = 0;
  int tCA = 0; int tCG = 0; int tCC = 0; int tCT = 0;
  int tGA = 0; int tGG = 0; int tGC = 0; int tGT = 0;
  int tTA = 0; int tTG = 0; int tTC = 0; int tTT = 0;

  for(int i = 0; i < s.length()-1; i++){
    a = s[i];
    b = s[i+1];

    if(a == 'A'){
      tA++;
      if(b == 'C'){
        tAC++;
      }
      if(b == 'G'){
        tAG++;
      }
      if(b == 'A'){
        tAA++;
      }
      if(b == 'T'){
        tAT++;
      }
    }
    else if(a == 'C'){
      tC++;
      if(b == 'C'){
          tCC++;
      }
      if(b == 'G'){
          tCG++;
      }
      if(b == 'A'){
          tCA++;
      }
      if(b == 'T'){
          tCT++;
      }
    }
    else if(a == 'T'){
      tT++;
      if(b == 'C'){
        tTC++;
      }
      if(b == 'G'){
        tTG++;
      }
      if(b == 'A'){
        tTA++;
      }
      if(b == 'T'){
        tTT++;
      }
    }
    else if(a == 'G'){
      tG++;
      if(b == 'C'){
        tGC++;
      }
      if(b == 'G'){
        tGG++;
      }
      if(b == 'A'){
        tGA++;
      }
      if(b == 'T'){
        tGT++;
      }
    }
  }
  if(b == 'A'){
    tA++;
  }
  if(b == 'C'){
    tC++;
  }
  if(b == 'G'){
    tG++;
  }
  if(b == 'T'){
    tT++;
  }

    setAdenine(tA);
    setThymine(tT);
    setGuanine(tG);
    setCytosine(tC);

    setProbA(setProbability(getSum(),getAdenine()));
    setProbG(setProbability(getSum(),getGuanine()));
    setProbC(setProbability(getSum(),getCytosine()));
    setProbT(setProbability(getSum(),getThymine()));

    setProbAA(setProbability(getSum(),tAA));
    setProbAC(setProbability(getSum(),tAC));
    setProbAG(setProbability(getSum(),tAG));
    setProbAT(setProbability(getSum(),tAT));

    setProbCA(setProbability(getSum(),tCA));
    setProbCC(setProbability(getSum(),tCC));
    setProbCG(setProbability(getSum(),tCG));
    setProbCT(setProbability(getSum(),tCT));

    setProbGA(setProbability(getSum(),tGA));
    setProbGC(setProbability(getSum(),tGC));
    setProbGG(setProbability(getSum(),tGG));
    setProbGT(setProbability(getSum(),tGT));

    setProbTA(setProbability(getSum(),tTA));
    setProbTC(setProbability(getSum(),tTC));
    setProbTG(setProbability(getSum(),tTG));
    setProbTT(setProbability(getSum(),tTT));
    setProbA(setProbability(getSum(),getAdenine()));
  }

double DNAstats::setProbability(int total,int lucky){
  double rdub = (double)lucky/total;
  return rdub;
}

int DNAstats::amountOfChar(const string& s, char a){
  int counter = 0;
  for(int i = 0; i < s.length();++i){
    if(s[i] == a){
      counter++;
    }
  }
  return counter-2;
}

string DNAstats::cleanLines(string& line){
  string newline = "";
  for(int i = 0; i < line.length(); i++){
    newline += toupper(line[i]);
  }
  string rline = "";
  for(int i = 0; i < newline.length(); i++){
    if(newline[i] == ' ' || newline[i] == 'G' || newline[i] == 'C' || newline[i] == 'T' || newline[i] == 'A'){
        rline = rline + newline[i];
    }
  }
  return rline;
}

void DNAstats::setUpVariance(const string& s){
  int j = 0;
  string ns = " " + s;
  string tmp = "";
  string lsizes = "";
  for(int i = 0; i < s.length(); i++){
    if((s[i] == ' ')&&(s[i-1] == 'A' || s[i-1] == 'G' || s[i-1] == 'C' || s[i] == 'T')){
      tmp = s.substr(j,(i-j));
      j = i;
      i++;
      int size = tmp.length();
      calcVariance(size,getMean());
    }
  }
}

void DNAstats::calcVariance(int& size, const double& mean){
  double vartmp;
  double prevVar = getVariance();
  if(counter == 0){
    setCounter(1);
    vartmp = (double)((size - mean) * (size - mean));
  }
  else{
    size--;
    vartmp = (double)((size - mean) * (size - mean));
  }
  setVariance(prevVar+vartmp);
}

void DNAstats::calcStandardGaussian(const double& mean, const double& variance){
  //std::uniform_real_distribution<double> dis(0.0,1.0);
  double a = (double)(rand()) / RAND_MAX;
  double b = (double)(rand()) / RAND_MAX;
  double c = sqrt(-2*log(a)) * cos(2*(M_PI)*b);
  double d = (variance*c + mean);
  setGaussian(d);
}

string DNAstats::toString(){
  string r = "";
  return "Sum: " + to_string(getSum()) + "\r\n" +
         "Mean: " + to_string(getMean()) + "\r\n" +
         "Variance: " + to_string(getVariance()) + "\r\n" +
         "Standard Deviation: " + to_string(getStandardDev()) + "\r\n" +
         "---------------------------------------------------------" + "\r\n" +
         "Amount of Adenine: " + to_string(getAdenine()) + "\r\n" +
         "Amount of Guanine: " + to_string(getGuanine()) + "\r\n" +
         "Amount of Thymine: " + to_string(getThymine()) + "\r\n" +
         "Amount of Cytosine: " + to_string(getCytosine()) + "\r\n" +
         "---------------------------------------------------------" + "\r\n" +
         "---------------------------------------------------------" + "\r\n" +
         "Probability (Out of 1):" + "\r\n" +
         "A Probability = " + to_string(getProbA()) + "\r\n" +
         "AA Probability = " + to_string(getProbAA()) + "\r\n" +
         "AC Probability = " + to_string(getProbAC()) + "\r\n" +
         "AG Probability = " + to_string(getProbAG()) + "\r\n" +
         "AT Probability = " + to_string(getProbAT()) + "\r\n" + "\r\n" +
         "C Probability = " + to_string(getProbC()) + "\r\n" +
         "CA Probability = " + to_string(getProbCA()) + "\r\n" +
         "CC Probability = " + to_string(getProbCC()) + "\r\n" +
         "CG Probability = " + to_string(getProbCG()) + "\r\n" +
         "CT Probability = " + to_string(getProbCT()) + "\r\n" + "\r\n" +
         "G Probability = " + to_string(getProbG()) + "\r\n"
         "GA Probability = " + to_string(getProbGA()) + "\r\n" +
         "GC Probability = " + to_string(getProbGC()) + "\r\n" +
         "GG Probability = " + to_string(getProbGG()) + "\r\n" +
         "GT Probability = " + to_string(getProbGT()) + "\r\n" + "\r\n" +
         "T Probability = " + to_string(getProbT()) + "\r\n"
         "TA Probability = " + to_string(getProbTA()) + "\r\n" +
         "TC Probability = " + to_string(getProbTC()) + "\r\n" +
         "TG Probability = " + to_string(getProbTG()) + "\r\n" +
         "TT Probability = " + to_string(getProbTT()) + "\r\n" +
         "GAUSSIAN  = " + "Sample value  "+ to_string(getGaussian()) + "\r\n";
}

string DNAstats::chooseSequenceNucleotide(const int& n){
  int knowntotalProb = 0;
  if(n == 0){
    knowntotalProb = (int)(getProbA()*100) + (int)(getProbG()*100) + (int)(getProbC()*100) + (int)(getProbT()*100);
  }
  else{
    knowntotalProb = (int)(getProbA()*100) + (int)(getProbAA()*100) + (int)(getProbAC()*100) + (int)(getProbAG()*100)
    + (int)(getProbAT()*100) + (int)(getProbG()*100) + (int)(getProbGA()*100) + (int)(getProbGC()*100) + (int)(getProbGG()*100)
    + (int)(getProbGT()*100) + (int)(getProbC()*100) + (int)(getProbCA()*100) + (int)(getProbCC()*100) + (int)(getProbCG()*100)
    + (int)(getProbCT()*100) + (int)(getProbT()*100) + (int)(getProbTA()*100) + (int)(getProbTC()*100) + (int)(getProbTG()*100) + (int)(getProbTT()*100);
  }
  int totalProb = 0;
  int rnum = rand() % knowntotalProb;
  rnum++;
  if(n==0){
    totalProb += (int)(getProbA()*100);
    if(rnum < totalProb){
      return "A";
    }
    totalProb += (int)(getProbC()*100);
    if(rnum < totalProb){
      return "C";
    }
    totalProb += (int)(getProbT()*100);
    if(rnum < totalProb){
      return "T";
    }
    totalProb += (int)(getProbG()*100);
    if(rnum < totalProb){
      return "G";
    }
  }
  else{
    totalProb += (int)(getProbA()*100);
    if(rnum < totalProb){
      return "A";
    }
    totalProb += (int)(getProbAA()*100);
    if(rnum < totalProb){
      return "AA";
    }
    totalProb += (int)(getProbAC()*100);
    if(rnum < totalProb){
      return "AC";
    }
    totalProb += (int)(getProbAG()*100);
    if(rnum < totalProb){
      return "AG";
    }
    totalProb += (int)(getProbAT()*100);
    if(rnum < totalProb){
      return "AT";
    }
    totalProb += (int)(getProbC()*100);
    if(rnum < totalProb){
      return "C";
    }
    totalProb += (int)(getProbCA()*100);
    if(rnum < totalProb){
      return "CA";
    }
    totalProb += (int)(getProbCC()*100);
    if(rnum < totalProb){
      return "CC";
    }
    totalProb += (int)(getProbCG()*100);
    if(rnum < totalProb){
      return "CG";
    }
    totalProb += (int)(getProbCT()*100);
    if(rnum < totalProb){
      return "CT";
    }
    totalProb += (int)(getProbG()*100);
    if(rnum < totalProb){
      return "G";
    }
    totalProb += (int)(getProbGA()*100);
    if(rnum < totalProb){
      return "GA";
    }
    totalProb += (int)(getProbGC()*100);
    if(rnum < totalProb){
      return "GC";
    }
    totalProb += (int)(getProbGG()*100);
    if(rnum < totalProb){
      return "GG";
    }
    totalProb += (int)(getProbGT()*100);
    if(rnum < totalProb){
      return "GT";
    }
    totalProb += (int)(getProbT()*100);
    if(rnum < totalProb){
      return "T";
    }
    totalProb += (int)(getProbTA()*100);
    if(rnum < totalProb){
      return "TA";
    }
    totalProb += (int)(getProbTC()*100);
    if(rnum < totalProb){
      return "TC";
    }
    totalProb += (int)(getProbTG()*100);
    if(rnum < totalProb){
      return "TG";
    }
    totalProb += (int)(getProbTT()*100);
    if(rnum < totalProb){
      return "TT";
    }
    totalProb += (int)(getProbT()*100);
    return "FAIL";
}
}
//i have to check if it is ever < the value of the variable i make.

string DNAstats::makeTwinSequence(){
  calcStandardGaussian(getMean(), getVariance());
  double proxyGaus = getGaussian();
  int proxyGausInt = getGaussian();
  string pgstring = to_string(proxyGausInt);
  int modifier = 1;
  for(int i = 1; i < pgstring.length();i++){
    modifier = modifier*10;
  }
  if((proxyGausInt % modifier) < 5){
    proxyGausInt = proxyGausInt + 0;
  }
  else{
    proxyGausInt = proxyGausInt +1;
  }
  string rstr = "";
  for(int i = 0; i < proxyGausInt; i++){
    calcStandardGaussian(getMean(), getVariance());
    rstr+= chooseSequenceNucleotide(i);
  }

  return rstr;
}

/*
Sends all the information into a file named "eneadodi.out"
*/
void DNAstats::toFile(){
  //inputs the statistics
  printf(toString().c_str());
  ofstream outfile("eneadodi.txt");
  if(outfile.is_open()){
    outfile << "helllloooo";
    outfile << "Name: Enea Dodi" << "\r\n" << "ID: 2296306" << "\r\n" << "Date: 9/13/2018" << "\r\n"
      << "Assignment: Assignment1" << "\r\n" << toString() <<"\r\n";
    string seqline = makeTwinSequence();
    for(int i = 0; i < 1000; i++){
      outfile << seqline <<"\r\n";
      seqline = makeTwinSequence();
    }

    outfile.flush();
    outfile.close();
  }

}
