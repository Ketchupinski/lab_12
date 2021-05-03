#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value);
Info remove(Elem*& L);
int Count(Elem* L);
void Print(Elem* L);

int main()
{
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    srand((unsigned)time(NULL));
    Elem* L = NULL;
    Info num;
    for (int i = 1; i <= 10; i++) {
        num = 1 + rand() % 100;
        insert(L, num);
    }

    Print(L);
   
    cout << endl;
    cout << "Знайдено " << Count(L) << " непарних елементів!" << endl << endl;

    while (L != NULL) {
        cout << remove(L) << " ";
    }
    cout << endl;
}

void insert(Elem*& L, Info value) // додавання елементу у список
{
    Elem* tmp = new Elem; // створення допоміжного елемента 
    tmp->info = value;
    if (L != NULL) // Якщо список не порожній
    {
        Elem* T = L; // ще один допомоміжий елемент
        while (T->link != L) // сканування до останнього елементу 
            T = T->link; // перехід далі
        T->link = tmp; 
    }
    else // Якщо список порожній
    {
        L = tmp; 
    }
    tmp->link = L; 
}

Info remove(Elem*& L) // видалення елементу зі списку 
{
    Elem* T = L; // допоміжний елемент
    while (T->link != L) // сканування до кінця списку
        T = T->link;  
    Info value = L->info; 
    if (T != L)
    {
        Elem* tmp = L->link; 
        delete L; 
        L = tmp; 
        T->link = L; 
    }
    else
    {
        delete L; 
        L = NULL; 
    }
    return value; 
}

void Print(Elem* L) {
    if (L == NULL)
        return;
    Elem* first = L;
    cout << L->info << " ";
    while (L->link != first)
    {
        L = L->link;
        cout << L->info << " ";
    }
    cout << endl;
}

int Count(Elem* L)
{
    if (L == NULL)
        return 0;
    Elem* first = L;
    int k = 0; // оголошення лічильника 
    while (L->link != first) // перевірка до останнього
    {
        if (L->info % 2 != 0) // перевірка на непарність
            k++; // збільшення лічильника непарних
        L = L->link; // перехід далі
    }
    if (L->info % 2 != 0) // перевірка останнього
        k++; // збільшення лічильника непарних
    return k;
}