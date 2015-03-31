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

void Floyed(bool graph[sz][sz]);

vector<char>v;
int d;

int main()
{
    bool graph1[sz][sz], graph2[sz][sz];
    int n, t, m, l,x,y;
    char a,b;
    bool ase;
    scanf("%d", &t);
    while(t--)
    {
        v.clear();
        scanf("%d ", &n);
//        cout<<"n = "<<n<<endl;
        l = n;
        clr(graph1,false);
        while(l--)
        {
            ase = false;
            scanf("%c %c ", &a, &b);
//            cout<<" "<<a<<" "<<b<<endl;
            for (int i=0; i<v.size(); i++)
                if(a==v[i])
                {
                    ase = true;
                    x = i;
                    break;
                }
            if(!ase)
            {
                x=v.size();
                v.pb(a);
            }
            ase = false;
            for (int i=0; i<v.size(); i++)
                if(a==v[i])
                {
                    ase = true;
                    y=i;
                    break;
                }
            if(!ase)
            {
                y=v.size();
                v.pb(b);
            }
            graph1[x][y]=true;
        }
        d = v.size();
        scanf("%d ", &m);
//        cout<<"m = "<<m<<endl;
        l = m;
        clr(graph2,false);
        while(l--)
        {
//            cout<<l<<endl;
//            cout<<" "<<a<<" "<<b<<endl;
            scanf("%c %c ", &a, &b);

            for (int i=0; i<d; i++)
                if(a==v[i])
                {
                    x=i;
                    break;
                }
            for (int i=0; i<d; i++)
                if(a==v[i])
                {
                    y=i;
                    break;
                }
            graph2[x][y]=true;
        }
//        cout<<"here";
        Floyed(graph1);
        Floyed(graph2);
        ase = true;
        for (int i=0; i<d; i++)
            for (int j=0; j<d; j++)
                if(graph1[i][j]!=graph2[i][j])
                {
                    ase = false;
                    break;
                }
        if(ase) printf("YES\n");
        else printf("NO\n");
        if(t) puts("");
    }

    return 0;
}

void Floyed(bool graph[sz][sz])
{
    int i, j, k;
    for (k=0; k<d; k++)
        for (i=0; i<d; i++)
            for (j=0; j<d; j++)
                graph[i][j] = (graph[i][k]&graph[k][j])|graph[i][j];
    return;
}
