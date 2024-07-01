#include <iostream>
#include <fstream>
using namespace std;
struct list
{
    int number;
    list* next;
};

void insert(list*&, int); //������� ���������� ��������, ���������� ����� ������ � ������, ������� ����������� 
int del(list*&, int);   //������� ��������, ���������� ����� ������ � ������, ������� ��������� 
int IsEmpty(list*);         //�������, ������� ���������, ���� �� ������
void printList(list*);      //������� ������
void menu(void);     //�������, ������������ ����
void sum2(list*);  //������� �������� ������������� ����������� ���������
void sum(list*);  
void toFile(list* p);               // ������ � ����
void fromFile(list*& p);            // ���������� �� �����
int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    int value;
    menu();    // ������� ���� 
    cout << " ? ";
    cin >> choice;
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:  	cout << "������� ����� "; // �������� ����� � ������
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:   if (!IsEmpty(first)) // ������� ����� �� ������
        {
            cout << "������� ��������� ����� ";
            cin >> value;
            if (del(first, value))
            {
                cout << "������� ����� " << value << endl;
                printList(first);
            }
            else
                cout << "����� �� �������" << endl;
        }
              else
            cout << "������ ����" << endl;
            break;
        case 3:   sum2(first);	// ���������� �����	
            break;
        case 4:   sum(first);	// ���������� �����	������������� ���������
            break;
        case 5:   toFile(first);
            break;
        case 6:   fromFile(first);
            break;
        default:  cout << "������������ �����" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    cout << "�����" << endl;
    return 0;
}

void menu(void)  //����� ���� 
{
    cout << "�������� �����:" << endl;
    cout << " 1 - ���� �����" << endl;
    cout << " 2 - �������� �����" << endl;
    cout << " 3 - ���������� ����� ������������� ����������� ��������� " << endl;
    cout << " 4 - ���������� ����� ������������� ���������" << endl;
    cout << " 5 - ������ � ���� " << endl;
    cout << " 6 - ������ ����� " << endl;
    cout << " 8 - �����" << endl;
}

void insert(list*& p, int value) //���������� ����� value � ������ 
{
    list* newP = new list;
    if (newP != NULL)     //���� �� �����?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "�������� ���������� �� ���������" << endl;
}

int del(list*& p, int value)  // �������� ����� 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // ����������� ���� 
        delete temp;      //���������� ������������� ���� 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // ������� � ���������� 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            delete(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) //������  ������? (1-��, 0-���) 
{
    return p == NULL;
}



void printList(list* p)  //����� ������ 
{
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        cout << "������:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void sum2(list* p)  // ������� ����� 
{
    int sm = 0;
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number >= 10 && p->number <= 100)
                sm = sm + (p->number);
            p = p->next;
        }
        cout << "����� = " << sm << endl;
    }
}

void sum(list* p)  // ������� ����� 
{
    int sm = 0;
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number > 0)
                sm = sm + (p->number);
            p = p->next;
        }
        cout << "����� = " << sm << endl;
    }
}

void toFile(list* p)
{
    ofstream frm("mList.dat", ios::binary); // ��������� ���� � �������� ������
    if (!frm.is_open())
    {
        cout << "\n������ �������� �����" << endl;
        return;
    }
    while (p != nullptr)
    {
        frm.write(reinterpret_cast<char*>(p), sizeof(list));
        p = p->next;
    }
    frm.close();
    cout << "������ ������� � ���� mList.dat" << endl;
}

void fromFile(list*& p) // ���������� �� �����
{
    ifstream frm("mList.dat", ios::binary); // ��������� ���� � �������� ������
    if (!frm.is_open())
    {
        cout << "\n������ �������� �����" << endl;
        return;
    }
    list* first = nullptr;
    list* last = nullptr;
    list* newNode = nullptr;
    list buf;
    while (frm.read(reinterpret_cast<char*>(&buf), sizeof(list)))
    {
        newNode = new list;
        newNode->number = buf.number;
        newNode->next = nullptr;
        if (first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
    frm.close();
    p = first;

    // ������� ��������� ������
    cout << "\n��������� ������:" << endl;
    printList(p);

    cout << "\n������ ������ �� ����� mList.dat" << endl;
}