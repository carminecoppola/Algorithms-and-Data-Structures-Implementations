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
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

        int time;
        void DFS_VISIT(Vertice<T> *u);

    public:

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(int i, Vertice<T> *vertice){grafo.at(i).append(vertice);}

        void DFS();

        friend ostream& operator<<(ostream &out, const GrafoOrientato<T> &obj)
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

template<class T> void GrafoOrientato<T>::DFS()
{
    for(auto u:grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        time = 0;
    }

    for(auto u:grafo)
    {
        if(u.getVertice()->getColore() == Color::WHITE)
            DFS_VISIT(u.getVertice());
    }
}

template<class T> void GrafoOrientato<T>::DFS_VISIT(Vertice<T> *u)
{
    u->setColor(Color::GRAY);
    u->setTempInizio(time++);

    list<Vertice<T>*> adj = getListAdj(u);
    
    for(auto v:adj)
    {
        if(v->getColore() == Color::WHITE)
        {
            v->setPredecessore(u);
            DFS_VISIT(v);
        }
    }
    u->setColor(Color::BLACK);
    u->setTempFine(time++);

}


#endif