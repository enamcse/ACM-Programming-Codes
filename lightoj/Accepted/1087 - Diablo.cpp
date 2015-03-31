#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 160000
#define MAX (sz<<2)
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
//#define SCCLR system("CLS")

using namespace std;

int stree[MAX], tree[sz],n,total;

void build(int ind, int LB, int UB, int P)
{
    if(P<LB||P>UB) return;
    if(LB == UB)
    {
        stree[ind] = 1;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) build(m, LB,mid, P);
    else build(m+1, mid+1, UB, P);
    stree[ind] = stree[m] + stree[m+1];
    return;
}

void update(int ind, int LB, int UB, int P,int val)
{
    if(UB==LB)
    {
        stree[ind] = val;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) update(m, LB,mid, P,val);
    else update(m+1, mid+1, UB, P,val);
    stree[ind] = stree[m] + stree[m+1];
    return;
}

void query(int ind, int LB, int UB, int P)
{
//    cout<<"ind = "<<ind<<", LB = "<<LB<<", UB = "<<UB<<", P = "<<P<<endl;
//    cout<<" s ="<<stree[ind]<<", c1 = "<<stree[ind<<1]<<", c2 = "<<stree[(ind<<1)+1]<<endl;
    if(UB==LB)
    {
//        cout<<" U :"<<UB<<endl;
        update(1,1,total,UB,0);
        printf("%d\n", tree[UB-1]);
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1), k;
    k = P - stree[m];
    if(k<=0) query(m, LB,mid, P);
    else query(m+1, mid+1, UB, k);
    return;
}

int main()
{
    _
    int t, q,cas=1, temp;
    char ch;
    scanf("%d", &t);
    while(t--)
    {
        printf("Case %d:\n", cas++);
        clr(stree,0);
        clr(tree,0);
        scanf("%d %d", &n, &q);//if(SCCLR) system("clear");
        total=n+q;
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &tree[i]);
            build(1,1,total,i+1);
        }

        for (int i = 0; i<q; i++)
        {
//            cout<<"Tree: "<<endl;
//            for (int j = 0; j<10; j++)
//                cout<<tree[j]<<" ";
//            cout<<endl;
            scanf(" %c", &ch);
            if(ch == 'c')
            {
                scanf("%d", &temp);
//                update(1,0,total-1,temp-1,1);
                if(temp>stree[1]) printf("none\n");
                else query(1,1,total,temp);
            }
            else
            {
                scanf("%d", &tree[n++]);
                update(1,1,total,n,1);

            }
        }

    }

    return 0;
}
/*
2

5 5
6 5 3 2 1
c 1
c 1
a 20
c 4
c 4

2 1
18811 1991
c 1
*/
