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

int mx;

// TRIE starts using pointer
#define trie_sz 2
struct node{
    bool ending;
    int counter,depth;
    node *next[trie_sz];
    node()
    {
        ending = false;
        depth = 0;
        counter=0;
        for (int i = 0; i<trie_sz; i++) next[i] = NULL;
    }
}*root;

void insert_in_trie(char *str, int len)
{
    node *cur = root;
    for (int i = 0; i<len; i++)
    {
        int now = str[i]-'0';
        if(cur->next[now]==NULL)
        {
            cur->next[now]=new node();
            cur->next[now]->depth = cur->depth+1;
        }

        cur=cur->next[now];
        cur->counter=cur->counter+1;
    }
    cur->ending=true;
}

int delete_from_trie(node *cur) // this is for memset, it should be called by delete_from_trie(root) from main
{

    for (int i = 0; i<trie_sz; i++)
        if(cur->next[i]!=NULL) delete_from_trie(cur->next[i]);
    mx = max(mx,cur->depth * cur->counter);
    delete(cur);
    return mx;
}
// TRIE ends using pointer


int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;
    char line[205];
    scanf("%d", &t);

    while(t--)
    {
        mx = 0;
        root = new node();
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%s", line);
            insert_in_trie(line, strlen(line));
        }
        printf("%d\n", delete_from_trie(root));
    }

    return 0;
}
