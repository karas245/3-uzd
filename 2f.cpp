/*#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <math.h>
#include <sstream>
#include <chrono>*/
#include "2f.h"

/*using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::setw;
using std::setprecision;
using std::left;
using std::fixed;
using std::ifstream;
using std::ofstream;*/

//template <typename container >


void generavimas()
{
   string v="Vardas";
   string p="Pavarde";
   std::ofstream r("duomenys1.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=10;i++)
   {
       r << left << setw(20) << v+std::to_string(i) << left << setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        r << left << setw(7) << rand()%10+1;
       r << endl;
   }
   r.close();
   std::ofstream rr("duomenys2.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=100;i++)
   {
       rr << left << setw(20) << v+std::to_string(i) << left << setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        rr << left << setw(7) << rand()%10+1;
       rr << endl;
   }
   rr.close();
   std::ofstream rrr("duomenys3.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=1000;i++)
   {
       rrr << left << setw(20) << v+std::to_string(i) << left << setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        rrr << left << setw(7) << rand()%10+1;
       rrr << endl;
   }
   rrr.close();
   std::ofstream fr("duomenys4.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=10000;i++)
   {
       fr << left << setw(20) << v+std::to_string(i) << left << std::setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        fr << left << setw(7) << rand()%10+1;
       fr << endl;
   }
   fr.close();
   std::ofstream frr("duomenys5.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=100000;i++)
   {
       frr << left << setw(20) << v+std::to_string(i) << left << setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        frr << left << setw(7) << rand()%10+1;
       frr << endl;
   }
   frr.close();

}
void skaitymas(vector<duomenys> &info)
{
    //ifstream fd("kursiokai.txt");
    generavimas();
    int x=0;
    string duom;
    cout << "Kuri duomenu faila norite nuskaityti? [1;5] : "; cin >> x;
    if (x==1)
    duom="duomenys1.txt";
    else if (x==2)
    duom="duomenys2.txt";
    else if (x==3)
    duom="duomenys3.txt";
    else if (x==4)
    duom="duomenys4.txt";
    else if (x==5)
    duom="duomenys5.txt";
    ifstream fd(duom);
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
            info[i].v.clear();

        }
        info[i].gal=0.4*(vid/ska) + 0.6*info[i].egz;
    }

}
void galutinisv(deque<duomenys> &info, int sk)
{

    sk=info.size();
    for(int i=0;i<sk;i++)
    {
        double vid=0;
        int ska=info[i].v.size();
        for(int j=0;j<ska;j++)
        {
            vid+=info[i].v[j];
            info[i].v.clear();

        }
        info[i].gal=0.4*(vid/ska) + 0.6*info[i].egz;
    }

}
void galutinism(vector<duomenys> &info, int sk)
{
    double med;
    sk=info.size();
    for(int i=0;i<sk;i++)
    {
        int ska=info[i].v.size();
        sort(info[i].v.begin(), info[i].v.end());
        if(ska%2==0)
        {
            med=info[i].v[ska/2];
            info[i].v.clear();
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

       /*
    cout << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        cout <<"-";
    cout << endl;
    for(int i=0;i<sk;i++)
    {
        cout << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    } */
    ofstream fr("galvociai.txt");
    ofstream frr("vargsiukai.txt");

    fr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    frr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        fr <<"-";
    fr << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        frr <<"-";
    frr << endl;

    for(int i=0;i<sk;i++)
    {
        if(info[i].gal>=5)
        fr << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
        else frr << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    }
    fr.close();
    frr.close();

}
void spausv(deque<duomenys> &info, int sk)
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

       /*
    cout << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        cout <<"-";
    cout << endl;
    for(int i=0;i<sk;i++)
    {
        cout << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    } */
    ofstream fr("galvociai.txt");
    ofstream frr("vargsiukai.txt");

    fr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    frr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        fr <<"-";
    fr << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        frr <<"-";
    frr << endl;

    for(int i=0;i<sk;i++)
    {
        if(info[i].gal>=5)
        fr << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
        else frr << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    }
    fr.close();
    frr.close();

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
/*
    cout << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Med.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        cout <<"-";
    cout << endl;
    for(int i=0;i<sk;i++)
    {
        cout << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    }*/
    ofstream fr("galvociai.txt");
    ofstream frr("vargsiukai.txt");

    fr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    frr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        fr <<"-";
    fr << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        frr <<"-";
    frr << endl;

    for(int i=0;i<sk;i++)
    {
        if(info[i].gal>=5)
        fr << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
        else frr << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    }
    fr.close();
    frr.close();

}
bool sortByName(const duomenys & stud1, const duomenys & stud2)
{
    return (stud1.var < stud2.var) ||
           ((stud1.var == stud2.var) && (stud1.pav > stud2.pav));
}
void spausv(list<duomenys> &info, int sk)
{
    int didv=1, didp=1;
    for(auto in:info)
    {
        if(in.var.size()>didv)
            didv=in.var.size();

        if(in.pav.size()>didp)
            didv=in.pav.size();
    }
    /*sort(in.begin(), in.end(),
       [](duomenys s1, duomenys s2) { return s1.var < s2.var; });*/

       info.sort( sortByName);

       /*
    cout << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        cout <<"-";
    cout << endl;
    for(int i=0;i<sk;i++)
    {
        cout << setw(didv+9) << left << info[i].var << setw(didp+15) << left << info[i].pav << setw(20) << left << fixed << setprecision(3) << info[i].gal << endl;
    } */
    ofstream fr("galvociai.txt");
    ofstream frr("vargsiukai.txt");

    fr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    frr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        fr <<"-";
    fr << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        frr <<"-";
    frr << endl;

    for(auto in:info)
    {
        if(in.gal>=5)
        fr << setw(didv+9) << left << in.var << setw(didp+15) << left << in.pav << setw(20) << left << fixed << setprecision(3) << in.gal << endl;
        else frr << setw(didv+9) << left << in.var << setw(didp+15) << left << in.pav << setw(20) << left << fixed << setprecision(3) << in.gal << endl;
    }
    fr.close();
    frr.close();

}
void test(vector<duomenys> &info, int sk)
{
    //auto start = std::chrono::system_clock::now();
    generavimas();
    //auto end = std::chrono::system_clock::now();
    //std::chrono::duration<double> elapsed_seconds_g = end-start;

    //int x;
    //cout << "Galutinio balo skaiciavimui naudojamas vidurkis " << endl;//cin >> x;

    string duom[5]={"duomenys1.txt", "duomenys2.txt", "duomenys3.txt", "duomenys4.txt", "duomenys5.txt"};
    for(int i=0;i<5;i++)
    {
        auto start = std::chrono::system_clock::now();
        ifstream fd(duom[i]);
    try{
        if(!fd)
            throw 0;
        }
        catch (int x)
        {
            cout << "File failed to open" << endl;
            std::abort();
        }
    string line, text;
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
    }
    sk=info.size();

   //if(x==1)
    //{
        galutinisv(info,sk);
        auto end = std::chrono::system_clock::now();
        spausv(info,sk);
    //}
    /*else if(x==2)
    {
        galutinism(info,sk);
        spausm(info,sk);
    }*/

    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Programa uztruko su " << duom[i] << " : " << elapsed_seconds.count() << " sekundziu\n";
    }

}
void test(deque<duomenys> &info, int sk)
{
    //auto start = std::chrono::system_clock::now();
    generavimas();
    //auto end = std::chrono::system_clock::now();
    //std::chrono::duration<double> elapsed_seconds_g = end-start;

    //int x;
    //cout << "Galutinio balo skaiciavimui naudojamas vidurkis " << endl;//cin >> x;

    string duom[5]={"duomenys1.txt", "duomenys2.txt", "duomenys3.txt", "duomenys4.txt", "duomenys5.txt"};
    for(int i=0;i<5;i++)
    {
        auto start = std::chrono::system_clock::now();
        ifstream fd(duom[i]);
    try{
        if(!fd)
            throw 0;
        }
        catch (int x)
        {
            cout << "File failed to open" << endl;
            std::abort();
        }
    string line, text;
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
    }
    sk=info.size();

   //if(x==1)
    //{
        galutinisv(info,sk);
        auto end = std::chrono::system_clock::now();
        spausv(info,sk);
    //}
    /*else if(x==2)
    {
        galutinism(info,sk);
        spausm(info,sk);
    }*/

    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Programa uztruko su " << duom[i] << " : " << elapsed_seconds.count() << " sekundziu\n";
    }

}
//template < typename container >

double galutinis(duomenys student)
{
    int sk=student.v.size();
    double vid=0;
    double gal=0;
    for(int i=0;i<sk;i++)
    {
        vid+=student.v[i];

    }
    gal=0.4*(vid/sk) + 0.6*student.egz;
    return gal;
}

void test1(list<duomenys> &info1, duomenys student)
{
    //auto start = std::chrono::system_clock::now();
//    generavimas();
    //auto end = std::chrono::system_clock::now();
    //std::chrono::duration<double> elapsed_seconds_g = end-start;

    //int x;
    //cout << "Galutinio balo skaiciavimui naudojamas vidurkis " << endl;//cin >> x;

    string duom[5]={"duomenys1.txt", "duomenys2.txt", "duomenys3.txt", "duomenys4.txt", "duomenys5.txt"};
    //duomenys student;
    for(int i=0;i<5;i++)
    {
        auto start = std::chrono::system_clock::now();
        ifstream fd(duom[i]);
    try{
        if(!fd)
            throw 0;
        }
        catch (int x)
        {
            cout << "File failed to open" << endl;
            std::abort();
        }
    string line, text;
    int ind = 0, grade;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        std::istringstream reading(line);
        //info1.push_back(duomenys());
        reading >> student.var;
        reading >> student.pav;
        while (reading) {
            reading >> grade;
            student.v.push_back(grade);
        }
        student.egz = student.v.back();
        student.v.pop_back();
        student.gal=galutinis(student);
        student.v.clear();
        info1.push_back(student);
        ind++;
    }

//    sk=student.size();

   //if(x==1)
    //{

        auto end = std::chrono::system_clock::now();
        spausv(info1,ind);
    //}
    /*else if(x==2)
    {
        galutinism(info,sk);
        spausm(info,sk);
    }*/

    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Programa uztruko su " << duom[i] << " : " << elapsed_seconds.count() << " sekundziu\n";
    }

}


