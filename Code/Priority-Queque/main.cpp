/*Progettare ed implementare una classe priority-queue
    che implementi le seguenti operazioni:
        1. Insert(S,x)
        2. maximum(S)/Minimum(S)
        3. Extract-Max(S)/Extract-Min(S)
        4. Increse-priority(S,x,k)/Decrese-priority(S,x,k)
*/

#include <iostream>
#include "maxHeap.h"
#include "priority_queue.h"

int main(){

    vector<int> tree;
    priority_queue <int> albero = priority_queue<int>(tree);

    albero.insertMH(106);
    albero.insertMH(105);
    albero.insertMH(104);
    albero.insertMH(103);
    albero.insertMH(110);
    albero.insertMH(109);
    albero.insertMH(108);
    albero.insertMH(107);

    albero.printArray();

    cout<<endl<<"L'elemento maggiore estratto è:"<< albero.extractMax()<<endl<<endl;

    albero.IncreasePriority(103,120);
    albero.printArray();

    return 0;
}