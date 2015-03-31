/**
* H:\Dropbox\Code\CodeChef\2015 February Challenge\STRQ Chef and Strings.cpp
* Created on: 2015-02-12-03.30.44, Thursday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define sz 1000005
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

char line[sz];
ll cum[16][sz];

int main()
{
#ifdef ENAM
    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m=0, i,j;
	scanf("%s", line);
	n = strlen(line);

	for (i = 0; i<n; i++)
    {
        for (j = 0; j<16; j++)
            cum[j][i+1]+=cum[j][i];

        if(line[i]=='c')
        {
            cum[0][i+1]++;
            cum[7][i+1]+=cum[1][i+1];
            cum[10][i+1]+=cum[3][i+1];
            cum[13][i+1]+=cum[2][i+1];
        }
        else if(line[i]=='h')
        {
            cum[1][i+1]++;
            cum[4][i+1]+=cum[0][i+1];
            cum[11][i+1]+=cum[3][i+1];
            cum[14][i+1]+=cum[2][i+1];
        }
        else if(line[i]=='e')
        {
            cum[2][i+1]++;
            cum[5][i+1]+=cum[0][i+1];
            cum[8][i+1]+=cum[1][i+1];
            cum[12][i+1]+=cum[3][i+1];
        }
        else ///if(line[i]=='f')
        {
            cum[3][i+1]++;
            cum[6][i+1]+=cum[0][i+1];
            cum[9][i+1]+=cum[1][i+1];
            cum[15][i+1]+=cum[2][i+1];
        }
    }

    scanf("%d", &m);
    char a, b;
    int l,r;
    ll ans=0;
    for (i=0; i<m; i++)
    {
        scanf(" %c %c %d %d", &a, &b, &l, &r);
        if(a=='c')
        {
            if(b=='h')
            {
                ans=(cum[4][r]-cum[4][l-1]);
                ans-=((cum[1][r]-cum[1][l-1])*(cum[0][l-1]));
            }
            else if(b=='e')
            {
                ans=(cum[5][r]-cum[5][l-1]);
                ans-=((cum[2][r]-cum[2][l-1])*(cum[0][l-1]));
            }
            else ///if(b=='f')
            {
                ans=(cum[6][r]-cum[6][l-1]);
                ans-=((cum[3][r]-cum[3][l-1])*(cum[0][l-1]));
            }
        }
        else if(a=='h')
        {
            if(b=='c')
            {
                ans=(cum[7][r]-cum[7][l-1]);
                ans-=((cum[0][r]-cum[0][l-1])*(cum[1][l-1]));
            }
            else if(b=='e')
            {
                ans=(cum[8][r]-cum[8][l-1]);
                ans-=((cum[2][r]-cum[2][l-1])*(cum[1][l-1]));
            }
            else ///if(b=='f')
            {
                ans=(cum[9][r]-cum[9][l-1]);
                ans-=((cum[3][r]-cum[3][l-1])*(cum[1][l-1]));
            }
        }
        else if(a=='f')
        {
            if(b=='c')
            {
                ans=(cum[10][r]-cum[10][l-1]);
                ans-=((cum[0][r]-cum[0][l-1])*(cum[3][l-1]));
            }
            else if(b=='h')
            {
                ans=(cum[11][r]-cum[11][l-1]);
                ans-=((cum[1][r]-cum[1][l-1])*(cum[3][l-1]));
            }
            else ///if(b=='e')
            {
                ans=(cum[12][r]-cum[12][l-1]);
                ans-=((cum[2][r]-cum[2][l-1])*(cum[3][l-1]));
            }
        }
        else ///if(a=='e')
        {
            if(b=='c')
            {
                ans=(cum[13][r]-cum[13][l-1]);
                ans-=((cum[0][r]-cum[0][l-1])*(cum[2][l-1]));
            }
            else if(b=='h')
            {
                ans=(cum[14][r]-cum[14][l-1]);
                ans-=((cum[1][r]-cum[1][l-1])*(cum[2][l-1]));
            }
            else ///if(b=='f')
            {
                ans=(cum[15][r]-cum[15][l-1]);
                ans-=((cum[3][r]-cum[3][l-1])*(cum[2][l-1]));
            }
        }
        printf("%lld\n", ans);
    }
   return 0;
}
