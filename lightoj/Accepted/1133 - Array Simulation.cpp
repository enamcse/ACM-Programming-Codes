#include <iostream>
#include <cstdio>
using namespace std;

int rev;
int arr[105],n,m;

int main() {
	// your code goes here
	int t,cas=1, l,k,z;
	char doll;
	scanf("%d", &t);
	while(t--)
	{
		rev = 0;
		scanf("%d %d", &n, &m);
		for(int i = 0; i<n;i++)
			scanf("%d", &arr[i]);

		for(int i = 0; i<m;i++)
		{
			scanf(" %c", &doll);
			switch(doll)
			{
				case 'S':
				scanf("%d", &k);
				for(int j = 0;j<n;j++)
					arr[j]+=k;
				break;
				case 'M':
				scanf("%d", &k);
				for(int j = 0;j<n;j++)
					arr[j]*=k;
				break;
				case 'D':
				scanf("%d", &k);
				for(int j = 0;j<n;j++)
					arr[j]/=k;
				break;
				case 'R':
				rev^=1;
				break;
				case 'P':
				scanf("%d %d", &k, &l);
				if(k!=l)
				{
					if(rev)
					{
						z = arr[n-1-k];
						arr[n-1-k] = arr[n-1-l];
						arr[n-1-l] = z;
					}
					else
					{
						z = arr[k];
						arr[k] = arr[l];
						arr[l] = z;
					}
				}
				break;
			}

		}
		printf("Case %d:\n", cas++);
		if(rev)
		{
			for(int i = n - 1;i>=0;i--)
			{
				printf("%d", arr[i]);
				if(i!=0)printf(" ");
			}
		}
		else
		{
			for(int i = 0;i<n;i++)
			{
				printf("%d", arr[i]);
				if(i!=n-1)printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
