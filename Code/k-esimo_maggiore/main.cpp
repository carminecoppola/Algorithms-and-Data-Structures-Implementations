/*  Data una sequenza di interi (rappresentata da un array),.
    trovare il k-esimo elemento più grande per ogni i=0...N-1.
        seq = [10,2,21,1,-1,45,8,12,78]
        k = 2
        i = 1 k-max = 3
        i = 2 k-max = 10
        i = 3 k-max = 10
        ...
*/

#include <iostream>
#include <vector>
#include"kMax.h"

using namespace std;

int main(){

    vector<int> tree {10,3,21};
    kMax <int> albero = kMax<int>(tree);

    albero.buildMinHeap();
    albero.printArray();

    cout<<endl<<"Il secondo minimo è: "<<albero.secondoMin()<<endl;
    


    return 0;
}