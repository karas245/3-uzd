#include "fun.h"

int main()
{
    int ii;
    cout << "Ar norite vykdyti programa(1) ar konteineriu analize(2)? "; cin >> ii;
    ifint(ii);
    vector<Studentas> studentai;

    if(ii==1)
    {

        int t;

        cout << "Ar norite duomenis skaityti is failo? (1 jei taip, 0 jei ne) ";cin >> t;
        ifint(t);
        if(t==1)
        {
            skaitymas(studentai);


        }

        else {
            int sk;
            cout << "Iveskite studentu skaiciu " ;
            cin >> sk; ifint(sk);
            cout << endl;
            studentai[sk];
            ivedimas(studentai,sk);
        }

        spaus(studentai);

    }
    else
    {

        cout << "1 strategija" << endl;
        {
            vector<Studentas> vargsiukai;
        vector<Studentas> kietekai;
        cout << "Naudojant vektorius" << endl;
        test(studentai,vargsiukai,kietekai);
        }

        cout << endl;
        cout << "2 strategija" << endl;
        {
            vector<Studentas> vargsiukai;
        cout << "Naudojant vektorius" << endl;
        test2(studentai,vargsiukai);
        }


    }




  return 0;
}
