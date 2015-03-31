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
#define false 0
#define true 1
using namespace std;

int tree[sz], stree[MAX];
bool upd[MAX];
void build(int ind, int LB, int UB, int P)
{
//    if(P<LB||P>UB) return;
    if(LB==UB)
    {
//        cout<<LB<<endl;
        if(LB==P) stree[ind]=tree[P];
        return;
    }
    int mid = ((UB+LB)>>1);
    int m = (ind<<1);
    if(P<=mid)build(m,LB,mid,P);
    else build(m+1,mid+1,UB,P);
    return;
}

void push_down(int ind, int LB, int UB)
{
    upd[ind] = false;
    if(UB==LB) return;
    int m = (ind<<1);
    upd[m] ^= true;
    upd[m+1] ^= true;
    stree[m]^=1;
    stree[m+1]^=1;
    stree[ind] = 0;
    return;
}

void update(int ind, int LB, int UB, int P, int Q)
{
    if(upd[ind]) push_down(ind,LB,UB);
    if(LB>Q||UB<P) return;
    if(LB>=P&&UB<=Q)
    {
        stree[ind]^=1;
        push_down(ind,LB,UB);
        return;
    }
    int mid = ((UB+LB)>>1);
    int m = (ind<<1);
    update(m,LB,mid,P,Q);
    update(m+1,mid+1,UB,P,Q);
    return;
}

int query(int ind, int LB, int UB, int P)
{
    if(upd[ind]) push_down(ind,LB,UB);
//    if(P<LB||P>UB) return;
    if(UB==LB) return stree[ind];
    int mid = ((UB+LB)>>1);
    int m = (ind<<1);
    if(P<=mid) return query(m,LB,mid,P);
    else return query(m+1,mid+1,UB,P);
}

int main()
{
    int t, n, q,cas=1, x, y;
    char line[sz], ch;
    scanf("%d",&t);
    while(t--)
    {
        clr(upd,0);
        clr(stree,0);
        clr(tree,0);
        printf("Case %d:\n",cas++);
        scanf("%s",line);
        n = strlen(line);
        for (int i = 0; i<n; i++)
            if(line[i]=='1') tree[i]=1,build(1,0,n-1,i);
//        for (int i = 0; i<26; i++)
//            cout<<i<<"="<<stree[i]<<endl;
        scanf("%d",&q);
        while(q--)
        {
            scanf(" %c",&ch);
            if(ch == 'I')
            {
                scanf("%d %d", &x, &y);
                update(1,0,n-1,x-1,y-1);
//                for (int i = 1; i<26; i++)
//                    cout<<i<<"="<<stree[i]<<" & "<<upd[i]<<endl;
            }
            else
            {
                scanf("%d", &x);
                printf("%d\n", query(1,0,n-1,x-1));
//                for (int i = 1; i<26; i++)
//                    cout<<i<<"="<<stree[i]<<" & "<<upd[i]<<endl;
            }
        }
    }
    return 0;
}
/*
2
0011001100
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
1011110111
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
*/
