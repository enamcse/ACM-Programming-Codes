/*
* @Author: Enamul Hassan
* @Date:   2015-03-24 01:02:08
* @Last Modified by:   Enamul
* @Last Modified time: 2015-03-24 02:15:55
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\lightoj\1310 - Tiles (III).cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int n, m;
bool flip;
char line[105][105];
int dp[105][(1 << 8)][(1<<8)];
int rec(int pos, int mask, int mask2);

int gen(int pos, int mask, int mask2, int mask3)
{
	int ret = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (!((1 << i)&mask))
		{
			if (i + 1 < n  && pos + 2 < m)
			{
				if (!((1 << (i + 1))&mask) && !((1 << i)&mask2)&& !((1 << (i + 1))&mask2) 
					&& !((1 << i)&mask3) && !((1 << (i + 1))&mask3) )
					ret = max(ret, 1+gen(pos, mask | (1 << i) | (1 << (i + 1)),
						mask2 | (1 << i) | (1 << (i + 1)),mask3 | (1 << i) | (1 << (i + 1))));
			}
			if (i + 2 < n  && pos + 1 < m)
			{
				if (!((1 << (i + 1))&mask) && !((1 << (i + 2))&mask) 
					&& !((1 << i)&mask2) && !((1 << (i + 1))&mask2) && !((1 << (i + 2))&mask2) ) 
					ret = max(ret, 1+gen(pos, mask | (1 << i) | (1 << (i + 1))| (1 << (i + 2)),
						mask2 | (1 << i) | (1 << (i + 1)) | (1 << (i + 2)),mask3));
			}
		}
	}
	ret = max(ret,rec(pos + 1, mask2, mask3));
	return ret;
}

int rec(int pos, int mask, int mask2)
{

	if (pos == m)
	{
		return 0;
	}
	int &ret = dp[pos][mask][mask2];
	if (ret!=-1) return ret;

	int n_mask = 0;


	for (int i = 0; i < n; ++i)
	{
		/* code */
		if (line[i][pos + 2] == '#') n_mask |= (1 << i);
	}

	if (pos >= m - 2) n_mask = 0;
	ret = gen(pos, mask, mask2, n_mask);
	return ret;
}


int main() {
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
	int t, cas = 1, mask, mask2;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; ++i)
		{
			/* code */
			scanf("%s", line[i]);
		}

		mask=mask2=0;
		for (int i = 0; i < n; ++i)
		{
			/* code */
			if (line[i][0] == '#') mask |= (1 << i);
		}

		for (int i = 0; i < n; ++i)
		{
			/* code */
			if (line[i][1] == '#') mask2 |= (1 << i);
		}
		clr(dp, -1);

		printf("Case %d: %d\n", cas++, rec(0, mask,mask2));
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

	return 0;
}

/*
1
2 3
..#
...
*/