/**
* H:\Dropbox\Code\CodeChef\Snack Down 2015\Round 1C\A.cpp
* Created on: 2015-06-07-21.54.23, Sunday
* Verdict: Solved
* Author: Enamul Hassan
* Problem Name: Devu and his mouse Jerry
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
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int cc[] = {0,0,1,-1};
int rr[] = {1,-1,0,0};


bool col[22][22];

int n,xs,ys, xd, yd, xb,yb;

int bfs()
{
    clr(col, false);
    queue<int>q;
    q.push(xs);
    q.push(ys);
    q.push(0);
    int x,y,u,v,cost;
    col[xs][ys] = true;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();
        cost = q.front();
        q.pop();

        for (int i = 0; i<4; i++)
        {
            u = x+cc[i];
            v = y+rr[i];
            if(u<1||v<1||u>n||v>n||col[u][v]) continue;
            if(u==xb&&v==yb) continue;
            if(u==xd&&v==yd) return cost+1;
            q.push(u);
            q.push(v);
            q.push(cost+1);
            col[u][v] = true;
        }
    }
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        cin>>n>>xs>>ys>>xd>>yd>>xb>>yb;
        cout<<bfs()<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
