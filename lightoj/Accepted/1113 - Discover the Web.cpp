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

struct data
{
    char web[60];
    data(char b[60])
    {
        strcpy(web,b);
    }
};

int main()
{
    _
    stack<data>backwrd,forwrd;
    char cur[60], input[60], word[10];
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        while(!forwrd.empty()) forwrd.pop();
        while(!backwrd.empty()) backwrd.pop();
        printf("Case %d:\n", cas++);
        strcpy(cur,"http://www.lightoj.com/");
        scanf("%s", &word);
        do
        {
            if(!strcmp(word,"VISIT"))
            {
                backwrd.push(data(cur));
                scanf("%s", &cur);
                printf("%s\n", cur);
                while(!forwrd.empty()) forwrd.pop();
            }
            else if (!strcmp(word,"BACK"))
            {
                if(!backwrd.empty())
                {
                    forwrd.push(data(cur));
                    strcpy(cur, backwrd.top().web);
                    printf("%s\n", cur);
                    backwrd.pop();
                }
                else printf("Ignored\n");
            }
            else if (!strcmp(word,"FORWARD"))
            {
                if(!forwrd.empty())
                {
                    backwrd.push(data(cur));
                    strcpy(cur, forwrd.top().web);
                    printf("%s\n", cur);
                    forwrd.pop();
                }
                else printf("Ignored\n");
            }
        scanf("%s", &word);
        }
        while(strcmp(word,"QUIT"));
    }
    return 0;
}
