#include <bits/stdc++.h>


#define sz 100055
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

ll stree1[(sz<<2)], stree2[(sz<<2)];

void build1(int ind, int LB, int UB, int P, ll val)
{
    if(P<LB || P>UB) return;
    if(LB == UB)
    {
        stree1[ind] = val;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) build1(m,LB,mid,P,val);
    else build1(m+1,mid+1,UB, P,val);

    stree1[ind] = stree1[m]+stree1[m+1];
    return;
}

ll query1(int ind, int LB, int UB, int P, int Q)
{
    if(Q<LB || P>UB) return 0;
    if(UB==LB)
        return stree1[ind];

    if(P<=LB && Q>=UB)
        return stree1[ind];

    int mid = ((LB+UB)>>1), m = (ind<<1);
    ll k=0LL;
    if(P<=mid) k += query1(m,LB,mid,P,Q);
    if(Q>mid) k+= query1(m+1,mid+1,UB, P, Q);
    return k;
}

void build2(int ind, int LB, int UB, int P, ll val)
{
    if(P<LB || P>UB) return;
    if(LB == UB)
    {
        stree2[ind] = val;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) build2(m,LB,mid,P,val);
    else build2(m+1,mid+1,UB, P,val);

    stree2[ind] = stree2[m]+stree2[m+1];
    return;
}

ll query2(int ind, int LB, int UB, int P, int Q)
{
//    cout<<ind<<": "<<LB<<" "<<UB<<" "<<P<<" "<<Q<<endl;
//    cout<<stree2[ind]<<"::"<<endl;
    if(Q<LB || P>UB) return 0;
//    if(UB==LB)
//        return stree2[ind];

    if(P<=LB && Q>=UB)
        return stree2[ind];

    int mid = ((LB+UB)>>1), m = (ind<<1);
    ll k=0LL;
    if(P<=mid) k += query2(m,LB,mid,P,Q);
//    cout<<k<<";;"<<endl;
    if(Q>mid) k += query2(m+1,mid+1,UB, P, Q);
//    cout<<k<<";"<<endl;
    return k;
}

vector<int>v;

int main()
{
    #ifdef ENAM
    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, a, b;

    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &m);
        v.pb(m);
        build1(1,1,n,i+1,(ll)m);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i<n; i++)
    {

        build2(1,1,n,i+1,(ll)v[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i<m; i++)
    {
        scanf("%d %d %d", &t, &a, &b);
        if(t==1)cout<<query1(1,1,n,a,b)<<endl;
//            printf("%I64d\n", query1(1,1,n,a,b));
        else cout<<query2(1,1,n,a,b)<<endl;
//            printf("%I64d\n", query2(1,1,n,a,b));
    }
    return 0;
}
