#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<limits>
#include<list>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

        int time;
        void DFS_VISIT(Vertice<T> u);
        queue<T> coda;
    public:
        
        int searchVertice(Vertice<T> *vertice);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);
        void DFS();

        friend ostream& operator<<(ostream& out, GrafoOrientato<T> &obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }
        
};

template<class T> int GrafoOrientato<T>::searchVertice(Vertice<T> *vertice)
{
    for(int i = 0; i < grafo.size(); i++)
    {
        if(this->grafo.getVertice() == vertice)
            return i;
    }
    return -1;
}

template<class T> Vertice<T> * GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == value)
            return i;
    }
    return nullptr;
}





#endif