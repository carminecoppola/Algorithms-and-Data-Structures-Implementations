#ifndef CASELLA_H
#define CASELLA_H

#include<iostream>
#include<vector>
#include<map>


using namespace std;

class Casella
{
    private:

        int value;
        map<int , int> elem;

    public:
        Casella():value{0},elem{}{};

        void setValue(int value){this->value = value;}
        void setMap(int key ,int value){ elem[key] = value;}


        int getValue(){return value;}
        int getMap(int key){return elem[key];}
};

#endif
