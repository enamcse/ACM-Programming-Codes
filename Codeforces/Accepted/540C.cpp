/**
* H:\Dropbox\Code\Codeforces\540C.cpp
* Created on: 2015-04-30-22.28.46, Thursday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
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

int cc[] = {0,0,1,-1};
int rr[] = {1,-1,0,0},n, m;

string s[505];
pair<int,int> par[505][505];
void print()
{
    cerr<<"-------------------\n";
    for (int i = 0; i<n; i++)
        cerr<<s[i]<<endl;
    cout<<"-------------------"<<endl;
}
bool bfs(int sx, int sy, int dx, int dy)
{
    bool ret = false;
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy));
    int x, y, xx, yy;
    while(!q.empty())
    {
//        cout<<x<<" "<<y<<endl;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i<4; i++)
        {
            xx = x+cc[i];
            yy = y+rr[i];
            if(xx<0||yy<0||xx>=n||yy>=m||par[xx][yy].first!=-1) continue;

            par[xx][yy] = make_pair(x,y);
            if(xx==dx&&yy==dy)
            {
                ret = true;
                break;
            }
            if(s[xx][yy] == 'X') continue;
            q.push(make_pair(xx,yy));
        }
    }
    if(!ret) return false;

    do
    {
        s[dx][dy] = 'X';
        x = par[dx][dy].first;
        y = par[dx][dy].second;
        dx = x;
        dy = y;
    }
    while(!(dx==sx && dy == sy));
//    print();
    return ret;
}




int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, cas=1, sx, sy, dx, dy, ki;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    clr(par,-1);
    cin>>n>>m;

    for (int i = 0; i<n; i++)
        cin>>s[i];

    cin>>sx>>sy>>dx>>dy;
    sx--;
    sy--;
    dx--;
    dy--;
    bool flag=true;
    ki = s[dx][dy]=='.';
    flag = bfs(sx,sy,dx,dy);
    clr(par,-1);
    if(ki&&flag)flag = bfs(dx,dy,dx,dy);

    if(flag) cout<<"YES";
    else cout<<"NO";



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
