#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info; // створення псевдоніму типу

struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info k, Info numb);
void Print(Elem* L);
void Process(Elem*& first, Info numb);
void dequeue(Elem*& first, Elem*& last);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	Elem* first = NULL,
		* last = NULL;

	enqueue(first, last, 1, 10);

	Print(first); // Вивід черги
	cout << endl;

	Info numb;
	cout << "Введіть число, до якого будуть видалені всі аргументи: "; cin >> numb;

	Process(first, numb); // Опрацювання черги

	dequeue(first, last); // Вивід та видалення черги
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info k, Info numb)
{
	Elem* tmp = new Elem;
	tmp->info = k;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
	if (k < numb) {
		k++;
		enqueue(first, last, k, numb);
	}

}

void dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	cout << value << " ";
	if (last != NULL) {
		dequeue(first, last);
	}
}

void Print(Elem* L)
{
	if (L != NULL) {
		cout << L->info << " ";
		L = L->link;
		Print(L);
	}
}

void Process(Elem*& first, Info numb)
{
	if (first != NULL && first->info < numb) {
		Elem* tmp = first->link;
		delete first;
		first = tmp;
		Process(first, numb);
	}
}