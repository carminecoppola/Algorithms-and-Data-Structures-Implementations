#include <iostream>
#include <vector>
#include"maxPriorityQueue.h"
#include"maxHeap.h"

using namespace std;
int main(){

    vector<int> tree;

    maxPriorityQueue<int> albero = maxPriorityQueue<int>(tree);


    albero.insertPQ(106);
    albero.insertPQ(105);
    albero.insertPQ(104);
    albero.insertPQ(103);
    albero.insertPQ(110);
    albero.insertPQ(109);
    albero.insertPQ(108);
    albero.insertPQ(107);

    albero.print();

    /*Vediamo qual'è l'elemento massimo dell'array*/
    cout<<" -Il Massimo è : "<<albero.maximum()<<endl;

    /*Facciamo l'estrazione del massimo elemento dell'array, 
      cioè 110 che dovra scomparire */
    cout<<endl<<" -ExtractMax:"<<albero.extractMax()<<endl;
    cout<<endl<<"ALBERO DOPO EXTRACTMAX:";
    albero.print();

    /*Utilizziamo l'increase_key() per aumentare la priorirà di un elemento*/
    cout<<endl<<"INCREASE-KEY:";
    albero.increaseKey(2, 120);
    albero.print();
}