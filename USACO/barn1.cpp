/*
ID: manetsus
PROG: barn1
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
#define sz 100
#define input_file "barn1.in"
#define output_file "barn1.out"
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

int flag[300];

vector<int>v;

int main()
{
#if !defined ENAM
    fread;
    fwrite;
#endif // ENAM
//    ofstream fout (input_file);
//    ifstream fin (output_file);

    int m, s, c, n, prev=-1,cnt=0, blocked=0;
    bool pre=false;
    scanf("%d %d %d", &m, &s, &c);

    for (int i = 0; i<c; i++)
    {
        scanf("%d", &n);
        flag[n-1] = true;
    }

    for (int i = 0; i<s; i++)
    {
        if(flag[i])
        {
            blocked++;
            if(!pre)
            {
                if(prev!=-1) v.pb(i-prev);
                cnt++;
            }
            prev=i+1;
        }
        pre = flag[i];
    }

    if(m<cnt)
    {
        sort(all(v));
        int i=0, k=v.size();

        while(m<cnt--&&i<k) blocked+=v[i++];
    }

    printf("%d\n", blocked);
    return 0;
}

