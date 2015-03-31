/**
* H:\Dropbox\Code\lightoj\1089 - Points in Segments (II).cpp
* Created on: 2015-02-09-02.13.38, Monday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define sz 50005
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

int  cum[sz*2];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int a[sz], b[sz],t, n, m, cas=1, k,q;

    scanf("%d", &t);

    while(t--)
    {
        vector<int>v;
        printf("Case %d:\n", cas++);
        scanf("%d %d", &n, &q);
        for (int i = 0; i<n; i++)
        {
            scanf("%d %d", &a[i], &b[i]);
            b[i]++;
            v.pb(a[i]);
            v.pb(b[i]);
        }
        sort(all(v));
        v.resize(distance(v.begin(),unique(all(v))));

        for (int i = 0; i<n; i++)
        {
            cum[ lower_bound(all(v),a[i]) - v.begin() ]++;
            cum[ lower_bound(all(v),b[i]) - v.begin() ]--;
        }
        k=v.size();
        for (int i = 1; i<k; i++)
            cum[i]+=cum[i-1];

        for (int i =0; i<q; i++)
        {
            scanf("%d", &m);
            printf("%d\n", cum[lower_bound(all(v),m) - v.begin()-!binary_search(all(v), m)]);
        }
        if(t)clr(cum,0);

    }



   return 0;
}
