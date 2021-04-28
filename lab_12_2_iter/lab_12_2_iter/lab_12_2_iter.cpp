#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info; // створення псевдоніму типу

struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
void Process(Elem*& first, Info numb);
Info dequeue(Elem*& first, Elem*& last);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	Elem* first = NULL,
		* last = NULL;

	for (int i = 1; i <= 10; i++) // створення черги
		enqueue(first, last, i);

	Print(first); // Вивід черги
	cout << endl;

	Info numb;
	cout << "Введіть число, до якого будуть видалені всі аргументи: "; cin >> numb;
	Process(first, numb); // Опрацювання черги

	while (last != NULL) {
		cout << dequeue(first, last) << " "; // Вивід та видалення черги
	}
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; 
	tmp->info = value; 
	tmp->link = NULL; 
	if (last != NULL)
		last->link = tmp; 
	last = tmp; 
	if (first == NULL)
		first = tmp; 
}

Info dequeue(Elem * &first, Elem * &last)
{
	Elem* tmp = first->link; 
	Info value = first->info; 
	delete first; 
	first = tmp; 
	if (first == NULL)
		last = NULL; 
	return value; 
}

void Print(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->link;
	}
	cout << endl;
}

void Process(Elem*& first, Info numb)
{
	while (first != NULL && first->info < numb) {
		Elem* tmp = first->link;
		delete first; 
		first = tmp;
	}
}