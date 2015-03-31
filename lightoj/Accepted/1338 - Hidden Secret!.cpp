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
#define sz 105
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int letter[26];

int main()
{
    int t, caseno=1, len;
    char ch, line[sz];
    scanf("%d ", &t);
    while(t--)
    {
        clr(letter,0);
        gets(line);
        len = strlen(line);
        for (int i = 0; i<len; i++)
        {
            ch = tolower(line[i]);
            if(ch>= 'a'&&ch<='z') letter[ch-'a']++;
        }

        gets(line);
        len = strlen(line);
        for (int i = 0; i<len; i++)
        {
            ch = tolower(line[i]);
            if(ch>= 'a'&&ch<='z') letter[ch-'a']--;
        }
        bool flag = true;
        for (int i = 0; i<26; i++)
            if(letter[i]!=0)
            {
                flag = false;
                break;
            }
        if(flag)
            printf("Case %d: Yes\n", caseno++);
        else
            printf("Case %d: No\n", caseno++);
    }
    return 0;
}
