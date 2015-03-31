#include <iostream>
using namespace std;

struct node
{
    int info;
    node *ptr;
};

struct card
{
    node *head, *tail;
    card();
    void enqueue(int x);
    int dequeue();
};

card::card()
{
    head = tail = NULL;
}

void card::enqueue(int x)
{
    node *temp;
    temp = new node;
    temp->info = x;
    temp->ptr = NULL;
    if(head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->ptr = temp;
        tail = temp;
    }
    return;
}


int card::dequeue()
{
    node *temp;
    temp = head;
    int a;
    if(temp==NULL)
    {
        return -1;
    }
    else if(temp->ptr==NULL)
    {
        a = temp->info;
        tail = head = NULL;
        delete temp;
        return a;
    }
    else
    {
        head = head->ptr;
        a = temp->info;
        delete temp;
        return a;
    }
}



int main()
{
    int t;
    int dis[100], rem, count;
    card c;
    cin>>t;

    while(t)
    {
        count = 0;
        for (int i = 1; i<=t; i++)
            c.enqueue(i);

        while (c.head != c.tail)
        {
            dis[count++] = c.dequeue();
            if(c.head == c.tail) break;
            int tem = c.dequeue();
            c.enqueue(tem);
        }
        rem = c.dequeue();
        cout<<"Discarded cards:";
        for (int i = 0; i<count; i++)
        {
            if(i!=count-1)
            {
                cout<<" "<<dis[i]<<",";
            }
            else cout<<" "<<dis[i];
        }
        cout<<endl<<"Remaining card: "<<rem<<endl;
        cin>>t;
    }

    return 0;
}
