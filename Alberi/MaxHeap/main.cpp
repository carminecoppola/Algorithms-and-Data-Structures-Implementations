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

    vector<int> tree;
    maxHeap <int> albero = maxHeap<int>(tree);

    albero.insert(10);
    albero.insert(30);
    albero.insert(50);
    albero.insert(60);
    albero.insert(20);

    albero.printArray();

    return 0;
}