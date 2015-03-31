//Verdict: NOT SOLVED
//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000009
using namespace std;

char arr[sz];
int t, n, m,x,y;
char ch;
ll ans;

int main()
{
#ifdef ENAM
//        fread;
//    fwrite;
#endif // ENAM


    scanf("%d", &t);

    while(t--)
    {
        clr(arr,0);
        ans=1;
        scanf("%d %d", &n, &m);

        for (int i = 0; i<m; i++)
        {
            scanf(" %c %d", &ch, &x);
            arr[x-1] = ch;
        }

        for (int i = 0; i<n; i++)
        {
            if(arr[i]!=0)
            {
                x=i;
                ch=arr[i];
                for (i++; i<n; i++)
                    if(arr[i]!=0)
                        if(arr[i]==ch) x = i;
                        else break;
//                        cout<<x<<" @ "<<i<<endl;
                if(i!=n)
                {
                    y = i-x;
                    if(i+1<n || x-1>=0) ans=(ans*y)%mod;
                    else if(y>1) ans=(ans*2)%mod;
                    i--;
                }
            }
        }
        printf("%lld\n", ans%mod);
    }


    return 0;
}

