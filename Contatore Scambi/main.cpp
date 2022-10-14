/*  Progettare ed implementare un algoritmo ricorsivo per contare il 
    numero di scambi necessari per ordinare un' array

                    [9,7,3,1]->(9,7),(9,3),(9,1)
                    [7,3,1,9]->(7,3),(7,1)
                    [3,1,7,9]->(3,1)
                    [1,3,7,9]
*/

//Marge a due vie

#include <iostream>

using namespace std;

//Prende in input l'array con e l'indice di SX e DX
void mergesort(int [], int ,int );
//Prende in input i due sottoarray, l'array temporaneo, e i loro size
void merge(int [],int [],int ,int [],int );

int main(){

    return 0;
}


void merge(int c[],int a[],int N,int b[],int M){

    //Finche il non abbiamo raggiunto il size dei due sotto array
    //prendiamo tutti gli elementi di A e di B

    for (int i = 0, j = 0, k = 0; k < N+M; k++){

        //Se ho preso gia tutti gli elementi di A prendo tutti 
        //i rimaneti di B che sono gia ordinati
        if (i == N){
            c[k] = b[j++];

        }
        
        //Se ho preso gia tutti gli elementi di B prendo tutti 
        //i rimaneti di A che sono gia ordinati
        else if (j == M){
            c[k] = a[i++];
        }
        
        //c[k] = (a[i]< b[j])

            
    }
    

}