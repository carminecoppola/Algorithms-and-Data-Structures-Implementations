#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<limits>
#include<vector>
#include<queue>
#include<stack>
#include<list>

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListAdj(Vertice<T> *vertice);
        
        queue<T> q;

    public:
        queue<T> getQueue(){return q;}
        int searchVertice(Vertice<T> *v);
        Vertice<T> *getIndirizzoVertice(T value);

        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T> *v1,Vertice<T> *v2);

        void BFS(Vertice<T> *sorgente);

        friend ostream& operator<<(ostream &out, GrafoOrientato<T> &obj)
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

//Questa funzione mi servirà per ritornare l'indirizzo del vertice
template<class T> Vertice<T> * GrafoOrientato<T>::getIndirizzoVertice(T value)
{
    for(auto nodo:grafo)
    {
        if(nodo.getVertice()->getValue() == value)
            return nodo.getVertice();
    }

    return nullptr;
}


/*Il metodo getListAdj restituisce la lista di vertici adiacenti 
  (listAdj) di un vertice specifico. Viene cercato il vertice 
  nella struttura dati (vettore di nodi) e quando viene trovato, 
  viene restituita la sua lista di vertici adiacenti. Se il vertice 
  non viene trovato, viene restituita la lista di vertici adiacenti 
  del primo nodo nel vettore di nodi.*/

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
    for(auto u:grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }

    sorgente->setColor(Color::WHITE);
    sorgente->setPredecessore(nullptr);
    sorgente->setDistanza(0);

    queue<Vertice<T>*> coda;
    coda.push(sorgente);

    while(!coda.empty())
    {
        auto u = coda.front();  //Primo elemento della coda
        coda.pop();

        list<Vertice<T>*> adj = getListAdj(u);

        for(auto v:adj)
        {
            if(v->getColor() == Color::WHITE)
            {
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza()+1);
                coda.push(v);
            }
        }

       u->setColor(Color::BLACK); 
    } 
}

#endif