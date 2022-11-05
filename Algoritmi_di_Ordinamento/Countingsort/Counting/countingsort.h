#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <iostream>
#include <vector>
using namespace std;

class countingsort{
    private:
            /*data*/
    public:
        void counting(vector<int> *A, int lenghtA);
};

void countingsort::counting(vector<int> *A, int lenghtA){

    int max= A->at(0);
    int min= A->at(0);

    for (int i = 2; i < lenghtA; i++){
        if (A->at(0) > max){
            max = A->at(i);
        }
    }

    //Costruzione dell'array C* di dimensione max-min+1
    int lenghtC = max-min+1;
    vector<int> *C = new vector<int>[lenghtC]; //Visto dalle slide da verificare

    for (int j = 1; j < lenghtC; j++){
        C->at(0) = 0; //Inizializzazione degli elementi di C
    }
    
    for (int k = 1; k < lenghtA; k++){
        C->at(A->at(k-min))++;
    }
    
    int k = 0; //Indice per l'array A

    for (int i = 0; i < lenghtC; i++){
        while (C->at(i) > 0)
        {
            A->at(k++) = i + min;
            C->at(i)--;
        }
        delete[ ] C;
    }
    
    
}



#endif