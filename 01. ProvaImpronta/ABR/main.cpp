/*Implementare un ABR con tutti i metodi*/

#include <iostream>
#include"BinaryTree.h"

using namespace std;

int main(){

    BinaryTree<int> tree;

    cout<<endl<<"CIAOOO"<<endl;

    tree.insert(11);
    tree.insert(12);
    tree.insert(16);
    tree.insert(10);
    tree.insert(13);
    tree.insert(14);
    tree.insert(17);
    
    cout<<"PROVA";

    cout<<"tree INORDER: ";
    tree.visitInOrder(tree.getRoot());
    cout<<endl<<"tree PREORDER: ";
    tree.visitPreOrder(tree.getRoot());
    cout<<"tree POSTORDER: ";
    tree.visitPostOrder(tree.getRoot());

    return 0;
}