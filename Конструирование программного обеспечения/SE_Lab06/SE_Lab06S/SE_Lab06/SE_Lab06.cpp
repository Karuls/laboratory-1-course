
#include <iostream>
#include <locale>
#include "Q:\VISUAL STUDIO\Конструирование программного обеспечения\SE_Lab06\SE_Lab06S\SE_Lab06L\Dictionary.h"
#pragma comment(lib, "Q:\\VISUAL STUDIO\\Конструирование программного обеспечения\\SE_Lab06\\SE_Lab06S\\x64\\Debug\\SE_Lab06L.lib")
using namespace Dictionary;
using namespace std;



int main()
{
#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY)> 1
#error "Only one THROW macro should be defined!"
#endif

    setlocale(0, "");
    try {

        Dictionary::Instance d1 = Dictionary::Create("Преподы", 7);
        Dictionary::Entry e1 = { 1,"Гладкий" }, e2 = { 2,"Веялкин" },
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
        Dictionary::Entry newentry1{ 6,"Гурин" };
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



//namespace Dictionary
//{
//    Instance Create(const char name[DICTNAMEMAXSIZE], int size) {
//
//        if (strlen(name) > DICTNAMEMAXSIZE) {
//            throw THROW01;
//        }
//
//        if (size > DICTMAXSIZE) {
//            throw THROW02;
//        }
//
//        Instance* dictionaryInstance = new Instance;
//
//        strcpy_s(dictionaryInstance->name, name);
//
//        dictionaryInstance->maxsize = size;
//
//        dictionaryInstance->size = 0;
//
//        dictionaryInstance->dictionary = new Entry[size];
//
//        return*dictionaryInstance;
//    }
//
//    void AddEntry(Instance& d1, Entry e1) {
//        for (int i = 0; i <= d1.size; i++) {
//            if (d1.dictionary[i].id == e1.id) {
//                throw THROW04;
//            }
//        }
//
//        if (d1.size >= d1.maxsize) {
//            throw THROW03;
//        }
//
//        strcpy_s(d1.dictionary[d1.size].name, e1.name);
//        d1.dictionary[d1.size].id = e1.id;
//        d1.size++;
//    }
//
//
//    void DelEntry(Instance& d1, int id) {
//        bool flag = false; int elment = 0;
//        if (d1.size == 0 || d1.dictionary == nullptr) {
//            return; // Нечего удалять
//        }
//
//
//        for (int i = 0; i <= d1.size; i++) {
//            if (d1.dictionary[i].id == id) {
//                d1.dictionary[i] = Entry();
//                flag = true;
//                break;
//            }
//            elment++;
//        }
//
//        if (flag == false) {
//            throw THROW06;
//        }
//
//        for (int i = elment; i < d1.size - 1; ++i) {
//            d1.dictionary[i] = d1.dictionary[i + 1];
//        }
//
//        d1.size--;
//    }
//
//    Entry GetEntry(Instance d, int id) {
//        bool flagG = false; int number = 0;
//        for (int i = 0; i < d.size; i++) {
//            if (d.dictionary[i].id == id) {
//                flagG = true; number = i;
//            }
//        }
//
//        if (flagG == false) {
//            throw THROW05;
//        }
//        else {
//            return d.dictionary[number];
//        }
//    }
//
//    void UpEntry(Instance& d2, int id, Entry new_ed) {
//        bool flag = false; int num = 0;
//        if (id > d2.size) {
//            throw THROW07;
//        }
//        for (int i = 0; i <= d2.size; i++)
//        {
//            if (i == id) {
//                if (d2.dictionary[i].id == new_ed.id) {
//                    throw THROW08;
//                }
//                else {
//                    strcpy_s(d2.dictionary[i - 1].name, new_ed.name);
//                    d2.dictionary[i - 1].id = new_ed.id;
//                }
//            }
//
//        }
//
//    }
//
//    void Delete(Instance& d) {
//        if (d.dictionary != nullptr) {
//            delete d.dictionary;
//        }
//
//    }
//
//
//    void Print(Instance& d) {
//        using namespace std;
//        cout << "--------- " << d.name << " ---------" << endl;
//        for (int i = 0; i < d.size; i++) {
//            cout << "Индтефикатор: " << d.dictionary[i].id;
//            cout << " Имя: " << d.dictionary[i].name << endl;
//        }
//
//    }
//
//
//}



