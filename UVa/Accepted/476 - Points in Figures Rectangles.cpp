#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
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

struct rectangle{
    double x[2],y[2];
};

rectangle rect[12];
int  n, m, cas=1;

bool check(double a, double b, int i)
{
    if(a<=rect[i].x[0]||a>=rect[i].x[1]) return false;
    if(b<=rect[i].y[0]||b>=rect[i].y[1]) return false;
    return true;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM

    _
	string s;
	double a,b;
	while(cin>>s)
	{
	    if(s=="*") break;
	    for (int i = 0; i<4; i++)
        {
            !(i&1)?cin>>rect[n].x[i/2]:cin>>rect[n].y[i/2];
        }
        sort(rect[n].x,rect[n].x+2);
        sort(rect[n].y,rect[n].y+2);
        n++;
	}


	while(cin>>a>>b)
	{
	    if(a==9999.9&&b==9999.9) break;
	    int i=0;
	    bool flag=true;
	    for (; i<n; i++)
            if(check(a,b,i)) flag = false, cout<<"Point "<<cas<<" is contained in figure "<<i+1<<"\n";
        if(flag) cout<<"Point "<<cas<<" is not contained in any figure\n";
        cas++;
	}

   return 0;
}
