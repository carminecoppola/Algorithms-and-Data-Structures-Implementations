#ifndef RADIXSORT_H
#define RADIXSORT_H

#include<iostream>
#include<vector>

using namespace std;

class Radixsort{
    private:
        static int getMax(vector<int> *A);
        static void countingRadix(vector<int> *A, int k);
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

/*  Questo metodo ha lo stesso funzionamento del counting sort, le uniche differenze
    sono che non prendiamo l'intero numero, ma partiamo dalla cifra meno significativa 
    fino ad arrivare a quella più significativa, questo lo faremo tramite il divisore (k)
    che passeremo dal main.
*/
void Radixsort::countingRadix(vector<int> *A, int k){

    int lenghtA = A->size();
    int output [lenghtA]; //Array di output
    int count[10] = {0}; //Array delle occorrenze inizializzato a zero

    //Occorrenze
    for (int i = 0; i < lenghtA; i++){       //es. C = 2 0 2 0 1 2 1 0 0 0   
        count[(A->at(i)/k) % 10]++;         //count[170/1 % 10]++   =>   count[0]++;
    }
    
    //Questo ciclo for ci darà la corretta posizione degli elementi di count
    for (int i = 1; i < 10; i++){       //es. C = 2 0 2 0 1 2 1 0 0 0
        count[i] += count[i-1];        //     C = 2 2 4 4 5 7 8 8 8 8
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

/*  In questo metodo utilizziamo il metodo scritto in precedenza per calcolarci
    l'elemento massimo "getMax()" che ci servirà per il countingRadix() eseguito
    in un ciclo for che parte da k = 1 finchè il rapporto tra l'elemento massimo e
    l'indice sia > 0, inoltre invece di incrementare l'indice lo moltiplichiamo
    ogni passaggio *10 come spiegato in seguito */

void Radixsort::radixsort(vector<int> *A){

    int massimo = getMax(A);    //utilizziamo il metodo getMax() per calcolarci il massimo
                               //es. A = 170 45 75 90 802 24 2 66    
                              //max = 802

    for (int k = 1; massimo/k > 0; k *= 10){        //div = 1;  802/1 => 802 > 0 V
        countingRadix(A,k);                        //div = 10; 802/10 => 80 > 0 V
    }                                             //div = 100 802/100 => 8 > 0 V
                                                 //div = 1000 802/1000 => 0. > 0 X
}

void Radixsort::print(vector<int> A){
    
    for (auto i:A){
        cout<<" "<<i<<"  ";
    }
    cout<<endl;
}

#endif