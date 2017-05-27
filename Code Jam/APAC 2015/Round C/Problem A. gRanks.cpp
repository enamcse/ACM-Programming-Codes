/**
* H:\Dropbox\Code\Code Jam\APAC 2015\Round C\Problem A. gRanks.cpp
* Created on: 2015-10-18-11.14.25, Sunday
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
#define allr(a) a.rbegin(),a.rend()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("A-large-practice.in","r",stdin)
#define fwrite freopen("outputALargePractice.txt","w",stdout)
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

struct info{
    string name;
    vector<int>point;
    ll total;
    info(){}
    info(string na)
    {
        name = na;
    }
};

vector<info>data;
vector<int>perpos;
map<string,int>mpp;
int cnt = 0;

bool comp(const info &a, const info &b)
{
    if(a.total == b.total) return a.name<b.name;
    return a.total>b.total;
}

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,p,k,ind;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;
    cin>>t;

    while(t--)
    {
        cin>>p;
        cnt = 0;
        mpp.clear();
        perpos.clear();
        data.clear();
        for (int i = 0; i<p; i++)
        {
            cin>>x;
            perpos.pb(x);
        }
        cin>>n;

        for (int i = 0; i<n; i++)
        {
            cin>>k;
            for (int j = 0; j<p; j++)
            {
                cin>>s;
                if(mpp.count(s)==0) {
                    data.pb(info(s));
                    mpp[s] = cnt++;
                }
                ind = mpp[s];
                data[ind].point.pb(perpos[j]*k);
            }
        }
        cin>>m;

        for (int i = 0; i<cnt; i++)
        {
            sort(allr(data[i].point));
            data[i].total = 0;
            k = min((int)data[i].point.size(),m);
            for (int j = 0; j<k; j++)
            {
                data[i].total+=data[i].point[j];
            }
        }
        sort(all(data),comp);
        cout<<"Case #"<<cas++<<":\n";
        m = 1;
        for (int i = 0; i<cnt; i++)
        {
//            cerr<<data[i].total<<">>>>>>>>>"<<endl;
            if(i&&data[i].total<data[i-1].total) m=i+1;
            cout<<m<<": "<<data[i].name<<"\n";
        }

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
