#ifndef MANAGER_H
#define MANAGER_H
#include "impiegato.h"
#include <string>
#include <iostream>


class Manager:public Impiegato{
    private:
        float bonus;

    public:
        Manager(float b,string n,float s);
        float getSalario();
        void printInfo();
        
};

Manager::Manager(float b,string n,float s):Impiegato(n,s),bonus(b){

}
//Possiamo sempilicemente aggiungere il bonus ed utilizzare il metodo getSalario() che gia avevamo:
float Manager::getSalario(){
    return(Impiegato::getSalario()+bonus);
}

void Manager::printInfo(){
    cout << "Manager"<<endl<<endl<<"Nome:"<<this-> getNome()<<endl<<"Salario con aggiunta bonus:"<<this->getSalario()<<endl;
}

#endif //MANAGER_