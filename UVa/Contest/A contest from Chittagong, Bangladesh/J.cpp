/**
* H:\Dropbox\Code\UVa\Contest\A contest from Chittagong, Bangladesh\J.cpp
*
* Created on: 2014-11-30-15.07.11, Sunday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);


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
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int a[sz], b[sz];

/*
1
31
0 1 1 1 1 2 2 2 3 3 3 4 4 4 5 5 5 6 6 6 7 7 7 7 8 8 8 9 9 9 9
1 1 2 3 4 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 4 1 2 3 1 2 3 4
*/


char num[15][10] = {{' '},
{'.',',', '?','\"'},
{'a','b','c'},
{'d','e','f'},
{'g','h','i'},
{'j','k','l'},
{'m','n','o'},
{'p','q','r','s'},
{'t','u','v'},
{'w','x','y','z'}
};

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;
    set< pair<int,int> >s;
//    _
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);

        for (int i = 0; i<n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &b[i]);
            s.insert(make_pair(a[i],b[i]));
        }

        assert(s.size()<32);
        for (int i = 0; i<n; i++)  {  assert(num[ a[i] ][ b[i]-1 ]!=0);
            printf("%c",num[ a[i] ][ b[i]-1 ]);}
        puts("");
    }
    return 0;
}
