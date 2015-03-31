/**
* H:\Dropbox\Code\lightoj\1226 - One Unit Machine.cpp
* Created on: 2015-02-26-12.57.33, Thursday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1005
#define ll long long
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
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

int arr[sz];
ll ans, fact[(int)1e6+10];

ll factorial(int x)
{
    if(fact[x]||x==0) return fact[x];
    return fact[x] = ((x*factorial(x-1))%mod);
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t,  cas=1;
    ll n, m;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    fact[0]=1;

    cin>>t;

    while(t--)
    {
        ans = 1;
        cin>>n;
        for (int i = 0; i<n; i++)
            cin>>arr[i];
        m = arr[0];

        /**
        *   Lets think about the second sample test. The very basic combination is J1 J1 J2 J2 J3 J3 J3.
        *   If we consider one job, then there would be one combination: J1 J1.
        *   If we add the second job, then very basic combination would be: J1 J1 J2 J2. Here, Last J2
        *   is not movable. So, without it, there are 3 elements. but 2 of them are same. So, 3!/2! would
        *   be multiplied by the previous result.
        *   If we add the third job, then very basic combination would be: J1 J1 J2 J2 J3 J3 J3. Here,
        *   Last J3 is not movable. So, without it, there are 6 elements. but 2 of them are same and 4 of
        *   them are calculated in the previous step. So, 6!/(2!*4!) would be multiplied by the previous
        *   result which is the final result. In this way, other cases could be calculated.
        */
        for (int i = 1; i<n; m+=arr[i++])
            ans = (((((ans*factorial( m+arr[i]-1 ))%mod) *inverse_mod(factorial(arr[i] -1 ),mod))%mod)*inverse_mod(factorial(m),mod))%mod;

        cout<<"Case "<<cas++<<": "<<ans<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
