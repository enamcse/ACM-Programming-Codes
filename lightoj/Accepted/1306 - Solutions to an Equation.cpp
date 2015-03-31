/**
* H:\Dropbox\Code\lightoj\1306 - Solutions to an Equation.cpp
* Created on: 2015-03-03-17.52.29, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: This kind of problem can be solved by Extended Euclidean Algorithm.
           If an equation of straight line is given like Ax + By = C, then
           extended euclidean algorithm can find a solution of it using
           diophantine equation. From this concept, all the solution in a
           certain range can also be counted and be found.
           Let  ax1 + by1 = c
                ax1 + a*b*T/g - a*b*T/g + by1 = c, where g = GCD get using EGCD
                a (x1 + b*T/g) + b (y1 + a*T/g) = c
           Comparing this equation with the previous, we get,
                x = x1+(b*T/g)
                y = y1-(a*T/g)
            Now, x>= min_x
                x1+(b*T/g) >= min_x
                (b*T/g) >= min_x - x1
                T >= (min_x-x1)* g/b
            On the other hand, y >= min_y
                y1-(a*T/g) >= min_y
                y1 - min_y >= (a*T/g)
                T <= (y1-min_y)* g/a
            Combining these two, we get
                (min_x-x1)* g/b <= T <= (y1-min_y)* g/a
            Again, x<= max_x
                x1+(b*T/g) <= max_x
                (b*T/g) <= max_x - x1
                T <= (max_x-x1)* g/b
            On the other hand, y <= max_y
                y1-(a*T/g) <= max_y
                y1 - max_y <= (a*T/g)
                T >= (y1-max_y)* g/a
            Combining these two, we get
                (y1-max_y)* g/a <= T <= (max_x-x1)* g/b
            So, the solution of our problem T would be:
            max((min_x-x1)* g/b,  (y1-max_y)* g/a ) <= T
                                <= min( (y1-min_y)* g/a , (max_x-x1)* g/b)

* Special Thanks to: Rumman Mahmud Mahdi Al Masud
**/

#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

int sign_(ll a,ll b)
{
    if(a<0 && b>0) return -1;
    if(a>0 && b<0) return -1;
    return 1;
}

ll Floor(ll a,ll b)
{
    ll F=a/b + (!(a%b == 0))*(sign_(a,b) < 0?-1:0);
    return F;
}

ll Ceil(ll a,ll b)
{
    ll C=a/b + (!(a%b == 0))*(sign_(a,b) < 0?0:1);
    return C;
}

ll EGCD(ll a,ll b,ll &X,ll &Y)
{
    if(b==0)
    {
        X=1;
        Y=0;
        return a;
    }
    ll x=-(a/b),PX,r;
    r=EGCD(b,a%b,X,Y);
    PX=X;
    X=Y;
    Y=(Y*x)+(PX);
    return r;
}

ll count_all_solution_in_range(ll a,ll b,ll c,ll mina,ll maxa,ll minb,ll maxb)
{
    ll x0,y0,x1,y1,x,y;
    ll g=EGCD(a,b,x0,y0);
    if(g && c%g) return 0;
    if(a==0 && b==0)
    {
        if(c==0) return (maxa-mina+1)*(maxb-minb+1);
        return 0;
    }
    else if(a==0)
    {
        if(c/b>=minb&&c/b<=maxb) return (maxa-mina+1);
        return 0;
    }
    else if(b==0)
    {
        if(c/a>=mina&&c/a<=maxa) return (maxb-minb+1);
        return 0;
    }
    x1=(c/g)*x0;
    y1=(c/g)*y0;
    ll minT1,maxT1,minT2,maxT2,minT,maxT,a1,b1;
    a1=b/g;
    b1=a/g;
    minT1=Ceil(mina-x1,a1);
    maxT1=Floor(y1-minb,b1);
    minT2=Ceil(y1-maxb,b1);
    maxT2=Floor(maxa-x1,a1);
    minT=max(minT1,minT2);
    maxT=min(maxT1,maxT2);
    return max(maxT-minT+1,0ll);
}



int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, A,B,C,x1,x2,y1,y2, cas=1,tmp;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d %d %d %d %d %d", &A, &B, &C, &x1, &x2, &y1, &y2);
        C=-C;
        if(A<0)
        {
            A=-A;
            tmp=x1;
            x1=-x2;
            x2=-tmp;
        }
        if(B<0)
        {
            B=-B;
            tmp=y1;
            y1=-y2;
            y2=-tmp;
        }

        printf("Case %d: %lld\n",cas++,
               count_all_solution_in_range(A,B,C,x1,x2,y1,y2));
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}

/**
2
1 -2 -29 -36 23 -35 -4
-2 1 -50 -46 -28 -41 -39
*/
