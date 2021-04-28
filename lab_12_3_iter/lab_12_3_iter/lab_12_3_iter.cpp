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
void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
bool Check(Elem* L);
bool HelpCheck(Elem* L, Info);


int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    Elem* first = NULL,
        * last = NULL;
    for (int i = 1; i <= 10; i++) {
        Info numb = 1 + rand() % 10;
        enqueue(first, last, numb);
    }

    cout << endl;

    if (Check(first)) {
        cout << "В данному списку є однакові елементи:" << endl << endl;
    }
    else {
        cout << "В данному списку немає однакових елементів:" << endl << endl;
    }

    while (last != NULL) {
        cout << dequeue(first, last) << " ";
    }
    cout << endl << endl;


}


void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; 
    tmp->info = value; 
    tmp->next = NULL; 
    if (last != NULL)
        last->next = tmp; 
    tmp->prev = last; 
    last = tmp; 
    if (first == NULL)
        first = tmp; 
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next; 
    Info value = first->info; 
    delete first; 
    first = tmp; 
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL; 
    return value; 
}

bool Check(Elem* L) {
    while (L->next != NULL)
    {
        Info x = L->info;
        if (HelpCheck(L, x)) {
            return true;
        }
        else {
            L = L->next;
            x = L->info;
        }
        
    }
    return false;
    cout << endl;
}

bool HelpCheck(Elem* L, Info x) {

    if (L->next != NULL)
        L = L->next;
    else
        return false;

    while (L != NULL) {
        if (L->info == x) {
            return true;
        }
        else {
            L = L->next;
        }
    }
    return false;
}

