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

int main()
{
    _
    char line[1000];
    scanf("%s", line);
    int len, u=0, l=0;
    len = strlen(line);
    for (int i =0; i<len; i++)
    {
        if(line[i]>='a') l++;
        else u++;
    }
    if(u>l)
    {
        for (int i = 0; i<len; i++)
            printf("%c", toupper(line[i]));
    }
    else
    {
        for (int i = 0; i<len; i++)
            printf("%c", tolower(line[i]));
    }
    return 0;
}
