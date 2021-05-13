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
    string punkt;
    Info distance;
};

void insert(Elem*& L, Elem*& last, string punkt, Info distance);
void find_dist(Elem* L, Elem* last, Info dist);
void find_punkt(Elem* L, string p1, string p2);
void print(Elem*& L);



int main()
{
    string punktOne, punktTwo;
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    Elem* L = NULL,
        * last = NULL;
    Info i = 0;
    string t;
    string save;
    Info dist;
    string p1, p2;
    char ch; // перемінна вибору в меню
    do { 
        if (i == 0) { // для початкового пункту
            cout << "Введіть назву першого пункту на автотрасі: "; cin >> t; // введення назви першого пункту 
            save = t; // збереження назви пункту для наступного
            cout << "Введіть дистанцію від початку автотраси до першого пункту: "; cin >> dist; // дистанція до першого пункту
            insert(L, last, t, dist);
            cout << endl;
            i++;
        }
        else {
            cout << "Введіть назву пункту, який йде після " << save << ": "; cin >> t; // введення назви першого пункту 
            cout << "Введіть дистанцію від " << save << " до " << t << ": "; cin >> dist; // дистанція до першого пункту
            save = t; // збереження назви пункту для наступного
            insert(L, last, t, dist);
            cout << endl;
        }
        cout << "Продовжити ввід? (Y/N) "; cin >> ch;
        cout << endl;
    } while (ch == 'y' || ch == 'Y');

    do
    {
        cout << endl;
        cout << "Головне меню:" << endl;
        cout << "[1] - вивід данних про автотрасу" << endl;
        cout << "[2] - знаходження пунктів автотраси по відстані;" << endl;
        cout << "[3] - знаходження відстані по назвам пунктів на автотрасі;" << endl << endl;

        cout << "[0] - завершення роботи." << endl << endl;
        cout << "Що потрібно зробити? "; cin >> ch;
        cout << endl;
        switch (ch)
        {
        case '0':
            break;
        case '1':
            print(L);
            break;
        case '2':
            Info distance;
            cout << "Введіть дистанцію для пошуку: "; cin >> distance;
            cout << endl;
            find_dist(L, last, distance);
            break;
        case '3':
            cout << "Введіть назву першого пункту для пошуку: "; cin >> p1;
            cout << "Введіть назву другого пункту для пошуку: "; cin >> p2;
            find_punkt(L, p1, p2);
            break;
        default:
            cout << "Помилка вводу! ";
        }
    } while (ch != '0');
    return 0;
}


void insert(Elem*& L, Elem*& last, string punkt, Info distance)
{
    Elem* tmp = new Elem;
    tmp->punkt = punkt;
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

void print(Elem*& L) {
    Elem* start = L;
    cout << "Пункти на автотрасі: " << endl << endl;
    cout << "Перший пункт на трасі: " << L->punkt << endl;
    cout << "Дистанція до першого пункту: " << L->distance << endl << endl;
    string save = L->punkt;
    L = L->next;
    while (L != start) {
        cout << "Наступний пункт після " << save << ": " << L->punkt << endl;
        cout << "Дистанція від " << save << " до " << L->punkt << ": " << L->distance << endl << endl;
        save = L->punkt;
        L = L->next;
    }
}


void find_dist(Elem* L, Elem* last, Info dist) {
    Elem* start = L; // початкова точка
    string t1 = L->punkt;
    Info distance = L->distance;
    Info chenge, min;
    string min_punkt1;
    string min_punkt2;
    string first_punkt = L->punkt;
    if (distance == dist) {
        cout << "Така довжина є між початком автотраси і " << t1 << ";" << endl;
        return;
    }
    else {
        if (distance < dist) {
            chenge = dist - distance;
        }
        else {
            chenge = distance - dist;
        }
    }
    min = chenge;
    min_punkt2 = L->punkt;
    min_punkt1 = "\"початок автотраси\"";
    L = L->next;
    string t2 = L->punkt;
    distance = L->distance;
    while (L != start) {
        if (distance == dist) {
            cout << "Така довжина є між " << t1 << " і " << t2 << ";" << endl;
            return;
        }
        else {
            if (distance < dist) {
                chenge = dist - distance;
            }
            else {
                chenge = distance - dist;
            }
        }
        if (chenge < min) {
            min = chenge;
            min_punkt1 = t1;
            min_punkt2 = t2;
        }
        t1 = t2;
        L = L->next;
        t2 = L->punkt;
        distance = L->distance;
    }
    cout << endl;
    cout << "Найменьша різниця з заданим значенням між пунктами " << min_punkt1 << " та " << min_punkt2 << ". Всього " << min << " км.";
    cout << endl << endl;
}



void find_punkt(Elem* L, string p1, string p2) {
    Elem* start = L;
    string t = L->punkt;
    Info dist = 0, k = 0;
    if (p1 == t) {
        k++;
    }
    L = L->next;
    while (L != start) {
        t = L->punkt;
        if (k == 0) {
            if (t == p1) {
                k++;
            }
        }
        else {
            if (t == p2) {
                dist = dist + L->distance;
                cout << endl;
                cout << "Дистанція між " << p1 << " та " << p2 << " становить " << dist << endl << endl;
            }
            else {
                dist = dist + L->distance;
            }
        }
        L = L->next;
    }
}

