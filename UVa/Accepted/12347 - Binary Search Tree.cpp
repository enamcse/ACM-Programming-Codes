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

struct node{
    int par, val, right, left;
};
int n=0;

node data[10005];


void rec(int k)
{
    if(data[k].right!=-1) rec(data[k].right);
    if(data[k].left!=-1) rec(data[k].left);
    printf("%d\n", data[k].val);
    return;
}


int main()
{
//    freopen("in.txt","r", stdin);
    int k, now, pre;

    while(~scanf("%d", &k))
    {
        if(n==0)
        {
            data[n].par = -1;
            data[n].val = k;
            data[n].right = -1;
            data[n++].left = -1;
        }
        else
        {
            now = 0;
            int side=0;
            while(now!=-1)
            {
                if(k<data[now].val)
                {
                    pre = now;
                    now = data[now].right;
                    side=1;
                }
                else if(k>data[now].val)
                {
                    pre = now;
                    now = data[now].left;
                    side=2;
                }
            }
            if(side==1)
            {
                data[pre].right = n;

            }
            else if(side==2)
            {
                data[pre].left = n;
            }

            data[n].par = pre;
            data[n].val = k;
            data[n].right = -1;
            data[n++].left = -1;
        }
    }
    rec(0);




    return 0;
}
