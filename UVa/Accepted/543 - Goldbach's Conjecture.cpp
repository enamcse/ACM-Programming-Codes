/*
* @Author: Enamul Hassan
* @Date:   2015-05-02 02:28:11
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-02 04:05:40
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\Accepted\543 - Goldbach's Conjecture.cpp
*/

#include <stdio.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000005
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

ll col[sz / 64 + 10];
int prime[sz], cnt;

void seive()//1 indexed
{
	long long i, j;
	for (i = 3; i < sz; i += 2)
		if (!(col[i / 64] & (1LL << (i % 64))))
			for (j = i * i; j < sz; j += 2 * i)
				col[j / 64] |= (1LL << (j % 64));

	for (i = 3; i < sz; i += 2)
		if (!(col[i / 64] & (1LL << (i % 64))))
			prime[cnt++] = i;
}

inline bool is_prime(ll i)
{
	if (!(col[i / 64] & (1LL << (i % 64)))) return true;
	return false;
}


int main() {
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
	int n, m,i;
	// _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
	seive();

	while (~scanf("%d", &n) && n)
	{
		m = (n >> 1);
		for (i = 0; prime[i] <= m; ++i)
			if (is_prime(n - prime[i])) 
				{
					printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
					// cout << n << " = " << prime[i] << " + " << n - prime[i] << "\n"; 
					break;
				}
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

	return 0;
}












