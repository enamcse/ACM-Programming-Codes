/**
* H:\Dropbox\Code\HackerRank\#HackerRankWorldCup\Lauren And Inversions.cpp
* Created on: 2015-09-20-18.56.30, Sunday
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
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

///0 based indexing

const int MAX = 500050;

int tree[MAX],bitN, arr[MAX], inv[MAX],LDS[MAX];

pair<int,int>val[MAX];

int seg[5*MAX];

void update(int ind, int LB, int UB, int pos, int vv)
{
    if(LB==UB)
    {
        seg[ind] = vv;
        return;
    }
    int mid = (UB+LB)>>1;
    if(pos<=mid)update((ind<<1), LB, mid,pos,vv);
    else update((ind<<1)+1, mid+1, UB,pos,vv);
    seg[ind] = max(seg[ind<<1], seg[(ind<<1)+1]);
    return;
}

int query(int ind, int LB, int UB,int s, int e)
{
    if(e<LB||s>UB) return 0;
    if(UB<=e&&LB>=s) return seg[ind];
    int mid=(UB+LB)>>1;
    return max(query(ind<<1,LB,mid,s,e), query((ind<<1)+1,mid+1,UB,s,e));
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,L;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        val[i] ={arr[i],i};
    }

    sort(val,val+n);

    for (m = 1; m<n; m++)
        if(arr[m]<arr[m-1]) break;

    if(m==n)
    {
        printf("Cool Array\n");
        return 0;
    }
    L = 0;
    for (int i = 0; i<n; i++)
    {
        LDS[ val[i].second ] = 1+query(1,0,n-1,val[i].second+1,n-1);
        update(1,0,n-1,val[i].second,LDS[ val[i].second ]);
        L = max(L, LDS[ val[i].second ]);
    }
    vector<int>v;

    for (int i = 0; i<n; i++) cerr<<i<<" = "<<LDS[i]<<endl;

    for (int i = 0; i<n&&L; i++)
    {
        if(LDS[i]==L)
        {
            v.pb(i+1);
            L--;
        }

    }
    assert(v.size()>1);
    printf("%d %d",v[0],v[(int)v.size()-1]);

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
