#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair< ll, ll > pall;


#define PI (2.0*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 100050
#define twoL(X) (((ll)(1))<<(X))

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

string infix_to_postfix(string &str , int order[] )
{
    stack<char>S;
    string res="";

    for(int i=0;i<SZ(str);i++)
    {
        if(isalpha(str[i])) res=res+str[i];///operand
        else { ///operator
            if(str[i]=='(') S.push(str[i]);
            else if(S.empty()) S.push( str[i] );
            else if(str[i]==')')
            {
                while(S.top()!='(') {
                    res=res+S.top();
                    S.pop();
                }
                S.pop(); /// ( is removed
                /// ) is not inserted into stack
            }
            else {
                while( !S.empty() &&  order[S.top()] >= order[ str[i] ] ) { ///pop untill the top of the stack has a lower precedence
                    res=res+S.top();
                    S.pop();
                }
                S.push(str[i]);
            }
        }
    }
    while(!S.empty()) {res=res+S.top();S.pop();}
    return res;
}

string purify(string inp)
{
    int cnt;
    string tmp;
    for(int i=0;i<SZ(inp);i++)
    {
        if(inp[i]=='!')
        {
            int j=i;cnt=0;
            for( ; j<SZ(inp);j++) {
                if(inp[j]=='!') cnt++;
                else break;
            }
            if(cnt%2) tmp.pb('!');

            i=j-1;
        }
        else tmp.pb(inp[i]);
    }
    return tmp;
}
int check_val(string &inp , int val[])
{
    stack<int>S;
    int t1,t2;
    for(int i=0;i<SZ(inp);i++)
    {
        if( isalpha( inp[i] ) ) S.push( val[inp[i]] );
        else {

            if(inp[i]=='!') {
                t1=S.top();S.pop();
                S.push(!t1);
            }
            else if(inp[i]=='&') {
                t2=S.top();S.pop();
                t1=S.top();S.pop();
                S.push(t1&t2);
            }
            else {
                t2=S.top();S.pop();
                t1=S.top();S.pop();
                S.push(t1|t2);
            }
        }
    }
    return S.top();
}
void init(int order[])
{
    mem(order,0);
    order['|']=1;
    order['&']=2;
    order['!']=3;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int order[400] , val[400];
    init(order);

    vector<char>v;

    string tmp1,tmp2,str1,str2;
    char arr[500];
    int cas,loop=0,ok;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s",arr);tmp1=arr;tmp1=purify(tmp1);
        str1=infix_to_postfix(tmp1,order);

        scanf("%s",arr);tmp2=arr;tmp2=purify(tmp2);
        str2=infix_to_postfix(tmp2,order);

//        deb("-->",str1,"-->",str2);
        v.clear();
        for(int i=0;i<SZ(str1);i++) if(isalpha(str1[i])) v.pb(str1[i]);
        for(int i=0;i<SZ(str2);i++) if(isalpha(str2[i])) v.pb(str2[i]);
        sort(all(v));v.resize( unique(all(v)) - v.begin() );

        ok=1;
        for(int mask=0;mask<(1<<SZ(v));mask++)
        {
            for(int p=0;p<SZ(v);p++)
                if(mask&(1<<p)) val[ v[p] ]=1;else val[ v[p] ]=0;

            if(check_val(str1,val)!=check_val(str2,val)) {ok=0;break;}
        }
        if(ok) printf("Case %d: Equivalent\n",++loop);
        else printf("Case %d: Not Equivalent\n",++loop);

    }

    return 0;
}
