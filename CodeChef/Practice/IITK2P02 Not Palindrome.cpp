/**
* H:\Dropbox\Code\CodeChef\Practice\IITK2P02 Not Palindrome.cpp
* Created on: 2015-03-04-21.57.22, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
* Problem link: http://www.codechef.com/problems/IITK2P02
* Concept: Lets think what would be the orientation of the word which
           would contain palindrome substring. If we want to make a word
           of length one, we can generate m words with the m letters of
           alphabet.
           If we want to make a word of length 2, first letter have the m
           possible way, but the second can be any thing other than the
           first letter. So, there exists m*(m-1) possible word which
           satisfy the condition.
           If we want to make a word of length 3, first letter have the m
           possible way, second letter can be any thing other than the
           first letter and the third one can be any thing other than the
           first two. So, there exists m*(m-1)*(m-2) possible word which
           satisfy the condition.
           What do you think? What would be the solution? m!,right? But no.
           If we want to make a word of length 4, the fourth letter can be
           anything other than the immediate two letters before it. Because,
           these two letters ensuring that this would not make any palindromic
           substring. So, the solution would be m*(m-1)*(m-2)^(n-2).
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

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    ll t, n, m,ans, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=(m*(m-1))%mod;
        if(n<=2)
        {
            if(n==1) cout<<m<<"\n";
            else cout<< ans <<"\n";
            continue;
        }
        ans*=bigmod(m-2,n-2,mod);
        ans%=mod;
        cout<<ans<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
