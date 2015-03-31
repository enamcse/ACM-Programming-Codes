#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int main()
{
    int a[6], d;
    double g,h, k;

    for (int i =0; i<6; i++) scanf("%d",&a[i]);

    if(a[3]) g = a[0]/(double)a[3], d = 1;
    else if(a[0]) g = a[3]/(double)a[0], d = 2;
    else if(a[4]) g = a[1]/(double)a[4], d = 1;
    else if(a[1]) g = a[4]/(double)a[1], d = 2;
    else if(a[5]) g = a[2]/(double)a[5], d = 1;
    else if(a[2]) g = a[5]/(double)a[2], d = 2;
    else d = 3;

    switch (d)
    {
    case 1:
        h =g * a[3];
        if((double)a[0]!=h)
        {
            printf("1\n");
            break;
        }
        h =g * a[4];
        if((double)a[1]!=h)
        {
            printf("1\n");
            break;
        }
        h =g * a[5];
        if((double)a[2]!=h)
        {
            printf("1\n");
            break;
        }
        printf("-1\n");
        break;

    case 2:
        h =g * a[0];
        if((double)a[3]!=h)
        {
            printf("1\n");
            break;
        }
        h =g * a[1];
        if((double)a[4]!=h)
        {
            printf("1\n");
            break;
        }
        h =g * a[2];
        if((double)a[5]!=h)
        {
            printf("1\n");
            break;
        }
        printf("-1\n");
        break;

    default:
        printf("-1\n");
        break;
    }
    return 0;
}
/*
A. Intersection
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

You are given two set of points. The first set is determined by the equation A1x + B1y + C1 = 0, and the second one is determined by the equation A2x + B2y + C2 = 0.

Write the program which finds the number of points in the intersection of two given sets.
Input

The first line of the input contains three integer numbers A1, B1, C1 separated by space. The second line contains three integer numbers A2, B2, C2 separated by space. All the numbers are between -100 and 100, inclusive.
Output

Print the number of points in the intersection or -1 if there are infinite number of points.
Sample test(s)
Input

1 1 0
2 2 0

Output

-1

Input

1 1 0
2 -2 0

Output

1
*/
