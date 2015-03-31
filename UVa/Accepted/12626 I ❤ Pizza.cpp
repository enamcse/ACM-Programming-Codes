#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>
#define sz 700
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int letter[26];

int main()
{
    int n, len, u;
    char line[sz];
    scanf("%d", &n);

    while(n--)
    {
        scanf("%s",line);
        for (int i = 0; i<26; i++)
            letter[i] = 0;
        len = strlen(line);
        for (int i = 0; i<len; i++)
        {
            u = line[i] - 'A';
            letter[u]++;
        }

        u = letter[0]/3;
        u = min(u, letter[6]);
        u = min(u,letter[8]);
        u = min(u, letter[12]);
        u = min(u, letter[17]/2);
        u = min(u, letter[19]);
        printf("%d\n", u);
    }

    return 0;
}
