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
    int i, n, s, t;
    bool only_R=true, only_L=true;
    string road;

    cin>>n;
    cin>>road;

    for (i=1; i<n; i++)
    {
        if(road[i]=='L')
        {
            only_R = false;
            break;
        }
    }

    for (i=1; i<n; i++)
    {
        if(road[i]=='R')
        {
            only_L = false;
            break;
        }
    }
//    cout<<only_L<<" "<<only_R<<endl;
    if(only_R)
    {
//        cout<<"::"<<endl;
//        for (i=1; i<n; i++)
//        {
//            cout<<i<<"::"<<road[i]<<endl;
//            if(road[i]=='R')
//            {
//                s=i;
//                t=s+2;
//                break;
//            }
//        }
//        cout<<"::"<<endl;
        for (i=n-2; i>=0; i--)
        {
            if(road[i]=='R')
            {
                t=i+2;
                s=t-1;
                break;
            }
        }
    }
    else if(only_L)
    {
        for (i=1; i<n; i++)
        {
            if(road[i]=='L')
            {
                t=i;
                s=t+1;
                break;
            }
        }
//        cout<<"::"<<endl;
        for (i=n-2; i>=0; i--)
        {
//            cout<<i<<"::"<<road[i]<<endl;

            if(road[i]=='L')
            {
                s=i+1;
                break;
            }
        }
//        cout<<"::"<<endl;
    }
    else
    {
        for (i=1; i<n; i++)
        {
            if(road[i]=='L')
            {
                s=t=i;
                break;
            }
            else if (road[i]=='R')
            {
                s=i+1;
                while(++i&&i<n)
                    if(road[i]=='L')
                    {
                        t=i;
                        break;
                    }
                    else if(road[i]=='.'&&i<n)
                    {
                        t=i+1;
                        break;
                    }
                break;
            }
        }
    }
    cout<<s<<" "<<t<<endl;
    return 0;
}
