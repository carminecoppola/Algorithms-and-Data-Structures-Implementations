#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main(){


    string myFile = "file";
    string myFile2 = "output";
    fstream file;
    fstream output;
    file.open(myFile.c_str(),ios::in);
    output.open(myFile2.c_str(),ios::out);
    vector<string> vettore;

    string line;
    while(getline(file,line))   //il secondo parametro di getLine() deve essere per forza una stringa
    {
        output<<line<<endl;
        cout<<line<<endl;
        vettore.push_back(line);
    }

    //Metto ciò che è scritto nel file in un vettore cosi da avere tutto sulla stessa riga

    for(auto i:vettore)
        cout<<i<<" ";
    cout<<endl;

    file.close();
    output.close();

    return 0;
}