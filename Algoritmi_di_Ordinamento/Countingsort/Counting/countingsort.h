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
        static void countingInverso(vector<int> *);
};

void countingsort::counting(vector<int> *A){

    int lenghtA = A->size();
    //Impostiamo il massimo e il minimo dell'array
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
        C[A->at(k)-min]++;
    }

    //Qui ordinaimo in base alla frequenza (contenuta nel vettore C) degli elementi di A;

    int k = 0; 
    //indice per l'array A
    for (int i = 0; i < lenghtC; i++){
        while (C[i] > 0){
            //Scriviamo C[i] volte il valore i+min dell'array A
            A->at(k) = i+min;
            k++;
            C[i]--;
        }  
    }
    
    delete[]C;
    
}


void countingsort::countingCormen(vector<int> *A, vector<int> *B){

    int lenghtA = A->size();
    //Impostiamo il massimo e il minimo dell'array
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

void countingsort::countingInverso(vector<int> *A){

    int lenghtA = A->size();
    //Impostiamo il massimo e il minimo dell'array
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

    for (int j = 0; j < lenghtC; j++){
        C[j] = 0; //Inizializzazione degli elementi di C
    }
    
    for (int k = 0; k < lenghtA; k++){
        C[A->at(k)-min]++;
    }

    /*Qui ordinaimo in base alla frequenza (contenuta nel vettore C) degli elementi di A
      ma lo facciamo partendo dalla fine dell'array C (lenghtC-1), finche non è >= 0 e 
      decrementiamo l'indice, tutto ciò perchè bisogna ordinare in maniera decrescente;
    */

    int k = 0; 
    //indice per l'array A
    for (int i = lenghtC-1; i >= 0; i--){
        while (C[i] > 0){
            //Scriviamo C[i] volte il valore i+min dell'array A
            A->at(k) = i+min;
            k++;
            C[i]--;
        }  
    }
    
    delete[]C;
   
}

#endif