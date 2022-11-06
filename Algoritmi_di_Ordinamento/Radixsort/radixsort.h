#ifndef RADIXSORT_H
#define RADIXSORT_H

#include<iostream>
#include<vector>

using namespace std;

class Radixsort{
    private:
        static void counting(vector<int> *A, int i);
        static int getMax(vector<int> *A);
    public:
        static void radixsort(vector<int> *A);
        static void print(vector<int> );
};

int Radixsort::getMax(vector<int> *A){

    int max = A->at(0); //Impostiamo la variabile max al primo elemento dell'array

    for (int i = 1; i < A->size(); i++){
        if (A->at(i) > max){    //Se l'i-esimo elemento è > del massimo lo sostituiamo
            max = A->at(i);
        }   
    }
    return max;   
}

void Radixsort::counting(vector<int> *A, int k){

    int lenghtA = A->size();
    int output [lenghtA]; //Array di output
    int count[10] = {0}; //Array delle occorrenze inizializzato a zero

    //Occorrenze
    for (int i = 0; i < lenghtA; i++){
        count[(A->at(i)/k) % 10]++;
    }
    
    //Questo ciclo for ci darà la corretta posizione degli elementi di count
    for (int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    //Questo ciclo for serve per creare l'array di output
    for (int i = lenghtA-1; i >= 0; i--){
        output[count[(A->at(i)/k)%10]-1] = A->at(i);
        count [(A->at(i)/k)%10]--;
    }
    
    //Questo ciclo for copia l'array di output nell'array iniziale
    for (int i = 0; i < lenghtA; i++){
        A->at(i) = output[i];
    } 

}

void Radixsort::radixsort(vector<int> *A){

    int massimo = getMax(A);    //utilizziamo il metodo getMax() per calcolarci il massimo

    for (int k = 1; massimo/k > 0; k *= 10){
        counting(A,k);
    }
    
}

void Radixsort::print(vector<int> A){
    
    for (auto i:A){
        cout<<" "<<i<<"  ";
    }
    cout<<endl;
}

#endif