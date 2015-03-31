#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>
#define sz 1005
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
    char line[sz], out[sz], ch;
    int n,i,len;
    stack<char>s;
    scanf("%d ", &n);
    while(n--)
    {
        while(scanf("%c", &ch)==1&&ch!='\n')
        {
            if(ch!=' ') s.push(ch);
            else
            {
                while(!s.empty())
                    printf("%c",s.top()),s.pop();
                printf(" ");
            }

        }
        while(!s.empty())
            printf("%c",s.top()),s.pop();
        printf("\n");
    }
    return 0;
}
