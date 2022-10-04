
#ifndef BLOCCHI_H
#define BLOCCHI_H
#include <iostream>
#include <string>
#include "transazioni.h"


class Blocchi{
    private:
        string id;
        Transazioni *listaBlocchi;
    public:
        Blocchi(string ,Transazioni *);
        //~Blocchi();
        void setId();
        void setListaBlocchi();
        string getId(){
            return id;
        }
        Transazioni getListaBlocchi(){
            return *listaBlocchi;
        }
        //void *listaBlocchi();

};

Blocchi::Blocchi(string i,Transazioni *lb){
    id = i;
    listaBlocchi = lb;
}

//Blocchi::~Blocchi(){}



#endif //BLOCCHI_H