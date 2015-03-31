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
    char ch[4];
    int a, b, t;
    scanf("%d", &t);
    while(t--)
    {
        a = 0;
        scanf("%3s-%d", ch, &b);
//        printf("%3s-%d", ch, b);
        a = 26 * (ch[0] - 'A') * 26 + (ch[1] -'A') * 26 + (ch[2] -'A');
        if(abs(a-b)<=100) printf("nice\n");
        else printf("not nice\n");
    }
    return 0;
}
