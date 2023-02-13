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
        list<Vertice<T>*> lista;

    public:
        Nodo(Vertice<T> *vertice){this->vertice = vertice;}

        //Metodi di get
        Vertice<T> *getVertice(){return vertice;}
        list<Vertice<T>*> getLista(){return lista;}
        void append(Vertice<T> *vertice){lista.push_back(vertice);}

        //Overload
        friend ostream& operator<<(ostream& out, const Nodo<T>& obj)
        {
            out<<*obj.vertice<<"-->";
            for(auto i:obj.lista)
                out<<*i<<"-->";
            out<<"NULL";
            return out;
        }
};

#endif
