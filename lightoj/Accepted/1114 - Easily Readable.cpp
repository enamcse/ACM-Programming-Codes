//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define SZ 100055
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

map<char,int>mp;
char s[SZ/10];
char line[SZ];

// TRIE starts array
#define trie_sz 52
struct node{
    int ending;
    int next[trie_sz];
    node()
    {
        ending = 0;
        for (int i = 0; i<trie_sz; i++) next[i] = 0;
    }
}data[SZ];
int counter=1;

void insert_in_trie(char *str, int len)
{
    int n = 0;
    for (int i = 0; i<len; i++)
    {
        int now = mp[str[i] ];
        if(data[n].next[now]==0)
        {
            data[n].next[now] = counter++;
        }
        n=data[n].next[now];
    }
    data[n].ending++;
}

int search_in_trie(char *str, int len)
{
    int n = 0;
    for (int i = 0; i<len; i++)
    {
        int now = mp[str[i] ];
        if(data[n].next[now]==0) return 0;
        n=data[n].next[now];
    }
    return data[n].ending;
}

inline void delete_from_trie() // this is for memset only
{
    clr(data,0);
}
// TRIE ends using array

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    for (int i = 0; i<26; i++)
        mp[ (char)('A'+i) ] = i;

    for (int i = 0; i<26; i++)
        mp[ (char)('a'+i) ] = i+26;
    int t, n, m, cas=1,k,p,cnt,q;
    scanf("%d", &t);
    while(t--)
    {
        counter=1;
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%s", s);
            q=strlen(s);
            if(q>3)sort(s+1,s+q-1);
            insert_in_trie(s,q);
        }

        scanf("%d", &n);
        getchar();
        printf("Case %d:\n",cas++);
        for (int i = 0; i<n; i++)
        {
            cnt = 1;
            p = m=0;
            gets(line);
            k = strlen(line);
            while(sscanf(line," %s", s)==1)
            {
                q=m=strlen(s);
                for (int j = 0; j<strlen(line); j++)
                    if(line[j]==' ') m++;
                    else break;
                p+=m;
                strcpy(line,line+m);
                if(q>3)sort(s+1,s+q-1);
                cnt*=search_in_trie(s,q);
                if(k<=p) break;
            }
            printf("%d\n",cnt);
        }
        if(t)delete_from_trie();
    }
    return 0;
}
