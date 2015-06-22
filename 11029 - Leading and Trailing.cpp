/*
 * RIG for UVa 11029 - Leading and Trailing
 */
#include<bits/stdc++.h>

using namespace std;


int main()
{
    freopen("output.txt","w",stdout);
    /* Variables used in the program */
    int i,t,n,k, j;

    /* Initialize random seed: */
    srand (time(NULL));
    t = rand()%999;
    printf("%d\n",t+2 );
    /* Upper bound */
    printf("%d %d\n", (int)2147483647, (int)10000000);
    /* Middle */
    printf("%d %d\n", (int)1073741824, (int)5000000);
    for(i = 0; i < t; i++)
    {
        /* Make sure n ranges in  positive INTEGER_LIMIT */
        n = (rand()*(long long)rand())%2147483647;
        n++;
        /* Make sure the range is from 1 through 1,00,00,000 */
        k=((rand()*(long long)rand())%10000000)+1;
        printf("%d %d\n", n , k);
    }
    return 0;
}

