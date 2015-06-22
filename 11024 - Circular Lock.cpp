/*
 * RIG for UVa 11024 - Circular Lock
 */
#include<bits/stdc++.h>
#define TEST_CASES 100
using namespace std;




int main()
{
    freopen("11024 - Circular Lock.txt","w",stdout);
    /* Variables used in the program */
    int i, p1,s1, p2, s2, j;

    /* Initialize random seed: */
    srand (time(NULL));
    printf("100\n" );
    for(i = 0; i < TEST_CASES; i++)
    {

        for (j=0; j<2; j++)
        {
            /* Make sure the p range is from 1 through 10000 */
            p1=(rand()%10000)+1;
            /* Make sure the s range is from 0 through p-1 */
            s1=rand()%p1;
            p2=(rand()%10000)+1;
            s2=rand()%p2;
            printf("%d %d %d %d\n", s1, s2, p1, p2);
        }
    }
    return 0;
}
