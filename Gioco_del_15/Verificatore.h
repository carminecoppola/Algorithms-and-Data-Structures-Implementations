#ifndef VERIFICATORE_H
#define VERIFICATORE_H

#include <iostream>
#include <fstream>
#include <vector>

class Verificatore{
    private:
        std::ifstream myFile;
        std::vector<int> matrix;
        void getMatrix(){
            int value;
            for(auto i = 0;i<15;i++){
                myFile>>value;
                matrix.push_back(value);
            }
        };
    public:
        Verificatore(std::string nomeFile){
            myFile.open(nomeFile);
            this->getMatrix();
        };
        ~Verificatore(){
            this->matrix.clear();
            myFile.close();
        };
        bool check(){
            std::vector<int>::iterator it;
            auto i = 1;
            auto result = true;
            for (it = matrix.begin(); it!= matrix.end()&&result; it++,i++)
            {
                if (*it != i)
                {
                    result= false;
                    //Stampa
                } 
            }
            return result;
            
        }
};



//Verificatore::~Verificatore(){}

#endif