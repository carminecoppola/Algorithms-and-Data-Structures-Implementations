/*  Progettare un algoritmo che dato un ABR ed una chiave k
    restitusca il successore dispari di k
*/

#include "binarySearchTree.h"
#include<iostream>

using namespace std;

template<class Item>
Item successorShots(binarySearchTree<Item> tree, Item k){

    auto successore = tree.successorTree(tree.treeSearch(k,tree.getRoot()));

    if (successore->getInfo() %2 == 0)
        return tree.successorTree(successore)->getInfo();
    else
        return successore->getInfo();
    
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

    cout<<endl<<"• Albero Pre-Order: "<<endl;
    tree.preOrderVisit(tree.getRoot());
    
    cout<<endl<<endl<<"  -Radice: "<<tree.getRoot()->getInfo()<<endl;

    cout<<endl<<"• Albero In-Order: "<<endl;
    tree.inOrderVisit(tree.getRoot());
    cout<<endl;

    int num = tree.treeSearch(12,tree.getRoot())->getInfo();

    cout << "Il successore dispari di " << num << " è: " << successorShots(tree,num) <<endl;

    return 0;
}