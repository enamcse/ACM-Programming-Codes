/**
* H:\Dropbox\Code\CodeChef\Practice\IITK2P10 Chef and Pattern.cpp
* Created on: 2015-03-04-21.38.54, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
* Problem Link: http://www.codechef.com/problems/IITK2P10
* Comment: The series would be:
           1 K K K^2 K^4 K^8 K^16 K^32...
           1 K K^2^0 K^2^1 K^2^2 K^2^3 K^2^4 K^2^5...
           For n=1, result is 1 and for n = 2, the result is K.
           For any other positive value of n, the result would be:
                            K^2^(n-3)
           We know, if we have to modulo a number and its power is
           as huge as we have to modulo the power, then the power
           should modulo by the phi of the mod number. Here, the
           mod number is a prime and phi of any prime number is equal
           to one less than the prime number. So,
                    (K^2^(n-3))%mod = K^((2^(n-3))%phi(mod))%mod
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}

using namespace std;

ll t, n, k, ans;

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

    cin>>t;

    while(t--)
    {
        cin>>k>>n;
        if(n<=2)
        {
            if(n==1) cout<<1<<"\n";
            else cout<<k<<"\n";
            continue;
        }
        ans=bigmod(k,bigmod(2,n-3,mod-1),mod);
        cout<<ans<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
