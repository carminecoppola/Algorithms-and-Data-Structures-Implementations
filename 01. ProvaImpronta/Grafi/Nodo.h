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
        Nodo(Vertice<T> * vertice){this->vertice = vertice;}
    
        //Metodi di get
        Vertice<T> *getVertice(){return vertice;}
        list<Vertice<T>*> getList(){return listaAdiacenza;}

        void append(Vertice<T> *);

        friend ostream &operator<<(ostream &out, const Nodo<T> &obj)
        {
            out<<*obj.vertice<<"-->";
            for(auto i :obj.listaAdiacenza)
                out<<*i<<"-->";
            out<<"NULL";
            return out;
        }

};

template<class T> void Nodo<T>::append(Vertice<T> *vertice)
{
    listaAdiacenza.push_back(vertice);
}

#endif