/*  Progettare un algoritmo ricorsivo che dato un ABR sommi le
    chiavi comprese tra il valore m ed il valore M, con m<M
*/

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

template <class Item>
Item sumBetween(Nodo<Item> *tree , int max, int min){

    if (tree->getInfo() > max || tree->getInfo() < min)
        return tree->getInfo();
    
    else (tree->getInfo() > min && tree->getInfo() < max)
        return sumBetween(tree->getLeft(),max,min) + sumBetween(tree->getRight(),max,min);

};

int main(){

    binarySearchTree<int> tree;

    tree.insert(13);
    tree.insert(12);
    tree.insert(16);
    tree.insert(10);
    tree.insert(11);
    tree.insert(14);
    tree.insert(17);

    cout << endl << "• Albero Pre-Order: " << endl;
    tree.preOrderVisit(tree.getRoot());
    
    cout << endl << endl << "  -Radice: "<<tree.getRoot()->getInfo()<<endl;

    cout<<endl<<"• Albero In-Order: "<<endl;
    tree.inOrderVisit(tree.getRoot());
    cout<<endl;

    int m = 14, n = 11;
    int somma = sumBetween(tree.getRoot(),m,n); 
    cout << endl << " Il valore della somma dei numeri compresi tra " << n << " e " << m << " è: " << somma << endl; 
};