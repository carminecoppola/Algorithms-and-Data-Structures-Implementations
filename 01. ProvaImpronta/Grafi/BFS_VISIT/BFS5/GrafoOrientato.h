#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<list>
#include<limits>
#include<vector>
#include<queue>
#include<stack>

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

    public:
        
        queue<T> getCoda(){return coda;}
        int searchVertice(Vertice<T> *v);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T> *v1, Vertice<T> *v2);
        void BFS(Vertice<T> *sorgente);

        //Overload
        friend ostream& operator<<(ostream& out, GrafoOrientato<T> &obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;
            return out;
        }

};

//SearchVertice
template<class T> int GrafoOrientato<T>::searchVertice(Vertice<T> *v)
{
    for(int i = 0; i < grafo.size(); i++)
    {
        if(this->grafo.at(i).getVertice()->getValue() == v->getValue())
            return i;
    }
    return -1;
}

//GetIndirizzoVertice
template<class T> Vertice<T> *GrafoOrientato<T>::getIndirizzoVertice(T value)
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
        if(i.getVertice() == vertice)
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

template<class T> void GrafoOrientato<T>::BFS(Vertice<T> *sorgente)
{
    //Per scrivere sul file di output ci creiamo il file e lo apriamo nella BFS
    ofstream output;
    output.open("Output.txt");


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

    while(!coda.empty())
    {
        auto u = coda.front();
        coda.pop();

        list<Vertice<T>*> adj = getListAdj(u);

        for(auto v:adj)
        {
            if(v->getColore() == Color::WHITE)
            {
                v->setColore(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(v->getDistanza()+1);
                coda.push(v);
            }
        }

        u->setColore(Color::BLACK);
        output << u->getValue() <<endl;  //Stampiamo sul file di output

    }

    /*Dato che la BFS non riesce per forza a visitare tutti i nodi 
    ci stampiamo anche quali sono i vertici non raggiungibili nella visita. */

    cout <<endl<< "***Questi sono i Vertici NON raggiungibili: " <<endl;
    for(auto i:grafo)
    {
        if(i.getVertice()->getDistanza() == UINT16_MAX)
        cout<< *(i.getVertice())<<endl;
    }
    output.close();

}

#endif