#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include<iostream>
#include<limits>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<sstream>
#include<fstream>
#include"Nodo.h"
#include"Vertice.h"


using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

        queue<T> coda;
    public:

        queue<T> getCoda(){return coda;}
        int searchVertice(Vertice<T> *vertice);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Vertice<T> *vertice){grafo.push_back(vertice);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);

        void BFS(Vertice<T> *sorgente);

        //Overload
        friend ostream& operator<<(ostream& out, GrafoOrientato<T>& obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }
    
};

template<class T> int GrafoOrientato<T>::searchVertice(Vertice<T> *vertice)
{
    for(int i = 0 ; i < grafo.size() ; i++)
    {
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }
    return -1;
}

template<class T> Vertice<T>* GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

template<class T> void GrafoOrientato<T>::addArco(Vertice<T> *v1, Vertice<T> *v2)
{
    int ind = searchVertice(v1);

    grafo.at(ind).append(v2);
}

template<class T> list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(i.getVertice() == vertice)
            return i.getLista();
    }
    return grafo.at(0).getLista();
}

template<class T> void GrafoOrientato<T>::BFS(Vertice<T> *sorgente)
{
    ofstream fileOut;
    string file2 = "Output.txt";

    fileOut.open(file2);

    for(auto u:grafo)
    {
        u.getVertice()->setColore(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }

    sorgente->setColore(Color::GRAY);
    sorgente->setPredecessore(nullptr);
    sorgente->setDistanza(0);

    queue<Vertice<T>*> q;

    q.push(sorgente);

    while (!q.empty())
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
                v->setDistanza(v->getDistanza()+1);
                q.push(v);
            }
        }

        u->setColore(Color::BLACK);

        fileOut << u->getValue() <<endl;
    }

    fileOut.close();
    
}

#endif