/**
* H:\Dropbox\Code\Timus\1084. Goat in the Garden.cpp
* Created on: 2015-03-15-05.15.37, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
* Concept: Centering the stake, the goat could explore within a limited area
           in the field and the area is nothing but a circle having the radius
           equals to the length of the rope and the kitchen-garden is a square.
           So, What are the possible scenarios of the problem? The scenarios
           could be classified into 3 type.
           1. The square is totally inside the circle.
           2. The circle is totally inside the square.
           3. Both overlap some area.
           For the first two, the answer is clear. In the first case, the area
           of the square is the answer of the problem and in the second case,
           the area of the circle is the answer. However, the main thing is to
           decide when the first scenario would come and when the second.

           The first scenario would come when the diameter of the circle would
           be greater than the diagonal of the square.

           The second scenario would come when the side of the square is less
           than or equal to the diameter of the circle.

           Lets talk about the overlapping scenario. We can take the area of
           the circle but to get the answer, we have to subtract the area of
           the portion which gone outside the square. We can calculate the
           area of this portion from one side and subtract them multiplying by
           4 as it is same in all four sides.
              A_____________
             E|\            |
             /|\ \          |
            / |  \ \        |
           | D|_____C       |
            \ |             |
             \|             |
             F|_____________|
              B
            The above picture may give an idea. We know that, to get the idea,
            no need to have a clear and exact picture. However, AC is the half
            of the diagonal of the square and CE is the radius of the circle.
            We can draw a perpendicular line from the center to side BE. Say
            this line is CD. Here, we don't know the length of DE but know the
            length of AD, because it is the half of the side of the square.
            In the right Triangle ACD, CD is the base and AD is the height and
            AC is the hypotenuse. Using Pythagorean theorem, we get,
                AC^2 = AD^2 + CD^2
            Lets the half of the side, s = AD and the diagonal, diag = AC, so,
            we can get the base, b = CD = square_root( diag^2 - s^2 ).
            From the right triangle CDE, CD is the base and DE is the height and
            CE is the hypotenuse. Using Pythagorean theorem, we get,
                CE^2 = DE^2 + CD^2
            Radius of the circle, r = CE, and lets DE = x.
            So, x = square_root( r^2 - b^2 ).
            Now, we know,  cos(ECD) = CD/CE
                                    = b/r.
                           ECD = cos(b/r)^-1.
            Here, the angle ECF, theta = 2 * angle ECD
                                       = 2 * cos(b/r)^-1.
            Lets talk about the area of a circle.
                2PI angle makes a circle having the area = PI*r*r
                  1 angle makes a circle having the area = PI*r*r/(2*PI)
                  T angle makes a circle having the area = r*r*T/2
            theta angle would make area = r*r*2 * (cos(b/r)^-1)/2
                                        = r*r*(cos(b/r)^-1).
            To calculate the extended area we have to subtract the area of the
            ACB triangle. In ACB triangle, height, CD = b, base, AB = 2*s.
            So, the area of the triangle ACB = b*2*s/2 = b*s.
            So, the final answer equals to PI*r*r - ( r*r*(cos(b/r)^-1) - b*s ).
* Special Thanks to: Rumman Mahmud Mahdi Al Masud.
**/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define PI acos(-1)


using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    double diag,r,area,d, side;
    cin>>n>>m;
    r = m;
    d = 2*r;
    diag =side= n;
    diag*= sqrt(2);
    if(diag<=d)
        area = side*side;
    else
    {
        area = PI*r*r;
        if(d>side)
        {
            double h = side/2.0;
            double theta = acos(h/r);
            double l = sqrt(r*r - h*h );
            area -=(4*( theta * r * r - side * l * .5));
        }
    }
    cout<<fixed<<setprecision(3)<<area;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
