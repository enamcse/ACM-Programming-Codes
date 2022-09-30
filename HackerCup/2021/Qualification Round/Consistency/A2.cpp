/**
* C:\Users\maqas\Dropbox\Code\HackerCup\2021\Qualification Round\Consistency\A2.cpp
* Created on: 2021-08-29-06.03.57, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
#define sz 4050
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("inputA2.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<28)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

int adj[26][26];

void init()
{
	for (size_t i = 0; i < 26; i++)
	{
		for (size_t j = 0; j < 26; j++)
		{
			if (i==j) adj[i][j] = 0;
			else adj[i][j] = 50;
		}
	}
}

void floyed()
{
	for (size_t i = 0; i < 26; i++)
	{
		for (size_t j = 0; j < 26; j++)
		{
			for (size_t k = 0; k < 26; k++)
			{
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
			
		}
		
	}
	
}

int main()
{
//#ifdef ENAM
      fread;
//  fwrite;
//#endif // ENAM
	_
	int cas = 1,t,n,x,y,k;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
	char s[sz], edge[sz];

	scanf("%d", &n);

	for (size_t i = 0; i < n; i++)
	{
		init();
		scanf(" %s %d", s, &k);
		for (size_t j = 0; j < k; j++)
		{
			scanf(" %s", edge);
			adj[edge[0]-'A'][edge[1]-'A'] = 1;
		}
		floyed();
		int cost = inf, m = strlen(s);
		char res = 'A';
		for (size_t cur = 0; cur < 26; cur++)
		{
			int curCost = 0;
			bool flag = true;
			for (size_t j = 0; j < m; j++)
			{
				if (adj[j][cur]>=26)
				{
					flag = false;
					break;
				}
				curCost += adj[j][cur];
			}
			if (flag && curCost<cost)
			{
				cost = curCost;
				res = 'A'+cur;
			}
		}
		printf("Case #%d: %d\n", i+1, (cost==inf?-1:cost));
	}

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
