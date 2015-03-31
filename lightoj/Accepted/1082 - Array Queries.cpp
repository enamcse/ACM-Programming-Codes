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
int min_query(int ind, int LB, int UB);

int val[sz], seg[3*sz], s, e;

int main()
{
    int T, N, q, caseno=1;

    scanf("%d ", &T);

    for (int i=0; i<T; i++)
    {
        printf("Case %d:\n", caseno++);
        scanf("%d %d", &N, &q);
        for (int j=1; j<=N; j++) scanf("%d", &val[j]);

        build(1,1,N);

        for (int j=0; j<q; j++)
        {
            scanf("%d %d", &s, &e);
             printf("%d\n", min_query(1,1,N));
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
    seg[ind] = min(seg[ind<<1], seg[(ind<<1)+1]);
    return;
}

int min_query(int ind, int LB, int UB)
{
    if(e<LB||s>UB) return inf;
    if(UB<=e&&LB>=s) return seg[ind];
    int mid=(UB+LB)>>1;
    return min(min_query(ind<<1,LB,mid), min_query((ind<<1)+1,mid+1,UB));
}
