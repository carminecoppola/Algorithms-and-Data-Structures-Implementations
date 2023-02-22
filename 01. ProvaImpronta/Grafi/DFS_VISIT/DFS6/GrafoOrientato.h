#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<limits>
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

        void DFS_VISIT(Vertice<T> *u);
        int time;
        queue<T> coda;

    public:
        queue<T> getCoda(){return coda;}
        int searchVertice(Vertice<T> *vertice);
        Vertice<T> *getIndirizzoVertice(T value);

        void DFS();

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);

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
    for(int i = 0; i< grafo.size(); i++)
    {
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }
    return -1;
}

//GetIndirizzoVertice
template<class T> Vertice<T> * GrafoOrientato<T>::getIndirizzoVertice(T value)
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
            // Albero (tree) edge
            v->setPredecessore(u);
            DFS_VISIT(v);
        }
        else if(v->getColore() == Color::GRAY)
        {
            // Back edge
            // L'arco (u,v) forma un ciclo
            fileOut << "Back Edge: (" << u->getValue() << ", " << v->getValue() << ")" << endl;
        }
        else
        {
            // Forward edge o cross edge
            // L'arco (u,v) è un forward edge se u->getTempoInizio() < v->getTempoInizio()
            // L'arco (u,v) è un cross edge se u->getTempoInizio() > v->getTempoInizio()
            fileOut << "Forward/Cross Edge: (" << u->getValue() << ", " << v->getValue() << ")" << endl;
        }
    }
    u->setColore(Color::BLACK);
    u->setTempoFine(time++);

    coda.push(u->getValue());
    
    queue<int> coda_locale = coda;
    while (!coda_locale.empty())
    {
        fileOut << coda_locale.front() <<endl;
        coda_locale.pop();
    }

    fileOut.close();
}


#endif