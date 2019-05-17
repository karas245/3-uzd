#ifndef fun_H_INCLUDED
#define fun_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <math.h>
#include <sstream>
#include <chrono>
#include <list>
#include <deque>
#include <vector>
#include <random>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::setw;
using std::setprecision;
using std::left;
using std::fixed;
using std::ifstream;
using std::ofstream;
using std::list;
using std::deque;

class Asmuo{
protected:
    string var ="Vardas";
    string pav ="Pavarde";
public:
    Asmuo() {var ="Vardas";pav ="Pavarde";}
    ~Asmuo() {}
    virtual string setVar(string vardas) { return var=vardas;}
    virtual string setPav(string pavarde) {return pav=pavarde;}
    virtual string getVar() const {return var;}
    virtual string getPav() const {return pav;}

};

class Studentas : public Asmuo{
private:
    vector<int> v;
    int egz;
    double gal;
    double galv;
    double galm;
    int nvar;
    int npav;
public:
    Studentas();
    ~Studentas() {}
    vector<int> setV(vector<int>);
    int setEgz(int);
    double setGal();
    double setGalutinis(int);
    double setGalV();
    double setGalM();
    int setNvar(int);
    int setNpav(int);

    int getEgz() const {return egz;}
    double getGal() const {return gal;}
    vector<int> getV() const {return v;}
    int getNvar() const {return nvar;}
    int getNpav() const {return npav;}

    void sortClass(vector<Studentas>);
    bool operator>=(const Studentas& st) ;
    bool operator<(const Studentas& st) ;
    friend std::ostream & operator<<(std::ostream &out, const Studentas &st);
};



bool namecheck(const Studentas & s1, const Studentas & s2);
void sortByName(vector<Studentas> & studentai);
void ifint(int ii);
void generavimas();
void skaitymas(vector<Studentas> &studentai);
void ivedimas(vector<Studentas> &studentai, int sk );
void spaus(vector<Studentas> &studentai);
void print1(vector<Studentas> &vargsiukai, vector<Studentas> &kietekai);
void test(vector<Studentas> &studentai, vector<Studentas> &vargsiukai, vector<Studentas> &kietekai);
bool ifvargsiukas(const Studentas & stu);
void print2(vector<Studentas> &studentai, vector<Studentas> &vargsiukai);
void test2(vector<Studentas> &info, vector<Studentas> &vargsiukai);



#endif // 2F_H_INCLUDED
