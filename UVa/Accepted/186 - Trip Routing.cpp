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

#define sz 105
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


int n, adj[sz][sz], graph[sz][sz], par[sz][sz];
map<string,int>m;
map<int,string>rev;
string route[sz][sz];

void floyed_warshall(int n)
{
    for (int k = 0 ; k<n; k++)
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                    par[i][j]=k;
                }
    return;
}


void print_path(int x, int y)
{
    if(par[x][y]==0)
    {
        printf("%-20s %-20s %-10s %5d\n",rev[x].c_str(), rev[y].c_str(), route[x][y].c_str(), adj[x][y]);
        return;
    }
    print_path(x,par[x][y]);
    print_path(par[x][y],y);
    return;
}

int main()
{
//    fread;fwrite;
    int i, indx, km, x, y;
    string converted[3];
    char line[1000], str[8][sz];

    for (int i =0; i<sz; i++)
        for (int j = 0; j<sz; j++)
            graph[i][j]=inf;

    for (int i = 0; i<sz; i++)
        graph[i][i]=0;


    while(gets(line))
    {
        if(strlen(line)==0) break;
        for (i = 0; line[i]!=','; i++)
            str[0][i]=line[i];
        str[0][i]='\0';

        for (i++,indx=0; line[i]!=','; i++)
            str[1][indx++]=line[i];
        str[1][indx]='\0';

        for (i++,indx=0; line[i]!=','; i++)
            str[2][indx++]=line[i];
        str[2][indx]='\0';


        for (i++,indx=0; line[i]!='\0'; i++)
            str[3][indx++]=line[i];
        str[3][indx]='\0';
        sscanf(str[3],"%d", &km);

        if(m[ str[0] ]==0)
        {
            x = n;
            rev[n] = str[0];
            m[ str[0] ]= n++;
        }
        else x = m[ str[0] ];

        if(m[ str[1] ]==0)
        {
            y = n;
            rev[n] = str[1];
            m[ str[1] ]= n++;
        }
        else y = m[ str[1] ];
        if(graph[x][y]==0||km<graph[x][y])
        {
            graph[x][y]=graph[y][x]= adj[x][y]=adj[y][x]=km;
            route[x][y]=route[y][x] = str[2];
        }
    }

    floyed_warshall(n);

    while(gets(line))
    {
        for (i = 0; line[i]!=','; i++)
            str[0][i]=line[i];
        str[0][i]='\0';

        for (i++,indx=0; line[i]!='\0'; i++)
            str[1][indx++]=line[i];
        str[1][indx]='\0';

        x = m[ str[0] ];
        y = m[ str[1] ];

        printf("\n\nFrom                 To                   Route      Miles\n");
        printf("-------------------- -------------------- ---------- -----\n");

        print_path(x,y);

        printf("                                                     -----\n");
        printf("                                          Total      %5d\n",graph[x][y]);
    }

    return 0;
}
