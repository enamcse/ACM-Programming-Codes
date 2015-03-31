#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1009
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int number[sz],cnt;

void merging(int a, int mid, int b)
{
    int i, j, rem, x[mid+1], y[b-mid],ind=a;
    for (i = 0; i<=mid-a; i++)
        x[i] = number[a+i];
    for (i = 0; i<b-mid; i++)
        y[i] = number[mid+1+i];
    i=j=0;
    rem = mid-a+1;
    while(i<=mid-a&&j<b-mid)
    {
        if(x[i]>y[j])
        {
            number[ind++] =y[j++];
            cnt+=rem;
        }
        else
        {
            number[ind++] =x[i++];
            rem--;
        }
    }
    if(i>mid-a) while (j<b-mid) number[ind++] =y[j++];
    if(j>=b-mid) while (i<=mid-a) number[ind++] =x[i++];
    return;
}

void merge_sort(int a, int b)
{
    if(a==b) return;
    int mid = ((a+b)>>1);
    merge_sort(a,mid);
    merge_sort(mid+1,b);
    merging(a,mid,b);
    return;
}

int main()
{
    _
    int n;
    while(scanf("%d", &n)==1)
    {
        cnt =0;
        for (int i = 0; i<n; i++)
            scanf("%d", &number[i]);
        merge_sort(0,n-1);
        printf("Minimum exchange operations : %d\n",cnt);
    }
    return 0;
}
