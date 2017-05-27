/**
* H:\Dropbox\Code\UVaLive\6930 - Wheels.cpp
* Created on: 2015-07-28-23.29.09, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb push_back
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

string ans[1005];
bool col[1005];


struct node{
    int x, y, r, id;
    node(int a, int b, int c, int d)
    {
        x = a;
        y = b;
        r = c;
        id = d;
    }
};

vector<node>v;

bool check(int x, int y)
{
    double w1 = sqrt((v[x].x - v[y].x)*(v[x].x - v[y].x) + (v[x].y - v[y].y)*(v[x].y - v[y].y));
    return abs(w1 - (v[x].r + v[y].r))<1e-9;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    _
    int n, m, t,a,b,c;
int u, w, p, qq;
    cin>>t;

    while(t--)
    {
        v.clear();
        clr(col,false);
        cin>>n;

        for (int i = 0; i<n; i++) ans[i] = "";


        for (int i = 0; i<n; i++)
        {
            cin>>a>>b>>c;
            v.pb(node(a,b,c,i));
        }

        queue<int>q;
        q.push(0);
        q.push(1);
        q.push(1);
        q.push(1);


        while(!q.empty())
        {
            u = q.front();
            q.pop();
            w = q.front();
            q.pop();
            p = q.front();
            q.pop();
            qq = q.front();
            q.pop();
//            cout<<u<<"LLLLLLLLL"<<endl;
            if(ans[u]!="") continue;

            char now[40];

            if(p%qq==0)
            {
                if(w){
                    sprintf(now,"%d clockwise",p/qq);
                }
                else{
                    sprintf(now,"%d counterclockwise",p/qq);
                }
            }else{
                int k = __gcd(p,qq);
               if(w){
                    sprintf(now,"%d/%d clockwise",p/k,qq/k);
                }
                else{
                    sprintf(now,"%d/%d counterclockwise",p/k,qq/k);
                }
            }
            ans[u] = now;
            col[u] = true;

            for (int i = 0; i<n; i++)
            {
                if(col[i]==true) continue;
                if(check(u,i)){
                    q.push(i);
                    col[i] = true;
                    q.push(w^1);
                    int aa = p*v[u].r;
                    int bb = qq*v[i].r;
                    int cc = __gcd(aa,bb);
                    q.push(aa/cc);
                    q.push(bb/cc);
                }
            }

        }

        for (int i = 0; i<n; i++)
        {
            if(ans[i]=="") cout<<"not moving\n";
            else cout<<ans[i] <<"\n";
        }



    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
