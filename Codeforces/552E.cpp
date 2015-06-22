/**
* H:\Dropbox\Code\Codeforces\552E.cpp
* Created on: 2015-06-18-22.40.19, Thursday
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
#define fread freopen("NJrG38dw.txt","r",stdin)
#define fwrite freopen("NJrG38dw.txt","w",stdout)
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

string s;

ll temp,n;
vector<int>v;

ll calc(int a, int b)
{

    ll sum = 0;
    temp = 0;
    char ch = s[b];
    s[b] = 0;
    for (int i = a+1; i<b; i+=2)
    {
        if(s[i+1]!='*')
        {
            temp*=(s[i]-'0');
            if(temp)sum+=temp;
            else sum+=(s[i]-'0');
            temp=0;
        }
        else
        {
            if(temp) temp*=(s[i]-'0');
            else temp = s[i]-'0';
        }
    }
    s[b] = ch;
//    cout<<a<<" "<<b<<": "<<sum<<endl;
    while(a>0 && s[a] =='*')
    {
        a--;
        sum*=(s[a]-'0');
        a--;
    }
    while(b<n && s[b] =='*')
    {
        b++;
        sum*=(s[b]-'0');
        b++;
    }
    temp=0;
    for (int i = b+1; i<n; i+=2)
    {
        if(s[i+1]!='*')
        {
            temp*=(s[i]-'0');
            if(temp)sum+=temp;
            else sum+=(s[i]-'0');
            temp=0;
        }
        else
        {
            if(temp) temp*=(s[i]-'0');
            else temp = s[i]-'0';
        }
    }
    temp=0;
    for (int i = 0; i<a; i+=2)
    {
        if(s[i+1]!='*')
        {
            temp*=(s[i]-'0');
            if(temp)sum+=temp;
            else sum+=(s[i]-'0');
            temp=0;
        }
        else
        {
            if(temp) temp*=(s[i]-'0');
            else temp = s[i]-'0';
        }
    }

    return sum;
}

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

    cin>>s;
    n = s.size();

    for (int i = 0; i<n; i++)
        if(s[i]=='*') v.pb(i);

    ll sum = calc(-1,n);
    temp=0;


for (int i = 0; i<v.size(); i++){
        temp = calc(-1,v[i]);
        sum = max(sum, temp);
        temp = calc(v[i],n);
        sum = max(sum, temp);
    }

    for (int i = 0; i<v.size(); i++)
        for (int j = i+1; j<v.size(); j++)
        {
            sum = max(sum, calc(-1,v[i]));
            sum = max(sum, calc(v[i],v[j]));
            sum = max(sum, calc(v[j],n));
        }


    cout<<sum;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
