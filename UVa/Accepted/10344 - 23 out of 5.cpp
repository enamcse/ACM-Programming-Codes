#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

void rec(int cnt);
void calc(int pos, int val);

vector<int>v;
int value[5];
bool tag;
bool col[5];


int main()
{
    while(scanf("%d %d %d %d %d",&value[0], &value[1],&value[2],&value[3],&value[4])==5)
    {
        if(!(value[0]||value[1]||value[2]||value[3]||value[4])) return 0;
        v.clear();
        tag = false;
        clr(col,false);
        rec(0);
        if(tag) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}

void rec(int cnt)
{
    if(cnt == 5)
    {
        if(tag==false) calc(0,v[0]);
        return;
    }
    for (int i=0; i<5; i++)
    {
        if(col[i]==false)
        {
            col[i]=true;
            v.pb(value[i]);
            rec(cnt+1);
            v.pp;
            col[i]=false;
        }
        if(tag==true) return;
    }
}

void calc(int pos, int val)
{
    if(pos==4)
    {
        if(val==23) tag = true;
        return;
    }
    if(tag==false) calc(pos+1,val+v[pos+1]);
    if(tag==false) calc(pos+1,val-v[pos+1]);
    if(tag==false) calc(pos+1,val*v[pos+1]);
    return;
}
