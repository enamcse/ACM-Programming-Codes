/**
* H:\Dropbox\Code\UVa\1246 - Find Terrorists.cpp
* Created on: 2015-02-09-21.27.07, Monday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)


using namespace std;

bool flag[100005];
pair<int,int>input[25];

#define sz 200000
ll col[sz/64+10];

void seive()//1 indexed
{
    long long i,j,k;
    for(i=3; i<sz; i+=2)
        if(!(col[i/64]&(1LL<<(i%64))))
            for(j=i*i; j<sz; j+=2*i)
                col[j/64]|=(1LL<<(j%64));
}

bool is_prime(int i)
{
    if(i==2) return true;
    if(i%2==0) return false;
    if(!(col[i/64]&(1LL<<(i%64)))) return true;
    return false;
}

void gen(int a, int b)
{
    int maxd = b;
    vector<int>facts[b+5];
    // Generates the divisors
    for(int i=2; i<=maxd; i++) if(facts[i].size()==0)
            for(int j=i; j<=maxd; j+=i) facts[j].push_back(i);

    for (int i = max(2,a); i<=b; i++)
    {
        int div = 1, cnt,k;
        for (int j = 0; j<facts[i].size(); j++)
        {
            cnt = 0;
            k = i;
            while(k%facts[i][j]==0)
            {
                cnt++;
                k/=facts[i][j];
            }
            div*=(cnt+1);
        }
        if(is_prime(div)) flag[i] = true;
    }
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    seive();
    int t, n=INFINITY, m=0, cas=1,k;
    _

    cin>>t;

    for (int i = 0; i<t; i++)
    {
        cin>>input[i].first>>input[i].second;
        n = min(n,input[i].first);
        m = max(m,input[i].second);
    }
    assert(m<1e5);
    gen(n,m);

    for (int cs = 0; cs<t; cs++)
    {
        k=0;
        for (int i = input[cs].first; i<=input[cs].second; i++)
        {
            if(flag[i])
            {
                if(k++) cout<<" ";
                cout<<i;
            }
        }

        if(!k) cout<<"-1";
        cout<<"\n";
    }
    return 0;
}
