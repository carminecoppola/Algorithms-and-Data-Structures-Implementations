#ifndef GRAFOORIENTATO
#define GRAFOORIENTATO

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<list>
#include<limits>
#include<stack>
#include<queue>

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

    public:

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(int i, Vertice<T> *vertice){grafo.at(i).append(vertice);}

        void BFS(Vertice<T> *sorgente);

        friend ostream& operator<<(ostream &out, GrafoOrientato<T> obj)
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
            return i.getListAdj();
    }
    return grafo.at(0).getListAdj();
}

template<class T> void GrafoOrientato<T>::BFS(Vertice<T> * sorgente)
{
    for(auto u:grafo)
    {
        u.getVertice()->setColore(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }

    sorgente->setColore(Color::WHITE);
    sorgente->setPredecessore(nullptr);
    sorgente->setDistanza(0);

    queue<Vertice<T>*> q;
    q.push(sorgente);

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();

        list<Vertice<T>*> adj = getListAdj(u);

        for(auto v:adj)
        {
            if(v->getColore() == Color::WHITE)
            {
                v->setColore(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza()+ 1);
                q.push(v);
            }
        }
        u->setColore(Color::BLACK);
    }
}

#endif