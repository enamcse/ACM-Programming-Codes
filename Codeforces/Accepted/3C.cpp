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

char board[3][5], boarding[9];

int check()
{
    int n = 0, m = 0;
    for (int i = 0; i<3; i++)
    {
        //rows
        if(boarding[i*3]=='X'&&boarding[i*3+1]=='X'&&boarding[i*3+2]=='X') n++;
        if(boarding[i*3]=='0'&&boarding[i*3+1]=='0'&&boarding[i*3+2]=='0') m++;
        //col
        if(boarding[i]=='X'&&boarding[3+i]=='X'&&boarding[6+i]=='X') n++;
        if(boarding[i]=='0'&&boarding[3+i]=='0'&&boarding[6+i]=='0') m++;
    }

    if(boarding[0]=='X'&&boarding[4]=='X'&&boarding[8]=='X') n++;
    if(boarding[0]=='0'&&boarding[4]=='0'&&boarding[8]=='0') m++;

    if(boarding[2]=='X'&&boarding[4]=='X'&&boarding[6]=='X') n++;
    if(boarding[2]=='0'&&boarding[4]=='0'&&boarding[6]=='0') m++;

    if(n&&m) return 0;  //illegal
    if(n) return 1;     //1st win
    if(m) return 2;     //2nd win
    return 3;            //draw
}

int main()
{
    int t, n=0, m=0, cas=0, verd;
    for (int i = 0; i<3; i++)
        cin>>board[i];
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if(board[i][j]=='X') n++;
            else if(board[i][j]=='0') m++;
            boarding[cas++] = board[i][j];
        }
    }
    if(n==m||n-m==1)
    {
        verd = check();
        if(verd == 3)
        {
            if(n+m==9) cout<<"draw"<<endl;
            else if(n==m) cout<<"first"<<endl;
            else cout<<"second"<<endl;
        }
        else if(verd == 1 && n==m+1) cout<<"the first player won"<<endl;
        else if(verd == 2 && n==m) cout<<"the second player won"<<endl;
        else cout<<"illegal"<<endl;
    }
    else cout<<"illegal"<<endl;           //illegal
    return 0;
}
