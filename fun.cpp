#include "fun.h"

Studentas::Studentas()
{
    var="Vardas";
    pav="Pavarde";
    v.push_back(0);
    egz=0;
    gal=0;
    galv=0;
    galm=0;
}


double Studentas::setGalV()
{
    int sk=v.size();
    double vid=0;
    for(auto pa:v)
    {
        vid+=pa;

    }
    galv=0.4*(vid/sk) + 0.6*egz;
    v.clear();

}
double Studentas::setGalM()
{
    double med;

    int ska=v.size();
    sort(v.begin(), v.end());
    if(ska%2==0)
    {
        med=v[ska/2];
        //v.clear();
    }
    else med=(v[ska/2]+v[ska/2+1])/2;

    galm=0.4*med + 0.6*egz;
    v.clear();

}
double Studentas::setGal()
{
    if(galv>0) gal=galv;
    else gal=galm;
}
double Studentas::setGalutinis(int galutinis)
{
    gal=galutinis;
}
string Studentas::setVar(string vardas)
{
    var=vardas;
}
string Studentas::setPav(string pavarde)
{
    pav=pavarde;
}
vector<int> Studentas::setV(vector<int> nd)
{
    for(auto i:nd)
    {
        v.push_back(i);
    }
    //v=nd;
}
int Studentas::setEgz(int e)
{
    egz=e;
}
bool namecheck(const Studentas & s1, const Studentas & s2)
{
    return (s1.getVar() < s2.getVar());
}

void sortByName(vector<Studentas> & studentai)
{
    sort(studentai.begin(), studentai.end(), namecheck);
}
void ifint(int ii)
{
    while (!cin.good())
    {
        cout << endl << "Prasome ivesti skaiciu ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> ii;
    }
}
void generavimas()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> ran(1,10);

   string v="Vardas";
   string p="Pavarde";
   std::ofstream r("duomenys1.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=10;i++)
   {
       r << left << setw(20) << v+std::to_string(i) << left << setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        r << left << setw(7) << ran(rng);
       r << endl;
   }
   r.close();
   std::ofstream rr("duomenys2.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=100;i++)
   {
       rr << left << setw(20) << v+std::to_string(i) << left << setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        rr << left << setw(7) << ran(rng);
       rr << endl;
   }
   rr.close();
   std::ofstream rrr("duomenys3.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=1000;i++)
   {
       rrr << left << setw(20) << v+std::to_string(i) << left << setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        rrr << left << setw(7) << ran(rng);
       rrr << endl;
   }
   rrr.close();
   std::ofstream fr("duomenys4.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=10000;i++)
   {
       fr << left << setw(20) << v+std::to_string(i) << left << std::setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        fr << left << setw(7) << ran(rng);
       fr << endl;
   }
   fr.close();
   std::ofstream frr("duomenys5.txt");
   r << left << setw(20) << "Vardas" << left << setw(30) << "Pavarde" << left << setw(7) << "ND1" << left << setw(7) << "ND2" << left << setw(7) << "ND3" << left << setw(7) << "ND4" << left << setw(7) << "ND5" << endl;
   for(int i=1;i<=100000;i++)
   {
       frr << left << setw(20) << v+std::to_string(i) << left << setw(30) << p+std::to_string(i) ;
       for(int j=0;j<5;j++)
        frr << left << setw(7) << ran(rng);
       frr << endl;
   }
   frr.close();

}
void skaitymas(vector<Studentas> &studentai)
{

    generavimas();
    int x=0;
    string duom;
    cout << "Kuri duomenu faila norite nuskaityti? [1;5] : "; cin >> x; ifint(x);
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
    Studentas stud;
    string line;
    int  grade;
    string vardas, pavarde;
    int e;
    vector<int> nd;
    std::getline(fd, line);
    int y;
    cout << "Galutinio balo skaiciavimui naudoti vidurki(1) ar mediana(2)? ";cin >> y; ifint(y);
    if(x==1)
    while (std::getline(fd, line)) {
        std::istringstream reading(line);
        reading >> vardas;
        reading >> pavarde;
        while (reading) {
            reading >> grade;
            nd.push_back(grade);
        }
        e = nd.back();
        nd.pop_back();

        stud.setVar(vardas);
    stud.setPav(pavarde);
    stud.setV(nd);
    stud.setEgz(e);
    if(y==1)
    stud.setGalV();
    else stud.setGalM();
    studentai.push_back(stud);
    nd.clear();
    }
}
void ivedimas(vector<Studentas> &studentai, int sk )
{
    //int sk=studentai.size();
    Studentas stud;
    string vardas, pavarde;
    int e;
    vector<int> nd;
    int x;
    cout << "Galutinio balo skaiciavimui naudoti vidurki(1) ar mediana(2)? ";cin >> x; ifint(x);

    for(int i=0;i<sk;i++)
    {
        cout << "Iveskite varda ";cin >> vardas; cout << endl;
        cout << "Iveskite pavarde ";cin >> pavarde; cout << endl;
        int a,y;
        cout << "Ar norite pazymius generuoti atsitiktinai?( 1 jei taip, 0 jei ne) ";cin>>y;
        int n;
        if(y==0)
        {
            cout << "Ar pazymiu skaicius yra zinomas (1 jei taip, 0 jei ne) "; cin >> a; ifint(a);
            if(a==1)
            {

                cout << "Iveskite pazymiu skaiciu "; cin >> n; ifint(n); cout << endl;
                cout << "Iveskite pazymius " << endl;
                for(int j=0;j<n;j++)
                {
                    int p;
                    cin >> p;
                    ifint(p);
                    nd.push_back(p);
                }
            }
            else if(a==0)
            {
                cout << "Iveskite pazymi " << endl;
                int p;
                cin >> p;
                ifint(p);
                nd.push_back(p);
                for(;;)
                {
                    int b;
                    cout << "Ar vesite dar viena pazymi? (1 jei taip, 0 jei ne) " << endl;
                    cin >> b;
                    ifint(b);
                    if(b==1)
                    {
                        cout << "Iveskite pazymi " << endl;
                        int p;
                        cin >> p;
                        ifint(p);
                        nd.push_back(p);
                    }
                    else break;
                }
            }
        }
        else
        {
            cout << "Iveskite pazymiu skaiciu ";cin >> n; ifint(n);
            for(int j=0;j<n;j++)
                nd.push_back(rand()%10+1 );
        }
        cout << "Iveskite egzamino rezultata ";cin >> e;ifint(e);cout << endl;
        stud.setVar(vardas);
        stud.setPav(pavarde);
        stud.setV(nd);
        stud.setEgz(e);
        if(x==1)
        stud.setGalV();
        else stud.setGalM();
        studentai.push_back(stud);
        nd.clear();
    }
}


void spaus(vector<Studentas> &studentai)
{
    int didv=1, didp=1;
    for(auto stud: studentai)
    {
        if(stud.getVar().size()>didv)
            didv=stud.getVar().size();

        if(stud.getPav().size()>didp)
            didv=stud.getPav().size();
    }
    sortByName(studentai);


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

    for(auto &stud:studentai)
    {
        stud.setGal();
        if(stud.getGal()>=5)
        fr << setw(didv+9) << left << stud.getVar() << setw(didp+15) << left << stud.getPav() << setw(20) << left << fixed << setprecision(3) << stud.getGal() << endl;
        else frr << setw(didv+9) << left << stud.getVar() << setw(didp+15) << left << stud.getPav() << setw(20) << left << fixed << setprecision(3) << stud.getGal() << endl;
    }
    fr.close();
    frr.close();

}


void print1(vector<Studentas> &vargsiukai, vector<Studentas> &kietekai)
{
    int didv=1, didp=1;
    for(auto varg: vargsiukai)
    {
        if(varg.getVar().size()>didv)
            didv=varg.getVar().size();

        if(varg.getPav().size()>didp)
            didv=varg.getPav().size();
    }
    for(auto kiet: kietekai)
    {
        if(kiet.getVar().size()>didv)
            didv=kiet.getVar().size();

        if(kiet.getPav().size()>didp)
            didv=kiet.getPav().size();
    }
    sortByName(kietekai);
    sortByName(vargsiukai);

    ofstream fr("kietekai.txt");
    ofstream frr("vargsiukai.txt");

    fr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    frr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        fr <<"-";
    fr << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        frr <<"-";
    frr << endl;

    for(auto i:kietekai)
    {
        fr << setw(didv+9) << left << i.getVar() << setw(didp+15) << left << i.getPav() << setw(20) << left << fixed << setprecision(3) << i.getGal() << endl;
    }
    for(auto i:vargsiukai)
    {
        frr << setw(didv+9) << left << i.getVar() << setw(didp+15) << left << i.getPav() << setw(20) << left << fixed << setprecision(3) << i.getGal() << endl;

    }
    fr.close();
    frr.close();
}

void test(vector<Studentas> &studentai, vector<Studentas> &vargsiukai, vector<Studentas> &kietekai)
{
    auto start = std::chrono::system_clock::now();
    generavimas();
    string duom[5]={"duomenys1.txt", "duomenys2.txt", "duomenys3.txt", "duomenys4.txt", "duomenys5.txt"};
    for(int i=3;i<5;i++)
    {

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

    Studentas stud;
    string line;
    int  grade;
    string vardas, pavarde;
    int e;
    vector<int> nd;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        std::istringstream reading(line);
        reading >> vardas;
        reading >> pavarde;
        while (reading) {
            reading >> grade;
            nd.push_back(grade);
        }
        e = nd.back();
        nd.pop_back();

        stud.setVar(vardas);
        stud.setPav(pavarde);
        stud.setV(nd);
        stud.setEgz(e);
        stud.setGalV();

        studentai.push_back(stud);
        nd.clear();
    }

    for(auto &stu:studentai)
    {
        stu.setGal();

    }
    int galutinis;
        for(auto &stu: studentai)
        {
            if(stu.getGal()>=5)
            {
                vardas=stu.getVar();
                pavarde=stu.getPav();
                galutinis=stu.getGal();
                stud.setVar(vardas);
                stud.setPav(pavarde);
                stud.setGalutinis(galutinis);
                kietekai.push_back(stud);

            }

            else if(stu.getGal()<5)
            {
                vardas=stu.getVar();
                pavarde=stu.getPav();
                galutinis=stu.getGal();
                stud.setVar(vardas);
                stud.setPav(pavarde);
                stud.setGalutinis(galutinis);
                vargsiukai.push_back(stud);
            }


        }
        print1(vargsiukai,kietekai);
        studentai.clear();
        vargsiukai.clear();
        kietekai.clear();

    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Programa uztruko : " << elapsed_seconds.count() << " sekundziu\n";

}

bool ifvargsiukas(const Studentas & stu)
{
    if(stu.getGal()>=5)
        return true;
    else return false;
}
void print2(vector<Studentas> &studentai, vector<Studentas> &vargsiukai)
{
    int didv=1, didp=1;
    for(auto varg: vargsiukai)
    {
        if(varg.getVar().size()>didv)
            didv=varg.getVar().size();

        if(varg.getPav().size()>didp)
            didv=varg.getPav().size();
    }
    for(auto stud: studentai)
    {
        if(stud.getVar().size()>didv)
            didv=stud.getVar().size();

        if(stud.getPav().size()>didp)
            didv=stud.getPav().size();
    }
    sortByName(studentai);
    sortByName(vargsiukai);

    ofstream fr("studentai.txt");
    ofstream frr("vargsiukai.txt");

    fr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    frr << setw(didv+9) << left << "Vardas" << setw(didp+15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        fr <<"-";
    fr << endl;
    for(int i=0;i<didv+didp+9+15+20;i++)
        frr <<"-";
    frr << endl;

    for(auto i:studentai)
    {
        fr << setw(didv+9) << left << i.getVar() << setw(didp+15) << left << i.getPav() << setw(20) << left << fixed << setprecision(3) << i.getGal() << endl;
    }
    for(auto i:vargsiukai)
    {
        frr << setw(didv+9) << left << i.getVar() << setw(didp+15) << left << i.getPav() << setw(20) << left << fixed << setprecision(3) << i.getGal() << endl;

    }
    fr.close();
    frr.close();
}

void test2(vector<Studentas> &studentai, vector<Studentas> &vargsiukai)
{
    auto start = std::chrono::system_clock::now();
    generavimas();

    string duom[5]={"duomenys1.txt", "duomenys2.txt", "duomenys3.txt", "duomenys4.txt", "duomenys5.txt"};
    for(int i=3;i<5;i++)
    {

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
    Studentas stud;
    string line;
    int  grade;
    string vardas, pavarde;
    int e;
    vector<int> nd;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        std::istringstream reading(line);
        reading >> vardas;
        reading >> pavarde;
        while (reading) {
            reading >> grade;
            nd.push_back(grade);
        }
        e = nd.back();
        nd.pop_back();

        stud.setVar(vardas);
        stud.setPav(pavarde);
        stud.setV(nd);
        stud.setEgz(e);
        stud.setGalV();
        studentai.push_back(stud);
        nd.clear();
    }

    for(auto &stu:studentai)
    {
        stu.setGal();
    }

    int sk=studentai.size();



        auto bound = std::stable_partition(studentai.begin(), studentai.end(),
                        [&](const auto& vec) { return ifvargsiukas(vec); });

        vargsiukai.insert(vargsiukai.end(), std::make_move_iterator(bound),
                  std::make_move_iterator(studentai.end()));

        studentai.erase(bound, studentai.end());



        print2(studentai,vargsiukai);
        studentai.clear();
        vargsiukai.clear();

    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Programa uztruko : " << elapsed_seconds.count() << " sekundziu\n";


}
