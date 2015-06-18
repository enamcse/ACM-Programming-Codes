/* 
* @Author: Enamul Hassan
* @Date:   2015-04-04 19:18:26
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-04 19:20:43
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\Codeforces\29C.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100005
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}
using namespace std;

int path[sz];

map<int,int>mpp,a1,a2;

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int n,x , y;
    vector< pair<int,int> >v;
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        cin>>x>>y;
        mpp[x]++;
        mpp[y]++;
        if(a1.count(x)==1) a2[x]=y;
        else a1[x]=y;
        if(a1.count(y)==1) a2[y]=x;
        else a1[y]=x;


    }

    bool flag=false;

    for (auto it : mpp )
    {
        if(it.second==1)
        {
            if(!flag) path[0] = it.first;
            else path[n] = it.first;
            if(flag == true) break;
            flag = true;
        }
    }

    for (int i = 1; i<n; i++)
    {
        if(a2.count(path[i-1])==0)
        {
            path[i] = a1[ path[i-1] ];
        }
        if(a1[ path[i-1] ] == path[i-2])
        {
            path[i] = a2[ path[i-1] ];
        }
        else
        {
            path[i] = a1[ path[i-1] ];
        }
    }

    for (int i = 0; i<=n; i++)
        cout<<path[i]<<" \n"[i==n];
	


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












