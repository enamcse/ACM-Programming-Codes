#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int num[1001];

int main()
{
    _
    int n,a,b, sum=0;
    scanf("%d", &n);
    for (int i = 0; i<n-1; i++)
        scanf("%d", &num[i]);
    scanf("%d %d", &a, &b);
    for (int i = a-1; i<b-1; i++)
        sum+=num[i];
    printf("%d", sum);
    return 0;
}
