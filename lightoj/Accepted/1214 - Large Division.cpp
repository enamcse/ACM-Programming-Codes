#include <bits/stdc++.h>

#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;


int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, cas=1, k;
    ll now;
    char line[205];

    scanf("%d", &t);

    while(t--)
    {
        scanf(" %s %lld", line, &now);
        int len = strlen(line);
        now = abs(now);
        if(line[0]=='-')k = 1;
        else k = 0;
        ll m=0;
        while(k<len) m = (m*10+line[k++]-'0')%now;

        if(!m) printf("Case %d: divisible\n", cas++);
        else printf("Case %d: not divisible\n", cas++);
    }

    return 0;
}
