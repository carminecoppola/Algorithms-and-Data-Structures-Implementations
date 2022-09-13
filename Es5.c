/*  Si  realizzi  un  programma  C  e  Posix  in  ambiente  Linux  che,  impiegando  la  libreria  Pthread, generi  tre  thread. 
    I primi due thread sommano 1000 numeri generati casualmente ed ogni volta incrementano un  contatore.
    Il terzo thread attende che il contatore incrementato dai due thread aggiunga un valore limite fornito da riga di comando, 
    notifica l’avvenuta condizione e termina. Utilizzare le variabili condizione.*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<unistd.h>
#include<errno.h>

int somma_num=0;
int contatore=0;

struct info{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
       
}th_info={PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER};


//Prima procedura per generare e sommare i 1000 numeri casuali
void* routine1(void* limite){

    int* lt= (int*)limite;
    int local_sum=0;


    while(contatore <= *lt){

        local_sum=rand()%(10-1)+1;

        //Entriamo in sezione critica poichè è una variabile condivisa
        pthread_mutex_lock(&th_info.mutex);        
        if(contatore == *lt){                        //Se il contatore raggiunge il limite allora bisogna uscire
            pthread_mutex_unlock(&th_info.mutex);   //Fine sezione critica
            pthread_cond_signal(&th_info.cond);    //Signal al terzo thread
            pthread_exit(0);
        }
     somma_num = somma_num+local_sum;            //Operazioni di somma e incremento del contatore richiesti dalla traccia
     contatore++;
     pthread_mutex_unlock(&th_info.mutex);      //Esco dalla sezione critica
    }
    pthread_exit(0);
}

//Routine 3 thread
void *routine2(void *limite){

    int *limit = (int*)limite;

    pthread_mutex_lock(&th_info.mutex);
    while(contatore < *limit)                                    //Condizione necessaria affinche il thread deve aspettare
        pthread_cond_wait(&th_info.cond,&th_info.mutex);         //in questo caso il contatore deve essere minore del limite imposatato;

    printf("\n Il limite impostato a %d è stato raggiunto\n Il risultato della somma è:%d\n Il contatore è %d\n", *limit,somma_num,contatore);
    pthread_mutex_unlock(&th_info.mutex);
     
pthread_exit(NULL);
}


//MAIN
void main(int argv,char* argc[]){

    srand(time(NULL));
    pthread_t th[3];

    int lim_ut = atoi(argc[1]); //Inserimento da riga di comando del limite

    if(lim_ut > 2000)
       lim_ut =2000;
    
//Creazione dei primi 2 thread:
    for(int i=0;i<2;i++)
        if(pthread_create(th+i,NULL,&routine1,(void*)&lim_ut)!=0)
            perror("Errore nella creazione thread");

        //Terzo thread:
        if(pthread_create(th+2,NULL,&routine2,(void*)&lim_ut)!=0)
            perror("Errore nella creazione thread");

//Creazione dei join:
    for(int i=0;i<3;i++)
      if(pthread_join(th[i],NULL)!=0)
            perror("Errore nei join");

}
