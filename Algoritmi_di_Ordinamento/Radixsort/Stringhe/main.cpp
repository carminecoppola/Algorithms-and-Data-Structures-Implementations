/*  Implementare radix sort su un array di parole di 4 caratteri  */

#include<iostream>
#include<vector>
#include<string>
#include"radixSort.h"

int main(){

    string A[] = {
        "zzzz",
        "bbbb",
        "aabb",
        "bbaa",
        "cccc",
        "dddd",
        "ccaa",
        "ddaa" };

    int size = sizeof(A)/sizeof(A[0]);

    cout<<"L'array iniziale: "<<endl<<endl;
    radixSort::print(A,size);
    radixSort::countingRadix(A,size,4);
    cout<<"L'array dopo RadixSort: "<<endl<<endl;
    radixSort::print(A,size);
    
    return 0;
}