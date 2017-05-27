/**
* E:\MyJudge\icpc2015-practice\L.cpp
* Created on: 2015-06-18-02.42.59, Thursday
* Verdict: Solved
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

ll fact[25];

struct node
{
    double p,e;
    ll f;
    node() {}
    node(double a, double b, ll c)
    {
        p = a;
        e = b;
        f = c;
    }

    bool operator < (const node &k) const
    {
        return p > k.p;
    }

};

priority_queue<node>pq;


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n=20, m, cas=1;
    _
    double s,c,r,f;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    fact[0]=1;

    for (int i = 1; i<=n; i++)
        fact[i] = fact[i-1] * i;

    cin>>n>>s>>c>>r>>f;

    for (int i = 0; i<=n; i++)
        for (int j = 0; i+j<=n; j++)
        {
            for (int k = 0; i+j+k<=n; k++)
            {
                int l = n-i-j-k;
                node n1;
                n1.f = (((fact[n]/fact[i])/fact[j])/fact[k])/fact[l];
                n1.e = 0.0;
                n1.p = 1.0*pow(s,i)*pow(c,j)*pow(r,k)*pow(f,l);
                pq.push(n1);
            }
        }

    node now, rem;

    while(!pq.empty())
    {
        now = pq.top();
        pq.pop();
        if(pq.empty()) break;

        if(now.f&1)
        {
            now.f--;
            rem = pq.top();
            pq.pop();
            rem.f--;
            if(rem.f>0) pq.push(rem);
            node n1;
            n1.p = rem.p + now.p;
            n1.e = rem.e + now.e + n1.p; /// from shahriar sir
            n1.f = 1;
            pq.push(n1);
        }

        if(now.f>=2)
        {
            node n1;
            n1.p = now.p*2;
            n1.f = now.f/2;
            n1.e = now.e*2+n1.p;
            pq.push(n1);
        }
    }

    cout<<setprecision(8)<<fixed<<now.e<<"\n";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
