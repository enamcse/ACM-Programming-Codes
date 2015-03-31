#include <stdio.h>
#include <string.h>
#include <queue>

#define sz 11
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e3)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

short rr[] = {0,0,-1,1};
short cc[] = {-1,1,0,0};

char line[sz][sz];
short posx[27], posy[27], col[sz][sz], cost[sz][sz],n;

struct point{
    short x, y;
    point(){}
    point(short a, short b)
    {
        x = a;
        y = b;
    }
};
short bfs(short pos)
{

    if(posx[pos+1]==-1) return cost[ posx[pos] ][ posy[pos] ];
    queue<point>p;
    p.push(point(posx[pos], posy[pos]));
    point now;
    short x,y;
    col[posx[pos]][posy[pos]]==pos+1;
    while(!p.empty())
    {
        now = p.front();
        p.pop();
        for (short i = 0; i<4; i++)
        {
            x = now.x + rr[i];
            y = now.y + cc[i];
            if(x<0||y<0||x>=n||y>=n||line[x][y]=='#'||col[x][y]>=pos+1) continue;
            if((short)(line[x][y]-'A')<=1+pos)
            {
                col[x][y]=pos+1;
                cost[x][y]=cost[now.x][now.y]+1;
                if(posx[pos+1]==x && posy[pos+1]==y) return bfs(pos+1);
                p.push(point(x,y));
            }
        }
    }
    return -inf;
}

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    short t, m, cas=1;

    scanf("%d", &t);

    while(t--)
    {
        clr(col,-1);
        clr(posx,-1);
        clr(posy,-1);
        clr(cost,0);

        scanf(" %d", &n);
        for (short i = 0; i<n; i++)
            scanf("%s", line[i]);

        for (short i = 0; i<n; i++)
            for (short j = 0; j<n; j++)
                if(line[i][j]!='.'&&line[i][j]!='#') posx[ line[i][j] - 'A' ] = i, posy[ line[i][j] - 'A' ] = j;
        m = bfs(0);
        if(m>=0)printf("Case %d: %d\n", cas++, m);
        else printf("Case %d: Impossible\n", cas++);
    }
    return 0;
}
/*
4

5
A....
####.
..B..
.####
C.DE.

2
AC
.B

2
A#
#B

3
A.C
##.
B..
*/
