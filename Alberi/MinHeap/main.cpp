/*  Progettare ed implementare una algoritmo che, dato un
    Min-Heap ed un valore X, stampi la somma dei valori dei
    nodi minori di X.
        • Es.: X=8 -> S=13
*/

#include<iostream>
#include<vector>
#include "minHeap.h"

using namespace std;

int main(){
    
    vector<int> tree;
    minHeap<int> albero = minHeap<int>(tree);

    albero.insert(10);
    albero.insert(30);
    albero.insert(50);
    albero.insert(60);
    albero.insert(20);

    albero.printArray();

    return 0;
}