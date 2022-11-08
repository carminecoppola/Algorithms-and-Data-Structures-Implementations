/* Progettare ed implementare una lista (linked list) di impiegati di un'azienda. 
   Un impiegato ha un nome ed un salario. Un manager è un impiegato cui viene 
   corrisposto un bonus oltre al salario.
     1)Creare una lista di impiegati e stamparla a video sfruttando il principio 
       del polimorfismo
     2)Implementare l'overload dell'operatore + in modo da sommare i salari di 
       tutti gli impiegati.
*/

#include <iostream>
#include "impiegato.h"
#include "manager.h"
#include "lista.h"

using namespace std;

int main(){

    Lista *prova = new Lista();

    prova->insLista(new Impiegato("Antonio",1000));
    prova->insLista(new Manager(80000,"Ciro",500000));
    prova->insLista(new Manager(700,"Francesca",2000));
    prova->insLista(new Manager(5000,"Miniello",100000));
    prova->insLista(new Impiegato("Anna",4000));
    prova->printLista();

    prova->somma();
    
    return 0;
}