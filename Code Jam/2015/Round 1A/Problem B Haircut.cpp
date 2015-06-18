/**
* H:\Dropbox\Code\Code Jam\2015\Round 1A\Problem B Haircut.cpp
* Created on: 2015-04-18-08.28.55, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("B-small-attempt0.in","r",stdin)
#define fwrite freopen("B-small.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int m[6],n,b;
ll lok;
int prime[] = {2,3,5,7,11,13,17,19,23,29};
int factor[]= {0,0,0,0, 0, 0, 0, 0, 0, 0};

void factorize(int x)
{
    for (int i = 0; prime[i]<=x; i++)
        if(x%prime[i]==0)
        {
            int cnt =0;
            while(x%prime[i]==0)
            {
                cnt++;
                x/=prime[i];
            }
            factor[i] = max(factor[i], cnt);
        }
}

ll dude()
{
    ll k=1, ret=0;
    for (int i = 0; i<9; i++)
        while(factor[i]--) k*=prime[i];
    for (int i = 1; i<=b; i++) ret+=(k/m[i]);
    return ret;
}

int see[6], tim[6],cnt;

int main()
{
//#ifdef ENAM
    	fread;
	fwrite;
//#endif // ENAM
    int t, cas=1, k,i,j;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();




    cin>>t;

    while(t--)
    {
        cout<<"Case #"<<cas++<<": ";
        clr(factor,0);
        cin>>b>>n;
        cnt=0;
        k=n;
        for (int i = 1; i<=b; i++)
        {
            cin>>m[i];
            factorize(m[i]);
        }

        lok = dude();
        k=(n-1)%lok;
        k++;
//        cerr<<k<<" haha";

        for (i = 1;i<=b; i++)
        {
            see[i]=++cnt;
            tim[i]=m[i];
            if(cnt==k)
            {
                cout<<i<<"\n";
                break;
            }
        }
        if(i<=b) continue;
        for (i = 1; ; i++)
        {
            for (j = 1; j<=b; j++)
                {
                    if(--tim[j]==0)
                    {
                        tim[j]=m[j];
                        see[j]=++cnt;
                        if(cnt==k)
                        {
                            cout<<j<<"\n";
                            break;
                        }
                    }
                }
            if(j<=b) break;
        }


    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
