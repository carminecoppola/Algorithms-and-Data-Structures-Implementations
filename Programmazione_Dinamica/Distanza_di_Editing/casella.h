#ifndef CASELLA_H
#define CASELLA_H

#include<iostream>
using namespace std;

enum class Direction{UP,LEFT,DIAG};

ostream& operator <<(ostream& out,const Direction& d){
    switch (d)
    {
        case Direction::UP:
            out<<"U";
        break;
        case Direction::LEFT:
            out<<"L";
        break;
        case Direction::DIAG:
            out<<"D";
        break;
        default:
            break;
    }
    return out;
}

class casella
{
    private:
        int value;
        Direction dir;
    public:
        //set
        casella():value{0},dir{Direction::UP}{};
        //get
        int getValue(){
            return this->value;
        }
        Direction getDir(){
            return this->dir;
        }

        void setValue(int value){
            this->value = value;
        }
        void setDir(Direction dir){
            this->dir = dir;
        }
};


#endif