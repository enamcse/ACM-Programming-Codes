/**
* H:\Dropbox\Code\lightoj\1062 - Crossed Ladders.cpp
* Created on: 2015-02-04-14.18.18, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <stdio.h>
#include <math.h>
#include <algorithm>

#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;
double x, y, c;

double EPS = 1e-12;
struct PT {
  double x, y; PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }


// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
//  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

bool check(double mid)
{
    double p = sqrt(x*x - mid*mid);
    double q = sqrt(y*y - mid*mid);

    PT intersect = ComputeLineIntersection(PT(0,0),PT(mid,q),PT(mid,0),PT(0,p));
    return intersect.y-c>=0;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, cas=1;
//    _
	double  lef, righ, mid;

	scanf("%d", &t);

	while(t--)
    {
        scanf("%lf %lf %lf", &x, &y, &c);

        lef = 0.0;
        righ = min(x,y);

        for (int i = 0; i<30; i++)
        {
            mid = (lef+righ)/2.0;
            if(check(mid)) lef = mid;
            else righ = mid;
        }
        printf("Case %d: %.9lf\n",cas++,mid);
    }


   return 0;
}
