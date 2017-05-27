/**
* H:\Dropbox\Code\HackerRank\World Cup - University Level CodeSprint 2015\Bishop War.cpp
* Created on: 2015-09-11-23.02.17, Friday
* Verdict: Solved
* Author: Enamul Hassan and Khan Mohammad Rumman Mahmud Mahdi Al Masud
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

int n, m;
int s[11], cntbt[1025];


int arr[1025];

int rec(int pos, int d1, int d2)
{
    if(pos==n-1)
    {
        int r1 = (d1>>(n-1));
        int r2 = arr[(d2>>(n-1))];

        r1|=r2;
        r1|=s[pos];
        return cntbt[r1];
    }


    int ret=0,x=d1,y=d2, bx,by;
    for (int i = 0; i<m; i++)
    {
        if(((s[pos]>>i)&1))
        {
            bx = pos+i;
            by = pos+(m-1-i);
            if( (x & (1<<bx)) ) x ^= (1<<bx);
            if( (y & (1<<by)) ) y ^= (1<<by);
        }
    }

    for(int i = 0; i<m; i++)
    {
        bx = pos+i;
        by = pos+(m-1-i);
        if(!((s[pos]>>i)&1) && !( (d1 & (1<<bx)) ) && !( (d2 & (1<<by)) ))
        {
            ret+=rec(pos+1,(x | (1<<bx)), (y | (1<<by)));
        }
    }

    return ret;
}

int main()
{
#ifdef ENAM
    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    cin>>n>>m;
    int lim=(1<<m);
    for (int i = 0; i<lim; i++)
    {
        for (int j = 0; j<m; j++)
        {
            if((1<<j)&i)arr[i]|=(1<<(m-1-j));
            else cntbt[i]++;
        }
    }
    string now;

    for(int i = 0;i<n;i++)
    {
        cin>>now;
        s[i] = 0;
        for (int j = 0; j<m; j++)
        {
            if(now[j]=='*') s[i]|=(1<<j);
        }
    }

    cout<<rec(0,0,0);
//    cout<<" s = "<<cnt;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
/**
4834872
10 10
.*.*.*.*.*
*.*.*.*.*.
.*.*.*.*.*
*.*.*.*.*.
.*.*.*.*.*
*.*.*.*.*.
.*.*.*.*.*
*.*.*.*.*.
.*.*.*.*.*
*.*.*.*.*.
10 10
.........*
....*.....
.......*..
....*.....
...*......
......*...
..*.......
.....*....
.........*
..........
26934990
10 10
..*.......
.........*
....*.....
.......*..
..*.......
.....*.*..
..........
...*.*.*..
..........
..........
21301239
10 10
..........
...*.*....
.....*.*..
..*.*.....
......*.*.
..*.*.....
.....*.*..
.*.*......
....*.*...
..........
65832336
*/
