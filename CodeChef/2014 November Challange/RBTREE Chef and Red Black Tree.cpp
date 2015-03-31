/**
* H:\Dropbox\Code\CodeChef\2014 November Challange\RBTREE Chef and Red Black Tree.cpp
*
* Created on: 2014-11-07-19.29.48, Friday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

bool query,black= true;
int a,b,c;

int findLCA(int x, int  y)
{
    a = floor(log2(x))+1;
    b = floor(log2(y))+1;
    int i,j,root=0;
    for (i = 31; i>=0; i--)
        if((1<<i)&x) break;
    for (j = 31; j>=0; j--)
        if((1<<j)&y) break;
    for(;i>=0&&j>=0;i--,j--)
        if(!((((1<<i) & x)==0 ) ^ (((1<<j) & y)== 0))) root = (root<<1) + (((1<<i) & x)!=0);
        else return root;
    return root;
}

int findDist(int par, int child)
{
    if(par == child) return (par&1)?black!=query:black==query;
    int dif = child - par+1;
    int ret = dif/2;
    if(!(dif&1)) return ret;
    if((black == query && !(par&1)) || (black != query && par&1)) ret++;
    return ret;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,q,x,y,ans;
    char line[10];

    scanf("%d", &q);

    while(q--)
    {
        scanf(" %s",line);
        if(line[1]=='i')
        {
            black^=true;
            continue;
        }
        else if(line[1]=='r') query = true;
        else if(line[1]=='b') query = false;

        scanf("%d %d",&x,&y);
        if(x>y) chng(x,y);

        m=findLCA(x,y);
        c = floor(log2(m))+1;
        ans=findDist(c,b)+findDist(c,a);
        if((black == query && !(c&1)) || (black != query && c&1)) ans--;

        printf("%d\n", ans);
    }


    return 0;
}
/*
5
Qb 4 5
Qr 4 5
Qi
Qb 4 5
Qr 4 5
*/
