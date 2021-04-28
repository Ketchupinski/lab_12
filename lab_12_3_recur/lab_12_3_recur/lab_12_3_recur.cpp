#include <iostream>
#include <Windows.h>
#include <time.h>

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

using namespace std;
void enqueue(Elem*& first, Elem*& last, Info k, Info numb);
void dequeue(Elem*& first, Elem*& last);
bool Check(Elem* L);
bool HelpCheck(Elem* L, Info x);


int main()
{
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
    srand((unsigned)time(NULL));

    Elem* first = NULL,
        * last = NULL;

    enqueue(first, last, 1, 10);

    cout << endl;

    if (Check(first)) {
        cout << "В данному списку є однакові елементи:" << endl << endl;
    }
    else {
        cout << "В данному списку немає однакових елементів:" << endl << endl;
    }

    dequeue(first, last);

    cout << endl << endl;


}


void enqueue(Elem*& first, Elem*& last, Info k, Info numb)
{
    Info value = 1 + rand() % 100; // рандомне число
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
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
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    cout << value << " ";
    if (last != NULL) {
        dequeue(first, last);
    }
}

bool Check(Elem* L) {
    if (L->next != NULL)
    {
        Info x = L->info;
        if (HelpCheck(L, x)) {
            return true;
        }
        else {
            L = L->next;
            return Check(L);
        }
    }
    return false;
}


bool HelpCheck(Elem* L, Info x) {
    if (L->next != NULL) {
        L = L->next;
        if (L->info == x)
            return true;
        else {
            return HelpCheck(L, x);
        }
    }
    else {
        return false;
    }
}
