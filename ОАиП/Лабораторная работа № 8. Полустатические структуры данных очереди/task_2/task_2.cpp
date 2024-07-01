#include<iostream> 
using namespace std;
struct Number
{
    char symbol;
    Number* next;
};
bool flag = false;
void create(Number** begin, Number** end, char p); //формирование элементов очереди
void view(Number* begin);                        //вывод элементов очереди 
Number* found_element(Number* begin);               //определение минимального элемента 
void DeltoElement(Number** begin, Number** p);    //удаление до минимального элемента 
int main()
{
    setlocale(0, "");
    Number* begin = NULL, * end, * t;
    t = new Number; 
    char p;int size;
    cout << "\nEnter size queue=";  cin >> size;
    cout << "Enter number= ";       cin >> p;
    t->symbol = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    for (int i = 1; i < size; i++) //создание очереди
    {
        cout << "Enter number= ";    cin >> p;
        create(&begin, &end, p);
    }
    cout << "\nelements of queue: \n";
    if (begin == NULL)   //вывод на экран
        cout << "No elements" << endl;
    else
        view(begin);
        t = found_element(begin);    //определение минимального
    if (flag == true) {
        cout << "Символ найден" << endl;
        DeltoElement(&begin, &t);
    }
      

    cout << "\nnew Queue:\n";
    view(begin);
    return 0;
}
void create(Number** begin, Number** end, char p) //Формирование элементов очереди
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->symbol = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->symbol << endl;
            t = t->next;
        }
}
Number* found_element(Number* begin) //Определение минимального элемента
{
    Number* t = begin, * try_t = nullptr;
    char enter_symbol = ' ';

    cout << "Введите желаемый символ: ";
    cin >> enter_symbol;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        while (t != NULL)
        {
            if (t->symbol == enter_symbol)
            {
                try_t = t;
                flag = true;
                break;
            }
            t = t->next;
        }
    }
    return try_t;
}
void DeltoElement(Number** begin, Number** p) //Удаление до минимального элемента 
{
    Number* t;
    t = new Number;
    while (*begin != *p)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}
