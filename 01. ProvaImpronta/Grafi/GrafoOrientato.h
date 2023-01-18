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

    public:
        void addNodo(Nodo<T>);
        void addArco(int ,Vertice<T> *);
        void BFS(Vertice<T> *);

        friend ostream &operator<<(ostream &out, GrafoOrientato<T> &obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }
};

template<class T> void GrafoOrientato<T>::addNodo(Nodo<T> nodo)
{
    grafo.push_back(nodo);
}

template<class T> void GrafoOrientato<T>::addArco(int i,Vertice<T> *vertice)
{
    grafo.at(i).append(vertice);
}

template<class T> list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i :grafo)
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

    queue<Vertice<T>*> q;

    q.push(sorgente);

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();

        list<Vertice<T>*> adj =getListAdj(u);

        for(auto v:adj)
        {
            if(v->getColor() == Color::WHITE)
            {
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza() + 1);
                q.push(v);
            }
        }
        u->setColor(Color::BLACK);

    }
}
#endif