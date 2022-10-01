
#ifndef IMPIEGATO_H
#define IMPIEGATO_H
#include <string>
#include <iostream>

using namespace std;

class Impiegato{
    private:
        string nome;
        float salario;
    public:
         Impiegato(string ,float); //Costruttore

        void setNome(string);
        virtual void setSalario(float);
        Impiegato operator+(Impiegato );

        string getNome(){
            return nome;
        }

        float getSalario(){
            return salario;
        }

        virtual void printInfo();

};

//Costruttore
Impiegato::Impiegato(string n, float s){
    nome=n;
    salario=s;
}

void Impiegato::setNome(string nom){
    nome = nom;
}
void Impiegato::setSalario(float stipendio){
    salario=stipendio;
}

void Impiegato::printInfo(){
    cout << endl << "Impiegato" << endl;
    cout << endl << "Nome:" << getNome()<< endl;
    cout << endl << "Salario:" << getSalario()<< endl<< endl;
}

Impiegato Impiegato::operator+(Impiegato a )
{
    Impiegato temp("", 0);
    
    temp.setSalario(this->getSalario() + a.getSalario());
    return temp;
}


#endif //IMPIEGATO_H