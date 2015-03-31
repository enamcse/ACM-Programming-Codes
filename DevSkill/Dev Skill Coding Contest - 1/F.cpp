/**
* H:\Dropbox\Code\DevSkill\Dev Skill Coding Contest - 1\F.cpp
* Created on: 2015-02-15-22.15.46, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 2005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input6.txt","r",stdin)
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

char line[sz], a[200], b[200], ans[500];

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1, x, y, now, k, carry, sum;
    bool flag;
	while(gets(line))
    {
        n = strlen(line);
        carry=x=y=m=0;
        flag = true;
        for (int i = 0; i<n; i++)
        {
            if(line[i]==',') {flag = false;continue;}
            if(flag) a[x++] = line[i];
            else b[y++] = line[i];
        }

        a[x] = 0;
        b[y] = 0;

        now = min(x,y);


        for (int i = 0; i<now; i++)
        {
            k = ((a[i]-'0')+(b[i]-'0'))+carry;
            sum = k%10;
            carry = k/10;
            ans[m++] = (sum+'0');
        }
        while(now<x)
        {
            k = (a[now++]-'0')+carry;
            sum = k%10;
            carry = k/10;
            ans[m++] = (sum+'0');
        }
        while(now<y)
        {
            k = (b[now++]-'0')+carry;
            sum = k%10;
            carry = k/10;
            ans[m++] = (sum+'0');
        }

        if(carry) ans[m++] = '1';
        ans[m]=0;
        flag = true;
        now = 0;
        for (int i = 0; i<m; i++)
        {
            if(flag)
            {
                if(ans[i]=='0') continue;
                putchar(ans[i]);
                flag = false;
            }
            else putchar(ans[i]);
        }
        if(flag) puts("0");
        else puts("");
    }



   return 0;
}
