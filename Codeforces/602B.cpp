/**
* H:\Dropbox\Code\Codeforces\602B.cpp
* Created on: 2015-11-24-22.48.47, Tuesday
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


using namespace std;

multiset<int>x,y;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t=1, n, m, cas=1,a,b=0, ans=2,flag=0,  now=0,c1,c2;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>t;
    c1=t;
    x.insert(0);
    for (int i = 1; i<n; i++)
    {
        cin>>t;

        if(flag==0)
        {
            if(c1!=t)
            {
                flag = 1;
                c2=t;
            }
            if(c1==t) x.insert(i);
            else y.insert(i);
            ans = max(ans, (int)(x.size()+y.size()));
            continue;
        }
        else if(abs(c1-t)>=2 || abs(c2-t)>=2)
        {
            // handle code
            if(abs(c1-t)>=2)
            {
                c1 = t;
                if(!x.empty())
                {
                    while(!y.empty()&& (*y.begin()) < (*x.rbegin()) ) y.erase(y.begin());
                    x.clear();
                }
            }
            else
            {
                c2 = t;
                if(!y.empty())
                {
                    while(!x.empty()&& (*x.begin())<(*y.rbegin()) ) x.erase(x.begin());
                    y.clear();
                }
            }


        }
        if(c1==t) x.insert(i);
        else if(c2==t)y.insert(i);
        else assert(0);

        ans = max(ans, (int)(x.size()+y.size()));
    }
    cout<<ans;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
