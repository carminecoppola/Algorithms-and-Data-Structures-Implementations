#ifndef NODO_H
#define NODO_H

#include"Vertice.h"
#include<iostream>
#include<list>

using namespace std;

template<class T>
class Nodo
{
    private:
        Vertice<T> *vertice;
        list<Vertice<T>*> listaAdj;

    public:
        Nodo(Vertice<T> *vertice){this->vertice = vertice;}

        //Get
        Vertice<T> *getVertice(){return vertice;}
        list<Vertice<T>*> getLista(){return listaAdj;}

        void append(Vertice<T> *vertice){listaAdj.push_back(vertice);}

        friend ostream& operator<<(ostream& out, const Nodo<T>& obj)
        {
            out<<*obj.vertice<<"-->";
            for(auto i:obj.listaAdj)
                out<<*i<<"-->";
            out<<"NULL";
            return out;
        }
};

#endif