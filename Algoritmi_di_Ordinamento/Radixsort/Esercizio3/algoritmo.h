#ifndef ALGORITMO_H
#define ALGORITMO_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class algoritmo{
    private:
        static int getMax(vector<string> A);
    public:
        static void countingRadix(vector<string> *A);
        static void print(vector<string> A);
};

int algoritmo::getMax(vector<string> A){

    int massimo = A.at(0).length();  //Lenght indica la lunghezza del singolo elemento mentre size di tutto l'array
    
    for (int i = 1; i < A.size(); i++){
        if (A.at(i).length() > massimo){     //Dobbiamo confrontare l'esima lunghezza della stringa
                                            // con il massimo
            massimo = A.at(i).length();    // e scambiamo
        }
    }
    return massimo;
}

void algoritmo::countingRadix(vector<string> *A){

    int lenghtA = A->size();
    vector<string> output(lenghtA);     //Creo l'array di l'output a cui passo il size di A
    int max = getMax(*A);
    int lenghtC = max+1;
    vector<int> count(lenghtC);

    //Costruzione dell'array C* di dimensione max+1
    for (int i = 0; i < lenghtC; i++){
        count.at(i) = 0;
        
    }
    
    for (int i = 0; i < lenghtA; i++){
        count.at(A->at(i).length())++;      //Aumento il valore dell'occorrenza

    }
    
    //Aggiorno il numero di numero di occorrenze
    for (int i = 1; i < lenghtC; i++){
        count.at(i) +=  count.at(i-1);
    }
    
    //Creazione array C* di output
    for (int i = lenghtA-1; i >= 0; i--){
        output.at(count.at(A->at(i).length())-1) = A->at(i);
        count.at(A->at(i).length())--;
    }

    //Copio l'array di output nell'array iniziale
    for (int i = 0; i < lenghtA; i++){
        A->at(i) = output.at(i);
    }
}


void algoritmo::print(vector<string> A){

    for(auto i : A){

        cout<<" "<< i<<endl;
    }
    cout<<endl;

}

#endif