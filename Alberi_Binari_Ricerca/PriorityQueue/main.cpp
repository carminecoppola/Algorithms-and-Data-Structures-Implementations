
/*  Progettare una classe PriorityQueue che implementi una 
    coda di priorità basata su BinarySearchTree. */

#include<iostream>
#include"binarySearchTree.h"
#include"maxPriorityQueue.h"

using namespace std;

int main(){

    maxPriorityQueue<int> albero;

    albero.insertMH(10);
    albero.insertMH(13);
    albero.insertMH(14);
    albero.insertMH(16);
    albero.insertMH(12);
    albero.insertMH(17);
    albero.insertMH(11);

    cout << endl << "Questo è l'albero con PriorityQueue: "<<endl;
    albero.printABR();
    cout << endl;
    
    cout << endl << "Questo è il massimo: " << albero.maximum() << endl;
 
    cout << endl << "Extract Max: " << endl;
    albero.extractMax();
    albero.printABR();

    cout << endl << "Decrese: " << endl;
    albero.IncreasePriority(11,18);
    albero.printABR();
    cout << endl;

    return 0;
}
