/*
* @Autmor: Enamul massan
* @Date:   2015-03-23 02:34:52
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-24 02:15:10
* @Verdict: Solved
* @File Patm: H:\Dropbox\Code\ligmtoj\1270 - Tiles (II).cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define ll unsigned long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

int n, m;
bool flip;
char line[105][105];
ll dp[105][(1<<8)];
bool visited[105][(1<<8)];

ll rec(int pos, int mask);

ll gen(int pos, int mask, int mask2)
{
	if (mask == (1 << n) - 1) return rec(pos + 1, mask2);

	ll ret = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (!((1 << i)&mask))
		{
			if (i + 1 < n )
			{
				if (!((1 << (i + 1))&mask) ) ret += gen(pos, mask | (1 << i) | (1 << (i + 1)), mask2);
			}
			if (pos + 1 < m)
			{
				if (!((1 << i)&mask2) ) ret += gen(pos, mask | (1 << i), mask2 | (1 << i));
			}
			if (i+1<n && pos + 1 < m)
			{
				if (!((1 << i)&mask2)  && !((1 << (i+1))&mask2)) ret += gen(pos, mask | (1 << i), mask2 | (1 << i) |(1 << (i+1)));
				if (!((1 << i)&mask2)  && !((1 << (i+1))&mask)) ret += gen(pos, mask | (1 << i)|(1 << (i+1)), mask2 | (1 << i) );
				if (!((1 << (i+1))&mask)  && !((1 << (i+1))&mask2)) ret += gen(pos, mask | (1 << i)|(1 << (i+1)), mask2 |(1 << (i+1)));
				
			}
			if(i && pos + 1 < m)
			{
				if (!((1 << i)&mask2)  && !((1 << (i-1))&mask2)) ret += gen(pos, mask | (1 << i), mask2 | (1 << i) |(1 << (i-1)));
			}

			break;
		}
	}
	if (i == n) ret = rec(pos + 1, mask2);
	return ret;
}

ll rec(int pos, int mask)
{
	if (pos == m)
	{
		if (!mask)
			return 1;
		return 0;
	}
	ll &ret = dp[pos][mask];
	if (visited[pos][mask]) return ret;
	visited[pos][mask] = true;
	int n_mask = 0;

	if (flip)
	{
		for (int i = 0; i < n; ++i)
		{
			/* code */
			if (line[pos+1][i] == '#') n_mask |= (1 << i);
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			/* code */
			if (line[i][pos+1] == '#') n_mask |= (1 << i);
		}
	}
	if(pos==m-1) n_mask = 0;
	ret = gen(pos, mask, n_mask);
	return ret;
}


int main() {
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
	int t, cas = 1, mask;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
	scanf("%d", &t);

	while(t--)
	{
		flip = false;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; ++i)
		{
			/* code */
			scanf("%s", line[i]);
		}

		if (n > m) flip = true, swap(n, m);
		mask = 0;
		if (flip)
		{
			for (int i = 0; i < n; ++i)
			{
				/* code */
				if (line[0][i] == '#') mask |= (1 << i);
			}
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				/* code */
				if (line[i][0] == '#') mask |= (1 << i);
			}
		}
		clr(visited,false);

		printf("Case %d: %llu\n",cas++, rec(0,mask));
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

	return 0;
}

/**
1
2 3
..#
...
*/