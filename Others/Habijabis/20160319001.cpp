/**
* E:\Dropbox\Code\Others\Habijabis\20160319001.cpp
* Created on: 2016-03-19-07.02.11, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include<bits/stdc++.h>
//#include "20160319001.h"
using namespace std;

class something
{
private:
    ///static in class which could not be initialized in place
    static int counter;
    int myCounter;
public:
    something()
    {
        myCounter = this->counter++;
    }
    static int getCounter()
    {
        return counter;
    }
    int getMyCounter()
    {
        return this->myCounter;
    }
    static void resetCounter()
    {
        counter = 1;
    }
};

///static in class must be initialized outside the class
int something::counter = 1;

int add(int k)
{
    ///static in normal function
    static int ret = 6;
    ret += k;
    return ret;
}
int main()
{
    int i;
    for(i = 4; i<10; i++)
    {
        printf("i = %d, sum = %d\n",i,add(i));
    }
    something::resetCounter();
    something a;
    something b;
    something c;

    printf("a: counter = %d, myCounter = %d\n", a.getCounter(), a.getMyCounter());
    printf("b: counter = %d, myCounter = %d\n", b.getCounter(), b.getMyCounter());
    printf("c: counter = %d, myCounter = %d\n", c.getCounter(), c.getMyCounter());
    printf("getCounter() = %d\n", something::getCounter());

    return 0
}
