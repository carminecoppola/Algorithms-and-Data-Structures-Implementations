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
#include"MinPriorityQueue.h"

using namespace std;

int main(){

    vector<int> tree {10,2,21,1,45,8,12,78};
    MinPriorityQueue <int> albero = MinPriorityQueue<int>();

    int k = 3;
    
   for (int i = 0; i < k; i++)
   {
        albero.insertMH(tree.at(i));
   }

    for (int j = k; j < tree.size(); j++)
    {
        if (tree.at(j) > albero.getAlbero().at(0))
        {
            cout<<endl<<"Inserito poiche "<<tree.at(j)<<" > "<<albero.getAlbero().at(0)<<endl;
            albero.insertMH(tree.at(j));
            albero.extractMin();
        }
        else{
            cout<<endl<<"L'elemento NON viene inserito poichè "<<tree.at(j)<<" < "<<albero.getAlbero().at(0)<<endl;
        }


    }

    albero.printArray();

    cout<<"L'elemento k-esimo più grande è: "<<albero.minimum()<<endl;
    
    return 0;
}

