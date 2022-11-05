#ifndef RADIXSORT_H
#define RADIXSORT_H

#include<iostream>
#include<vector>

using namespace std;

class Radixsort{
private:
    /* data */
public:
    static void radixsort(vector<int> *A);
    static void counting(vector<int> *A, int i);
    static int getMax(vector<int> *A);
    static void print(vector<int> );
};

int Radixsort::getMax(vector<int> *A){

    
    int max = A->at(0);

    for (int i = 1; i < A->size(); i++){
        if (A->at(i) > max){
            max = A->at(i);
        }   
    }
    return max;   
}

void Radixsort::counting(vector<int> *A, int k){

    int lenghtA = A->size();
    int output [lenghtA]; //Array di output
    int count[10] = {0}; //Array delle occorrenze

    //Occorrenze
    for (int i = 0; i < lenghtA; i++){
        count[(A->at(i)/k) % 10]++;
    }
    
    //Corretta posizione di count
    for (int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    //Array di output
    for (int i = lenghtA-1; i >= 0; i--){
        output[count[(A->at(i)/k)%10]-1] = A->at(i);
        count [(A->at(i)/k)%10]--;
    }
    
    //Copia Array
    for (int i = 0; i < lenghtA; i++){
        A->at(i) = output[i];
    } 

}

void Radixsort::radixsort(vector<int> *A){

    int massimo = getMax(A); 

    for (int k = 1; massimo/k > 0; k *= 10){
        counting(A,k);
    }
    
}

void Radixsort::print(vector<int> A){

    
    for (auto i:A)
    {
        cout<<" "<<i;
    }
    cout<<endl;
}

#endif