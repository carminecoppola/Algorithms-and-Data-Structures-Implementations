/* 
La blockchain è una struttura dati composta da una lista di blocchi all'interno 
dei quali è memorizzato un insieme di transazioni. Una transazione è costituita da 
un indirizzo FROM, un indirizzo TO ed un valore intero QT.
    1) Progettare ed implementare una struttura dati LinkedList mediante template ed 
       utilizzarla per realizzare una blockchain
    2) Dato un indirizzo A, stampare a video/salvare su file tutte le transazioni in 
       cui compare A ed il suo bilancio finale 
*/

#include <iostream>
#include "transazioni.h"
#include "linkedList.h"
#include "nodo.h"
#include "blocchi.h"

using namespace std;

int main (){

   /*Blocchi *test = new Blocchi(11);   
   test->getLista()->insertList(new Transazioni("ciao","amore",300));
   test->printList("ciao");
   */

  linkedList<Blocchi> *blockchain = new linkedList<Blocchi>();

   Blocchi *trans1 = new Blocchi(1);
   //Blocchi *trans2 = new Blocchi(2);
   trans1->insertList(2);
   //trans2->insertList(3);

   string indirizzo;

   blockchain->insertList(trans1);
   //blockchain->insertList(trans2);

   Nodo<Blocchi> *prova = blockchain->getTesta();
   
   cout<<"Inserisci il tuo indirizzo: "<<endl;
   cin>>indirizzo;

   while (prova != nullptr)
   {
      int saldo = 0;

      cout<<"Blocco: "<<prova->getInfo()->getID()<<endl;
      saldo += prova->getInfo()->printList(indirizzo);
      cout<<"Bilancio per questo blocco: "<<saldo<<endl;
      prova = prova->getNext();
   }
  return 0;
}