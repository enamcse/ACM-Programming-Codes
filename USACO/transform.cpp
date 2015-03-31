/*
ID: manetsus
PROG: transform
LANG: C++
*/
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
#define sz 11
#define input_file "transform.in"
#define output_file "transform.out"
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen(input_file,"r",stdin)
#define fwrite freopen(output_file,"w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define chng(a,b) a^=b^=a^=b;
#define PI acos(-1)
#define mod 1000000007

using namespace std;

char pre[sz][sz], post[sz][sz], original[sz][sz];
char temp[sz][sz];

void make_mirrored(int n)
{
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            temp[i][j] = pre[i][n-1-j];

    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            original[i][j] = pre[i][j];
            pre[i][j]=temp[i][j];
        }
    return;
}

void get_original(int n)
{
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            pre[i][j]=original[i][j];
    return;
}



void rotat(int n)
{

    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            temp[i][j] = pre[n-j-1][i];

    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            pre[i][j] = temp[i][j];

    return;
}

bool check(int n)
{
    int i;
    for (i = 0; i<n; i++)
    {
        int j;
        for (j=0; j<n; j++)
            if(pre[i][j]!=post[i][j]) break;
        if(j!=n) break;
    }
    if(i==n) return true;
    return false;
}


int main()
{
#if !defined ENAM
    fread;
    fwrite;
#endif // ENAM
//    ofstream fout (input_file);
//    ifstream fin (output_file);

    int ans = 0, i,n;

    scanf("%d", &n);

    for (i = 0; i<n; i++)
        scanf("%s", pre[i]);

    for (i = 0; i<n; i++)
        scanf("%s", post[i]);


    switch (1)
    {
    case 1:
        //rotate 90-degree
        rotat(n);
        if(check(n))
        {
            ans = 1;
            break;
        }

        //rotate 180-degree
        rotat(n);
        if(check(n))
        {
            ans = 2;
            break;
        }

        //rotate 270-degree
        rotat(n);
        if(check(n))
        {
            ans = 3;
            break;
        }

        //back to original
        rotat(n);
        make_mirrored(n);

//        for (int i = 0; i<n; i++)
//            cout<<pre[i]<<endl;


        //check mirrored
        if(check(n))
        {
            ans = 4;
            break;
        }


        //rotate 90,180,270-degree
        for (i=0; i<3; i++)
        {
            rotat(n);
            if(check(n))
            {
                ans = 5;
                break;
            }
        }
        if(i!=3) break;

        get_original(n);

        if(check(n))
        {
            ans = 6;
            break;
        }

        ans = 7;
        break;

    }

    printf("%d\n", ans);

    return 0;
}

/*
4
@@@@
@@@@
-@@@
@@@@
@@@@
@@@@
@@@-
@@@@
*/
