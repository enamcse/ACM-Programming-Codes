#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;


int main()
{
//    long long int n, i, row, col, p, q, t, in, a, sq, beg, end, mid=-1;
    ll n, t, i, d,ss, m;
//    double ns, rt, dif;
    double sq;
    scanf("%lld", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld", &n);
        sq = (sqrt((double)(1+((n-1)<<2)))-1)/2;
//        printf(":%lf:", sq);
        ss = sq;
//        cou<<ss<<" "<<sq<<endl;
        if(ss==sq) printf("Case %lld: %lld %lld\n",i,ss+1,ss+1);
        else
        {
            ss++;
            m = 1 + ss*(ss+1);
            d = m - n;
//            cout<<"n = "<<ss<<" m = "<<m<<" d = "<<d<<endl;
            if(d<ss+1)
            {
                if(ss%2) printf("Case %lld: %lld %lld\n",i,ss-d+1,ss+1);
                else printf("Case %lld: %lld %lld\n",i,ss+1,ss-d+1);
            }
            else
            {
                if(ss%2) printf("Case %lld: %lld %lld\n",i,d-ss,ss);
                else printf("Case %lld: %lld %lld\n",i,ss,d-ss);
            }
        }
//        rt = sqrt(in);
//        n = rt;
//
//        dif = rt - n;
//        if(dif>0) n++;
//
//        row = col = n;
//        sq = n * n;
//        a = sq - n + 1;
//        if(n%2)
//        {
//            if(a>in)
//            {
//                beg=(n-1)*(n-1)+1;
//                end=a;
//
//                while(beg!=end)
//                {
//                    mid = (beg+end)/2;
//                    if(mid>in)
//                    {
//                        end = mid-1;
//                        row -= (end-mid+1);
//                    }
//                    else
//                    {
//                        a++, col--;
//                    }
//                }
//            }
//            else
//            {
//                beg=a;
//                end = sq;
//                mid = (beg+end)/2;
//            }
//
//
//        }
//        else
//        {
//            while(a!=in)
//            {
//                if(a>in)
//                {
//                    a--, col--;
//                }
//                else
//                {
//                    a++, row--;
//                }
//            }
//        }
//        printf("Case %lld: %lld %lld\n",i,col,row);
//        cout<<"Case "<<i<<": "<<col<<" "<<row<<endl;
    }


    return 0;

}
