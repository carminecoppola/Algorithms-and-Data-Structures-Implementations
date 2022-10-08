#ifndef CONTATORE_H
#define CONTATORE_

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Contatore{
    private:
        ifstream myFile;
        map <string,int> occorrenze;
    public:
        Contatore(string);
        ~Contatore();

        void contaOccorrenze();
};

Contatore::Contatore(string nf){
    myFile.open(nf,ios::in);
}

Contatore::~Contatore(){
    myFile.clear();
    myFile.close();
}


void Contatore::contaOccorrenze(){
    map<string, int>::iterator it;
    string word;

    while (myFile>>word)
    {
        it = occorrenze.find(word);

        if (it == occorrenze.end()){
            occorrenze.insert(make_pair(word,1));
        }
        else{
            occorrenze.at(word)++;      
        }  
    }
    
     for(it =occorrenze.begin(); it!=occorrenze.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;
}

#endif //CONTATORE_H