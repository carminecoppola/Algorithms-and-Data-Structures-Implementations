#include"GrafoOrientato.h"
#include"Nodo.h"
#include"Vertice.h"

#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(){

    GrafoOrientato<string> grafo;

    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");

    grafo.addNodi(Nodo<string>(&a));
    grafo.addNodi(Nodo<string>(&b));
    grafo.addNodi(Nodo<string>(&c));
    grafo.addNodi(Nodo<string>(&d));
    grafo.addNodi(Nodo<string>(&e));
    grafo.addNodi(Nodo<string>(&f));

    grafo.addArco(0,&b);
    grafo.addArco(0,&e);
    grafo.addArco(1,&c);
    grafo.addArco(2,&d);
    grafo.addArco(2,&e);
    grafo.addArco(4,&f);

    queue<Vertice<string>*> queue;
    queue.push(&a);

    cout<<endl<<"DFS: "<<endl;
    grafo.DFS();
    cout<<grafo<<endl;

    return 0;

}