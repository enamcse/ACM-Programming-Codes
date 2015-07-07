/**
* H:\Dropbox\Code\Codeforces\96B.cpp
* Created on: 2015-07-03-16.07.15, Friday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))


using namespace std;

string s, temp, res="";
int n,dp[12][8][8][2];

int rec(int pos, int four, int seven, int flag)
{
    if(pos==n) return 1;
    int &ret = dp[pos][four][seven][flag];
    if(ret!=-1) return ret;
    ret = 0;
    int st = flag?s[pos]-'0':4;

    if(st<=4 && four>0) ret|=rec(pos+1, four-1,seven,flag&&(s[pos]=='4'));
    if(st<=7 && seven>0) ret|=rec(pos+1, four,seven-1,flag&&(s[pos]=='7'));
    return ret;
}

void print(int pos, int four, int seven, int flag)
{
    if(pos==n) return;
    int ret = rec(pos,four,seven,flag);
    int st = flag?s[pos]-'0':4;

    if(st<=4 && four>0)
    {
        int tem=rec(pos+1, four-1,seven,flag&&(s[pos]=='4'));
        if(tem)
        {
            res+='4';
            print(pos+1,four-1,seven,flag&&(s[pos]=='4'));
            return;
        }
    }

    res+='7';
    print(pos+1,four,seven-1,flag&&(s[pos]=='7'));

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

    if(n%2)
    {
        n++;
        s="";
        n/=2;
        for (int i = 0; i<n; i++)
            s+='4';
        for (int i = 0; i<n; i++)
            s+='7';
        cout<<s;
        return 0;
    }

    temp = s;
    int m = n/2;
    for (int i = 0; i<m; i++)
        temp[i]='7';
    for (int i = m; i<n; i++)
        temp[i]='4';

    if(s>temp)
    {
        n+=2;
        s="";
        n/=2;
        for (int i = 0; i<n; i++)
            s+='4';
        for (int i = 0; i<n; i++)
            s+='7';
        cout<<s;
        return 0;
    }

    clr(dp,-1);

    rec(0,n/2,n/2,1);
    print(0,n/2,n/2,1);

    cout<<res;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
