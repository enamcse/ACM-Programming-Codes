/**
* E:\PE\Problem 39 Integer right triangles.cpp
* Created on: 2015-06-16-01.03.40, Tuesday
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

vector<tuple<int,int,int>>v;
map< int,int >mpp;
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

    for (int i = 1; i<=1000; i++)
    {
        for (int j = i; j<=1000; j++)
        {
            double a = i, b = j, c;
            c = sqrt(a*a+b*b);
            if(floor(c)==ceil(c))
            {
                v.pb(make_tuple(i,j,floor(c)));
                mpp[i+j+floor(c)]++;
            }
        }
    }
    m=0,t=0;
    for (int i = 1; i<1000; i++)
        if(mpp[i]>m) m=mpp[i],t=i;

    cout<<t;

//    for (int i = 0; i<v.size(); i++)
//        cout<<(get<0>(v[i]))<<" "<<(get<1>(v[i]))<<" "<<(get<2>(v[i]))<<endl;


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
