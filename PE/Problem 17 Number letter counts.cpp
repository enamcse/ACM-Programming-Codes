//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 55
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
	fwrite;
#endif // ENAM
    int t, n, m=0, cas=1, cnt=0,mm=0,k;

    while(++mm<1000)
    {
        k = cnt;
        n = mm;

        m = n%10;   //oneth position
        t=(n%100)/10;   //tenth position
        //processing of last two digits
        if(t==0)
        {
            if(m==1||m==2||m==6) cnt+=3;
            else if(m==4||m==5||m==9) cnt+=4;
            else if(m==3||m==7||m==8) cnt+=5;
            else if(n/100) cnt-=3;  //when the word and is unnecessary, which is added later
        }
        else if(t==1)
        {
            if(m==1||m==2) cnt+=6;
            else if(m==5||m==6) cnt+=7;
            else if(m==3||m==4||m==9||m==8) cnt+=8;
            else if(m==7) cnt+=9;
            else if(m==0) cnt+=3;
        }
        else
        {
            if(t==2||t==3||t==8||t==9) cnt+=6;
            else if(t==5||t==4 ||t==6) cnt+=5;
            else if(t==7) cnt+=7;

            if(m==1||m==2||m==6) cnt+=3;
            else if(m==4||m==5||m==9) cnt+=4;
            else if(m==3||m==7||m==8) cnt+=5;

        }

        if(n/100) cnt+=3;   //for the word and
        else continue;

        m = n/100;
        /// for the digit of hundredth position
        if(m==1||m==2||m==6) cnt+=3;
        else if(m==4||m==5||m==9) cnt+=4;
        else if(m==3||m==7||m==8) cnt+=5;

        cnt+=7; // for the word hundred
    }
    cnt+=11;    //for one thousand
    cout<<"1000: "<<11<<", cum = "<<cnt<<endl;
    return 0;
}
