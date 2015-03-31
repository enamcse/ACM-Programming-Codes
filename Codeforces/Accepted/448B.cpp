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

#define sz 50005
#define pb(a) push_back(a)
#define pp pop_back()
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
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int freq_a[26], freq_b[26];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1,flag = 0, k =0;

    string a, b;
    cin>>a>>b;
    n = a.size();
    m = b.size();

    for (int i = 0; i<n; i++)
        freq_a[ a[i]- 'a' ]++;

    for (int i = 0; i<m; i++)
        freq_b[ b[i]- 'a' ]++;

    for (int i = 0; i<26; i++)
        if(freq_b[i]>freq_a[i]) flag = 4;

    if(flag != 4)
    {
        for (int i = 0; i<n&&k<m; i++)
            if(a[i]==b[k]) k++;
        if(k==m) flag = 1;

        for (int i = 0; i<26; i++)
            if(freq_a[i]!=freq_b[i]) cas++;
        if(cas==1) flag = 2;
        if(flag == 1) puts("automaton");
        else if(flag == 2) puts("array");
        else puts("both");
    }
    else puts("need tree");

    return 0;
}
