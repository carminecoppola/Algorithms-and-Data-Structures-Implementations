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
#include<fstream>
#include<sstream>

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);

        int time;
        int DFS_VISIT(Vertice<T> *u);
        queue<T> coda;
    public:
        
        queue<T> getCoda(){return coda;}
        int searchVertice(Vertice<T> *vertice);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);
        int DFS();

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
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }
    return -1;
}

template<class T> Vertice<T> * GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for(auto i:grafo)
    {
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
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

template<class T> void GrafoOrientato<T>::addArco(Vertice<T> *v1, Vertice<T> *v2)
{
    int indice = searchVertice(v1);

    grafo.at(indice).append(v2);
}

template<class T> int GrafoOrientato<T>::DFS()
{
    int num_c = 0;

    for(auto u:grafo)
    {
        u.getVertice()->setColore(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
    }
    time = 0;

    for(auto u:grafo)
    {
        if(u.getVertice()->getColore() == Color::WHITE)
            num_c += DFS_VISIT(u.getVertice());              
    }
    cout<<"Numero cicli: " <<num_c <<endl;
    return num_c;
}

template<class T> int GrafoOrientato<T>::DFS_VISIT(Vertice<T> *u)
{
    int num_ciclo = 0;

    ofstream fileOut;
    string file2 = "Output.txt";

    fileOut.open(file2);


    u->setColore(Color::GRAY);
    u->setTempoInizio(time++);

    list<Vertice<T>*> adj = getListAdj(u);

    for(auto v:adj)
    {
        if(v->getColore() == Color::GRAY)
            num_ciclo++;
        if(v->getColore() == Color::WHITE)
        {
            v->setPredecessore(u);
            num_ciclo += DFS_VISIT(v);
        }
    }

    u->setColore(Color::BLACK);
    u->setTempoFine(time++);

    //Oridnamento topologico
    coda.push(u->getValue());

    queue<T> coda_locale = coda;

    while (!coda_locale.empty())
    {
        fileOut << coda_locale.front() << endl;
        coda_locale.pop();
    }
    fileOut.close();

    return num_ciclo;
}

#endif