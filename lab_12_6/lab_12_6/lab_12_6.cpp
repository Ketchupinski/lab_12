#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	string info;
};

void enqueue(Elem*& first, Elem*& last, string value);
string dequeue(Elem*& first, Elem*& last);
void readTXT(Elem*& first, Elem*& last);
bool checkQueue(Elem*& first, Elem*& last);
void copyQueue(Elem* L, Elem*& new_start, Elem*& new_end);
void print(Elem* L);
Info count(Elem* L);

int main()
{
	Elem* first = NULL,
		* last = NULL;
	readTXT(first, last);
	cout << "Queue status: ";
	if (checkQueue(first, last)) {
		cout << "queue is empty" << endl << endl;
	}
	else {
		cout << "queue is not empty" << endl << endl;
	}

	cout << "Elements in this queue: " << count(first) << endl;

	Elem* new_start = NULL,
		* new_end = NULL;

	cout << endl << "Copied queue: ";
	copyQueue(first, new_start, new_end);

	cout << endl << endl;
	print(new_start); // друк скопійованої черги
	cout << endl;

	cout << "Original queue: " << endl << endl;
	while (first != NULL)
		cout << dequeue(first, last) << " ";
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, string value)
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

string dequeue(Elem * &first, Elem * &last)
{
	Elem* tmp = first->link; 
	string value = first->info; 
	delete first; 
	first = tmp; 
	if (first == NULL)
		last = NULL; 
	return value; 
}

void readTXT(Elem*& first, Elem*& last)
{
	ifstream f("symbols.txt"); // відкриття потоку зчитування файла
	string symbol;
	while (!f.eof()) { // всі інші цифри
		f >> symbol;
		enqueue(first, last, symbol);
	}
}

bool checkQueue(Elem*& first, Elem*& last) { // перевірка на пустоту списку 
	if (first == NULL && last == NULL) {
		return true;
	}
	else
		return false;
}

void copyQueue(Elem* L, Elem*& new_start, Elem*& new_end) {
	while (L != NULL)
	{
		Elem* tmp = new Elem;
		tmp->info = L->info;
		tmp->link = NULL;
		if (new_end != NULL)
			new_end->link = tmp;
		new_end = tmp;
		if (new_start == NULL)
			new_start = tmp;
		L = L->link;
	}
}

void print(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->link;
	}
	cout << endl;
}


Info count(Elem* L)
{
	Info k = 0; // оголошення лічильника елементів
	while (L->link != NULL)
	{
		k++; // збільшення лічильника при кожній ітерації
		L = L->link;
	}
	if (L != NULL) { // останній елемент
		k++;
	}
	return k;
}