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

#define sz 50005
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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;


struct point{
    int x, y;
    point(){}
    point(int a, int b){
    x=a,y=b;}
};

vector<point>v;


bool comp(point a, point b)
{
    return a.y<b.y;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, w, k, cas=1, p, q, last, cnt, ans;

    scanf("%d", &t );

    while(t--)
    {
        ans = 1;
        scanf("%d %d %d", &n, &w, &k );
        v.clear();
        for (int i = 0; i<n; i++)
        {
            scanf("%d %d", &p, &q );
            v.pb(point(p,q));
        }
        sort(v.begin(), v.end(), comp);
        cnt = 1;
        last = v[0].y+w;
        for (int i = 0; i<n; i++)
        {
            if(v[i].y>last){
                last = v[i].y+w;
                cnt++;
                if(cnt>k){
//                        cout<<"i = "<<i<<endl;
                    ans = i;
                    break;
                }
            }
        }
        if(cnt<=k) ans = n;
        cnt=1;
        last = v[n-1].y-w;
        for (int i = n-1; i>=0; i--)
        {
//            cout<<"ii = "<<i<<" : "<<last<<"> "<<v[i].y<<" a:"<<ans <<endl;
            if(v[i].y<last){
                last = v[i].y-w;
                cnt++;
                if(cnt>k){
                    ans =max( n-i-1, ans);
                    break;
                }
            }
        }
        if(cnt<=k) ans = n;
        printf("Case %d: %d\n", cas++, ans);
    }




    return 0;
}
