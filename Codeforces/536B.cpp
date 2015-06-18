/**
* H:\Dropbox\Code\Codeforces\536B.cpp
* Created on: 2015-04-15-00.11.22, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000005
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define mod 1000000007

using namespace std;

bool arr[sz];
int z[sz];


void z_function(string &s)
{
    int n = s.size();
    for (int i = 1, l = 0, r = 0; i<n; i++)
    {
        if(i<= r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[ i+z[i] ] ) z[i]++;
        if(i+z[i]-1 > r) l=i,r=i+z[i]-1;
    }
}

bool check(string &s)
{
    z_function(s);
    int n = s.size();
    for (int i = 1; i<n; i++)
        if(arr[i]&&z[i]<n-i) return false;
    return true;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, k, last=0,cnt,i;
    ll ans=1;
    string p;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>m>>p;
    k = p.size();
    for (i = 0; i<m; i++)
    {
        cin>>t;
        t--;
        if(last<=t)
        {
            cnt = t-last;
            while(cnt--) ans=(ans*26)%mod;
        }
        else arr[k-last+t] = true;
        last = t+k;
    }
    cnt = n-last;
    if(cnt>0)while(cnt--) ans=(ans*26)%mod;
    if(check(p)) cout<<ans;
    else cout<<0;


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
