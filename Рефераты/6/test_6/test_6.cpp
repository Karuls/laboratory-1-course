﻿#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
using namespace std; 

struct Uzel  // Объявление структуры для узла дерева
{
    char Key; // Символ.
    Uzel* Left; // Указатель на левое поддерево.
    Uzel* Right; // Указатель на правое поддерево.
};

struct zveno  // Объявление структуры для элемента стека.
{
    Uzel* Element; // Указатель на узел дерева.
    zveno* Sled; // Указатель на следующий элемент стека.
};

class Tree // Определение класса Tree.
{
private:
    Uzel* Root; // Указатель на корень дерева.
    zveno* Stack; // Указатель на вершину стека.
public:
    Tree(); // Конструктор класса Tree.
    void Udalenie(Uzel**); // Метод удаления элемента из стека.
    void V_stack(Uzel*); // Метод помещения элемента в стек.
    void PrintTree(Uzel*, int); // Метод для вывода дерева на экран.
    void Print_Tree_Left(Uzel*, int); // Метод для левостороннего обхода дерева.
    void Print_Tree_End(Uzel*, int); // Метод для концевого обхода дерева.
    void Print_Tree_Back(Uzel*, int); // Метод для обратного обхода дерева.
    Uzel* GetTree() { return Root; }; // Метод для получения указателя на корень дерева.
};


void Tree::V_stack(Uzel* Elem) // Определение метода V_stack.
{
    zveno* q = new (zveno); // Создание нового элемента стека.

    q->Element = Elem; // Присвоение переданного узла элементу стека.
    q->Sled = Stack; // Установка ссылки на следующий элемент стека.
    Stack = q; // Обновление указателя на вершину стека.
}

void Tree::Udalenie(Uzel** tmp) // Определение метода Udalenie.
{
    zveno* q; // Объявление указателя на элемент стека.

    if (Stack != NULL) // Проверка, не пуст ли стек.
    {
        (*tmp) = Stack->Element; // Присвоение указателю на переданный узел значения вершины стека.
        q = Stack; // Присвоение указателю q значения вершины стека.
        Stack = Stack->Sled; // Перемещение указателя на следующий элемент стека.
        delete q; // Освобождение памяти, занимаемой вершиной стека.
    }
}

void Tree::PrintTree(Uzel* w, int l) // Определение метода PrintTree.
// Вывод дерева на экран.
{
    if (w != NULL) // Проверка, не пусто ли дерево.
    {
        PrintTree(w->Right, l + 1); // Рекурсивный вызов PrintTree для правого поддерева.
        for (int i = 1; i <= l; i++) cout << "   "; // Вывод отступа для текущего узла.
        cout << w->Key << endl; // Вывод символа текущего узла.
        PrintTree(w->Left, l + 1); // Рекурсивный вызов PrintTree для левого поддерева.
    }
}

void Tree::Print_Tree_Left(Uzel* w, int l) // Определение метода Print_Tree_Left.
// Левосторонний обход бинарного дерева.
{
    if (w != NULL) // Проверка, не пусто ли дерево.
    {
        cout << w->Key << " "; // Вывод символа текущего узла.
        Print_Tree_Left(w->Left, l + 1); // Рекурсивный вызов Print_Tree_Left для левого поддерева.
        Print_Tree_Left(w->Right, l + 1); // Рекурсивный вызов Print_Tree_Left для правого поддерева.
    }
}

void Tree::Print_Tree_End(Uzel* w, int l) // Определение метода Print_Tree_End.
// Концевой обход бинарного дерева.
{
    if (w != NULL) // Проверка, не пусто ли дерево.
    {
        Print_Tree_End(w->Left, l + 1); // Рекурсивный вызов Print_Tree_End для левого поддерева.
        Print_Tree_End(w->Right, l + 1); // Рекурсивный вызов Print_Tree_End для правого поддерева.
        cout << w->Key << " "; // Вывод символа текущего узла.
    }
}

void Tree::Print_Tree_Back(Uzel* w, int l) // Определение метода Print_Tree_Back.
// Обратный обход бинарного дерева.
{
    if (w != NULL) // Проверка, не пусто ли дерево.
    {
        cout << "("; 
        Print_Tree_Back(w->Left, l + 1); // Рекурсивный вызов Print_Tree_Back для левого поддерева.
        cout << w->Key << " "; // Вывод символа текущего узла.
        Print_Tree_Back(w->Right, l + 1); // Рекурсивный вызов Print_Tree_Back для правого поддерева.
        cout << ")";
    }
}

Tree::Tree() // Определение конструктора класса Tree.
{
    Stack = NULL;  // Инициализация указателя на вершину стека как NULL
    // Формирование заглавного узла дерева
    Root = new (Uzel); // Выделение памяти под корневой узел
    Root->Right = NULL; // Установка правого поддерева корня как NULL
}

void main() // Основная функция программы.
{
    setlocale(LC_ALL, "Rus");
    char Formula_Post[30]; // Объявление массива для хранения постфиксной формы выражения
    char k; // Вспомогательная переменная
    Uzel* Ukazatel = NULL; // Объявление указателя на узел

    cout << "Введите формулу, записанную в постфиксной форме... \n";
    gets_s(Formula_Post); // Ввод формулы
    // Получили "перевертыш" слова Formula_Post
    _strrev(Formula_Post); // Реверс строки Formula_Post
    cout << "Приступим к построению дерева-формулы...\n";

    Tree A; // Создание объекта класса Tree.
    Uzel* Temp = A.GetTree(); // Получение указателя на корень дерева.
    // Формирование дерева постфиксной формы и вывод его на экран.
    for (int i = 0; i < strlen(Formula_Post); i++) // Цикл по символам постфиксной формы выражения.
    {
        k = Formula_Post[i]; // Присвоение k очередного символа формулы.
        // Переходим к анализу символа k.
        if (strchr("+-*/^", k) != NULL) // Если символ - операция.
        {
            if (Temp->Right == NULL) // Если у текущего узла нет правого поддерева.
            {
                // Резервирование места для вставляемого узла.
                Temp->Right = new (Uzel);
                // Установка указателя на вставляемый узел.
                Temp = Temp->Right;
                // Инициализация вставляемого узла.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                // Ссылка на предыдущий узел --> стек.
                A.V_stack(Temp);
            }
            else // Если у текущего узла есть правое поддерево.
            {
                // Резервирование места для вставляемого узла.
                Temp->Left = new (Uzel);
                // Установка указателя на вставляемый узел.
                Temp = Temp->Left;
                // Инициализация вставляемого узла.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                // Ссылка на предыдущий узел --> стек.
                A.V_stack(Temp);
            }
        }
        else // Если символ - операнд.
        {
            if (Temp->Right == NULL) // Если у текущего узла нет правого поддерева.
            {
                // Резервирование места для вставляемого узла.
                Temp->Right = new (Uzel);
                // Установка указателя на вставляемый узел.
                Temp = Temp->Right;
                // Инициализация вставляемого узла.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                // Текущий указатель "возвращается" назад.
                A.Udalenie(&Ukazatel);
                Temp = Ukazatel;
            }
            else // Если у текущего узла есть правое поддерево.
            {
                // Резервирование места для вставляемого узла.
                Temp->Left = new (Uzel);
                // Установка указателя на вставляемый узел.
                Temp = Temp->Left;
                // Инициализация вставляемого узла.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                // Текущий указатель "возвращается" назад.
                A.Udalenie(&Ukazatel);
                Temp = Ukazatel;
            }
        }
    } // Конец цикла for.
    cout << "\nКонтрольный вывод дерева-формулы...\n"; 
    A.PrintTree(A.GetTree()->Right, 0); // Вывод дерева на экран.
    cout << "Пред Вами формула, записанная в инфиксной форме...\n"; 
    A.Print_Tree_Back(A.GetTree()->Right, 0); // Вывод формулы в инфиксной форме.
    cout << endl; 
    cout << "------------------------------------------ \n"; // Вывод разделителя.
    cout << "Пред Вами формула, записанная в префиксной форме...\n"; 
    A.Print_Tree_Left(A.GetTree()->Right, 0); // Вывод формулы в префиксной форме.
    cout << endl;
    cout << "------------------------------------------ \n"; // Вывод разделителя.
    cout << "Пред Вами формула, записанная в постфиксной форме...\n"; 
    A.Print_Tree_End(A.GetTree()->Right, 0); // Вывод формулы в постфиксной форме.

    cout << "\n";
    system("PAUSE"); 
}
