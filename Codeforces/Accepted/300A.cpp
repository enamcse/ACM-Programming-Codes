#include <iostream>
#include <vector>
#define sz 100
#define pb(b) push_back(b)
#define pp pop_back()

using namespace std;

int main()
{
    int n, a;

    vector<int>x,y,z;
    vector<int>::iterator it;
    cin>>n;

    while(n--)
    {
        cin>>a;
        if(a<0) x.pb(a);
        else if (a>0) y.pb(a);
        else z.pb(a);
    }

    if(y.empty())
    {
        y.pb(x.back());
        x.pp;
        y.pb(x.back());
        x.pp;
    }

    if(x.size()%2==0)
    {
        z.pb(x.back());
        x.pp;
    }

    cout<<x.size();
    for (it=x.begin(); it<x.end(); it++)
        cout<<" "<<*it;
    cout<<endl;

    cout<<y.size();
    for (it=y.begin(); it<y.end(); it++)
        cout<<" "<<*it;
    cout<<endl;

    cout<<z.size();
    for (it=z.begin(); it<z.end(); it++)
        cout<<" "<<*it;
    cout<<endl;

    return 0;
}
