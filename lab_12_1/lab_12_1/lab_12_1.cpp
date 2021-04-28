#include <iostream>

struct Elem
{
    Elem* link1,
        * link2;
    int info;
};

int main()
{
    Elem* p;
    p = new Elem; 
    p->info = 1; 
    p->link2 = NULL; 
    p->link1 = new Elem;
    p->link1->info = 2;
    p->link1->link1 = NULL;
    p->link1->link2 = new Elem;
    p->link1->link2->info = 3;
    p->link1->link2->link2 = NULL;
    p->link1->link2->link1 = new Elem;
    p->link1->link2->link1->info = 4;
    p->link1->link2->link1->link1 = p->link1;
    p->link1->link2->link1->link2 = p;
    delete p->link1->link2->link1; // 4
    delete p->link1->link2; // 3
    delete p->link1; // 2
    delete p; // 1
}