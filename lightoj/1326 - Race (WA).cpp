/**
* H:\Dropbox\Code\lightoj\1326 - Race.cpp
* Created on: 2015-01-14-12.18.18, Wednesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 2005
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
#define mod 10056
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int n;
bool siv[1001];
int prime[1001],cnt;
int fact[1001][200];
map<int,int>mpp;

bool seive()
{
    int sq = sqrt(1001);
    for (int i = 3; i<=sq; i+=2)
        if(!siv[i])
            for (int j = i*i; j<1001; j+=i+i)
                siv[j]=true;
    prime[cnt++] = 2;
    for (int i = 3; i<1001; i+=2)
        if(!siv[i]) {mpp[i] = cnt;prime[cnt++] = i;}
}

void gen()
{
    for (int i = 2; i<=1000; i++)
    {
        int now = i;
        for (int j = 0; prime[j]*prime[j]<=i; j++)
            if(now%prime[j]==0)
            {
                int cnt = 0;
                while(now%prime[j]==0)
                {
                    cnt++;
                    now/=prime[j];
                }
                fact[i][j]=cnt;
            }
        if(now>1) fact[i][ mpp[now] ] = 1;
    }
}

int alloc[sz],cn,dp[sz][sz][201];
bool visited[sz][sz];


int rec(int num, int pos)
{
    if(num==n)
    if(!visited[num][pos]) return ;
    visited[num][pos] = true;

}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t,  m, cas=1, ans;
    _
    seive();
//    cout<<cnt<<endl;
    gen();

//    for (int i = 1000; i<=1000; i++)
//        for (int j = 0; j<=100; j++)
//            cout<<fact[i][j]<<" \n"[j==100];
//    cout<<endl;

    cin>>t;

	while(t--)
    {

        clr(visited,0);
        cin>>n;

        rec(0,1);

        cout<<"Case "<<cas++<<": "<<ans<<"\n";
    }


   return 0;
}
