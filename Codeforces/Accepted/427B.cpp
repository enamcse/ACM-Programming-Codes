#include <iostream>
#include <cstdio>
#include <string>

#define sz 800008
using namespace std;

int stree[sz];

void build(int ind, int LB, int UB, int P, int val)
{
    if(P<LB || P>UB) return;
    if(LB == UB)
    {
        stree[ind] = val;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) build(m,LB,mid,P,val);
    else build(m+1,mid+1,UB, P,val);

    stree[ind] = max(stree[m],stree[m+1]);
    return;
}

int query(int ind, int LB, int UB, int P, int Q)
{
    if(Q<LB || P>UB) return 1;
    if(UB==LB)
        return stree[ind];

    if(P<=LB && Q>=UB)
        return stree[ind];

    int mid = ((LB+UB)>>1), m = (ind<<1), k=0;
    if(P<=mid) k = max(query(m,LB,mid,P,Q),k);
    if(Q>mid) k= max(k,query(m+1,mid+1,UB, P, Q));
    return k;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int n, m, q, t, c, cnt=0;
    scanf("%d %d %d", &n, &t, &c);
    {

        for (int i = 0; i<n; i++)
        {
            scanf("%d", &q);
            build(1,1,n,i+1,q);
        }
        m = n-c+1;
        for (int i = 0; i<m; i++)
        {
                if(query(1, 1, n, i+1 , i+c)<=t) cnt++;
        }
        printf("%d\n",cnt);
    }
}





