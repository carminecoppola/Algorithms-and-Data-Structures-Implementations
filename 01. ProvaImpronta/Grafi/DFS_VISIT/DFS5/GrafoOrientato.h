#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<list>
#include<limits>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);
        
        void DFS_VISIT(Vertice<T> *u);
        int time;
        queue<T> coda;

    public:
    
        queue<T> getCoda(){return coda;}
        int searchVertice(Vertice<T> *vertice);
        Vertice<T> *getInizizzoVertice(T value);

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


//SearchVertice:
template<class T> int GrafoOrientato<T>::searchVertice(Vertice<T> *vertice)
{
    for (int i = 0; i < grafo.size(); i++)
    {
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }
    return -1;
}

//GetIndirizzoVertice
template<class T> Vertice<T> * GrafoOrientato<T>::getInizizzoVertice(T value)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

//AddArco
template<class T> void GrafoOrientato<T>::addArco(Vertice<T> *v1,Vertice<T> *v2)
{
    int vertice = searchVertice(v1);
    
    grafo.at(vertice).append(v2);
}

//GetListAdj
template<class T>  list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(i.getVertice() == vertice)
            return i.getLista();
    }

    return grafo.at(0).getLista();
}


//DFS
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
        if(u.getVertice()->getColor() == Color::WHITE)
            DFS_VISIT(u.getVertice());
    }


}

//DFS_VISIT
template<class T> void GrafoOrientato<T>::DFS_VISIT(Vertice<T> *u)
{
    u->setColor(Color::GRAY);
    u->setTempoInizio(time++);

    list<Vertice<T>*> adj = getListAdj(u);

    for(auto v:adj)
    {
        if(v->getColor() == Color::WHITE)
        {
            v->setPredecessore(u);
            DFS_VISIT(v);
        }
    }

    u->setColor(Color::BLACK);
    u->setTempoFine(time++);

    //Ordinamento topologico
    coda.push(u->getValue());
}


#endif