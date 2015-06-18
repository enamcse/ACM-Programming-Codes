/* 
* @Author: Enamul Hassan
* @Date:   2015-04-04 01:50:03
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-04 06:19:48
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\12439 - February 29.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

char months[12][20] = {"January", "February", "March", "April", "May", "June", "July",
"August", "September", "October", "November", "December"};
int mm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

inline bool check(int y)
{
	if(y%400==0) return true;
	if(y%100==0) return false;
	if(y%4==0) return true;
	return false;
}

int main(){
	#ifdef ENAM
   	fread;
	fwrite;
#endif // ENAM
    int t, cas=1;
    ll ans;
    int m[2], d[2];
    ll y[2];
    char line[30];
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    for (int i = 1; i < 13; ++i)
    	mm[i]+=mm[i-1];

	scanf("%d", &t);

	while(t--)
	{
		ans = 0;
		scanf(" %s %d, %lld", line, &d[0], &y[0]);
		for (int i = 0; i < 12; ++i)
		{
			if(!strcmp(line,months[i]))
			{
				m[0] = i;
				break;
			}
		}
		d[0]+= mm[ m[0] ];
		if(m[0]>=2&&check(y[0])) d[0]++;

		scanf(" %s %d, %lld", line, &d[1], &y[1]);
		for (int i = 0; i < 12; ++i)
		{
			if(!strcmp(line,months[i]))
			{
				m[1] = i;
				break;
			}
		}
		d[1]+= mm[ m[1] ];
		if(m[1]>=2&&check(y[1])) d[1]++;

		if(y[1]-y[0]<2000)
		{
			for (int i = y[0]; i <= y[1]; ++i)
			{
				if(check(i))
				{
					if(i==y[0] && i ==y[1])
					{
						if(d[0]<=60&&d[1]>=60) ans++;
					}
					else if(i==y[0])
					{
						if(d[0]<=60) ans++;
					}
					else if(i==y[1])
					{
						if(d[1]>=60) ans++;
					}
					else ans++;
				}
			}
		}
		else
		{
			if(check(y[0]++)) if(d[0]<=60) ans++;
			// cerr<<ans<<"::"<<endl;
			while((y[0]-1)%400!=0)
			{
				if(check(y[0]))
				{
					ans++;
				}
				y[0]++;
			}
			y[0]--;
			if(check(y[1]--)) if(d[1]>=60) ans++;
			while(y[1]%400!=0)
			{
				if(check(y[1]))
				{
					ans++;
				}
				y[1]--;
			}
			if(y[1]==y[0]) assert(false);
			ans+=( ( (y[1]-y[0])/400LL ) * 97LL );
		}
		printf("Case %d: %lld\n",cas++, ans);
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}

/**
4
January 12, 2012
March 19, 2012
August 12, 2899
August 12, 2901
August 12, 2000
August 12, 2005
February 29, 2004
February 29, 2012
*/










