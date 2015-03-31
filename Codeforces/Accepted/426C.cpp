//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 255
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

vector<int>v,w;

int arr[sz];


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1,k, cnt, ind=0, sum,a,b,mx=-inf;

    scanf("%d %d", &n, &k);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        mx = max(mx,arr[i]);
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = 1+i; j<=n; j++)
        {
            v.clear();
            w.clear();
            sum = 0;
            for (int z = 0; z<i; z++)
            {
                w.pb(arr[z]);
            }

            for (int z = i; z<j; z++)
            {
                sum+=arr[z];
                v.pb(arr[z]);
            }
            if(v.size()==0) continue;
            mx = max(mx,sum);
            ind = v.size();
            for (int z = j; z<n; z++)
            {
                w.pb(arr[z]);
            }
            if(w.size()>0)
            {
                sort(v.begin(),v.end());
                sort(w.begin(),w.end());
                a = w.size()-1;
                for (int x = 0; x<k&&a>=0; x++)
                {
                    v.pb(w[a--]);
                    sort(v.begin(),v.end());
                    sum = 0;
                    for (int lll = v.size()-1; lll>x; lll--)
                        sum+=v[lll];
                    mx = max(mx,sum);
                }
            }
        }
    }

    printf("%d\n", mx);




    return 0;
}
