#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<list>
#include<limits>
#include<stack>
#include<fstream>
#include<sstream>
#define K 2

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

    public:

        int searchVertice(Vertice<T> *vertice);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Vertice<T> *vertice){grafo.push_back(vertice);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);

        void BFS(Vertice<T> *sorgente);

        friend ostream& operator<<(ostream& out, GrafoOrientato<T>&obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }

};

//SearchVertice
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
template<class T> Vertice<T>* GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

//GetListaAdj
template<class T> list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == vertice->getValue())
            return i.getLista();
    }
    return grafo.at(0).getLista();
}

//AddArco
template<class T> void GrafoOrientato<T>::addArco(Vertice<T> *v1, Vertice<T> *v2)
{
    int indice = searchVertice(v1);

    grafo.at(indice).append(v2);
}

//BFS
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

    queue<Vertice<T>*> coda;
    coda.push(sorgente);

    while (!coda.empty())
    {
        auto u = coda.front();
        coda.pop();

        if(u->getDistanza() > K)
            break;
        else{

            list<Vertice<T>*> adj = getListAdj(u);

            for(auto v:adj)
            {
                if(v->getColore() == Color::WHITE)
                {
                    v->setColore(Color::GRAY);
                    v->setPredecessore(u);
                    v->setDistanza(u->getDistanza() + 1);
                    coda.push(v);
                }
            }

            u->setColore(Color::BLACK);

            fileOut<<"Il valore: "<<u->getValue()<< " ha distanza = " << u->getDistanza()<<endl;
        }
    }

    fileOut.close();
}

#endif
