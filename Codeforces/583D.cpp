/**
* H:\Dropbox\Code\Codeforces\583D.cpp
* Created on: 2015-10-03-23.50.21, Saturday
* Verdict: Not Solved
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

int arr[105];

map<int,int>freq,first,last;
map<int,bool>col;

int LIS(int n, vector<int> &sequence)
{
    int mid, LISLength=0;
    temp[0] = -inf;
    for (int i =1; i<=n; i++)
        temp[i]=inf;
    for (int i = 0; i<n; i++)
    {
        int low, mid, high;
        low = 0;
        high = LISLength;

        while(low<=high)
        {
            mid = ((high+low)>>1);
            if(sequence[i]>temp[mid]) low = mid+1;
            else high = mid-1;
        }
        temp[low] = sequence[i];
        L[i] = low;
        if(LISLength<low) LISLength = low;
    }
    return LISLength;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,ans=1,mx=1,temp;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>t;

    for (int i = 0; i<n; i++)
    {
        cin>>arr[i];
        if(!freq.count(arr[i]))
            first[ arr[i] ]=i;
        freq[ arr[i] ]++;
        last[ arr[i] ]=i;
        mx = max(mx,freq[ arr[i] ]);
    }
    for (int i = 0; i<n; i++)
    {
        if(col.count(arr[i])) continue;

        if(freq[ arr[i] ]==mx)
        {
            vector<int>v;
            for (int j = first[ arr[i] ]; j<; )
                ;
        }
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
