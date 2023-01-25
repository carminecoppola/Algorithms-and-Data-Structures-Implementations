#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<list>
#include<limits>
#include<stack>
#include<queue>
#include<queue>


using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

        int time;
        queue<T> q;
        void DFS_VISIT(Vertice<T> *u);

    public:

        queue<T> getQueue(){return q;}
        int searchVertice(Vertice<T> *v);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);
        void DFS();


        //Overload
        friend ostream& operator<<(ostream& out, GrafoOrientato<T> &obj)
        {

            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }

};

template<class T> int GrafoOrientato<T>::searchVertice(Vertice<T> *v)
{
    for(int i = 0; i < grafo.size() ; i++)
    {
        if(this->grafo.at(i).getVertice()->getValue() == v->getValue())
            return i;
    }
    return -1;
}

template<class T> void GrafoOrientato<T>::addArco(Vertice<T> *v1,Vertice<T> *v2)
{
    int indice = searchVertice(v1);
    grafo.at(indice).append(v2);

}

template<class T> Vertice<T> * GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for(auto nodo:grafo)
    {
        if(nodo.getVertice()->getValue() == value)
            return nodo.getVertice();
    }

    return nullptr;
}

template<class T> list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(i.getVertice() == vertice)
            return i.getList();
    }
    return grafo.at(0).getList();
}

template<class T> void GrafoOrientato<T>::DFS()
{
    
    for(auto u:grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        
    }

    time = 0;

    for(auto u:grafo)
    {
        if(u.getVertice()->getColore() == Color::WHITE)
            DFS_VISIT(u.getVertice());
    }
}

template<class T> void GrafoOrientato<T>::DFS_VISIT(Vertice<T> *u)
{
    u->setColor(Color::GRAY);
    u->setTempInizio(++time);

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
    u->setTempFine(++time);
    q.push(u->getValue());
}

#endif