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
        list<Nodo<T>*> listaAdj;

    public:
        Nodo(Vertice<T> *vertice){this->vertice = vertice;}

        //GET
        Vertice<T> *getVertice(){return vertice;}
        list<Nodo<T>*> getLista(){return listaAdj;}
        void append(Vertice<T> *vertice){listaAdj.push_back(vertice);}
        
        //Overload
        friend ostream& operator<<(ostream& out, const Nodo<T>&obj)
        {
            out<<obj.vertice<<"-->";
            for(auto i:obj.listaAdj)
                out<<*i<<"-->";
            out<<"NULL";
            return out;
        }
};

#endif