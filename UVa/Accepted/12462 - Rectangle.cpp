/**
* H:\Dropbox\Code\UVa\12462 - Rectangle.cpp
* Created on: 2015-05-29-01.24.47, Friday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100005
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

ll  val[sz],le[sz], ri[sz], col[55][sz];


void histogram(int n)
{
    for (int i = 1; i<=n; i++)
        le[i] = ri[i] = i;

    for (int i = 1; i<=n; i++)
    {
        while(le[i]>1 && val[ i ]<= val[le[i]-1])
            le[i]=le[le[i]-1];
    }

    for (int i = n; i>=1; i--)
    {
        while(ri[i]<n && val[ i ]<= val[ri[i]+1])
            ri[i]=ri[ri[i]+1];
    }
}

bool asol(int x, int y, int c)
{
    for (int i = 0; i<c; i++)
    {
        if(col[i][y]-col[i][x-1]<1) return 0;
    }
    return 1;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    ll t, n, m, cas=1, ans, c;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

//    scanf("%lld", &t);

    while(scanf("%lld %lld", &n, &c)&&(n+c))
    {
        ;
        ans = 0;

        for (int i = 0; i<c; i++)
            for (int j = 0; j<=n; j++)
                col[i][j]=0;


        for (int i = 1; i<=n; i++)
            scanf("%lld", &val[i]);

        for (int i = 1; i<=n; i++)
        {
            scanf("%lld", &m);
            col[m][i]++;
        }

        for (int i = 0; i<c; i++)
            for (int j = 2; j<=n; j++)
                col[i][j]+=col[i][j-1];


        val[n+1]=-1;

        histogram(n);

        for (int i = 1; i<=n; i++)
            ans = max(ans,(ri[i]-le[i]+1)*val[i]*asol(le[i],ri[i],c));
        printf("%lld\n", ans);
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
/**
6 3
2 3 1 7 3 5
2 0 1 0 1 2
3 1
2 2 2
0 0 0
5 2
3 2 1 2 3
1 0 1 0 1
6 4
1 2 3 4 5 6
0 1 2 3 1 0
7 2
1 2 3 4 3 2 1
0 1 0 1 0 1 0
10 2
2 1 2 1 1 2 1 2 2 1
1 0 0 0 1 0 0 1 1 0
3 2
1000000000 999999997 999999999
0 1 1
0 0
*/
