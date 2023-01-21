#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;


int main(){

    string file = "file1";
    string file2 = "OutputPrimoFile";
    string prova;
    vector<string> vect;

    fstream myFile;
    fstream output;

    //Apriamo il file
    myFile.open(file.c_str(),ios::in);
    output.open(file2.c_str(),ios::out);

    cout<<endl<<"Stampa del file nel file di output: "<<endl;
    while(getline(myFile,prova))
    {
        output<<prova<<endl;     //qui lo metto in un file... è una semplice copia    
        cout<<prova<<endl;      //qui lo stampo
        vect.push_back(prova); //qui lo metto in un vettore
    }
    cout<<endl;

    /*Questo lo stampa tutto sulla stessa riga poichè
    nel file iniziale lo abbiamo messo su più righe*/

    cout<<"Stampa su una sola riga: "<<endl;
    for(auto i:vect)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}