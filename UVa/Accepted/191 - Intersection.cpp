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
using namespace std;

struct point{
    int x;
    int y;
};

int direction(point a, point b, point c)
{
    return ((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y)); ///(p1 - p0) X (p2 - p0) = clockwise (positive) or anticlockwise (negative).
}

bool on_segment(point a, point b, point c)
{
    int x = min(a.x,b.x), X = max(a.x,b.x);
    int y = min(a.y,b.y), Y = max(a.y,b.y);
    if(x<=c.x && c.x<=X && y<=c.y && c.y<=Y) return true;   /// c is in between a and b or not
    return false;
}

bool segment_intersect(point a, point b,point c, point e)
{
    point p[4];
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = e;
    int d[4];
    d[0] = direction(p[2], p[3], p[0]); /// side of p1 in respect to the line p3p4
    d[1] = direction(p[2], p[3], p[1]); /// side of p2 in respect to the line p3p4
    d[2] = direction(p[0], p[1], p[2]); /// side of p3 in respect to the line p1p2
    d[3] = direction(p[0], p[1], p[3]); /// side of p4 in respect to the line p1p2

    if(((d[0]>0&&d[1]<0) || (d[0]<0&&d[1]>0)) && ((d[2]>0&&d[3]<0) || (d[2]<0&&d[3]>0))) return true; /// lines intersect
    if(d[0]==0 && on_segment(p[2], p[3], p[0])) return true;    /// whether p1 is on line p3p4
    if(d[1]==0 && on_segment(p[2], p[3], p[1])) return true;    /// wherher p2 is on line p3p4
    if(d[2]==0 && on_segment(p[0], p[1], p[2])) return true;    /// whether p3 is on line p1p2
    if(d[3]==0 && on_segment(p[0], p[1], p[3])) return true;    /// whether p4 is on line p1p2
    return false;
}

bool comp(point a, point b)
{
    if(a.y==b.y) return a.x<b.x;
    else return a.y>b.y;
}


int main()
{
    int n,x ,y;
    point q[2];
    scanf("%d", &n);
    point p[4];
    while(n--)
    {
        scanf("%d %d", &x, &y);
        q[0].x = x; q[0].y = y;

        scanf("%d %d", &x, &y);
        q[1].x = x; q[1].y = y;

        scanf("%d %d", &x, &y);
        p[2].x = p[0].x = x; p[1].y = p[0].y = y;

        scanf("%d %d", &x, &y);
        p[3].x = p[1].x = x; p[2].y = p[3].y = y;
        sort(p,p+4, comp);
        /// next two conditions check whether the whole line lies in the rectangle or not
        if((p[0].x<=q[0].x && q[0].x <= p[1].x) && (p[2].y<=q[0].y && q[0].y <= p[0].y))
        {
            printf("T\n");
            continue;
        }

        if((p[0].x<=q[1].x && q[1].x <= p[1].x) && (p[2].y<=q[1].y && q[1].y <= p[0].y))
        {
            printf("T\n");
            continue;
        }

        /// next four conditions check whether any of the sides of the rectangle intersects the line or not
        if(segment_intersect(q[0],q[1], p[0], p[1]))
        {
            printf("T\n");
            continue;
        }

        if(segment_intersect(q[0],q[1], p[0], p[2]))
        {
            printf("T\n");
            continue;
        }

        if(segment_intersect(q[0],q[1], p[1], p[3]))
        {
            printf("T\n");
            continue;
        }

        if(segment_intersect(q[0],q[1], p[2], p[3]))
        {
            printf("T\n");
            continue;
        }
        printf("F\n");
    }
    return 0;
}
