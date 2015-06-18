/**
* H:\Dropbox\Code\Codeforces\546D.cpp
* Created on: 2015-05-22-23.27.17, Friday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

#define sz 5000010
ll res[sz];
ll col[sz/64+10];
int prime[sz], cnt;

void seive()//1 indexed
{
    long long i,j,k=sqrt(sz);
    for(i=3;i<=k;i+=2)
         if(!(col[i/64]&(1LL<<(i%64))))
                for(j=i*i;j<sz;j+=2*i)
                    col[j/64]|=(1LL<<(j%64));

    prime[cnt++]=2;
    for (int i = 3; i<sz; i+=2)
        if(!(col[i/64]&(1LL<<(i%64))))
            prime[cnt++] = i;
}

bool is_prime(ll i)
{
    if(i==2) return true;
    if(i%2==0) return false;
    if(!(col[i/64]&(1LL<<(i%64)))) return true;
    return false;
}

void pre()
{
    ll now, k;
    for (int i = 2,j=-1; i<sz; i++,j=-1)
    {
        now = 0;
        if(is_prime(i)) now = 1;
        else
        {
            k = i;
            while(++j>-2)
                if(k%prime[j]==0) {now+=res[ k/prime[j] ]+1;break;}
        }
        res[i] = now;
    }
    for (int i = 2; i<sz; i++)res[i]+=res[i-1];
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
//    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    seive();
    pre();

//    cin>>t;
    scanf("%d", &t);
    while(t--)
    {
//        cin>>n>>m;
//        cout<<res[n]-res[m]<<"\n";
        scanf("%d %d", &n, &m);
        printf("%I64d\n", res[n]-res[m]);
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
