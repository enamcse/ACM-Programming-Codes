#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
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
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _

	cin>>t;

	while(t--)
    {
        m=0;
        cin>>n;
        if(n>180000)
        {
            n-=180000;
            if(n<=300000) m+=ceil(n*0.1);
            else
            {
                n-=300000;
                m+=30000;
                if(n<=400000) m+=ceil(n*0.15);
                else
                {
                    n-=400000;
                    m+=60000;
                    if(n<=300000)m+=ceil(n*0.2);
                    else
                    {
                        n-=300000;
                        m+=60000;
                        if(n)m+=ceil(n*.25);
                    }
                }
            }
            m=max(m,2000);
        }
        cout<<"Case "<<cas++<<": "<<m<<"\n";

    }




   return 0;
}
