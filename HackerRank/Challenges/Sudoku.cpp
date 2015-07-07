/**
* H:\Dropbox\Code\HackerRank\Challenges\Sudoku.cpp
* Created on: 2015-07-01-18.19.54, Wednesday
* Verdict: Not Solved
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
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

char grid[9][10], ans[9][10];
int limit=9,up;

int sq[9];
int column[9], row[9];
bool flag;
int quad[9][9];
struct point
{
    int x, y;
};
vector<point>v;

void sudoku_solve(int z)
{
    //your logic here

    if(!flag) return;
    if(z==up)
    {
        flag = false;

        for (int i = 0; i<limit; i++)
            strcpy(ans[i],grid[i]);

        return;
    }

    int a=0, b, c=inf;
    point p;
    for (int i = 0; i<up; i++)
    {
        p = v[i];

        if(grid[p.x][p.y]!='.') continue;
        b=0;

        for (int j = 1; j<=limit; j++)
            if(!(sq[ quad[p.x][p.y] ]&(1<<j)) && !(column[p.y]&(1<<j)) && !(row[p.x]&(1<<j)) ) b++;
        if(b<c)
        {
            c = b;
            a = i;
        }
    }
    if(c==0) return;
    p = v[a];

    for (int j = 1; j<=limit; j++)
    {
        if(!(sq[ quad[p.x][p.y] ]&(1<<j)) && !(column[p.y]&(1<<j)) && !(row[p.x]&(1<<j)) )
        {
            sq[ quad[p.x][p.y] ]|=(1<<j);
            column[p.y]|=(1<<j);
            row[p.x]|=(1<<j);
            grid[p.x][p.y] = j+'0';
            if(flag) sudoku_solve(z+1);
            sq[ quad[p.x][p.y] ]^=(1<<j);
            column[p.y]^=(1<<j);
            row[p.x]^=(1<<j);
            grid[p.x][p.y] = '.';
        }
    }

}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int n=3,kk,m;

    point p;
    for (int i = 0; i<limit; i++)
        for (int j = 0; j<limit; j++)
            quad[i][j] = (i/n)*n+(j/n);

    cin >> kk;
    for(int i=0; i<kk; i++)
    {
        flag = true;
        clr(column,0);
        clr(row,0);
        clr(sq,0);
        for(int j=0; j<9; j++)
        {
            for(int k=0; k<9; k++)
            {
                cin >> grid[j][k];
                if(grid[j][k]!='0')
                {
                    m = grid[j][k] - '0';
                    sq[ quad[j][k] ]|= (1<<m);
                    column[k]|= (1<<m);
                    row[j]|= (1<<m);
                }
                else
                {
                    grid[j][k]='.';
                    p.x = j;
                    p.y = k;
                    v.pb(p);
                }
            }

        }
        up = v.size();
        sudoku_solve(0);
        for(int j=0; j<9; j++)
        {
            for(int k=0; k<9; k++)
            {
                cout<<ans[j][k]<<" \n"[k==8];
            }
        }
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}

/**
#include <bits/stdc++.h>
#define pb push_back
#define inf (1e9)
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

char h[9][10], w[9][10];
int l=9,up;

int sq[9];
int g[9], t[9];
bool s;
int u[9][9];
struct o
{
    int x, y;
};
vector<o>v;

void r(int z)
{
    if(!s) return;
    if(z==up)
    {
        s = false;

        for (int i = 0; i<l; i++)
            strcpy(w[i],h[i]);

        return;
    }

    int a=0, b, c=inf;
    o p;
    for (int i = 0; i<up; i++)
    {
        p = v[i];

        if(h[p.x][p.y]!='.') continue;
        b=0;

        for (int j = 1; j<=l; j++)
            if(!(sq[ u[p.x][p.y] ]&(1<<j)) && !(g[p.y]&(1<<j)) && !(t[p.x]&(1<<j)) ) b++;
        if(b<c)
        {
            c = b;
            a = i;
        }
    }
    if(c==0) return;
    p = v[a];

    for (int j = 1; j<=l; j++)
    {
        if(!(sq[ u[p.x][p.y] ]&(1<<j)) && !(g[p.y]&(1<<j)) && !(t[p.x]&(1<<j)) )
        {
            sq[ u[p.x][p.y] ]|=(1<<j);
            g[p.y]|=(1<<j);
            t[p.x]|=(1<<j);
            h[p.x][p.y] = j+'0';
            if(s) r(z+1);
            sq[ u[p.x][p.y] ]^=(1<<j);
            g[p.y]^=(1<<j);
            t[p.x]^=(1<<j);
            h[p.x][p.y] = '.';
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n=3,kk,m;
    o p;
    for (int i = 0; i<l; i++)
        for (int j = 0; j<l; j++)
            u[i][j] = (i/n)*n+(j/n);

    cin >> kk;
    for(int i=0; i<kk; i++)
    {
        s = true;
        clr(g,0);
        clr(t,0);
        clr(sq,0);
        for(int j=0; j<9; j++)
            for(int k=0; k<9; k++)
            {
                cin >> h[j][k];
                if(h[j][k]!='0')
                {
                    m = h[j][k] - '0';
                    sq[ u[j][k] ]|= (1<<m);
                    g[k]|= (1<<m);
                    t[j]|= (1<<m);
                }
                else
                {
                    h[j][k]='.';
                    p.x = j;
                    p.y = k;
                    v.pb(p);
                }
            }
        up = v.size();
        r(0);
        for(int j=0; j<9; j++)
            for(int k=0; k<9; k++)
                cout<<w[j][k]<<" \n"[k==8];
    }
    return 0;
}
*/
