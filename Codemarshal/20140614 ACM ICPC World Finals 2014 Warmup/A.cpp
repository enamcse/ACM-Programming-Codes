#include <bits/stdc++.h>

#define sz 50005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

char line[sz];

int freq[26];

int main()
{
    int n, len;

    while(~scanf("%s", line) && strcmp(line, "#"))
    {
        len = strlen(line);
        n = 0;
        clr(freq,0);
        for (int i = 0; i<len; i++)
        {
            freq[ line[i] - 'a' ]++;
        }

        for (int i = 0; i<26; i++)
        {
            if(freq[i]%2) n++;
        }
        if((len+n-1)%2&&n>1)
        {
            for (int i = 0; i<26; i++)
            {
                if(freq[i]%2)
                {
                    n--;
                    printf("%c", i+'a');
                    if(n==1) break;
                }
            }
            puts("");
        }
        else if((len+n-1)%2) puts("");
        else if((len+n)%2==0&&n)
        {
            cout<<len<<": "<<n<<endl;
            for (int i = 0; i<26; i++)
            {
                if(freq[i]%2)
                {
                    n--;
                    printf("%c", i+'a');
                    if(n==0) break;
                }
            }
            puts("");
        }
        else puts("");

    }

    return 0;
}
