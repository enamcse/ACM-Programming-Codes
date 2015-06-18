/* 
* @Author: Enamul Hassan
* @Date:   2015-05-02 04:39:23
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-02 05:15:53
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\401 - Palindromes.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
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

map<char,char>mirror;

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;

    mirror['A']='A';
    mirror['E']='3';
    mirror['H']='H';
    mirror['I']='I';
    mirror['J']='L';
    mirror['L']='J';
    mirror['M']='M';
    mirror['O']='O';
    mirror['S']='2';
    mirror['T']='T';
    mirror['U']='U';
    mirror['V']='V';
    mirror['W']='W';
    mirror['X']='X';
    mirror['Y']='Y';
    mirror['Z']='5';
    mirror['1']='1';
    mirror['2']='S';
    mirror['3']='E';
    mirror['5']='Z';
    mirror['8']='8';


	while(cin>>s)
	{
		m=3;
		n = s.size();
		for (int i = 0; i < n; ++i)
			if(s[i]!=mirror[ s[n-i-1] ])
			{
				m^=2;
				break;
			}

		for (int i = 0; i < n/2; ++i)
			if(s[i]!=s[n-i-1])
			{
				m^=1;
				break;
			}

		if(m==3) cout<<s<<" -- is a mirrored palindrome.\n\n";
		else if(m==2) cout<<s<<" -- is a mirrored string.\n\n";
		else if(m==1) cout<<s<<" -- is a regular palindrome.\n\n";
		else cout<<s<<" -- is not a palindrome.\n\n";
	}

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












