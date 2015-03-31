#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100000
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

char line[20];
int len, k;

struct node
{
    int let[10];
    bool comp;
};

int main()
{
    int t, cas=1,n, p, num;
    node digit[sz];
    bool flag;
    scanf("%d", &t);
    while(t--)
    {
        k = 0;
        scanf("%d", &n);
        flag = true;
        clr(digit,0);
        k++;
        for (int i =0; i<n; i++)
        {
            scanf("%s", line);
            if(!flag) continue;
            len = strlen(line);
            p=0;
            for (int j =0; j<len; j++)
            {
                num = line[j]-'0';
                if((digit[p].comp))
                {
                    flag = false;
                    break;
                }
                if(digit[p].let[num]!=0)
                {
                    p = digit[p].let[num];
                }
                else
                {
                    digit[p].let[num] = k;
                    digit[k].comp = false;
                    p = k;
                    k++;
                }
                if(j==len-1)
                {
                    digit[p].comp = true;
                    for (int l = 0; l<10; l++)
                    {
                        if(digit[p].let[l]) flag = false;
                    }
                }
            }
        }

        if(flag) printf("Case %d: YES\n", cas++);
        else printf("Case %d: NO\n", cas++);
    }
    return 0;
}

/*
3
3
911
97625999
91125426
3
91125426
97625999
911
5
113
12340
123440
12345
98346
*/







