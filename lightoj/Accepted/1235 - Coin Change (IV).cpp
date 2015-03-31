/**
* H:\Dropbox\Code\lightoj\1235 - Coin Change (IV).cpp
* Created on: 2015-02-05-16.48.46, Thursday
* Verdict: Solved
* Author: Enamul Hassan
**/

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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int K, n, m;

int arr1[10], arr2[10];
vector<int>v1,v2;
int pow3[10];


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, cas=1;
    bool flag;
    pow3[0]=1;
    for (int i =1; i<10; i++)
        pow3[i]=pow3[i-1]*3;

    scanf("%d", &t);

    while(t--)
    {
        v1.clear();
        v2.clear();

        scanf("%d %d", &n, &K);
        m = n/2;
        n = n - m;
        for (int i = 0; i<n; i++)
            scanf("%d", &arr1[i]);
        for (int i = 0; i<m; i++)
            scanf("%d", &arr2[i]);
        flag = false;

        int bit,lim = pow3[n], sum;
        for (int i = 0; i<lim; i++)
        {
            sum = 0;
            for (int j = 0; j<n; j++)
            {
                bit = (i/pow3[j])%3;
                if(bit==1) sum+=arr1[j];
                else if(bit==2) sum+=arr1[j]+arr1[j];
            }
            if(sum<=K) v1.pb(sum);
        }
        lim = pow3[m];
        for (int i = 0; i<lim; i++)
        {
            sum = 0;
            for (int j = 0; j<m; j++)
            {
                bit = (i/pow3[j])%3;
                if(bit==1) sum+=arr2[j];
                else if(bit==2) sum+=arr2[j]+arr2[j];
            }
            if(sum<=K) v2.pb(sum);
        }
        sort(all(v2));

        for (int i = 0; i<v1.size(); i++)
            {
                if(binary_search(all(v2), K-v1[i]))
                {
                    flag = true;
                    break;
                }
            }
        if(flag) printf("Case %d: Yes\n", cas++);
        else printf("Case %d: No\n", cas++);

    }
   return 0;
}
