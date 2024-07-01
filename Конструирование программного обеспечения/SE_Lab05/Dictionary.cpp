#include"Dictionary.h"

namespace Dictionary
{
Instance Create(const char name[DICTNAMEMAXSIZE], int size) {

    if (strlen(name) > DICTNAMEMAXSIZE) {
        throw THROW01;
    }

    if (size > DICTMAXSIZE) {
        throw THROW02;
    }

    Instance* dictionaryInstance = new Instance;

    strcpy_s(dictionaryInstance->name, name);

    dictionaryInstance->maxsize = size;
        
    dictionaryInstance->size = 0;

    dictionaryInstance->dictionary = new Entry[size];

    return* dictionaryInstance;
}

void AddEntry(Instance& d1, Entry e1) {
    for (int i = 0; i <= d1.size; i++) {
        if (d1.dictionary[i].id == e1.id) {
            throw THROW04;
        }
    }
   
    if (d1.size >= d1.maxsize) {
        throw THROW03;
    }

        strcpy_s(d1.dictionary[d1.size].name, e1.name);
        d1.dictionary[d1.size].id = e1.id;
        d1.size++;
 }


void DelEntry(Instance& d1, int id) {
    bool flag = false; int elment = 0;
    if (d1.size == 0 || d1.dictionary == nullptr) {
        return; // Нечего удалять
    }

    
    for (int i = 0; i <= d1.size; i++) {
        if (d1.dictionary[i].id == id) {
            d1.dictionary[i] = Entry();
            flag = true; 
            break;
        }   
        elment++;
    }

    if (flag == false) {
        throw THROW06;
    }

    for (int i = elment; i < d1.size - 1; ++i) {
        d1.dictionary[i] = d1.dictionary[i + 1];
    }

    d1.size--;
  }

Entry GetEntry(Instance d, int id) {
    bool flagG = false; int number = 0;
    for (int i = 0; i < d.size; i++) {
        if (d.dictionary[i].id == id) {
            flagG = true; number = i;
        }
    }
    
    if (flagG == false) {
        throw THROW05;
    }
    else {
        return d.dictionary[number];
    }
}

void UpEntry(Instance& d2, int id, Entry new_ed) {
    bool flag = false; int num = 0;
    if (id > d2.size) {
        throw THROW07;
    }
    for (int i = 0; i <= d2.size; i++)
    {
        if (i == id) {
            if (d2.dictionary[i].id == new_ed.id) {
                throw THROW08;
            }
            else {
                strcpy_s(d2.dictionary[i-1].name, new_ed.name);
                d2.dictionary[i-1].id = new_ed.id;
            }
        }

    }

}

void Delete(Instance& d) {
    if (d.dictionary != nullptr) {
        delete d.dictionary;
    }
    
}


void Print(Instance& d) {
    using namespace std;
    cout << "--------- " << d.name << " ---------" << endl;
    for (int i = 0; i < d.size; i++) {
        cout << "Индтефикатор: " << d.dictionary[i].id;
        cout << " Имя: "<< d.dictionary[i].name << endl;
    }

}


}

	
