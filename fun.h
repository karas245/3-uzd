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
void generavimas();
void skaitymas(vector<duomenys> &info);
void ivedimas(vector<duomenys> &info, int sk );
void galutinisv(vector<duomenys> &info, int sk);
void galutinisv(deque<duomenys> &info, int sk);
void galutinism(vector<duomenys> &info, int sk);
void spausv(vector<duomenys> &info, int sk);
void spausm(vector<duomenys> &info, int sk);
bool sortByName(const duomenys & stud1, const duomenys & stud2);
void ifint(int ii);
void print1(vector<duomenys> &vargsiukai, vector<duomenys> &kietekai);
void print1(deque<duomenys> &vargsiukai, deque<duomenys> &kietekai);
void print1(list<duomenys> &vargsiukai, list<duomenys> &kietekai);
void test(vector<duomenys> &info, vector<duomenys> &vargsiukai, vector<duomenys> &kietekai);
void test(deque<duomenys> &info, deque<duomenys> &vargsiukai, deque<duomenys> &kietekai);
double galutinis(duomenys student);
void test(list<duomenys> &info, duomenys student, list<duomenys> &vargsiukai, list<duomenys> &kietekai);
template< typename container>
bool ifvargsiukas(container &stud);
void print2(vector<duomenys> &info, vector<duomenys> &vargsiukai);
void print2(deque<duomenys> &info, deque<duomenys> &vargsiukai);
void print2(list<duomenys> &info, list<duomenys> &vargsiukai);
void test2(vector<duomenys> &info, vector<duomenys> &vargsiukai);
void test2(deque<duomenys> &info, deque<duomenys> &vargsiukai);
void test2(list<duomenys> &info, duomenys student, list<duomenys> &vargsiukai);

#endif // 2F_H_INCLUDED
