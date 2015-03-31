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


int main()
{
    int n, m, i, pos;
    bool flag=true;
    char block;

    vector<char> v;

    cin>>n>>m;

    for (i=0; i<n; i++)
    {
        cin>>block;
        v.pb(block);
    }

//    for (i=0; i<n; i++)
//        cout<<v[i]<<endl;

    if(m==1)
    {
        for (i=0; i<n; i++)
        if(v[i]=='#') flag = false;
    }
    else
    for (pos=i=0; i<n; i++)
    {
        if(v[i]!='.')
        {
//            cout<<v[i]<<" "<<i<<endl;
            if(i==n-1) break;
            if(v[i+1]=='.') continue;
//            cout<<v[i]<<" "<<i<<endl;
            pos = 1;
            while(i++)
            {
                if(v[i]=='#') pos++;
                else break;
            }
//            cout<<pos<<";"<<i<<endl;
            if(pos>=m)
            {
                flag = false;
                break;
            }
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
