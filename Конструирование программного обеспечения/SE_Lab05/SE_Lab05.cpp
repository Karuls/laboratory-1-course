    #include "stdafx.h"   
    #include <iostream>   
    #include <locale>
    #include"Dictionary.h"
    using namespace std;


    int main()
    {
#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY)> 1
#error "Only one THROW macro should be defined!"
#endif

        setlocale(0, "");
        try{

            Dictionary::Instance d1 = Dictionary::Create("Преподы", 7);
            Dictionary::Entry e1 = { 1,"Гладкий" },e2 = { 2,"Веялкин" },
            e3 = { 3,"Смелов" }, e4 = { 4,"Урбанович" }, e5 = { 5,"Пацей" }, e6 = { 6,"Север" }, e7 = { 7,"Мароз" };
            Dictionary::AddEntry(d1, e1);
            Dictionary::AddEntry(d1, e2);
            Dictionary::AddEntry(d1, e3);
            Dictionary::AddEntry(d1, e4);
           /* Dictionary::AddEntry(d1, e5);
            Dictionary::AddEntry(d1, e6);
            Dictionary::AddEntry(d1, e7);*/
            Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
            Dictionary::DelEntry(d1, 2);
            Dictionary::Entry newentry1{6,"Гурин"};
            Dictionary::UpEntry(d1, 2, newentry1);
            Dictionary::Print(d1);
            Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
            Dictionary::Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 3,"Сидоров" }
            , s4 = { 4,"Растаман" }, s5 = { 5,"Шурик" }, s6 = { 7,"Tyson" }, s7 = { 7,"Последний" };
            Dictionary::AddEntry(d2, s1);
            Dictionary::AddEntry(d2, s2);
            Dictionary::AddEntry(d2, s3);
            /*Dictionary::AddEntry(d2, s4);
            Dictionary::AddEntry(d2, s5);
            Dictionary::AddEntry(d2, s6);
            Dictionary::AddEntry(d2, s7);*/
          /*  Dictionary::Print(d2);*/
            Dictionary::Entry newentry3 = { 3,"Николаев" };
            Dictionary::UpEntry(d2, 3, newentry3);
            Dictionary::Print(d2);
            Delete(d1);
            Delete(d2);
        }
        catch (const char* e) {
            cout << e << endl;
        };
        system("pause");
        return 0;
    }

