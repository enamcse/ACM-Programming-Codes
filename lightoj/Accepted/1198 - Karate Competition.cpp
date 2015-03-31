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

#define sz 1055
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

vector<int> v, k;
vector<int>::iterator it;


int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n, m, cas=1, p, q, cnt =0, mx;

    scanf("%d", &t);


    while(t--)
    {
        v.clear();
        k.clear();
        mx=cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &p);
            v.pb(p);
        }

        for (int i = 0; i<n; i++)
        {
            scanf("%d", &p);
            k.pb(p);
        }
        sort(v.begin(), v.end());
        sort(k.begin(), k.end());

        for (int i = 0; i<v.size(); i++)
        {
            it = lower_bound(k.begin(),k.end(),v[i]);
            if(it==k.begin()) continue;
            cnt+=2;
            k.erase(it-1);
            v.erase(v.begin()+i--);

        }
        n = v.size();
        for (int i = 0; i<n; i++)
        {
            if(!binary_search(k.begin(),k.end(),v[i])) continue;
            it = lower_bound(k.begin(),k.end(),v[i]);
            cnt++;
            k.erase(it);
        }

        printf("Case %d: %d\n", cas++,cnt);
    }
    return 0;
}


/*
2
30
224 337 914 657 839 125 705 611 845 761 781 902 263 870 53 731 585 649 229 137 57 941 827 765 142 708 390 717 43 546
590 25 416 982 550 486 855 381 878 376 564 709 677 692 397 611 764 487 697 409 390 695 93 208 947 740 337 421 772 57

30
43 53 57 125 137 142 224 229 263 337 390 546 585 611 649 657 705 708 717 731 761 765 781 827 839 845 870 902 914 941
25 57 93 208 337 376 381 390 397 409 416 421 486 487 550 564 590 611 677 692 695 697 709 740 764 772 855 878 947 982

*/
