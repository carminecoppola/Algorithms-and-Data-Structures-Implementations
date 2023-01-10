#include <iostream>
#include "Nodo.h"
#include "GrafoOrientato.h"
#include "Vertice.h"
#include <string>
#include <queue>

using namespace std;

int main(){
GrafoOrientato<string> grafo;

    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");

    grafo.addNodo(Nodo<string>(&a));
    grafo.addNodo(Nodo<string>(&b));
    grafo.addNodo(Nodo<string>(&c));
    grafo.addNodo(Nodo<string>(&d));
    grafo.addNodo(Nodo<string>(&e));
    grafo.addNodo(Nodo<string>(&f));

    grafo.addArco(0, &b);         // 0|A|--->|B|   |--->|E|   |--->NULL
    grafo.addArco(0, &e);         // 1|B|--->|C|   |--->NULL
    grafo.addArco(1, &c);         // 2|C|--->|D|   |--->|E|   |--->NULL
    grafo.addArco(2, &d);         // 3|D|--->NULL
    grafo.addArco(2, &e);         // 4|E|--->|F|   |--->NULL
    grafo.addArco(4, &f);         // 5|F|--->NULL

    queue<Vertice<string>*> queue;
    queue.push(&a);
    grafo.BFS(&a);
    cout << grafo << endl;


    return 0;
}