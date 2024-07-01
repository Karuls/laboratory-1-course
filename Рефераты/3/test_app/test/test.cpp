
#include <iostream>
using namespace std;
struct node
{
    int elem;
    node* sled;
    node* pred;
};
class Spisok
{
private:
    node* nsp, * ksp;
public:
    Spisok() { nsp = ksp = NULL; }
    void Postroenie();
    void VyvodForward();
    void VyvodBack();
    void Ochistka();
    void InsAfter(int, node*);
    void InsBefore(int, node*);
    void Delete(node*);
    void DelAfter(node*);
    node* PoiskForward(int);
    node* PoiskBack(int);
    
};
void main()
{
    setlocale(0, "");
    Spisok A;
    node* Res;
    int el, el1;

    A.Postroenie();
    A.VyvodForward(); A.VyvodBack();

    cout << "Введите элемент звена, после которого";
    cout << "Осуществляется вставка: ";
    cin >> el;
    cout << "Введите элемент вставляемого звена";
    cin >> el1;
    Res = A.PoiskForward(el);
    if (Res != NULL) {
        A.InsAfter(el1, Res);
        A.VyvodForward(); A.VyvodBack();
    }
    else cout << "Звена с заданным элементом в списке нет!\n";

    cout << "Введиье элемет звена, перед которым";
    cout << "надо удалить";
    cin >> el;
    Res = A.PoiskForward(el);
    if (Res != NULL) {
        A.Delete(Res);
        A.VyvodForward(); A.VyvodBack();
    }
    else cout << "Звена с заданным элементом в списке нет!\n";

    A.Ochistka();

    cout << "\n";
    system("PAUSE");

}

void Spisok::Postroenie() 
    // Построение двунаправленного списка с заглавным звеном
    // nsp - указатель на начало списка
    // ksp - указатель на конец списка
{
    node* rsp;
    int el;

    nsp = new(node);
    rsp = nsp;
    (*nsp).pred = NULL;
    (*nsp).sled = NULL;
    cout << "Вводите последовательность: \n";
    cin >> el;
    while (el != 0) {
        (*rsp).sled = new(node);
        (*((*rsp).sled)).pred = rsp;
        rsp = (*rsp).sled;
        (*rsp).sled = NULL;
        (*rsp).elem = el;
        cin >> el;
    }

    ksp = rsp;

}

void Spisok::VyvodForward()
// Вывод содержимого двунаправленного списка от его начала
// nsp - указатель на начало списка
// ksp - указатель на конец списка
{
    node* rsp;
    rsp = (*nsp).sled;
    cout << "Двунаправленный список содержит: ";
    while (rsp != NULL)
    {
        cout << (*rsp).elem << " "; 
        rsp = (*rsp).sled;
    }
    cout << endl;

}

void Spisok::VyvodBack()
// Вывод содержимого двунаправленного списка от его конца
// nsp - указатель на начало списка
// ksp - указатель на конец списка
{
    node* rsp;
    rsp = ksp;
    cout << "Двунаправленнй список в обратном порядке:  \n";
    while ((*rsp).pred != NULL) {
        cout << (*rsp).elem << " ";
        rsp = (*rsp).pred;
    }
    cout << endl;
}

node* Spisok::PoiskForward(int el)
// Функция возвращает указатель на найденный элемент el
// Двунаправленного списка, заданного указателями nsp
// и ksp, и NULL, если элемент в списке не найден.

{
    node* q;
    node* Res;

    Res = NULL;
    q = (*nsp).sled;
    while (q != NULL && Res == NULL)
        if ((*q).elem == el) Res = q;
        else q = (*q).sled;
    return Res;
}

node * Spisok::PoiskBack(int el)
// Функция возвращает указатель на найденный элемент el
// Двунаправленного списка, заданного указателями nsp
// и ksp, и NULL, если элемент в списке не найден.
{
    node* q;
    node* Res;

    Res = NULL;
    q = ksp;
    while (q != NULL && Res == NULL)
        if ((*q).elem == el) Res = q;
        else q = (*q).pred;
    return Res;
}

void Spisok::InsAfter(int el, node* Res)
// Вставка звена с информационным полем el в 
// в Двунаправленный список, заданный указателями
// nsp и ksp, после звена, на которое указывает Res.
{
    node* q;

    q = new(node);
    (*q).elem = el;
    if ((*Res).sled != NULL)
    {
        (*q).sled = (*Res).sled;
        (*q).pred = (*(*Res).sled).pred;
        (*(*Res).sled).pred = q;
        (*Res).sled = q;
    }
    else
    {
        (*q).sled = NULL;
        (*q).pred = Res;
        ksp = q;
        (*Res).sled = q;
    }
}

void Spisok::InsBefore(int el, node* Res)
// Вставка звена с информационным полем el в 
// в Двунаправленный список, заданный указателями
// nsp и ksp, перед звеном, на которое указывает Res.
{
    node* q;
    q = new(node);
    (*q).elem = el;
    (*q).sled = (*(*Res).pred).sled;
    (*q).pred = (*Res).pred;
    (*(*Res).pred).sled = q;
    (*Res).pred = q;
}

void Spisok::Delete(node* Res)
// Удаление звена из двунаправленного списка.
// nsp - указатель на начало списка
// ksp - указатель на конец списка
// Res - указатель на удаляеиое звено

{
    if ((*Res).sled != NULL)
    {
        (*(*Res).sled).pred = (*Res).pred;
        (*(*Res).pred).sled = (*Res).sled;
            delete Res;
    }
    else
    {
        (*(*Res).pred).sled = NULL;
        ksp = (*ksp).pred;
        delete Res;
    }
}

void Spisok::DelAfter(node* Res)
// Удаление звена из двунаправленного списка.
// nsp - указатель на начало списка
// ksp - указатель на конец списка
// Res - указатель на звено, предыдущее удаляемому
{
    node* q;

    if ((*Res).sled != NULL)
    {
        (*(*Res).sled).pred = (*Res).pred;
        (*(*Res).pred).sled = (*Res).sled;
        delete Res;
    }
    else
    {
        (*(*Res).pred).sled = NULL;
        ksp = (*ksp).pred;
        delete Res;
    }

    void Spisok::DelAfter(node * Res)
        // Удаление звена из двунаправленного списка.
        // nsp - указатель на начало списка
        // ksp - указатель на конец списка
        // Res - указатель на звено, предыдущее удаляемому

    {
        node* q;

        if ((*Res).sled != NULL)
        {
            (*(*Res).sled).pred = (*Res).pred;
            (*(*Res).pred).sled = (*Res).sled;
            delete Res;
        }
        else
        {
            (*(*Res).pred).sled = NULL;
            ksp = (*ksp).pred;
            delete Res;
        }
    }

    void Spisok::Ochistka() 
      // Удаление двунаправленного списка из памяти
      // nsp - указатель на начало списка
      // ksp - указатель на конец списка
     
    {
        node* q, * q1;
        q = nsp; 
        q1 = (*q).sled;
        while(q1 != NULL)
        {
            q = q1;
            q1 = (*q1).sled;
            delete q;
        }
        delete nsp;
        nsp = ksp = NULL;
    }


