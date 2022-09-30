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
    int n, a, b, cas=1,k;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: ", cas++);
        if(a==1||b==1)
        {
            if(a==1) printf("%d\n",b);
            else printf("%d\n",a);
        }
        else if (a==2||b==2)
        {
            if(a==2)
            {
                k = (b>>2);
                if(b%4) k++;
                k<<=2;
                if(b%4==1) k-=2;
                printf("%d\n", k);
            }
            else
            {
                k = (a>>2);
                if(a%4) k++;
                k<<=2;
                if(a%4==1) k-=2;
                printf("%d\n", k);
            }
        }
        else
        {
            k = a * b;
            if(k%2)
            {
                k>>=1;
                k++;
            }
            else k>>=1;
            printf("%d\n",k);
        }
    }
    return 0;
}
/**
20
2 2
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 10
2 11
2 12
2 13
2 14
2 15
2 16
2 17
2 18
2 19
2 20
*/
