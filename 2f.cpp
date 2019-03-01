#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <math.h>
#include <sstream>
#include "2f.h"

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

void skaitymas(vector<duomenys> &info)
{
    ifstream fd("kursiokai.txt");
    try{
        if(!fd)
            throw 0;
        }
        catch (int x)
        {
            cout << "File failed to open" << endl;
            std::abort();
        }
    string line;
    int ind = 0, grade;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        std::istringstream reading(line);
        info.push_back(duomenys());
        reading >> info[ind].var;
        reading >> info[ind].pav;
        while (reading) {
            reading >> grade;
            info[ind].v.push_back(grade);
        }
        info[ind].egz = info[ind].v.back();
        info[ind].v.pop_back();


        ind++;
    }//cout << info.size() << endl;
}
void ivedimas(vector<duomenys> &info, int sk )
{

    for(int i=0;i<sk;i++)
    {
        cout << "Iveskite varda ";cin >> info[i].var; cout << endl;
        cout << "Iveskite pavarde ";cin >> info[i].pav; cout << endl;
        int a,y;
        cout << "Ar norite pazymius generuoti atsitiktinai?( 1 jei taip, 0 jei ne) ";cin>>y;
        if(y==0)
        {
            cout << "Ar pazymiu skaicius yra zinomas (1 jei taip, 0 jei ne) "; cin >> a;
            if(a==1)
            {
                cout << "Iveskite pazymiu skaiciu "; cin >> info[i].n; cout << endl;
                cout << "Iveskite pazymius " << endl;
                for(int j=0;j<info[i].n;j++)
                {
                    int p;
                    cin >> p;
                    info[i].v.push_back(p);
                }
            }
            else if(a==0)
            {
                cout << "Iveskite pazymi " << endl;
                int p;
                cin >> p;
                info[i].v.push_back(p);
                for(;;)
                {
                    int b;
                    cout << "Ar vesite dar viena pazymi? (1 jei taip, 0 jei ne) " << endl;
                    cin >> b;
                    if(b==1)
                    {
                        cout << "Iveskite pazymi " << endl;
                        int p;
                        cin >> p;
                        info[i].v.push_back(p);
                    }
                    else break;
                }
            }
        }
        else
        {
            cout << "Iveskite pazymiu skaiciu ";cin >> info[i].n;
            for(int j=0;j<info[i].n;j++)
                info[i].v.push_back(rand()%10+1 );
        }
        cout << "Iveskite egzamino rezultata ";cin >> info[i].egz;cout << endl;
    }
}

void galutinisv(vector<duomenys> &info, int sk)
{

    sk=info.size();
    for(int i=0;i<sk;i++)
    {
        double vid=0;
        int ska=info[i].v.size();
        for(int j=0;j<ska;j++)
        {
            vid+=info[i].v[j];

        }
        info[i].gal=0.4*(vid/ska) + 0.6*info[i].egz;
    }

}
void galutinism(vector<duomenys> &info, int sk)
{
    double med;

    for(int i=0;i<sk;i++)
    {
        int ska=info[i].v.size();
        sort(info[i].v.begin(), info[i].v.end());
        if(ska%2==0)
        {
            med=info[i].v[ska/2];
        }
        else med=(info[i].v[ska/2]+info[i].v[ska/2+1])/2;

        info[i].gal=0.4*med + 0.6*info[i].egz;
    }
}
void spausv(vector<duomenys> &info, int sk)
{
    int didv=info[0].var.size(), didp=info[0].pav.size();
    for(int i=0;i<sk;i++)
    {
        if(info[i].var.size()>didv)
            didv=info[i].var.size();

        if(info[i].pav.size()>didp)
            didv=info[i].pav.size();
    }
    sort(info.begin(), info.end(),
       [](duomenys s1, duomenys s2) { return s1.var < s2.var; });

    cout << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        cout <<"-";
    cout << endl;
    for(int i=0;i<sk;i++)
    {
        cout << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    }

}
void spausm(vector<duomenys> &info, int sk)
{
    int didv=info[0].var.size(), didp=info[0].pav.size();
    for(int i=0;i<sk;i++)
    {
        if(info[i].var.size()>didv)
            didv=info[i].var.size();

        if(info[i].pav.size()>didp)
            didv=info[i].pav.size();
    }
     sort(info.begin(), info.end(),
       [](duomenys s1, duomenys s2) { return s1.var < s2.var; });

    cout << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Med.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        cout <<"-";
    cout << endl;
    for(int i=0;i<sk;i++)
    {
        cout << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    }

}


