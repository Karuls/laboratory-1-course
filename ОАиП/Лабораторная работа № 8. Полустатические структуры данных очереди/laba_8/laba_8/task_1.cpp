#include<iostream> 
using namespace std;
struct Number
{
    int symbol;
    Number* next;
};
bool flag = false;
void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin);                        //вывод элементов очереди 
Number* found_element(Number* begin);               //определение минимального элемента 
void DeltoElement(Number** begin, Number** p, Number** end);    //удаление до минимального элемента 
int main()
{
    setlocale(0, "");
    Number* begin = NULL, * end, * t;
    t = new Number;
    int p; int size;
    cout << "Enter size queue = ";  cin >> size;
    cout << "Enter number = ";       cin >> p;
    t->symbol = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    for (int i = 1; i < size; i++) //создание очереди
    {
        cout << "Enter number = ";    cin >> p;
        create(&begin, &end, p);
    }
    cout << "\nelements of queue: \n";
    if (begin == NULL)   //вывод на экран
        cout << "No elements" << endl;
    else
        view(begin);
    t = found_element(begin);    //определение максимального
        DeltoElement(&begin, &t, &end);
    

    cout << "\nnew Queue:\n";
    view(begin);
    return 0;
}
void create(Number** begin, Number** end, int p) //Формирование элементов очереди
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
    Number* t = begin, * max = nullptr;
    int max_digit;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        max_digit = t->symbol;
        while (t != NULL)
        {

            if (t->symbol > max_digit)
            {
                max = t;
                max_digit = t->symbol;
            }
            t = t->next;
        }
    }
    return max;
}
void DeltoElement(Number** begin, Number** p, Number** end) //Сдвиг до максимального элемента 
{


    while (*begin != *p) {
     
    Number* t = new Number;
    t->next = NULL;

    t->symbol = (*begin)->symbol;

    (*end)->next = t;// добавление в конец
    *end = t;
    
    t = *begin;//удаление
     *begin = (*begin)->next;
     delete t;
        }

}
