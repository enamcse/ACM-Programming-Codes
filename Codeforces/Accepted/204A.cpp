/*
* @Author: Enamul Hassan
* @Date:   2015-04-11 08:56:50
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-11 09:08:03
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\Codeforces\204A.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;


ll niche[22], pow10[22];
ll calc(string s)
{
    int n = s.size();
    if(n==1) return s[0]-'0';
    ll ret = niche[n-1];
    ret+= pow10[n-2]*(s[0]-'0'-1);
    ll x=0;
    if(n>2)
    {
        string now = s.substr(1,n-2);
        sscanf(now.c_str(),"%lld", &x);
    }
    x++;
    ret+=x;
    if(s[0]>s[n-1]) ret--;
    return ret;
}

int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();


	string a, b;
    cin>>a>>b;
    niche[1] = niche[2] = 9;
    pow10[0]=1;
    pow10[1]=10;
    for (int i = 3; i<=19; i++)
        niche[i]=niche[i-1]*10;

    for (int i = 2; i<=19; i++)
    {
        niche[i]+=niche[i-1];
        pow10[i]=pow10[i-1]*10LL;
    }

    int n = a.size();
    for(int i = n-1; i>=0; i--)
    {
        if(a[i]=='0') a[i] = '9';
        else
        {
            a[i]--;
            break;
        }
    }

    if(a[0]=='0'&&n>1)
        a = a.substr(1);
    ll ans = calc(b);
    cout<<(ans-calc(a))<<"\n";


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












