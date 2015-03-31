#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100010
#define ll long long
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

ll stree[(sz<<2)], scale[(sz<<2)];
bool upd[(sz<<2)];

void push_down(ll ind, ll LB, ll UB)
{
    upd[ind] = false;
    stree[ind]+=(scale[ind]*(UB-LB+1));
    if(UB!=LB)
    {
        ll c = (ind<<1);
        upd[c] = upd[c+1] = true;
        scale[c]+= scale[ind];
        scale[c+1]+= scale[ind];
    }
    scale[ind] = 0;
    return;
}

void push_up(ll ind, ll LB, ll UB)
{
    stree[ind] = stree[(ind<<1)] + stree[(ind<<1)+1];
    return;
}

void update(ll ind, ll LB, ll UB, ll P, ll Q, ll val)
{
    if(upd[ind]) push_down(ind, LB, UB);
    if(P<=LB&&Q>=UB)
    {
        scale[ind]+= val;
        push_down(ind,LB,UB);
        return;
    }
    if(UB<P||LB>Q) return;
    ll mid = ((UB+LB)>>1);
    update((ind<<1), LB, mid, P,Q,val);
    update((ind<<1)+1, mid+1,UB, P,Q,val);
    push_up(ind,LB,UB);
    return;
}

ll query(ll ind, ll LB, ll UB, ll P, ll Q)
{
    if(upd[ind]) update(ind, LB, UB,P,Q,0);
    if(LB>Q||UB<P) return 0L;
    if(LB>=P&&UB<=Q) return stree[ind];
    ll mid = ((UB+LB)>>1);
    return (query((ind<<1), LB, mid, P, Q)+query((ind<<1)+1,mid+1, UB, P,Q));
}

int main()
{
    _
    ll t, n, q, x, y, v, w,cas=1;
    scanf("%lld", &t);
    while(t--)
    {
        clr(stree,0);
        clr(upd,0);
        clr(scale,0);
        scanf("%lld %lld", &n, &q);
        printf("Case %lld:\n", cas++);
        while(q--)
        {
            scanf("%lld", &w);
            if(w)
            {
                scanf("%lld %lld", &x, &y);
                printf("%lld\n", query(1,0,n-1,x,y));
            }
            else
            {
                scanf("%lld %lld %lld", &x, &y, &v);
                update(1,0,n-1,x,y,v);
            }
        }
    }
    return 0;
}
/*
2
10 5
0 0 9 10
1 1 6
0 3 7 2
0 4 5 1
1 5 5
20 3
0 10 12 1
1 11 12
1 19 19
*/

