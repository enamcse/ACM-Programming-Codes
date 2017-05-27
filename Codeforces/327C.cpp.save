/**
* H:\Dropbox\Code\Codeforces\327C.cpp
* Created on: 2015-10-25-15.38.35, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb push_back
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
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007

using namespace std;
int n;
string s[2];

void doit(bool ff)
{
    int zero, one;

    for (int i = 1; i<n-1; i++)
    {
        zero = one = 0;
        if(s[ff][ ((i-1)<<1) ]=='1') one++;
        else zero++;
        if(s[ff][ ((i+1)<<1) ]=='1') one++;
        else zero++;
        if(s[ff][ (i<<1)  ]=='1') one++;
        else zero++;

        if(zero>1) s[ff^1][(i<<1)] = '0';
        else s[ff^1][(i<<1)] = '1';
    }
//    cout<<s[ff]<<" : "<<s[ff^1]<<endl;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, m=0, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n;
    string k(2*n-1, ' ');
    for (int i = 0; i<n; i++)
    {
        cin>>t;
        if(t) k[(i<<1)] = '1';
        else k[(i<<1)] = '0';
    }
    s[1] = s[0] = k;
    doit(m&1);
    while(s[0]!=s[1])
    {

        m++;
        doit(m&1);
        if(m>1700)
        {
            assert(0);
            cout<<-1;
            return 0;
        }
    }
    cout<<m<<"\n"<<s[(m+1)&1];
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
