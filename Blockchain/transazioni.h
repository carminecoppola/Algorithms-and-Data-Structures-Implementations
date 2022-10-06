
#ifndef TRANSAZIONI_H
#define TRANSAZIONI_H
#include <iostream>
#include <string>

using namespace std;

class Transazioni{
    private:
        string from;
        string to;
        float qt;
    public:
        Transazioni(string ,string ,float);   //Costruttore
        //~Transazioni();
        
        void setFrom(string );
        void setTo(string );
        void setQt(float );

        string getFrom(){
            return from;
        }
        string getTo(){
            return to;
        }
        float getQt(){
            return qt;
        }

        void printTransazione();    //Metodo per stampare le transazioni
};

//Costruttore
Transazioni::Transazioni(string f,string t,float q){
    from = f;
    to = t;
    qt = q;
}

//Distruttore
//Transazioni::~Transazioni(){}

void Transazioni::setFrom(string fr){
    from = fr;
}

void Transazioni::setTo(string t){
    to = t;
}

void Transazioni::setQt(float quant){
    qt = quant;
}

void Transazioni::printTransazione(){
    cout << endl << "This is the frist transaction:" << endl;
    cout << endl << "Transaction From: " << from<< endl 
         << "Transaction To: "<< to << endl
         << "Transaction Quantity: "<< qt << endl << endl;
}

#endif //TRANSAZIONI_H