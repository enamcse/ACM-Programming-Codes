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

vector<char>v;

int main()
{
    _
    int n, x,y,z;
    bool flag;
    char line[200], ch, mx;
    while(~scanf("%s", line))
    {
        v.clear();
        if(!strcmp(line, "#")) break;
        flag = true;
        n = strlen(line);
        if(n<2) printf("No Successor\n");
        else if (n==2)
        {
            if(line[1]>line[0]) printf("%c%c\n", line[1], line[0]);
            else printf("No Successor\n");
        }
        else
        {
            mx=ch = line[n-1];
            for (int i = n-2; i>=0&&flag; i--)
            {
                if(line[i]<ch)
                {
                    mx = line[i+1];
                    x  = i+1;
                    for (int j = i+2; j<n; j++)
                    {
                        if(line[j]>line[i])
                        {
                            if(line[j]<mx)
                            {
                                mx = line[j];
                                x  = j;
                            }
                        }
                    }

                    for (int j = i; j<n; j++)
                    {
                        if(j!=x) v.pb(line[j]);
                    }
                    line[i] = mx;
                    sort(v.begin(),v.end());
                    for (int k=0, j = i+1; j<n; j++)
                    {
                        line[j] = v[k++];
                    }
                    flag = false;
                    break;
                }
                ch = line[i];
            }
            if(flag) printf("No Successor\n");
            else printf("%s\n", line);
        }
    }
    return 0;
}
