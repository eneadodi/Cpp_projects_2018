
#ifndef DNASTATS_H
#define DNASTATS_H

#include<cstdlib>
#include<ostream>
#include<fstream>
using namespace std;

class DNAstats {
public:
    DNAstats();
    DNAstats(DNAstats& orig);
    DNAstats(string& DNASequence);
    double getMean();
    void setMean(const double& m);
    int getCounter();
    void setCounter(const double& c);
    int getSum();
    void setSum(const int& s);
    double getVariance();
    void setVariance(const double& v);
    double getStandardDev();
    void setStandardDev(const double& sd);
    double getGaussian();
    void setGaussian(const double& g);
    int getAdenine();
    void setAdenine(const int& a);
    int getGuanine();
    void setGuanine(const int& g);
    int getThymine();
    void setThymine(const int& t);
    int getCytosine();
    void setCytosine(const int& a);
    double getProbA();
    void setProbA(const double& pa);
    double getProbAA();
    void setProbAA(const double& paa);
    double getProbAC();
    void setProbAC(const double& pac);
    double getProbAG();
    void setProbAG(const double& pag);
    double getProbAT();
    void setProbAT(const double& pat);
    double getProbG();
    void setProbG(const double& pg);
    double getProbGA();
    void setProbGA(const double& pga);
    double getProbGC();
    void setProbGC(const double& pgc);
    double getProbGG();
    void setProbGG(const double& pgg);
    double getProbGT();
    void setProbGT(const double& pgt);
    double getProbT();
    void setProbT(const double& pt);
    double getProbTA();
    void setProbTA(const double& pta);
    double getProbTC();
    void setProbTC(const double& ptc);
    double getProbTG();
    void setProbTG(const double& ptg);
    double getProbTT();
    void setProbTT(const double& ptt);
    double getProbC();
    void setProbC(const double& pc);
    double getProbCA();
    void setProbCA(const double& pca);
    double getProbCC();
    void setProbCC(const double& pcc);
    double getProbCG();
    void setProbCG(const double& pcg);
    double getProbCT();
    void setProbCT(const double& pct);
    int getTotalLines();
    void setTotalLines(int tl);

    void calcMean(const int& sum, const int& totalLines);
    void calcVariance(int& size, const double& mean);
    void calcStandardDev(const double& variance);
    void calcStandardGaussian(const double& mean, const double&variance);
    string cleanLines(string& line);
    int amountOfChar(const string& s, char a);
    void setAmountNucleotides(const string& s);
    double setProbability(int total,int lucky);
    void setAllProb(const string& s, const int& sum);
    void setUpVariance(const string& s);
    void toFile();
    string toString();
    //LAST FILE WOOHOO
    string makeTwinSequence();
    string chooseSequenceNucleotide(const int& n);


private:
    double standardGaussian;
    int totalLines;
    double mean;
    double counter;
    int sum;
    double variance;
    double standardDev;
    int adenine;
    int guanine;
    int thymine;
    int cytosine;
    double probA;
    double probG;
    double probT;
    double probC;
    double probAA;
    double probAC;
    double probAG;
    double probAT;
    double probCA;
    double probCC;
    double probCT;
    double probCG;
    double probTA;
    double probTT;
    double probTC;
    double probTG;
    double probGG;
    double probGC;
    double probGT;
    double probGA;

    ifstream DNAFile;
    ofstream reFile;

};

#endif
