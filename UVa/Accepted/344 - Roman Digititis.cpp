/**
* H:\Dropbox\Code\UVa\344 - Roman Digititis.cpp
* Created on: 2015-02-19-06.09.52, Thursday
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int arr[105][5];
char ch[] = {'i', 'v', 'x', 'l', 'c'};
void gen(int x)
{
    int a = x/10, b = x%10;
    if(b)
    {
        if(b<4) arr[x][0]+=b;
        else if(b<9)
        {
            arr[x][1]++;
            arr[x][0]+=abs(5-b);
        }
        else
        {
            arr[x][2]++;
            arr[x][0]++;
        }
    }
    if(a)
    {
        if(a<4) arr[x][2]+=a;
        else if(a<9)
        {
            arr[x][3]++;
            arr[x][2]+=abs(5-a);
        }
        else
        {
            arr[x][4]++;
            arr[x][2]+=(10-a);
        }
    }
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    for (int i = 1; i<=100; i++)
    {
        gen(i);
        for (int j = 0; j<5; j++)
            arr[i][j]+=arr[i-1][j];
    }


    while(cin>>n&&n)
    {
        cout<<n<<":";
        for (int j = 0; j<5; j++)
            cout<<" "<<arr[n][j]<<" "<<ch[j]<<",\n"[j==4];
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
