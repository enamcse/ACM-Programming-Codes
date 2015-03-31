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
#include<set>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

bool div (int len, string &line, int mod)
{
    int x=0;
    for (int i = 0; i<len; i++)
    {
        x*=10;
        x+=(line[i]-'0');
        x%=mod;
    }
    if(x) return false;
    else return true;
}

int main()
{
    string line, s;
    int year, len;
    bool flag, l, sp=false;
    while(cin>>line)
    {
        if(sp) cout<<endl;
        sp = true;
        flag = l = false;
        len = line.size();
        s = line.substr(len-4,4);
        year = atoi(s.c_str());
//        cout<<year;
        if ((year % 4 == 0) && ((year % 100 != 0) || year % 400 == 0))
        {
            flag = true;
            l = true;
            cout<<"This is leap year."<<endl;
        }
        if (div(len, line,15))
        {
            flag = true;
            cout<<"This is huluculu festival year."<<endl;
        }
        if (l && div(len,line, 55))
        {
            flag = true;
            cout<<"This is bulukulu festival year."<<endl;
        }
        if (!flag) cout<<"This is an ordinary year."<<endl;
    }
    return 0;
}
