/**
* H:\Dropbox\Code\PE\Problem 26.cpp
* Created on: 2015-06-11-17.48.46, Thursday
* Verdict: Solved
* Author: Enamul Hassan
* Comment: By doing this problem, I conclude that, The highest reciprocal cycle's length
*          depends upon the prime numbers which are less than or equal to that number.
*          Only prime numbers could generate these types of large cycles. But all prime
*          numbers could not do it. So, The best way is to check some immediate lower
*          prime numbers. How could we determine that it is the largest? Well, the prime
*          which is generating the largest cycle would always generate a cycle whose length
*          is one less than that number.
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

string s[1000];

int main()
{
#ifdef ENAM
//    	fread;
    fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    for (int i = 2; i<1000; i++)
    {
        s[i] = "";
        n = 1;
        m=10000;
        while(m--)
        {
            n*=10;
            s[i]+=(char)(n/i+'0');
            n%=i;
        }
//        cout<<i<<": "<<s[i]<<endl;
    }
//    return 0;
    t = 1;
    bool flag;
    int ind = 3,j,i,k,l;
    for (i = 2; i<1000; i++)
    {
        flag = true;
        int best=0;
        for (j = 0; j<10000; j++)
        {
            for (k = 1; k<2000-j; k++)
            {
                string p = s[i].substr(j,k), q;
                if(j+k+k>=2000) continue;
                for (l = j+k; l<2000-k; l+=k)
                {
                    q = s[i].substr(l,k);
//                    cout<<i<<", "<<j<<", "<<k<<", "<<l<<", "<<"p = "<<p<<", q = "<<q<<endl;
                    if(p!=q) break;
                }
                if(l>=2000-k)
                {
                    if(k>t)
                    {
                        t = k;
                        ind = i;
                        flag = false;

                    }
                    best = max(best,k);

                    break;
                }
            }
            if(!flag) break;
        }
        cout<<i<<" == "<<best<<endl;
//        cout<<i<<": "<<t<<">> "<<ind<<endl;
    }

//    cout<<t<<">>>>>>>>> "<<ind<<endl;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
