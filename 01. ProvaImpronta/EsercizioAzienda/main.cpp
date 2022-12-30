/*      Un'azienda è quotata in borsa. Si supponga di avere un array
        A[1...N] contenente la quotazione delle azioni in un periodo di
        N giorni e che A[1]<A[N]. È possibile dimostrare che esiste
        almeno una coppia di giorni consecutivi i, i+1 tali che
        A[i]<A[i+1].
        Progettare ed implementare un algoritmo divide-et-impera che
        trovi un indice i che verifichi la condizione data
                    |20|15|13|12|21|  --> la coppia da restituire è |12|21|
*/

#include<iostream>
using namespace std;

/* Questa funzione ci ritornerà la coppia che rispetta 
   la condizione prestabilita, quindi che A[i]<A[i+1].*/
int searchCouple(int arr[],int start,int end){

        int mid,ind;

        /*I caso base sarà quando nell'array saranno presenti solo due numeri
          che rispettano la condizione A[i]<A[i+1] altrimenti ritorna -1.*/

        if (end+1-start == 1){   //Se la lunghezza dell'array è uguale a 2
           if(arr[start] < arr[end]){
              return start;     //Poiche basta ritornare solo un indice e poi nel main il successivo
           }
           else
              return -1;
        }
        /*
         Nel caso in cui non ci troviamo nel caso base allora
         dovremmo operare ricorsivamente.
          1)Troviamo il mediano;
          2)Il primo controllo da fare è se il mediano è < del 
            suo successivo (mediano+1);
          3)Qualora questa condizione non fosse verificata allora
            bisogna esaminare la porzione di SX;
          4)Se non è presente a SX per forza dovremmo trovarla nella
            porzione di DX;
          5)Ovviamente ritorniamo sempre l'indice della posizione minore;
        */
        else { 
          mid = (start + end)/2;        //Calcolo mediano

          if (arr[mid] < arr[mid+1]){      //Se il mediano rispetta la condizione ritoriamo il mediano
                return mid;  
          }      
          else{
                ind = searchCouple(arr,start,mid); //Ricorsione nella parte di sinista
                if(ind == -1)                     //Se la ricerca a sinista non porta a buon fine fare la ricorsione a dx
                    return searchCouple(arr,mid+1,end);      //Ricorsione nella parte destra
                else
                    return ind;
          }
       }
}


int main(){

        int A[]={20,15,13,12,21};

        int ind = searchCouple(A,0,4); //Passiamo 0 come indice di partenza e 4 come indice di fine array

        cout<<endl<<"La coppia che rispetta la condizione è: "<<A[ind]<<" "<< A[ind+1]<<endl<<endl;

        return 0;
}

