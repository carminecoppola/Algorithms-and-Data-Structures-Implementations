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
        list<Vertice<T>*> listAdj;

    public:
        Nodo(Vertice<T> *vertice){this->vertice = vertice;}

        //Metodi di get
        Vertice<T> *getVertice(){return vertice;}
        list<Vertice<T>*> getListAdj(){return listAdj;}
        
        void append(Vertice<T> *vertice){listAdj.push_back(vertice);}
        //overload dell'operatore
        friend ostream& operator<<(ostream &out, const Nodo<T> &obj)
        {
            out<<*obj.vertice<<"-->";
            for(auto i:obj.listAdj)
                out<<*i<<"-->";
            out<<"NULL";
            return out;
        }
};

#endif