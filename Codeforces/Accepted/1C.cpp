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

#define sz 55
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

struct point{
    double x,y;
};

bool int_check(double k)
{
    return (fabs(k-floor(k))<(1e-4) ||fabs(k-ceil(k))<(1e-4) );
}


int main()
{
    double a,b,c, area, theta[3], R, m;
    point p[3];
    for (int i = 0; i<3; i++)
        scanf("%lf %lf", &p[i].x, &p[i].y);

    /**
    three arm of the triangle made by three given points.
    */
    a = sqrt((p[0].x - p[1].x)*(p[0].x - p[1].x) + (p[0].y - p[1].y)*(p[0].y - p[1].y));
    b = sqrt((p[1].x - p[2].x)*(p[1].x - p[2].x) + (p[1].y - p[2].y)*(p[1].y - p[2].y));
    c = sqrt((p[0].x - p[2].x)*(p[0].x - p[2].x) + (p[0].y - p[2].y)*(p[0].y - p[2].y));
    /**
    angle between arm b and c can be determined by cosine formula.
    */
    theta[0] = acos((b*b+c*c-a*a)/(2.0*b*c));

    /**
    From Lami's theorem, a/sin (theta 1) = 1/2R
    =>R = a/2sin(theta 1)
    */

    R = a /(2.0*sin(theta[0]));
    /**
    Angles made by three arms at center point can be determined by using the cosine formula.
    */

    if((((2.0*R*R - a*a)/(2.0*R*R)))<-1) theta[0] = PI;
    else theta[0] = acos((2.0*R*R - a*a)/(2.0*R*R));

    if((((2.0*R*R - b*b)/(2.0*R*R)))<-1) theta[1] = PI;
    else theta[1] = acos((2.0*R*R - b*b)/(2.0*R*R));

    if((((2.0*R*R - c*c)/(2.0*R*R)))<-1) theta[2] = PI;
    else theta[2] = acos((2.0*R*R - c*c)/(2.0*R*R));

    /**
    2pi/n angle created by 1 arm
    1 angle created by n/2pi arm
    theta angle created by n*theta/2pi arm, which must be integer.
    we will look for tt=he integer value in range n = 1 to 100.
    */
    sort(theta,theta+3);
    if(abs(theta[0]+theta[1]+theta[2]-2.0*PI)<1e-9);
    else
    theta[2] = (2*PI) - theta[2];
    for (int i = 3; i<=100; i++)
    {
        a = ((i*theta[0])/(2.0*PI));
        b = ((i*theta[1])/(2.0*PI));

        c = ((i*theta[2])/(2.0*PI));
        m = a+b+c;
        if(int_check(a) && int_check(b) && int_check(c) && (m-i)<1e-4)
        {
            /**
            Let an arm of the polygon creates  2*theta angle at the center. Now, lets draw a straight line from center to
            the mid point of the arm which creates two pythagorean triangle with 2*theta/2 = theta angle. on the other
            hand, 2*theta = 2pi/n, so, theta = pi/n. the hypotenuse (otivuj) is the radius of the triangle R here. so,
            each of those two triangle has a base and a height. where base = R cos (theta) and height = R sin (theta).
            the area of this triangle   = (base*height)/2
                                        = (R cos(theta) * R sin (theta))/2
                                        = R^2 (2 sin(theta) * cos (theta))/4
                                        = R^2 sin(2 theta)/4
            There exists total two times of n triangles in the circle.
            So, the total area  = 2n * area of one triangle
                                = 2n*R^2*sin(2 theta)/4
                                = nR^2 sin( 2 theta)/2
                                = (n/2)*R*R*sin(2pi/n)
            */

            area = ((i*R*R*sin((2.0*PI)/(i*1.)))/2.0);
            printf("%lf", area);
            break;
        }
    }
    return 0;
}
/*
-13.242302 -45.014124
-33.825369 51.083964
84.512928 -55.134407
*/
