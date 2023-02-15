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
#include<sstream>
#include<fstream>

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

        void DFS_VISIT(Vertice<T>* u);
        queue<T> coda;
        int time;
    public:

        queue<T> getCoda(){return coda;}

        int searchVertice(Vertice<T> *v);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);

        void DFS();

        //Overload
        friend ostream& operator<<(ostream& out, GrafoOrientato<T>& obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }

};

//SearchVertice
template<class T> int GrafoOrientato<T>::searchVertice(Vertice<T> *v)
{
    for(int i = 0; i < grafo.size() ; i++)
    {
        if(this->grafo.at(i).getVertice()->getValue() == v->getValue())
            return i;
    }
    return -1;
}

//GetIndirizzo
template<class T> Vertice<T>* GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

//GetListADJ
template<class T> list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(i.getVertice()== vertice)
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

//DFS
template<class T> void GrafoOrientato<T>::DFS()
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

//DFS_VISIT
template<class T> void GrafoOrientato<T>::DFS_VISIT(Vertice<T>* u)
{
    ofstream fileOut;
    string file2 = "Output.txt";

    fileOut.open(file2);

    u->setColore(Color::GRAY);
    u->setTempoInizio(time++);

    list<Vertice<T>*> adj = getListAdj(u);

    for(auto v:adj)
    {
        if(v->getColore() == Color::WHITE)
        {
            v->setPredecessore(u);
            DFS_VISIT(v);
        }
    }
    u->setColore(Color::BLACK);
    u->setTempoFine(time++);


    coda.push(u->getValue());
    for(auto i:grafo)
    {
        fileOut<<i.getVertice()->getValue()<<endl;

    }
    fileOut.close();
}

#endif