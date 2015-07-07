/**
* H:\Dropbox\Code\HackerRank\Challenges\BotClean.cpp
* Created on: 2015-06-29-15.11.32, Monday
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
string now;
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
        if(now=="") now="DOWN\n";
    }
    else if(col[x][y] == 'U')
    {
        goup(x+1,y);
        if(now=="") now="UP\n";
    }
    else if(col[x][y] == 'R')
    {
        goup(x,y-1);
        if(now=="") now="RIGHT\n";
    }
    else if(col[x][y] == 'L')
    {
        goup(x,y+1);
        if(now=="") now="LEFT\n";
    }
}

void next_move(int posr, int posc, vector <string> board)
{
    //add logic here
    int n = board.size();
    memset(col,0,sizeof col);
    queue<int>q;
    col[posr][posc]='m';
    if(board[posr][posc]=='d')
    {
        cout<<"CLEAN\n";
        return;
    }
    q.push(posr);
    q.push(posc);
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
            if(board[x][y] == 'd')
            {
                now="";
                goup(x,y);
                cout<<now;
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
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0; i<5; i++)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
