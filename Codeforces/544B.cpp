/**
* H:\Dropbox\Code\Codeforces\544B.cpp
* Created on: 2015-05-07-23.11.19, Thursday
* Verdict: Solved
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
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
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

int cc[] ={0,0,1,-1};
int rr[] ={1,-1,0,0};

int covered[105][105];
int n;
string s[105];

void rec(int row, int baki, bool flag)
{
    if(baki==0) return;
    int u,v;

    for (int i = flag; i<n; i+=2)
    {
        baki--;
        s[row][i]='L';
        covered[row][i] = 100;
        for (int j = 0; j<4; j++)
        {
            u = row+cc[j];
            v = i+rr[j];
            if(u<0||v<0) continue;
            covered[u][v]++;
        }
        if(baki==0) return;
    }
    rec(row+1,baki,flag^1);
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, m, cas=1,p,k,u,v;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>k;

    p = n*n;
    p = p/2 + p%2;
    if(k>p) cout<<"NO";
    else
    {
        cout<<"YES\n";
        string ss="";
        for (int i = 0; i<n; i++)
            ss+="S";
        for (int j = 0; j<n; j++)
            s[j]=ss;

        rec(0,k,0);

        for (int i = 0; i<10000; i++)
        {
            for (int j = 0; j<n; j++)
                for (int o = 0; o<n; o++)
                    if(covered[j][o]==1)
                    {
                        s[j][o]='L';
                        covered[j][o]=100;
                        for (int a = 0; a<4; a++)
                        {
                            u = j+cc[a];
                            v = o+rr[a];
                            if(u<0||v<0) continue;
                            covered[u][v]++;
                        }
                    }
        }

        for (int i = 0; i<n; i++)
            cout<<s[i]<<"\n";


    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
