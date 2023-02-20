#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

        queue<T> coda;
        void DFS_VISIT(Vertice<T> *u);
        int time;
    public:
        
        queue<T> getCoda(){return coda;}

        int searchVertice(Vertice<T> *vertice);
        Vertice<T> *getIndirizzoVertice(T value);
        
        void addNodo(Vertice<T> *nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);

        void DFS();

        //Overload
        friend ostream& operator<<(ostream& out, GrafoOrientato<T>&obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }
};

template<class T> int GrafoOrientato<T>::searchVertice(Vertice<T> *vertice)
{
    for (int i = 0; i < grafo.size(); i++)
    {
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }
    return -1;
}

template<class T> Vertice<T> * GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for (auto i : grafo)
    {
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

template<class T> void GrafoOrientato<T>::addArco(Vertice<T> *v1, Vertice<T> *v2)
{
    int indice = searchVertice(v1);

    grafo.at(indice).append(v2);
}

template<class T> list<Vertice<T>*> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == vertice->getValue())
            return i.getLista();
    }
    return grafo.at(0).getLista();
}

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

template<class T> void GrafoOrientato<T>::DFS_VISIT(Vertice<T> *u)
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

    queue<T> coda_locale = coda;

    while (!coda_locale.empty())
    {
        fileOut << coda_locale.front() <<endl;
        coda_locale.pop();
    }

    fileOut.close();
    
}


#endif