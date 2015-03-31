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

#define sz 55
#define pb(a) push_back(a)
#define pp() pop_back()
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

// TRIE starts using pointer
#define trie_sz 128

int total;

struct node
{
    int ending;
    node *next[trie_sz];
    node()
    {
        ending = 0;
        for (int i = 0; i<trie_sz; i++) next[i] = NULL;
    }
}*root;

void insert_in_trie(char *str, int len)
{
    int now;
    node *cur = root;
    for (int i = 0; i<len; i++)
    {
        now = str[i];
        if(cur->next[now]==NULL)
            cur->next[now]=new node();
        cur=cur->next[now];
    }
    cur->ending++;
}

bool delete_from_trie(node *cur, vector<int>v) // this is for memset, it should be called by delete_from_trie(root) from main
{
    for (int i = 0; i<trie_sz; i++)
    {
        if(cur->next[i]!=NULL)
        {
            v.pb(i);
            delete_from_trie(cur->next[i],v);
            v.pp();
        }
    }
    if(cur->ending)
    {
        int now = v.size();
        char ch;
        for (int i = 0; i<now; i++)
        {
            ch = v[i];
            printf("%c",ch);
        }
        double per;
        per = (100.0*cur->ending)/(total*1.0);
        printf(" %.4lf\n",per);
    }

    delete(cur);
}
// TRIE ends using pointer

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    char line[40];
    scanf("%d\n\n", &t);
    vector<int>v;
    while(t--)
    {
        total = 0;
        root = new node();
        gets(line);

        do
        {
            insert_in_trie(line,strlen(line));
            total++;
        }
        while(gets(line)&&strcmp(line,""));
        delete_from_trie(root,v);
        if(t) printf("\n");
    }


    return 0;
}
