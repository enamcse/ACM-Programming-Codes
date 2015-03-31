#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 10010000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

bool pr[sz];
vector<int>prime;

void seive()
{
    int n, k;
    pr[0] = pr[1] =true;
    for (int i = 4; i<sz; i+=2)
        pr[i] = true;
    for (int i =3; i<sz; i+=2)
    {
        if(pr[i]) continue;
        for (int j = 2; j<sz/i; j++)
        {
            pr[j*i] = true;
        }
    }
    prime.pb(2);
    for (int i = 3; i<sz; i+=2)
        if(!pr[i]) prime.pb(i);
    return;
}

int main()
{
    _
    seive();
    int n,t,cas=1, r, cnt_prime=prime.size(), cnt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        r = (n>>1);
        cnt = 0;
        for (int i = 0; i<cnt_prime&&prime[i]<=r; i++)
            if(!pr[n-prime[i]]) cnt++;
        cout<<"Case "<<cas++<<": "<<cnt<<endl;
    }
    return 0;
}
