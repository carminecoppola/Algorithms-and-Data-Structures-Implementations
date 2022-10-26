/*  Progettare ed implementare un algoritmo ricorsivo che dato
    un array verifichi se rappresenta un heap binario
*/

#include<iostream>
#include <vector>
#include"isHeap.h"

using namespace std;

int main(){

    vector<int> tree{60,50,30,10,20};    //E un max
    //vector<int> tree{40,50,30,10,20};   //Non è un Max ne un min
    //vector<int> tree{10,20,50,60,30};  //E' un min 
    //vector<int> tree{21,20,50,60,30}; //Non è un min ne un max
    isHeap<int> albero;

    albero.print(tree,tree.size(),0);

    //vector<int>treem{21,20,50,60,30};
    //isHeap<int>alb;



    return 0;
}