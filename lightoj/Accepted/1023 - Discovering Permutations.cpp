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

#define sz 100
#define pb(a) push_back(a)
#define pp() pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int k, n,cnt;
bool col[26];
char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<char>v;

void permutation(int pos)
{
    if(cnt==k) return;
    if(n==pos)
    {
        cnt++;
        for (int i = 0; i<n; i++)
            printf("%c", v[i]);
        printf("\n");
    }
    for (int i =0; i<n; i++)
    {
        if(col[i]) continue;
        col[i]= true;
        v.pb(letter[i]);
        permutation(pos+1);
        v.pp();
        col[i]=false;
    }
    return;
}

int main()
{
    int t, cas=1;
    scanf("%d", &t);
    for (int i =0; i<t; i++)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d:\n", cas++);
        cnt=0;
        permutation(0);
    }
	return 0;
}
