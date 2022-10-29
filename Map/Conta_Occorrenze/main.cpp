/*Progettare ed implementare un programma che utilizzando una Map, conti il
numero di occorrenze di ogni parola contenuta in un file.*/

#include <iostream>
#include "Contatore.h"

using namespace std;

int main(){

    Contatore ogg("File1.txt");

    ogg.contaOccorrenze();

    return 0;
}