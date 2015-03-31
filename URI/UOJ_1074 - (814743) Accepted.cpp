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
#define PI 3.14159
using namespace std;

int main()
{
    _
    int a, b;

    scanf("%d", &a);

    while(a--)
    {
        scanf("%d", &b);
        if(b==0) puts("NULL");
        else if(b%2)
        {
            printf("ODD ");
            if(b>0) puts("POSITIVE");
            else puts("NEGATIVE");
        }
        else
        {
            printf("EVEN ");
            if(b>0) puts("POSITIVE");
            else puts("NEGATIVE");
        }
    }

    return 0;
}
