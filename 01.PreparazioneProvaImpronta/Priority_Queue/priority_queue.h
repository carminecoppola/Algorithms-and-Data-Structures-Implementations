#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include<iostream>
#include<vector>

using namespace std;

template<class T>
class priority_queue
{
    private:
        
    public:
        priority_queue(/* args */);
        ~priority_queue();

        T maximum();
        T extractMax();
        void increaseKey();
};


template<class T> priority_queue<T>::priority_queue(/* args */)
{
}



#endif