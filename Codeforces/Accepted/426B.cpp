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

#define sz 155
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

int mat[sz][sz], made[sz][sz];

bool check(int n, int m)
{
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if(mat[i][j]!=made[i][j]) return false;
    return true;
}

void copys(int beg, int m)
{
    for (int i = 0; i<beg; i++)
        for (int j = 0; j<m; j++)
            made[(beg<<1) - i - 1 ][j]=made[i][j];
    return;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, row = 0, tew, beg;
    bool flag;
    scanf("%d %d", &n, &m);

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            scanf("%d", &mat[i][j]);

    while(++row<n)
    {
        tew = row;
        while(tew<n) tew<<=1;

        if(tew!=n) continue;
//        cout<<row<<" "<<tew<<endl;
        tew = row;
        for (int i = 0; i<row; i++)
            for (int j = 0; j<m; j++)
                made[i][j] = mat[i][j];

        while(tew<n)
        {
            copys(tew,m);
            tew<<=1;
        }

//        for (int i = 0; i<n; i++)
//        {
//            for (int j = 0; j<m; j++)
//                cout<<mat[i][j]<<" ";
//            cout<<endl;
//        }
//
//        cout<<endl<<"made:"<<endl;
//
//        for (int i = 0; i<n; i++)
//        {
//            for (int j = 0; j<m; j++)
//                cout<<made[i][j]<<" ";
//            cout<<endl;
//        }
//
//        cout<<endl<<"ok!"<<endl;

        if(check(n,m))
        {
            printf("%d", row);
            return 0;
        }

    }

    printf("%d", n);




    return 0;
}
