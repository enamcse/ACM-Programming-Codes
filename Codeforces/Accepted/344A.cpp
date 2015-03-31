#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    _
    int n, cnt = 1, a, b;
    scanf("%d", &n);
    if(n==1)
    {
        scanf("%d", &n);
        printf("1");
        return 0;
    }
    scanf("%d", &a);
    for (int i =1; i<n; i++)
    {
        scanf("%d", &b);
        if(a!=b) cnt++;
        a =b;
//        cout<<a<<" "<<b<<endl;
    }
    printf("%d", cnt);
    return 0;
}
