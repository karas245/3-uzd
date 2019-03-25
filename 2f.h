//#ifndef 2F_H_INCLUDED
//#define 2F_H_INCLUDED

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

struct duomenys{
    string var;
    string pav;
    int n;
    vector<int> v;
    int egz;
    double gal;
};
template<typename container>
void generavimas();
void skaitymas(vector<duomenys> &info);
void ivedimas(vector<duomenys> &info, int sk );
void galutinisv(vector<duomenys> &info, int sk);
void galutinisv(deque<duomenys> &info, int sk);
void galutinism(vector<duomenys> &info, int sk);
void spausv(vector<duomenys> &info, int sk);
void spausv(deque<duomenys> &info, int sk);
void spausm(vector<duomenys> &info, int sk);
bool sortByName(const duomenys & stud1, const duomenys & stud2);
void spausv(list<duomenys> &info1, int sk);
void test(vector<duomenys> &info, int sk);
void test(deque<duomenys> &info, int sk);
double galutinis(duomenys student);
void test1(list<duomenys> &info1, duomenys student);
//#endif // 2F_H_INCLUDED
