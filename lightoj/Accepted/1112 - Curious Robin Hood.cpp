#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100001
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf 1<<30
using namespace std;

void build(int ind, int LB, int UB);
int sum_query(int ind, int LB, int UB);
void update(int ind, int LB, int UB);

int val[sz], seg[3*sz], s, e, value, ith;

int main()
{
    int T, N, q, caseno=1, type;

    scanf("%d", &T);

    for (int i=0; i<T; i++)
    {
        printf("Case %d:\n", caseno++);
        scanf("%d %d", &N, &q);
        for (int j=1; j<=N; j++) scanf("%d", &val[j]);

        build(1,1,N);
//        for (int k=1; k<=3*N; k++)
//                cout<<seg[k]<<" ";
//        cout<<endl;
        for (int j=0; j<q; j++)
        {
            scanf("%d", &type);

            switch(type)
            {
            case 1:
                scanf("%d", &ith);
                ith++;
                printf("%d\n", val[ith]);
                value = -val[ith];
                update(1,1,N);
                val[ith] = 0;
                break;
            case 2:
                scanf("%d %d", &ith, &value);
                ith++;
                update(1,1,N);
                val[ith]+= value;
                break;
            case 3:
                scanf("%d %d", &s, &e);
                s++,e++;
                printf("%d\n", sum_query(1,1,N));
                break;
            }

//            for (int k=1; k<=N; k++)
//                cout<<val[k]<<" ";
//            cout<<endl;
//            for (int k=1; k<=3*N; k++)
//                cout<<seg[k]<<" ";
//            cout<<endl;
        }
    }

    return 0;
}

void build(int ind, int LB, int UB)
{
    if(LB==UB)
    {
        seg[ind] = val[LB];
        return;
    }
    int mid = (UB+LB)>>1;
    build((ind<<1), LB, mid);
    build((ind<<1)+1, mid+1, UB);
    seg[ind] = seg[ind<<1] + seg[(ind<<1)+1];
    return;
}

int sum_query(int ind, int LB, int UB)
{
    if(e<LB||s>UB) return 0;
    if(UB<=e&&LB>=s) return seg[ind];
    int mid=(UB+LB)>>1;
    return (sum_query(ind<<1,LB,mid) + sum_query((ind<<1)+1,mid+1,UB));
}

void update(int ind, int LB, int UB)
{
//    cout<<":"<<ind<<" "<<LB<<" "<<UB<<endl;
    if(UB>=ith&&ith>=LB)
    {
//        cout<<"::"<<ind<<" "<<LB<<" "<<UB<<endl;
        seg[ind]+=value;
        if(UB==LB) return;
        int mid=(UB+LB)>>1;
        update(ind<<1,LB,mid);
        update((ind<<1)+1,mid+1,UB);
        return;
    }
    else return;
}
