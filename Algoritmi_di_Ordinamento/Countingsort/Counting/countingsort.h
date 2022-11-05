#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <iostream>
#include <vector>
using namespace std;

class countingsort{
    private:
            /*data*/
    public:
        static void counting(vector<int> *);
        static void countingCormen(vector<int> *, vector<int> *);
};

void countingsort::counting(vector<int> *A){
    
}


void countingsort::countingCormen(vector<int> *A, vector<int> *B){

    int lenghtA = A->size();
    int max= A->at(0);
    int min= A->at(0);

    for (int i = 1; i < lenghtA; i++){

        if (A->at(i) > max){
            max = A->at(i);
        }
        else if (A->at(i) < min){
            min = A->at(i);
        }
    }

    //Costruzione dell'array C* di dimensione max-min+1
    int lenghtC = max-min+1;
    int *C = new int[lenghtC]; //Visto dalle slide da verificare

    for (int j = 0; j < lenghtC-1; j++){
        C[j] = 0; //Inizializzazione degli elementi di C
    }
    
    for (int k = 0; k < lenghtA-1; k++){
        C[A->at(k)]++;
    }

    for (int i = 1; i < lenghtC; i++){
        C[i] += C[i-1];
    }
    

    for (int i = lenghtA-1; i >= 0; i--){
        B->at(C[A->at(i)]-1) = A->at(i);
        C[A->at(i)]--;
    }
    
    delete[]C;
    
}



#endif