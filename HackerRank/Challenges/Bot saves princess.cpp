/**
* H:\Dropbox\Code\HackerRank\Challenges\Bot saves princess.cpp
* Created on: 2015-06-29-14.26.25, Monday
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
int cc[] = {0,0,1,-1};
int rr[] = {1,-1,0,0};

char col[105][105];
int k;
void goup(int x, int y)
{
//    cout<<x<<" OK "<<y<<endl;
//
//    for (int i = 0; i<k; i++)
//    {
//        for (int j = 0; j<k; j++)
//            cout<<col[i][j];
//        cout<<endl;
//    }
//    return;

    if(col[x][y]=='m') return;
    if(col[x][y] == 'D')
    {
        goup(x-1,y);
        cout<<"DOWN\n";
    }
    else if(col[x][y] == 'U')
    {
        goup(x+1,y);
        cout<<"UP\n";
    }
    else if(col[x][y] == 'R')
    {
        goup(x,y-1);
        cout<<"RIGHT\n";
    }
    else if(col[x][y] == 'L')
    {
        goup(x,y+1);
        cout<<"LEFT\n";
    }
}

void displayPathtoPrincess(int n, vector <string> grid)
{
    //your logic here
    k = n;
    memset(col,0,sizeof col);
    queue<int>q;
    for(int i = 0,j; i<n; i++)
    {
        for( j = 0; j<n; j++)
            if(grid[i][j]=='m')
            {
                q.push(i);
                q.push(j);
                col[i][j] = 'm';
                break;
            }
        if(j!=n) break;
    }
    int u, v,x ,y;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++)
        {
            x = u+cc[i];
            y = v+rr[i];
            if(x<0||y<0||x>=n||y>=n||col[x][y]) continue;
            col[x][y] = (i>1?(i%2?'U':'D'):(i%2?'L':'R'));
            if(grid[x][y] == 'p')
            {
                goup(x,y);
                return;
            }
            q.push(x);
            q.push(y);

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

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++)
    {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}

/**
3
---
-m-
p--
*/
