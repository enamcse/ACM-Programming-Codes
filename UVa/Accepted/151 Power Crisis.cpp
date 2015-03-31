#include <iostream>
using namespace std;
int traverse(int m);
struct node
{
    int info;
    node *ptr;
};

struct q
{
    node *head, *tail;
    q();
    void enq(int x);
    int deq();
};

q::q()
{
    head = tail = NULL;
}

void q::enq(int x)
{
    node *temp = new node;
    temp->info = x;
    temp->ptr = NULL;
    if(head==NULL)
    {
        head = tail = temp;
        return;
    }
    tail->ptr = temp;
    tail = temp;
    return;
}

int q::deq(void)
{
    int x;
    if(head == NULL) return -1;
    if(head->ptr==NULL)
    {
        x = head->info;
        delete head;
        head = tail= NULL;
        return x;
    }
    node *temp = head;
    head = head->ptr;
    x = temp->info;
    delete temp;
    return x;
}
int n;
int main()
{
    int m, t;
    while(cin>>n&&n)
    {
        m = 1;
        while(1)
        {
            t = traverse(m);
            if(t==13) break;
            m++;
        }
        cout<<m<<endl;
    }
    return 0;
}

int traverse(int m)
{
    q r;
    int pos, c = n-1;
    for (int i = 1; i<=n; i++)
            r.enq(i);
    pos=r.deq();
    while(c--)
    {
        for (int i = 1; i<m; i++)
            r.enq(r.deq());
        pos=r.deq();
    }
//    cout<<pos<<" ";
    return pos;
}
