//TRACCIA 1:

/*  Si progetti un programma in ambiente Linux che, impiegando  la  libreria  pthread,  
    crei  un  thread  che  estrae N volte (con N passato da riga di comando) un numero 
    casuale compreso tra 0 e 10 e ne calcoli il fattoriale  ponendolo  in  una  variabile  
    condivisa  e  un  thread  che  stampi  a  video  il  fattoriale  calcolato  N  volte 
    prelevandolo dalla variabile condivisa.

*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

//VARIABILI GLOBALI
int *fattoriale;
int *num_casuali;
int n;
int controllo;

struct info{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}th_info={PTHREAD_MUTEX_INITIALIZER,PTHREAD_COND_INITIALIZER};

// fattoriale
int calcoloFattoriale(unsigned int n){
    if (n==0) 
        return 1;
    else if (n==1) 
        return 1;
    else
        return n*calcoloFattoriale(n-1);
} 

void* estrazione(){
    //Questa routine dovra estrarre un numero casuale (tra 0 e 10) N volte
   //E calcolera il suo fattoriale mettendolo in una variabile condivisa;

    int rand_num=0;
    for(int i=0;i<n;i++){
        rand_num = rand()%(10-1)+1;
        pthread_mutex_lock(&th_info.mutex);
            *(fattoriale+i)=calcoloFattoriale(rand_num);
            *(num_casuali+i)=rand_num;
        pthread_mutex_unlock(&th_info.mutex);
    }
    pthread_mutex_lock(&th_info.mutex);
        controllo=1;
    pthread_mutex_unlock(&th_info.mutex);
    pthread_cond_signal(&th_info.cond);
    pthread_exit(0);
}

void* stampa(){
    //Questa routine serve a stampare il fattoriale calcolato N volte preso dalla variabile condivisa;

    while(controllo==0){
        pthread_cond_wait(&th_info.cond,&th_info.mutex);
    } 
    for(int i=0 ;i<n; i++)   
    printf("\n Il Fattoriale[%d] di %d = %d", i,*(num_casuali+i),*(fattoriale+i));
    puts("");
}

void main(int argc, char* argv[]){
    srand(time(NULL));
    n = atoi(argv[1]);
    fattoriale = malloc(n*sizeof(int));
    num_casuali = malloc(n*sizeof(int));
    controllo = 0;

    pthread_t th[2];

    if ( pthread_create(th, NULL, &estrazione, NULL) != 0 )
        printf("\nErrore");
    if ( pthread_create(th+1, NULL, &stampa, NULL) != 0 )
        printf("\nErrore");

    if ( pthread_join(th[0], NULL) != 0 )
        printf("\nErrore");
    if ( pthread_join(th[1], NULL) != 0 )
        printf("\nErrore");
}
