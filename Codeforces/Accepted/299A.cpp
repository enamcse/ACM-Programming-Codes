#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
using namespace std;

vector<int> a;
vector<int>::iterator it, jt;

int main()
{
    int i, n, t, mod;

    bool flag=true;

    cin>>n;

    for (i=0; i<n; i++)
    {
        cin>>t;
        a.pb(t);
    }

    sort(a.begin(),a.end());
    jt=a.begin();
    for (it=a.begin()+1; it<a.end(); it++)
    {
        if(*it%*jt!=0)
        {
            flag = false;
            break;
        }
    }

    if(flag) cout<<*jt<<endl;
    else cout<<-1<<endl;

    return 0;
}

