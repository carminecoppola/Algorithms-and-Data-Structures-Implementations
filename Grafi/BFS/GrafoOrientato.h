#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include<iostream>
#include<limits>
#include<queue>
#include<list>
#include<stack>
#include"Nodo.h"
#include"Vertice.h"

using namespace std;

template<class T>
class GrafoOrientato
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>* > getListAdj(Vertice<T> *);

    public:
        void addNodo(Nodo<T> );
        void addArco(int ,Vertice<T> * );
        void BFS(Vertice<T> *);
        void BFSRecursive(queue<Vertice<T>*> );

        //Facciamo l'overload dell'operatore
        friend ostream &operator<<(ostream &out, GrafoOrientato<T> &obj)
        {
            for(auto i:obj.grafo)
                out<<i<<endl;

            return out;
        }
};

//ADD NODO
/*Il nostro metodo addNodo servirà ovviamente per aggiungere un nodo
  poichè un grafo può essere visto come un vettore di nodi.*/
template<class T> void GrafoOrientato<T>::addNodo(Nodo<T> nodo)
{
    grafo.push_back(nodo);
}

//ADD ARCO
/*Per ogni nodo che inseriamo dobbiamo tracciare i vertici dato che ha una lista di vertici.
  Gli archi inseriti collegheranno il nodo inserito alla sua lista di adiacenza.
  i è dunque il nodo a cui è collegato il vertice che passiamo
  i = 0 append vertice(f) significa che il nodo 0 sarà collegato al vertice f 
  (creiamo la sua lista di adiacenza)
*/
template<class T> void GrafoOrientato<T>::addArco(int i, Vertice<T> *vertice)
{
    grafo.at(i).append(vertice);
}

//GETLISTADJ
/*Estraggo la lista di adiacenza del vertice specifico*/
template<class T> list<Vertice<T> *> GrafoOrientato<T>::getListAdj(Vertice<T> *vertice)
{
    for (auto i : grafo)
    {
        if (i.getVertice() == vertice)
            return i.getList();  
    }
    
    return grafo.at(0).getList();
}

//BFS
template<class T> void GrafoOrientato<T>::BFS(Vertice<T> *sorgente)
{
    //Inizializzazione
    for(auto u : grafo)
    {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }

    sorgente->setColor(Color::GRAY);
    sorgente->setDistanza(0);
    sorgente->setPredecessore(nullptr);
    queue<Vertice<T> *> q;

    //Inseriamo nella coda FIFO
    q.push(sorgente);       //ENQUEUE
    
    while(!q.empty())   //Finche la coda non è vuota
    {
        auto u = q.front();  //Viene utilizzato front per recuperare il primo elemento di una coda
        q.pop();

        //Creo la lista di adiacenza
        list<Vertice<T>* > adj = getListAdj(u);

        for(auto v : adj)
        {
            if(v->getColor() == Color::WHITE)
            {
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza() + 1);
                q.push(v);
            }
        }
        u->setColor(Color::BLACK);
    }

}

//BFS RICORSIVA
template<class T> void GrafoOrientato<T>::BFSRecursive(queue<Vertice<T>*> queue)
{
    static bool isFirst = true;

    if (isFirst)
    {
        //Inizializzazione
        for (auto u : grafo)
        {
            u.getVertice()->setColor(Color::WHITE);
            u.getVertice()->setPredecessore(nullptr);
            u.getVertice()->setDistanza(UINT16_MAX);
        }

        isFirst = false;
    }

    if(!queue.empty())
    {
        auto u = queue.front();
        queue.pop();

        list<Vertice<T>*> adj = getListAdj(u);

        for (auto v : adj)
        {
            if(v->getColor() == Color::WHITE)
            {
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza() + 1);
                queue.push(v);
            }
        }
        u->setColor(Color::BLACK);  //Finita la visita lo settiamo di colore Nero
        BFSRecursive(queue);
    }
    
}


#endif