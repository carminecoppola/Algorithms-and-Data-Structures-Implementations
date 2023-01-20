#ifndef GRAFOORIENTATO_H 
#define GRAFOORIENTATO_H

#include<iostream>
#include<limits>
#include<list>
#include<queue>
#include<stack>
#include"Vertice.h"
#include"Nodo.h"

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *);

    public:
        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(int i, Vertice<T> *vertice){grafo.at(i).append(vertice);} 

        void BFS(Vertice<T> *);

        friend ostream &operator<<(ostream &out, GrafoOrientato<T> &obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }

};

template<class T> list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(i.getVertice() == vertice)
            return i.getList();
    }
    return grafo.at(0).getList();
}

template<class T> void GrafoOrientato<T>::BFS(Vertice<T> *sorgente)
{
    for(auto u:grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }

    sorgente->setColor(Color::WHITE);
    sorgente->setPredecessore(nullptr);
    sorgente->setDistanza(0);

    queue<Vertice<T> *> q;
    q.push(sorgente);

    while(!q.empty())
    {
        auto u = q.front();     //Prendo il primo elemento della coda
        q.pop();

        list<Vertice<T>*> adj = getListAdj(u);   //Creo la lista di ADJ

        for(auto v:adj)
        {
            if(v->getColor() == Color::WHITE)
            {
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza()+1);
                q.push(v);
            }
        }

        u->setColor(Color::BLACK);

    }

}


#endif