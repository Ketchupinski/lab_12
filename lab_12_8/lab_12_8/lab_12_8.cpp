#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>

typedef int Info;

using namespace std;

struct Elem
{
    Elem* next,
        * prev;
    string punktOne;
    string punktTwo;
    Info distance;
};

void insert(Elem*& L, Elem*& last, string one, string two, Info distance);
void remove(Elem*& L, Elem*& last);
void find_dist(Elem* L, Elem* last, Info dist);
void find_punkt(Elem* L, Elem* last, string p1, string p2);



int main()
{
    string punktOne, punktTwo;
    srand((unsigned)time(NULL));
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    Elem* L = NULL,
        * last = NULL;
    
    Info N;
    cout << "Введіть кількість елементів у списку: "; cin >> N;
    cout << endl << endl;
    for (int i = 0; i < N; i++) {
        Info distance;
        cout << "Ввердіть назву першого пункту: "; cin >> punktOne;
        cout << "Ввердіть назву другого пункту пункту: "; cin >> punktTwo;
        cout << "Введіть дистанцію між " << punktOne << " і " << punktTwo << "(km): "; cin >> distance;
        cout << endl;
        insert(L, last, punktOne, punktTwo, distance);
    }
    string p1, p2;
    cout << endl << endl;
    cout << "Пошук по назвам пунктів:" << endl;
    cout << "Ввердіть назву першого пункту: "; cin >> p1;
    cout << "Ввердіть назву другого пункту пункту: "; cin >> p2;
    cout << endl;
    find_punkt(L, last, p1, p2);
    cout << endl << endl;


    Info dist;
    cout << "Пошук по дистанції: " << endl;
    cout << "Введіть дистанцію: "; cin >> dist;
    cout << endl;
    find_dist(L, last, dist);

    

    while (L != NULL) {
        remove(L, last);
    }
    cout << endl << endl;


}

void insert(Elem*& L, Elem*& last, string one, string two, Info distance)
{
    Elem* tmp = new Elem;
    tmp->punktOne = one;
    tmp->punktTwo = two;
    tmp->distance = distance;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (L == NULL)
        L = tmp;
    last->next = L;
    L->prev = last;
}



void remove(Elem*& L, Elem*& last) // видалення елементу зі списку 
{
    // вивід
    cout << endl;
    cout << "Перший пункт: " << L->punktOne;
    cout << endl;
    cout << "Другий пункт: " << L->punktTwo;
    cout << endl;
    cout << "Дистанція між пунктами: " << L->distance;
    cout << endl;
    // видалення
    if (last != L) {
        Elem* tmp = L->next;
        delete L;
        L = tmp;
        last->next = L;
    }
    else {
        delete L;
        L = NULL;
    }
}

void find_dist(Elem* L, Elem* last, Info dist) {
    Elem* start = L; // початкова точка
    Info distance = L->distance;
    string t1 = L->punktOne;
    string t2 = L->punktTwo;


    Info change;
    if (distance < dist) {
        change = dist - distance;
    }
    if (distance > dist) {
        change = distance - dist;
    }
    if (distance == dist) { // коли збігається
        cout << "Така дистанція є між " << t1 << " та " << t2 << endl;
        return;
    }

    Info min = change; // Мінмальна різниця дистанції на данний момент

    L = L->next;

    while (L != start) {
        distance = L->distance;
        if (distance < dist) {
            change = dist - distance;
        }
        if (distance > dist) {
            change = distance - dist;
        }
        if (distance == dist) { // коли збігається
            cout << "Така дистанція є між " << t1 << " та " << t2 << endl;
            return;
        }

        if (change < min) {
            min = change;
            t1 = L->punktOne;
            t2 = L->punktTwo;
        }
        L = L->next;
    }
    cout << endl;
    cout << "Найменьша різниця з точками " << t1 << " та " << t2 << ". Всього " << min << " км.";
    cout << endl << endl;
}

void find_punkt(Elem* L, Elem* last, string p1, string p2) {
    Elem* start = L; // початкова точка
    if ((p1 == L->punktOne && // перший елемент
        p2 == L->punktTwo) ||
        (p2 == L->punktOne &&
            p1 == L->punktTwo)) // Якщо користувач перепутає, то все-одно буде знайдено
    {
        cout << "Відстань між заданими містами: " << L->distance << endl;
    }

    L = L->next;

    while (L != start) { // всі інші елементи
        if ((p1 == L->punktOne &&
            p2 == L->punktTwo) ||
            (p2 == L->punktOne &&
                p1 == L->punktTwo)) // Якщо користувач перепутає, то все-одно буде знайдено
        {
            cout << "Відстань між заданими містами: " << L->distance << endl;
        }

        L = L->next;
    }
}
