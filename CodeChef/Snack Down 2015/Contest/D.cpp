/**
* E:\MyJudge\icpc2015-practice\D.cpp
* Created on: 2015-06-22-01.00.17, Monday
* Verdict: Solved
* Author: Enamul Hassan
* Special Thanks to: Nafis Sadique (World Finalist, ACM ICPC 2015 from JU)
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

struct sphere{
    int x, y, z, r;
    double volume, minz, maxz;
    sphere(){}
    sphere(int x1, int y1, int z1, int r1)
    {
        x = x1;
        y = y1;
        z = z1;
        r = r1;
        volume = ((double)PI*r*r*r*4.0)/3.0;
        minz = z-r;
        maxz = z+r;
    }
};

vector<sphere> v;
vector<double>ans;
double nowpointer;
int n;
double vol = 1e15;

double getcap(double  r, double h)
{
    if(h>r)
    {
        h = r+r-h;
        return ((PI*r*r*r*4.0)/3.0) - getcap(r,h);
    }
    return (PI * h * h * (3.0*r - h))/3.0;
}

bool getcondition(double mid)
{
    double nowvol = 1e10 *(mid - nowpointer);

    for (int i = 0; i<n; i++)
    {
        /** the sphere is fully on the right of the segment */
        if(v[i].minz > mid) continue;
        /** the sphere is fully on the left of the segment */
        if(v[i].maxz < nowpointer) continue;

        /** the sphere is fully inside the segment */
        if(v[i].minz >=nowpointer && mid >= v[i].maxz) nowvol -= v[i].volume;
        /** the sphere has extended part in both side of the segment */
        else if( v[i].minz <=nowpointer && mid <= v[i].maxz)
            nowvol -= ( v[i].volume-getcap(v[i].r,nowpointer-v[i].minz) - getcap(v[i].r, v[i].maxz - mid) );
        /** the sphere has extended part on left of the segment */
        else if(mid >= v[i].maxz)
            nowvol -= abs(getcap(v[i].r, v[i].maxz - nowpointer ) );
        /** the sphere has extended par on the right if the segment */
        else if(v[i].minz >=nowpointer)
            nowvol-= getcap(v[i].r, mid - v[i].minz);
    }

    return nowvol<vol;
}


void get_next()
{
    double l = nowpointer, r = 1e5, mid;
    for (int i = 0; i<40; i++)
    {
        mid = (l+r)/2.0;

        if(getcondition(mid)) l = mid;
        else r = mid;

    }
    mid = (l+r)/2.0;
    ans.pb((mid-nowpointer)/1000.0);
    nowpointer = mid;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int s,x ,y , z, r;

    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>s;

    for (int i = 0; i<n; i++)
    {
        cin>>r>>x>>y>>z;
        v.pb(sphere(x,y,z,r));
        vol-=v[i].volume;
    }
    vol/=s;
    for (int i = 0; i<s; i++) get_next();

    for (int i = 0; i<s; i++)
        cout<<setprecision(8)<<fixed<<ans[i]<<"\n";


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
