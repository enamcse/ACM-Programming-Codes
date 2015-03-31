/**
* H:\Dropbox\Code\DevSkill\Dev Skill Coding Contest - 1\E.cpp
* Created on: 2015-02-15-21.59.26, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("InputFileE.txt","r",stdin)
#define fwrite freopen("outputE2.txt","w",stdout)
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
using namespace std;

ll E, keys[11];


int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
//    cout<<cnt;
    int t, n, m, cas=1;
    _
    ll gg;
    while(cin>>E)
    {
        cin>>n;

        for (int i = 0; i<n; i++)
            cin>>keys[i];


        int j;
        gg=keys[0];
        for (j = 1; j<n; j++)
            gg=__gcd(gg,keys[j]);

        for (j = 0; j<n; j++)
            E-=(keys[j]/gg);

        cout<<"Output: "<<E<<endl;


    }

    return 0;
}
