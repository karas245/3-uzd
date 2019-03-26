#include "fun.cpp"

int main()
{
    int ii;
    cout << "Ar norite vykdyti programa(1) ar konteineriu analize(2)? "; cin >> ii;
    ifint(ii);
    vector<duomenys> info;
    int sk;
    if(ii==1)
    {

        int t;

        cout << "Ar norite duomenis skaityti is failo? (1 jei taip, 0 jei ne) ";cin >> t;
        ifint(t);
        if(t==1)
        {
            skaitymas(info);
            sk=info.size();

        }

        else {
            cout << "Iveskite studentu skaiciu " ;
            cin >> sk; ifint(sk);
            cout << endl;
            info[sk];
            ivedimas(info,sk);
        }
        int x;
        cout << "Galutinio balo skaiciavimui naudoti vidurki(1) ar mediana(2)? ";cin >> x; ifint(x);
        if(x==1)
        {
            galutinisv(info,sk);
            spausv(info,sk);
        }
        else
        {
            galutinism(info,sk);
            spausm(info,sk);
        }

    }
    else
    {

        cout << "1 strategija" << endl;
        {
            vector<duomenys> vargsiukai;
        vector<duomenys> kietekai;
        cout << "Naudojant vektorius" << endl;
        test(info,vargsiukai,kietekai);
        }
        {
            cout << "Naudojant deque" << endl;
        deque<duomenys> info;
        deque<duomenys> vargsiukai;
        deque<duomenys> kietekai;
        test(info,vargsiukai, kietekai);
        }

        {
            duomenys student;
        cout << "Naudojant list" << endl;
        list<duomenys> info;
        list<duomenys> vargsiukai;
        list<duomenys> kietekai;
        test(info,student,vargsiukai,kietekai);
        }
        cout << endl;
        cout << "2 strategija" << endl;
        {
            vector<duomenys> vargsiukai;
        cout << "Naudojant vektorius" << endl;
        test2(info,vargsiukai);
        }
        {
            deque<duomenys> info;
            deque<duomenys> vargsiukai;
        cout << "Naudojant deque" << endl;
        test2(info,vargsiukai);
        }
        {
            duomenys student;
            list<duomenys> info;
            list<duomenys> vargsiukai;
            cout << "Naudojant list" << endl;
            test2(info,student,vargsiukai);
        }

    }




  return 0;
}
