#ifndef VERIFICATORE_H
#define VERIFICATORE_H

#include <iostream>
#include <fstream>
#include <vector>

class Verificatore{
    private:
        std::ifstream myFile;
        std::vector<int> matrix;

        void getMatrix();

    public:
        //Costruttore
        Verificatore(std::string nomeFile);
        //Distruttore
        ~Verificatore();
        //Controllo dei numeri presenti
        bool check();
};

Verificatore::Verificatore(std::string nomeFile){
     myFile.open(nomeFile);
            this->getMatrix();
}

Verificatore::~Verificatore(){
    this->matrix.clear();
            myFile.close();
}

void Verificatore::getMatrix(){
    int value;

    for(auto i = 0;i<15;i++){
        myFile>>value;
        matrix.push_back(value);
    }
}

bool Verificatore::check(){
    std::vector<int>::iterator it;
    auto i = 1;
    auto result = true;

    for (it = matrix.begin(); it!= matrix.end()&&result; it++,i++){
        if (*it != i){
            result= false;
            //Stampa
        } 
    }
    return result;
}

#endif //VERIFICATORE_H