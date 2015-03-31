/**
* H:\Dropbox\Code\Codeforces\486B.cpp
*
* Created on: 2014-11-11-20.48.12, Tuesday
* Author: Enamul Hassan
* Verdict: SOLVED
**/

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

#define sz 100005
#define pb(a) push_back(a)

#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007

using namespace std;

int mat[200][200], made[200][200], check[200][200];
int row[200], col[200];


bool ki(int m, int n)
{
    for (int i = 0; i<m; i++)
        for (int j = 0; j<n; j++)
            if(check[i][j]!=mat[i][j]) return false;
    return true;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, p,pp;

    scanf("%d %d", &m, &n);
    for (int i = 0; i<m; i++)
        for (int j = 0; j<n; j++)
            scanf("%d", &mat[i][j]);

    for (int k = 0; k<m; k++)
        row[k] = 1;
    for (int k = 0; k<n; k++)
        col[k] = 1;

    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            row[i]&=mat[i][j];
            col[j]&=mat[i][j];
        }
    }


    for (int i = 0; i<m; i++)
        for (int j = 0; j<n; j++)
            made[i][j] = (row[i]&col[j]);

    for (int i = 0; i<m; i++)
        for (int j = 0; j<n; j++)
        {
            if(made[i][j]==1)
            {
                for (int k = 0; k<m; k++)
                    check[k][j] = 1;
                for (int k = 0; k<n; k++)
                    check[i][k] = 1;
            }
        }

    if(ki(m,n))
    {
        puts("YES");

        for (int i = 0; i<m; i++)
        {
            for (int j = 0; j<n; j++)
                printf("%d ", made[i][j]);
            printf("\n");
        }
    }
    else puts("NO");



//    for (int i =0; i<m; i++)
//        for (int j = 0; j<n; j++)
//        {
//            p=pp=0;
//            for (int k = 0; k<m; k++)
//                if(pp==0&&mat[k][j]==1) pp++,k=-1;
//                else if(pp==1&&mat[k][j]==0) {pp++;break;}
//            for (int k = 0; k<n; k++)
//                if(p==0&&mat[i][k]==1) p++,k=-1;
//                else if(p==1&&mat[i][k]==0) {p++;break;}
//
//            if(i==0)
//            {
//                for (int k = 0; k<m; k++)cout<<"kk"<<mat[k][j]<<endl;
//                for (int k = 0; k<n; k++)cout<<"ff"<<mat[i][k]<<endl;
//                cout<<j<<":::"<<pp<<" "<<p<<endl;
//            }
//
//            if(pp==1&&p==1) made[i][j]=1;
//            if(pp==2&&p==2)
//            {
//                puts("NO");
//                return 0;
//            }
//        }




    return 0;
}
