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
    list<Vertice<T>*> listaAdj;

    public:
    Nodo(Vertice<T> *vertice){this->vertice = vertice;}

    //Metodi di get
    Vertice<T> *getVertice(){return vertice;}
    list<Vertice<T>*> getList(){return listaAdj;}
    void append(Vertice<T> *vertice){listaAdj.push_back(vertice);}

    //Overload
    friend ostream &operator<<(ostream &out, const Nodo<T> &obj)
    {
        out<<*obj.vertice<<"-->";
        for(auto i :obj.listaAdj)
            out<<*i<<"-->";
        out<<"NULL";
        return out;
    }

};

#endif