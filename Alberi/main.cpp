/*  Progettare ed implementare una classe template Max-Heap
    dotata delle seguenti operazioni
        • Max-Heapify
        • Build-Max-Heap 
        • Insert
        • PrintArray
        • (PrintAsciiTree)
*/
#include<iostream>
#include<vector>
#include "maxHeap.h"

using namespace std;

int main(){

    vector <int> albero[5] = new maxHeap();

    albero->insert(10);
    albero->insert(20);
    albero->insert(3);
    albero->insert(15);
    albero->insert(7);
    return 0;
}