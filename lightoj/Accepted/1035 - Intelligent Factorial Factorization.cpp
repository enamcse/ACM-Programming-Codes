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
#include <stack>

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int factor[101][sz];
int prime[sz], cnt=0;
void pre()
{
    prime[cnt++]=2;
    factor[2][cnt-1] = 1;
    for (int i = 3; i<100; i+=2)
    {
        int len = sqrt(i), flag = 1;
        for (int j =3; j<=len; j+=2)
        {
            if(i%j==0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            prime[cnt++]=i;
            factor[i][cnt-1]=1;
//            cout<<prime[cnt-1]<<" ";
        }
    }

    for (int i = 2; i<=100; i++)
    {
        for (int j = 0; j<cnt; j++)
        {
            if(prime[j]>=i) break;
            if(i%prime[j]==0)
            {
                int c = 0, d =i;
                while(d%prime[j]==0)
                {
                    d/=prime[j];
                    c++;
                }
                factor[i][j]=c;
            }
        }
    }
//    for (int i = 0; i<cnt; i++)
//        cout<<prime[i]<<"-";
    for (int i = 3; i<=100; i++)
    {
        for (int j = 0; j<cnt; j++)
            factor[i][j]+=factor[i-1][j];
    }



    return;
}

int main()
{
    pre();
    int t, cas=1, n, flag=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("Case %d: %d = ",cas++,n);
        for (int i = 0; i<cnt; i++)
        {
//            cout<<prime[i]<<" ";
            if(factor[n][i]>0)
            {
//                cout<<i<<" ";
                if(flag==cas) printf(" * %d (%d)",prime[i], factor[n][i]);
                else
                {
                    printf("%d (%d)",prime[i], factor[n][i]);
                    flag=cas;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
