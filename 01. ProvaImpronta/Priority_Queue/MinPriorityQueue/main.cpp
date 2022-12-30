#include <iostream>
#include <vector>
#include"minPriorityQueue.h"
#include"minHeap.h"

using namespace std;
int main(){

    vector<int> tree;

    minPriorityQueue<int> albero = minPriorityQueue<int>(tree);


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
    cout<<" -Il Minimo è : "<<albero.minimum()<<endl;

    /*Facciamo l'estrazione del minimo elemento dell'array, 
      cioè 110 che dovra scomparire */
    cout<<endl<<" -ExtractMin:"<<albero.extractMin()<<endl;
    cout<<endl<<"ALBERO DOPO EXTRACTMIN:";
    albero.print();

    /*Utilizziamo la decrase_key() per diminuire la priorirà di un elemento*/
    cout<<endl<<"DECRASE-KEY:";
    albero.decrasePriority(2, 120);
    albero.print();

    return 0;
}