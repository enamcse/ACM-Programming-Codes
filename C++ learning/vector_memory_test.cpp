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
#define SZ(s) ((int)s.size())
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
#define VI vector<int>
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}
using namespace std;

int main()
{
    #ifdef ENAM
//        fread;
//    fwrite;
    #endif // ENAM
    int t, n, m, cas=1;

    vector<int>v;
//    cout<<(*v.begin())<<':'<<(*v.end())<<endl;
    for (int i = 1; i<18; i++)
    {

        vector<int> &k = v;
        cout<<"@"<< (&k) <<endl;

        v.push_back(2);
        int &r = *v.begin(), &l = *v.end();
        cout<<(&r)<<':'<<(&l)<<endl;

        cout<<endl;
        for (int j = 0; j<i; j++)
        {
            int &q = v[j];
            cout<< (&q) <<' '<<&v[j]<<endl;
        }
        cout<<endl;
    }






    return 0;
}

