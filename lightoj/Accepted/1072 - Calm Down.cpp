/*
distance from centre of any small circle to centre of the large circle  = R - r
where, R = the radius of large circle and r = radius of any small circle.
Now, Let's have a tangent on any small circle from the centre of any large circle.
Let B be the point where the tangent touched on the small circle.
Suppose, the centre of small circle is A and the centre of the large circle is O.
Now, in OAB circle, OA is the hypotenuse = R - r
Then, AB = r
So, sin (theta) = r / (R - r), where theta = angle AOB
    => theta = asin(r / (R - r)) --------------(1)
On the other hand, 2 * theta * n = 2 * PI
    => theta * n = PI
    => asin( r / (R - r)) = PI / n
    => sin (PI / n) = r / (R - r)
    =>  (R - r) * sin (PI / n) = r
    =>  R * sin (PI / n) = r (1 + sin (PI / n) )
    => r = (R * sin (PI / n)) / (1 + sin (PI / n) )
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
#include <list>
#include<set>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    int n, t,caseno=1;
    double R, r, sine;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%lf %d", &R, &n);
        sine = sin(PI/((double) n));
        r = (R * sine) / (1 + sine);
        printf("Case %d: %.10lf\n", caseno++, r);
    }

    return 0;
}
