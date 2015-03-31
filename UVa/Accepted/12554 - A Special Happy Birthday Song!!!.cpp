#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <bitset>

using namespace std;

#define inf 1e9
#define pb push_back
#define pp pop_back
#define clr(y,z) memset(y, z, sizeof(y))
#define mp make_pair
#define BE(a) a.begin(),a.end()
#define ll long long

char lines[20][100] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

char line[100][500];


int main()
{
    int n, ind = 0, cnt = 0, cyc=0;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%s", line[i]);
    }

    do
    {
        for (int i = 0; i<n; i++)
        {
            printf("%s: %s\n", line[i], lines[ind++]);
            if(ind==16) ind=0, cnt++;
            if(!ind&&cnt && cyc) return 0;
        }
        cyc++;
    }
    while(1);


    return 0;
}
/**
17
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
*/
