//#ifndef 2F_H_INCLUDED
//#define 2F_H_INCLUDED

using std::string;
using std::vector;
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
void galutinism(vector<duomenys> &info, int sk);
void spausv(vector<duomenys> &info, int sk);
void spausm(vector<duomenys> &info, int sk);
void test(vector<duomenys> &info, int sk);

//#endif // 2F_H_INCLUDED
