/**
* H:\Dropbox\Code\lightoj\1077 - How Many Points.cpp
* Created on: 2015-02-26-01.22.10, Thursday
* Verdict: Solved
* Author: Enamul Hassan
* Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1077
**/

#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, cas=1;
    ll a, b, x, y;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
        /**
        *   At first lets simplify the problem. Lets assume that there exists n lattice points
        *   in between segment AB. If a lattice point breaks down a segment into two, then the
        *   answer = n + 1. we should take the absolute difference of x co-ordinate and y
        *   co-ordinate between these two points. That means we made the scenario originated.
        *   In co-ordinate, one of two points became (0,0). Lets name the new segment as A'B'
        *   Now, think, when does a lattice point come in this case while traversing from A'
        *   to B'? A lattice point comes when we pass an integer amount in x co-ordinate and
        *   at the same time we should pass an integer amount in y co-ordinate. If we found
        *   the first lattice point, then the distance between the lattice point and A' would
        *   be repeated until we reach B' and name this distance d. That means, we would get
        *   the second lattice point if we pass d distance from the first lattice point, third
        *   lattice point would be revealed by second and so on. It can be proved
        *   mathematically that this n is equal to GCD of(difference of x co-ordinate,
        *   difference of y co-ordinate between).
        *   Now, come to the mathematical view. Lets think about the segment A'B'. One of the
        *   two corner points is (0,0) and let the other is (p,q). Now, the equation for this
        *   line is y = (p/q)*x. Here, we should bring p/q to the least possible term. It can
        *   done by taking GCD(p,q) = G and y = ((p/G)/(q/G))*x.  From the points on the
        *   equation y = (p/q)*x, only those points would be counted as lattice points which
        *   are integers and its both x and y co-ordinates are less than p and q respectively.
        *   These points can obtain by  letting G ranging 1 to G in equation y=((p/G)/(q/G))*x.
        *   An example may clear the scenario. Lets consider three cases.
        *           1. (2,3),
        *           2. (4,6) and
        *           3. (6,9)
        *   The equation of these three lines are y = (2/3)*x, y = (4/6)*x and y = (6/9)*x
        *   respectively. Lets take their GCD and make them Least possible term. Here, GCD
        *   equals to 1, 2, 3 respectively and all of them indicates one single line y =
        *   (2/3)*x. But we would count 1, 2, 3 lattice points for the equation no 1, 2, 3
        *   respectively. Our answer is one more than this GCD, because we are missing point
        *   (0,0) in the scenario.
        *   Do some paper work if you could not understand the scenario till now.
        */
        printf("Case %d: %lld\n",cas++,1LL+__gcd(abs(x-a),abs(y-b)));
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
