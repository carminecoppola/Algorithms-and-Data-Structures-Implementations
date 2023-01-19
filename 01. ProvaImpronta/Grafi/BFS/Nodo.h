#ifndef NODO_H
#define NODO_H

#include<iostream>
#include<list>
#include"Vertice.h"
using namespace std;

template<class T>
class Nodo
{
    private:

        Vertice<T> *vertice;
        list<Vertice<T>*> listaAdiacenza;
    public:
        Nodo(Vertice<T> *vertice){this->vertice = vertice;}

        //Metodi di getter
        Vertice<T> *getVertice(){return vertice;}
        list<Vertice<T>*> getList(){return listaAdiacenza;}

        void append(Vertice<T> *);

        //C'è bisogno dell'overload dell'operatore
        friend ostream &operator<<(ostream &out, const Nodo<T> &obj){
            out<<*obj.vertice<<"-->";
            for(auto i :obj.listaAdiacenza)
                out<<*i<<"-->";
            out<<"NULL";
            return out;
        }

};

//L'append serve per aggiungere i vertici alla lista di adiacenza di quel nodo
template<class T> void Nodo<T>::append(Vertice<T> *vertice)
{
    listaAdiacenza.push_back(vertice);
}

#endif