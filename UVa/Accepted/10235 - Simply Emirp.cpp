/* 
* @Author: Enamul Hassan
* @Date:   2015-05-02 01:34:13
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-02 01:56:13
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\10235 - Simply Emirp.cpp
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

#define sz 1000100
ll col[sz/64+10];
int prime[sz], cnt;

void seive()//1 indexed
{
    long long i,j;
    for(i=3;i<sz;i+=2)
         if(!(col[i/64]&(1LL<<(i%64))))
                for(j=i*i;j<sz;j+=2*i)
                    col[j/64]|=(1LL<<(j%64));

    prime[cnt++]=2;
    for (int i = 3; i<sz; i+=2)
        if(!(col[i/64]&(1LL<<(i%64))))
            prime[cnt++] = i;
}

bool is_prime(ll i)
{
    if(i==2) return true;
    if(i%2==0) return false;
    if(!(col[i/64]&(1LL<<(i%64)))) return true;
    return false;
}


int main(){
	#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int  n, m, k;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    seive();

	while(~scanf("%d", &n))
	{
		printf("%d is ", n);
		if(is_prime(n))
		{
			m=0;
			k=n;
			while(n)
			{
				m*=10;
				m+=(n%10);
				n/=10;
			}
			if(k!=m&&is_prime(m)) puts("emirp.");
			else puts("prime.");
		}
		else puts("not prime.");
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}












