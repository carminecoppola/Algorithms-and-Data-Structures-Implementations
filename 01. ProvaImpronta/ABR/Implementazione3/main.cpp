#include"nodo.h"
#include"BinaryTree.h"

using namespace std;

int main(){

    BinaryTree<int> albero;

    albero.insert(13);
    albero.insert(12);
    albero.insert(16);
    albero.insert(10);
    albero.insert(11);
    albero.insert(14);
    albero.insert(17);

    cout<<endl<<"• Albero In-Order: "<<endl;
    albero.visitInOrder(albero.getRoot());
    cout<<endl;

    //Calcolo la radice
    cout<<endl<<"Radice: "<< albero.getRoot()->getInfo()<<endl;

    Nodo<int> *n = albero.treeSearch(albero.getRoot(),12);

    cout << endl <<"Questo è il nodo ricercato tramite la treeSearch(): " << n->getInfo() <<endl;

    //MAX E MIN
    cout << endl <<"Il mimimo dell'albero è: " << albero.getMinimum(albero.getRoot())->getInfo()<< endl; 
    cout << endl <<"Il massimo dell'albero è: " << albero.getMaximum(albero.getRoot())->getInfo()<< endl;

    //SUCCESSORE E PREDECESSORE
    cout << endl <<"Il predecessore del numero " << n->getInfo() << " è: " << albero.predecessor(n)->getInfo()<< endl;
    cout << endl <<"Il successore del numero " << n->getInfo() << " è: " << albero.successor(n)->getInfo()<< endl;

    

    return 0;
}