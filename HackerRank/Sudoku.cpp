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
#include <stack>

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int box[9][9],col[9][9], row[9][9], board[9][9], ans[9][9];
bool flag;
void solve(int i, int j)
{
    if(j==9) i++,j=0;
    if(flag) return;

    if(i==9)
    {
        for (int p=0; p<9; p++)
            for (int q=0; q<9; q++)
                ans[p][q]=board[p][q];
        flag=true;
        return;
    }
    int quad=(i/3)*3+(j/3);
    for (int k = 0; k<9; k++)
        if(!box[quad][k]&&!col[j][k]&&!row[i][k]&&!flag&&!board[i][j])
        {
            board[i][j]=k+1;
            box[quad][k]=col[j][k]=row[i][k]=1;
            solve(i,j+1);
            board[i][j]=0;
            box[quad][k]=col[j][k]=row[i][k]=0;
        }
    return;
}

int main()
{
    int t,x,y,quad;
    scanf("%d", &t);
    while(t--)
    {
        clr(col,0);
        clr(row,0);
        clr(box,0);
        flag = false;
        for (int i =0; i<9; i++)
            for (int j =0; j<9; j++)
            {
                scanf("%d",&board[i][j]);
                if(board[i][j])
                {
                    col[j][ board[i][j]-1 ] =1;
                    row[i][ board[i][j]-1 ] =1;
                    quad=(i/3)*3+(j/3);
                    box[quad] [ board[i][j]-1 ]=1;
                }
            }

        solve(0,0);
        for (int i =0; i<9; i++)
        {
            for (int j =0; j<9; j++)
            {
                printf("%d",ans[i][j]);
                if(j!=8) printf(" ");
            }

            printf("\n");
        }
    }
    return 0;
}
