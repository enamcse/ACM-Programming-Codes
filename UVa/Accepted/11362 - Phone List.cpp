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

// TRIE starts using pointer
struct node
{
    bool ending;
    node *next[10];
    node()
    {
        ending = false;
        for (int i = 0; i<10; i++) next[i] = NULL;
    }
}*root;

void insert_in_trie(char *str, int len)
{
    node *cur = root;
    for (int i = 0; i<len; i++)
    {
        int now = str[i]-'0';
        if(cur->next[now]==NULL)
            cur->next[now]=new node();
        cur=cur->next[now];
    }
    cur->ending=true;
}

bool search_in_trie(char *str, int len)
{
    node *cur=root;
    for (int i = 0; i<len; i++)
    {
        int now = str[i]-'0';
        if(cur->next[now]==NULL) return cur->ending;
        if(cur->ending==true) return cur->ending;
        cur=cur->next[now];
    }
    return !cur->ending;
}

bool delete_from_trie(node *cur) // this is for memset, it should be called by delete_from_trie(root) from main
{
    for (int i = 0; i<10; i++)
        if(cur->next[i]!=NULL) delete_from_trie(cur->next[i]);
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
    char line[10005];
    scanf("%d", &t);
    bool flag;
    while(t--)
    {
        root = new node();
        scanf("%d", &n);
        scanf("%s", line);
        insert_in_trie(line,strlen(line));
        flag = true;
        for (int i = 1; i<n; i++)
        {
            scanf("%s", line);
            if(flag)
                if(!search_in_trie(line,strlen(line))) insert_in_trie(line,strlen(line));
                else flag = false;
        }
        delete_from_trie(root);
        flag==true?printf("YES\n"):printf("NO\n");
    }


    return 0;
}
