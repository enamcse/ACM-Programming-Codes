#ifndef a20160319001_H_INCLUDED
#define a20160319001_H_INCLUDED

class something
{
private:
    static int counter;
    int myCounter;
public:
    something()
    {
        myCounter = this->counter++;
    }
    int getCounter()
    {
        return this->counter;
    }
    int getMyCounter()
    {
        return this->myCounter;
    }
    static void resetCounter()
    {
        //counter = 1;
    }
};

#endif // 20160319001_H_INCLUDED
