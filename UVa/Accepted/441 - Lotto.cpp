#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 15
#define pb(a) push_back(a)
#define pp() pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int arr[sz],n;
vector<int>v;

void rec(int pos, int taken)
{
    if(taken==6)
    {
        for (int i = 0; i<5; i++)
            printf("%d ", v[i]);
        printf("%d\n", v[5]);
        return;
    }
    if(pos==n) return;
    v.pb(arr[pos]);
    rec(pos+1,taken+1);
    v.pp();
    rec(pos+1,taken);

    return;
}


int main()
{
    bool flag = false;
    while(~scanf("%d", &n)&&n)
    {
        if(flag) puts("");
        else flag = true;

        for (int i = 0; i<n; i++)
            scanf("%d", &arr[i]);

        rec(0,0);

    }


    return 0;
}
