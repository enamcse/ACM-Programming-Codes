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

int note[] = {100, 50, 20, 10, 5, 2, 1};

int main()
{
    _
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 0; i<7; i++)
    {
        printf("%d nota(s) de R$ %d,00\n", n/note[i], note[i]);
        n%=note[i];
    }
    return 0;
}
