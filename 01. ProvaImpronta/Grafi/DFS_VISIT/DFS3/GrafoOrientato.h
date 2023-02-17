#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<list>
#include<limits>
#include<stack>
#include<queue>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Vertice<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

        int DFS_VISIT(Vertice<T> *u);
        int time;
        queue<T> coda;

    public:
        
        queue<T> getCoda(){return coda;}
        int searchVertice(Vertice<T> *v);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Vertice<T> *vert){grafo.push_back(vert);}
        void addArco(Vertice<T> *v1 , Vertice<T> *v2);

        int DFS();

        friend ostream& operator<<(ostream& out, GrafoOrientato<T>& obj)
        {
            for(auto i:obj.grafo)
                out<<*i<<endl;
            return out;
        }
};

template<class T> int GrafoOrientato<T>::searchVertice(Vertice<T> *v)
{
    for (int i = 0; i < grafo.size(); i++)
    {
        if(this->grafo.at(i).getVertice()->getValue() == v->getValue())
            return i;
    }
    return -1;
}

template<class T> Vertice<T>* GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == value)
            return i;
    }
    return nullptr;
}

template<class T> void GrafoOrientato<T>::addArco(Vertice<T> *v1 , Vertice<T> *v2)
{
    int ind = searchVertice(v1);

    grafo.at(ind).append(v2);
}

template<class T> list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(grafo.at(i).getVertice() == vertice)
            return i.getLista();
    }
    return grafo.at(0).getLista();
}

template<class T> int GrafoOrientato<T>::DFS()
{

    for(auto u:grafo)
    {
        u.getVertice()->setColore(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
    }
    time = 0;

    for(auto u:grafo)
    {
        if(u.getVertice()->getColore() == Color::WHITE)
            DFS_VISIT(u.getVertice());
    }
}

template<class T> int GrafoOrientato<T>::DFS_VISIT(Vertice<T> *u)
{

    u->setColore(Color::GRAY);
    u->setTempoInizio(time++);

    list<Vertice<T>*> adj = getListAdj(u);

    for(auto v:adj)
    {
        if(v.getVertice()->getColor() == Color::WHITE)
        {
            v->setPredecessore(u);
            DFS_VISIT(v);
        }
    }

    u->setColore(Color::BLACK);
    u->setTempoFine(time++);

    coda.pop(u->getValue());
}

#endif