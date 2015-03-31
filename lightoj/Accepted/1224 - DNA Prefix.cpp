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
#include <stack>

#define sz 1310720
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
map<char,int>mp;

// TRIE starts using pointer
#define trie_sz 4
struct node
{
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
        int now = mp[ str[i] ];
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

void delete_from_trie(node *cur) // this is for memset, it should be called by delete_from_trie(root) from main
{

    for (int i = 0; i<trie_sz; i++)
        if(cur->next[i]!=NULL) delete_from_trie(cur->next[i]);
    mx = max(mx,cur->depth * cur->counter);
    delete(cur);
    return;
}
// TRIE ends using pointer
int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    mp['A']=0;
    mp['T']=1;
    mp['G']=2;
    mp['C']=3;

    int t, cas=1,n;

    char line[100], ch;
    scanf("%d", &t);
    while(t--)
    {
        mx=0;
        root = new node();
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%s", line);
            insert_in_trie(line, strlen(line));
        }
        delete_from_trie(root);
        printf("Case %d: %d\n",cas++,mx);
    }


    return 0;
}
/*
3
4
ACGT
ACGTGCGT
ACCGTGC
ACGCCGT
3
CGCGCGCGCGCGCCCCGCCCGCGC
CGCGCGCGCGCGCCCCGCCCGCAC
CGCGCGCGCGCGCCCCGCCCGCTC
2
CGCGCCGCGCGCGCGCGCGC
GGCGCCGCGCGCGCGCGCTC
*/
