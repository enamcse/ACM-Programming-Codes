#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100010
#define MAX (sz<<2)
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

ll stree[MAX], scale[MAX], element, g, sum;
bool upd[MAX];

void push_down(int ind, int LB, int UB)
{
    upd[ind] = false;
    stree[ind] = (UB-LB+1)*scale[ind];
    if(UB!=LB)
    {
        int m = (ind<<1);
        upd[m] = upd[m+1] = true;
        scale[m] = scale[m+1] = scale[ind];
    }
    scale[ind]=0;
    return;
}

void push_up(int ind, int LB, int UB)
{
    int m =(ind<<1);
    stree[ind] = stree[m]+stree[m+1];
    return;
}

void update(int ind,int LB, int UB, int P, int Q, int val)
{
//    cout<<"ind = "<<ind<<", LB = "<<LB<<", UB = "<<UB<<", P = "<<P<<", Q = "<<Q<<", val = "<<val<<endl;
    if(upd[ind]) push_down(ind,LB,UB);
    if(LB>Q||UB<P) return;
    if(LB>=P&&UB<=Q)
    {
        scale[ind] = val;
        push_down(ind,LB,UB);
        return;
    }
    int mid = ((UB+LB)>>1), m = (ind<<1);
    update(m,LB,mid,P,Q,val);
    update(m+1,mid+1,UB,P,Q,val);
    push_up(ind,LB,UB);
    return;
}

ll query(int ind, int LB, int UB, int P, int Q)
{
//    cout<<"1ind = "<<ind<<", LB = "<<LB<<", UB = "<<UB<<", P = "<<P<<", Q = "<<Q<<", val = "<<stree[ind]<<endl;
    if(upd[ind])
    {
        push_down(ind,LB,UB);
//        push_up(ind,LB,UB);
    }
//    cout<<"2ind = "<<ind<<", LB = "<<LB<<", UB = "<<UB<<", P = "<<P<<", Q = "<<Q<<", val = "<<stree[ind]<<endl;
    if(LB>Q||UB<P) return 0;
    if(LB>=P&&UB<=Q) return stree[ind];
    int mid = ((UB+LB)>>1), m = (ind<<1);
    return (query(m,LB,mid,P,Q)+query(m+1,mid+1,UB,P,Q));
}

int main()
{
    _
    int t, cas=1,n, q, cond, v,w,x;
    scanf("%d", &t);
    while(t--)
    {
        clr(upd,false);
        clr(stree,0);
        clr(scale,0);
        printf("Case %d:\n", cas++);
        scanf("%d %d", &n, &q);
        for (int i = 0; i<q; i++)
        {
            scanf("%d", &cond);
            if(cond==1)
            {
                scanf("%d %d %d", &w,&x,&v);
                update(1,0,n-1,w,x,v);
            }
            else
            {
                scanf("%d %d", &w,&x);
                sum = (ll)query(1,0,n-1,w,x);
                element = (ll)(x-w+1);
//                cout<<element<<" sum = "<<sum<<endl;
                g = (ll) __gcd(element,sum);
                sum/=g;
                element/=g;
                if(element!=1) printf("%lld/%lld\n",sum,element);
                else printf("%lld\n", sum);
            }
        }

    }
    return 0;
}
/*
1
10 6
1 0 6 6
2 0 1
1 1 1 2
2 0 5
1 0 3 7
2 0 1
*/
