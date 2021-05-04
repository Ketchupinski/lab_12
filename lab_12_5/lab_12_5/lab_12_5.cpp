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

void push(Elem*& top, Info value);
string pop(Elem*& top);
void readTXT(Elem*& top);
void count(Elem*& top, Info& operaz, Info& operand);

int main()
{
	Elem* top = NULL;
	readTXT(top);
	Info operaz = 0, operand = 0;
	count(top, operaz, operand);
	cout << "Operations: " << operaz << endl << endl;
	cout << "Operands: " << operand << endl << endl;
	cout << "Stack: " << endl;
	while (top != NULL) {
		cout << pop(top) << " "; // видалення та вивід на екран стеку
	}
	cout << endl;
}


void push(Elem*& top, string value)
{
	Elem* tmp = new Elem; 
	tmp->info = value; 
	tmp->link = top; 
	top = tmp; 
}

string pop(Elem*& top)
{
	Elem* tmp = top->link;
	string value = top->info;
	delete top;
	top = tmp;
	return value;
}

void readTXT(Elem*& top)
{
    ifstream f("symbols.txt"); // відкриття потоку зчитування файла
	string a, b, symbol;
	if (!f.eof()) { // перші цифри
		f >> a; // зчитування з файла і запис у стек 
		push(top, a);
		f >> symbol;
		push(top, symbol);
		f >> b;
		push(top, b);
	}
	while (!f.eof()) { // всі інші цифри
		f >> symbol;
		push(top, symbol);
		f >> b;
		push(top, b);
	}
}

void count(Elem*& top, Info& operaz, Info& operand) // рахунок операцій і операндів
{
	Elem* tmp = top;
	while (tmp->link != NULL) {
		if (tmp->info == "+" ||
			tmp->info == "-" ||
			tmp->info == "*" ||
			tmp->info == "/")
			operaz++; // операції
		else {
			operand++; // операнди
		}
		tmp = tmp->link;
	}
	// Для останнього елементу стеку
	if (tmp->info == "+" ||
		tmp->info == "-" ||
		tmp->info == "*" ||
		tmp->info == "/")
		operaz++; // операції
	else {
		operand++; // операнди
	}
	cout << endl;
}