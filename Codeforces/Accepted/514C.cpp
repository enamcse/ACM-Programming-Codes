/**
* H:\Dropbox\Code\Codeforces\514C.cpp
* Created on: 2015-02-14-22.22.49, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 650005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

// TRIE starts array
#define trie_sz 3
struct node{
    bool ending;
    int next[trie_sz];
    node()
    {
        ending = false;
        for (int i = 0; i<trie_sz; i++) next[i] = 0;
    }
}data[sz];
int counter=1;

void insert_in_trie(char *str, int len)
{
    int n = 0;
    for (int i = 0; i<len; i++)
    {
        int now = str[i]-'a';
        if(data[n].next[now]==0)
        {
            data[n].next[now] = counter++;
        }
        n=data[n].next[now];
    }
    data[n].ending=true;
}

int now;
char s[sz];
bool ret;

void rec(int pos, int k, int hand)
{
    if(pos==now) {ret=data[k].ending&&hand;return;}
    int dis = data[k].next[ s[pos]-'a' ];
    if(hand==0)
    {
        if(!ret&&dis) rec(pos+1,dis, hand);
        if(!ret&&s[pos]!='a' && data[k].next[ 0 ]) rec(pos+1,data[k].next[ 0 ], hand+1);
        if(!ret&&s[pos]!='b'&& data[k].next[ 1 ]) rec(pos+1,data[k].next[ 1 ], hand+1);
        if(!ret&&s[pos]!='c'&& data[k].next[ 2 ]) rec(pos+1,data[k].next[ 2 ], hand+1);
    }
    else if(dis)rec(pos+1,dis, hand);
    return;
}

bool delete_from_trie() // this is for memset only
{
    counter=1;
    clr(data,0);
}
// TRIE ends using array


int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i<n; i++)
        {
            scanf("%s", s);
            insert_in_trie(s,strlen(s));
        }

    for (int i = 0; i<m; i++)
        {
            scanf("%s", s);
            now = strlen(s);
            ret=false;
            rec(0,0,0);
            ret?printf("YES\n"):printf("NO\n");
        }
//    delete_from_trie();
    return 0;
}

/**
2 8
aaaaa
acacaca
a
aa
aaa
aaaa
aaaaa
aaaaaa
aaaab
aaaac
*/
