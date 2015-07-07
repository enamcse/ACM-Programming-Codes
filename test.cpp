#include <bits/stdc++.h>
#define pb push_back
#define inf (1e9)
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

char h[9][10], w[9][10];
int l=9,up;

int sq[9];
int g[9], t[9];
bool s;
int u[9][9];
struct o
{
    int x, y;
};
vector<o>v;

void r(int z)
{
    if(!s) return;
    if(z==up)
    {
        s = false;

        for (int i = 0; i<l; i++)
            strcpy(w[i],h[i]);

        return;
    }

    int a=0, b, c=inf;
    o p;
    for (int i = 0; i<up; i++)
    {
        p = v[i];

        if(h[p.x][p.y]!='.') continue;
        b=0;

        for (int j = 1; j<=l; j++)
            if(!(sq[ u[p.x][p.y] ]&(1<<j)) && !(g[p.y]&(1<<j)) && !(t[p.x]&(1<<j)) ) b++;
        if(b<c)
        {
            c = b;
            a = i;
        }
    }
    if(c==0) return;
    p = v[a];

    for (int j = 1; j<=l; j++)
    {
        if(!(sq[ u[p.x][p.y] ]&(1<<j)) && !(g[p.y]&(1<<j)) && !(t[p.x]&(1<<j)) )
        {
            sq[ u[p.x][p.y] ]|=(1<<j);
            g[p.y]|=(1<<j);
            t[p.x]|=(1<<j);
            h[p.x][p.y] = j+'0';
            if(s) r(z+1);
            sq[ u[p.x][p.y] ]^=(1<<j);
            g[p.y]^=(1<<j);
            t[p.x]^=(1<<j);
            h[p.x][p.y] = '.';
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n=3,kk,m;
    o p;
    for (int i = 0; i<l; i++)
        for (int j = 0; j<l; j++)
            u[i][j] = (i/n)*n+(j/n);

    cin >> kk;
    for(int i=0; i<kk; i++)
    {
        s = true;
        clr(g,0);
        clr(t,0);
        clr(sq,0);
        for(int j=0; j<9; j++)
            for(int k=0; k<9; k++)
            {
                cin >> h[j][k];
                if(h[j][k]!='0')
                {
                    m = h[j][k] - '0';
                    sq[ u[j][k] ]|= (1<<m);
                    g[k]|= (1<<m);
                    t[j]|= (1<<m);
                }
                else
                {
                    h[j][k]='.';
                    p.x = j;
                    p.y = k;
                    v.pb(p);
                }
            }
        up = v.size();
        r(0);
        for(int j=0; j<9; j++)
            for(int k=0; k<9; k++)
                cout<<w[j][k]<<" \n"[k==8];
    }
    return 0;
}
