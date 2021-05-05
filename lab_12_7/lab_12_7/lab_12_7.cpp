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
void print(Elem* L);
Info process(Elem*& L);

int main()
{
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    srand((unsigned)time(NULL));
    Elem* L = NULL;
    Info num;
    for (int i = 1; i <= 20; i++) {
        insert(L, i);
    }
    cout << "Оригінальний список: ";
    print(L);
    cout << endl;

    cout << "Вилучено елементів: " << process(L) << endl << endl;

    cout << "Змінений список: ";
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

void print(Elem* L) {
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

Info process(Elem*& L)
{
    Info k = 0, l = 0; // лічильники
    Elem* start = L; // збереження початку
    cout << "Елементи, що вилучаються: ";
    while (L->link != start) {
        k++; // лічильник на кожен третій елемент
        if (k == 3) {
            cout << L->info << " ";
            remove(L);
            l++; // лічильник кількості вилучених елементів
            k = 0; // обнулення лічильника 
        }
        else {
            L = L->link; // перехід до наступного елемента
        }
    }
    cout << endl << endl;
    L = start; // повернення на початок
    return l; // повернення кількості вилучених елементів
}