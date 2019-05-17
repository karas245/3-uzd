#include "fun.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


struct StudentasTest : testing::Test {
    Studentas* vardas;
    Studentas* pavarde;
    Studentas* egz;
    StudentasTest() {
        vardas = new Studentas;
        pavarde = new Studentas;
        egz = new Studentas;
    }
    ~StudentasTest() {
        delete vardas;
        delete pavarde;
        delete egz;
    }
};
TEST_F(StudentasTest, StudentoVardas) {
    EXPECT_EQ("Vardas", vardas->getVar());
}
TEST_F(StudentasTest, StudentoPavarde) {
    EXPECT_EQ("Pavarde", pavarde->getPav());
}
TEST_F(StudentasTest, StudentoEgzaminas) {
    EXPECT_EQ(0, egz->getEgz());
}
int main(int argc, char** argv)
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
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();



  return 0;
}
