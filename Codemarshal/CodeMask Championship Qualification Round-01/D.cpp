/**
* E:\Dropbox\Code\Codemarshal\CodeMask Championship Qualification Round-01\D.cpp
* Created on: 2016-02-04-20.16.34, Thursday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
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
#define cspf printf("Case %d: ", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

char line[100];

int a[sz],b[sz], c[sz],aa,bb,cc;


int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
    int t, n, cas=1,x,y,z;
	int flag;
	scanf("%d", &t);
	while(t--)
    {
        scanf("%d", &n);
        aa=bb=cc=0;
        for (int i = 0; i<n; i++)
        {
            scanf(" %d %s", &x,line);
            if(!strcmp(line,"Good"))
            {
                //printf(">>>>>>%d\n",x);
                a[aa++]=x;
            }
            else if(!strcmp(line,"Bad"))
            {
                b[bb++]=x;
            }
            else if(!strcmp(line,"Ugly"))
            {
                c[cc++]=x;
            }
        }
        sort(a,a+aa);
        sort(b,b+bb);
        sort(c,c+cc);
        flag = 1;
        y=z=0;
        if(aa!=bb||aa!=cc) flag = 0;
        if(flag){
            for(int i = 0;i<aa;i++ )
            {
                while(y<bb && a[i]>b[y]) y++;
                while(z<cc && a[i]>c[z]) z++;
                //cout<<i<<" : "<<a[i]<<" "<<y<<" "<<b[y]<<" > "<<z<<" "<<c[z]<<endl;
                if(y==bb||z==cc)
                {
                    flag = 0;
                    break;
                }
            }
        }
        cspf
        if(flag)printf("GBU\n");
        else printf("Undefined\n");
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
