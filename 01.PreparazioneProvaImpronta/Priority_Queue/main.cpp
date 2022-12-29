#include <iostream>
#include <vector>
#include"priority_queue.h"
#include"maxHeap.h"

using namespace std;
int main(){

    vector<int> tree;

    priority_queue<int> albero = priority_queue<int>(tree);


    albero.insertPQ(106);
    albero.insertPQ(105);
    albero.insertPQ(104);
    albero.insertPQ(103);
    albero.insertPQ(110);
    albero.insertPQ(109);
    albero.insertPQ(108);
    albero.insertPQ(107);

    cout<<endl<<"ALBERO INIZIALE:"<<endl;
    albero.printArray();

    cout<<endl<<"EXTRACTMAX:"<<endl<<endl;
    cout<<" -Il Massimo è : "<<albero.maximum()<<endl;
    cout<<" -ExtractMax:"<<albero.extractMax()<<endl;
    cout<<endl<<"ALBERO DOPO EXTRACTMAX:"<<endl;
    albero.printArray();

    cout<<endl<<"INCREASEKEY:"<<endl<<endl;
    albero.increaseKey(2, 120);
    cout<<" -Albero dopo l'increase:"<<endl<<endl;
    albero.printArray();
}