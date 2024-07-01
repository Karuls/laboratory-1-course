struct Stack
{
	int data;     //информационный элемент
	Stack* next;	 //указатель на следующий элемент
};

struct Stack_2
{
	int data_2;     
	Stack_2* next;	 
};

struct Stack_3
{
	int data_3;     
	Stack_3* next;	 
};
void show(Stack*& myStk);
char pop(Stack*& myStk);
void push(int x, Stack*& myStk);
void push_2(int y, Stack_2*& myStk_2);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
void clear(Stack*& myStk, Stack_2*& myStk_2, Stack_3*& myStk_3);


