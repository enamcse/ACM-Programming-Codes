/**
* H:\Dropbox\Code\Codeforces\2B.cpp
* Created on: 2015-05-18-02.30.08, Monday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: The powers of two and the powers of five together make trailing zeros.
*          So, we would keep the powers of two and the powers of five only. Now, we would
*          consider only the usual cases. Tricky and Exceptional cases would be handled later.
*          The minimal trailing zero would be bottle necked by either the powers of two of the
*          powers of five. So, the minimal path would be either the minimal powers of two or
*          the minimal powers of five. So, we would apply dynamic programming for the path of
*          minimal powers of two and the path of minimal powers of five.
*          Then we would calculate which one of these two paths is optimal.
*          Now, come to the exceptional case. What if we get a zero in any place of the board?
*          The best answer would be one.
*          Is there any tricky case which is not handled till now? Yes, After getting a zero,
*          there could exist more optimal path which have contain no trailing zero. So, getting
*          a zero would take effect on the optimal result when it would be greater than zero.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 1005
#define pb(a) push_back(a)
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int f2[sz][sz],f5[sz][sz];
int dp1[sz][sz], dp2[sz][sz];
char path2[sz][sz];
char path5[sz][sz];
int n,m;
bool tew;
int rec(int x, int y)
{
    if(x==n-1 && y == n-1) return tew?f2[x][y]: f5[x][y];
    int &ret = (tew?dp1[x][y]:dp2[x][y]), temp;

    if(ret != -1) return ret;
    ret = inf;
    if(x != n-1)
    {
        temp=rec(x+1,y);
        temp+= (tew?f2[x][y]: f5[x][y]);

        if(temp < ret )
        {
            ret = temp;
            if(tew)path2[x][y] = 'D';
            else path5[x][y] = 'D';
        }
    }
    if(y != n-1)
    {
        temp=rec(x,y+1);
        temp+= (tew?f2[x][y]: f5[x][y]);

        if(temp< ret )
        {
            ret = temp;
            if(tew)path2[x][y] = 'R';
            else path5[x][y] = 'R';
        }
    }
    return ret;
}

pair<int,int> check(int x,int y, bool flag)
{
    if(x==n-1 && y==n-1) return make_pair(f2[x][y], f5[x][y]);
    pair<int,int> ret;
    if((flag&&path2[x][y]=='D') || (!flag&&path5[x][y]=='D') )ret = check(x+1,y,flag);
    else ret = check(x,y+1, flag);
    ret.first+= f2[x][y];
    ret.second+= f5[x][y];
    return ret;
}


void print(int x, int y)
{
    cout<<1<<"\n";
    for (int i = 0; i<x; i++) cout<<'D';
    for (int i = 0; i<y; i++) cout<<'R';
    for (int i = x+1; i<n; i++) cout<<'D';
    for (int i = y+1; i<n; i++) cout<<'R';
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
    clr(dp1,-1);
    clr(dp2,-1);
    int two, five,p1,p2;
    bool zero=false;
    cin>>n;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            cin>>m;
            if(!m) {p1=i, p2 = j;zero = true;}
            two = five = 0;
            while(m%2==0&&m)
            {
                two++;
                m>>=1;
            }
            while(m%5==0&&m)
            {
                five++;
                m/=5;
            }
            f2[i][j] = two;
            f5[i][j] = five;
        }

    rec(0,0);
    tew = true;
    rec(0,0);
    pair<int,int> x1 = check(0,0,1);
    pair<int,int> x2 = check(0,0,0);
    bool flag = (min(x1.first, x1.second) <= min(x2.first, x2.second));
    int ans = (flag?min(x1.first, x1.second) : min(x2.first, x2.second) );
    if(zero&&ans>1)
    {
        print(p1,p2);
        return 0;
    }
    cout<<ans<<"\n";

    m = ((n-1)<<1);
    two = 0, five = 0;
    for (int i = 0; i<m; i++)
    {
        cout<<(flag?path2[two][five]:path5[two][five]);
        if(flag&&path2[two][five]=='D') two++;
        else if(flag) five++;
        else if(path5[two][five]=='D') two++;
        else five++;
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
