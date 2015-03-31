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
#include<set>

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
using namespace std;

int main()
{
    int n, cas=1;
    double a, b, c, theta[3], r[3], area_circle[3], area, s;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lf %lf %lf", &r[0], &r[1], &r[2]);
        a = r[0]+r[1];
        b = r[1]+r[2];
        c = r[0]+r[2];
        theta[1] = acos((a*a+b*b-c*c)/(2*a*b));
        theta[2] = acos((c*c+b*b-a*a)/(2*c*b));
        theta[0] = acos((a*a+c*c-b*b)/(2*a*c));
        s = (a+b+c)/2;
        area= sqrt(s*(s-a)*(s-b)*(s-c));
        for (int i = 0; i<3; i++){
            area_circle[i] = (r[i]*r[i]*theta[i])/2;
            area-= area_circle[i];
        }
        printf("Case %d: %lf\n", cas++, area);
    }
    return 0;
}
