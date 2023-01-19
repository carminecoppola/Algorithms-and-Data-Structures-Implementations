#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include<iostream>
#include<limits>
#include<queue>
#include<list>
#include<stack>
#include"Nodo.h"
#include"Vertice.h"

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *);

        int time;
        void DFSVisit(Vertice<T> *);
    public:
        void addNodo(Nodo<T> );
        void addArco(int ,Vertice<T> *);
        void DFS();
        void DFSIterative(Vertice<T> *);


        friend ostream &operator<<(ostream &out, GrafoOrientato<T> &obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;

            return out;
        }
};


//ADD NODO
/*Il nostro metodo addNodo servirà ovviamente per aggiungere un nodo
  poichè un grafo può essere visto come un vettore di nodi.*/
template<class T> void GrafoOrientato<T>::addNodo(Nodo<T> nodo)
{
    grafo.push_back(nodo);
}

//ADD ARCO
/*Per ogni nodo che inseriamo dobbiamo tracciare i vertici dato che ha una lista di vertici.
  Gli archi inseriti collegheranno il nodo inserito alla sua lista di adiacenza.
  i è dunque il nodo a cui è collegato il vertice che passiamo
  i = 0 append vertice(f) significa che il nodo 0 sarà collegato al vertice f 
  (creiamo la sua lista di adiacenza)
*/
template<class T> void GrafoOrientato<T>::addArco(int i, Vertice<T> *vertice)
{
    grafo.at(i).append(vertice);
}

//GETLISTADJ
/*Estraggo la lista di adiacenza del vertice specifico*/
template<class T> list<Vertice<T>* > GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for (auto i : grafo)
    {
        if(i.getVertice() == vertice)
            return i.getList();
    }

    return grafo.at(0).getList();
    
}

template<class T> void GrafoOrientato<T>::DFS()
{
    //Inizializzo
    for (auto u : grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        time = 0;
    }
    
    //Qui avviene la chiamata ricorsiva
    for (auto u : grafo)
    {
        if(u.getVertice()->getColor() == Color::WHITE)
            DFSVisit(u.getVertice());
    }
    
}

//DFSVISIT
template<class T> void GrafoOrientato<T>::DFSVisit(Vertice<T> *u)
{
    u->setColor(Color::GRAY);
    u->setTempInizio(time++);

    list<Vertice<T>*> adj = getListAdj(u);
    for (auto v : adj)
    {
        if(v->getColor() == Color::WHITE)
        {
            v->setPredecessore(u);
            DFSVisit(v);
        }
    }
    
    u->setColor(Color::BLACK);
    u->setTempFine(time++);

}

//DFS ITERARIVA
template<class T> void GrafoOrientato<T>::DFSIterative(Vertice<T> *sorgente)
{
    for(auto u : grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        time = 0;
    }

    //per implementare un dfs iterativa abbiamo bisogno di uno stack perché 
    //il primo elemento che vine colorato di nero è l'ulitmo inserito
    //necessitiamo dunque di una struttura LIFO tipica degli stack

    stack<Vertice<T> *> stack;
    stack.push(sorgente);

    while (!stack.empty())
    {
        auto u = stack.top();
        stack.pop();

        //ci serve il vertice bianco
        if(u->getColor() == Color::WHITE)
        {
            u->setColor(Color::GRAY);
            u->setTempInizio(time++);
        }
            //se un nodo adiacente non è sttao ancora visitato inseriscilo nello stack
            list<Vertice<T>*> adj = getListAdj(u);
            for(auto v: adj)
            {
                if(v->getColor() == Color::WHITE)
                    stack.push(v);
            }

            u->setColor(Color::BLACK);
            u->setTempFine(time++);
        
    }

}
#endif
