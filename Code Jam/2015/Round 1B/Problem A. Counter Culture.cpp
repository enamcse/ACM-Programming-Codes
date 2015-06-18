/* 
* @Author: Enamul Hassan
* @Date:   2015-05-02 22:02:32
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-03 07:38:14
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\Code Jam\2015\Round 1B\Problem A. Counter Culture.cpp
* @Problem Link: https://code.google.com/codejam/contest/8224486/dashboard#s=p0
* @Concept: Lets take the input number as string, say s, and n it's length, n = |s|.
		Now, we would classify the cases into two types. They are:
			1. n <= 2
			2. n > 2
		1. That means the number ranges from 1 to 99. This range could be classified
		into two.
			a. s <= 20, answer would be s (output = input).
			b. s > 20, these numbers would be classified into two too!
				i. expept tens (21,22,23, ..., 29,31,32,..., 99)
				ii. tens (30,40,50,...,90)
			
			i. The values except tens could be reached easily by a silly technique.
			From the values 12, 13, 14, 15, 16, 17, 18 and 19 we can easily get 21, 31,
			41, 51, 61, 71, 81, 91. Then, from these values, we can go the desired number.
			Let m be the number representation of the string s and k is a number defined
			by m/10 (integer division) or k = floor(m/10). The result would be then
			10 + k + 1 + m - (k * 10 + 1). Confused??
			Ok, an example may clear the scenario. Lets take 99. To reach 99, we have to
			reach 51 first and to reach 51, we have to reach 15 first. At first, our
			answer x = 0. we could easily reach 15 by adding 10 + floor(99/10), where
			floor(99/10) is actually k for 99 and k = 9 here. So, we are standing on 19
			and x = 10 + 9 = 19. we can easily go to 91 from 19 by reversing the number
			with adding 1 to x, x = 20. Now, only the m - (k * 10 + 1) part is remaining.
			It is just the difference from our source, 91, to our destination 99. m = 99
			and (k * 10 + 1) = 91 is our current position. So, x = 20 + 99 - 91 = 28.
			But what we would do, if m = 50? Lets see in the next section.

			ii. For m = 50, we have no way to count back from 51. The optimal way is to
			count from 41. For 50, we have to go 41 instead of 51. To ensure this, we have
			to make a slight change in our previous formula. To calculate k, we would deduct
			one from m so that it would take the same value of k for the number 49 and 50.
			That means, k = floor((m-1)/10).
		
		2. Lets talk about length 3 and higher. We would also classify this part into two
		like previous parts, but before that we have to think about some observations.
		Lets observe, how could we reach a number whose length is n+1 from a number having
		length n? There is no other way except counting the first number of length n+1 after
		counting the last number of length n. That means if we want to reach a number of
		length n, we have to complete all its lower lengths. So, how can we reach 100? 
		ofcourse form 99! and we calculated the cost to reach 99, which is 28. Thus the
		cost to reach 100 is 29. Now, the problem is sub-divided into two parts:
			a. calculating the cost to reach the minimum number of length n.
			b. calculating the cost to reach the desired number from the minimum number
			of length n.

			a. we would write a function which would take a parameter length, x and would
			return the cost for reaching the lowest number of length x from the highest
			number of length x-1. This function would be called for all numbers range from
			3 to n (Actually from 1 to n, but we already calculated for 3).

			In the function, we would return 29 for x = 3, otherwise, we would divide 
			the problem into two as I metioned before!
				i. even length to odd length, x = 3, 5, 7, ...
				ii. odd length to even length, x = 4, 6, 8, ...

				i. How could we reach from 1000 to 10000? Lets see:
					1. 1000 to 1099 costing 99.
					2. 1099 to 9901 costing 1.
					3. 9901 to 9999 costing 98.
					Total cost = (200 - 2) = 2 * (10 ^ 2) - 2
				More generally, Cost = 2 * (10 ^ ceil(x/2)) - 2

				ii. Now, How could we reach from 10000 to 100000? Lets see:
					1. 10000 to 10999 costing 999.
					2. 10999 to 99901 costing 1.
					3. 99901 to 99999 costing 99.
					Total cost = 1000 + 99 = 10^3 + 10^2 - 1
				More generally, Cost = (10 ^ (x/2)) + (10 ^ (x/2 - 1)) - 1

			b. Now, we already reached the minimum number of length n,let it is p. now, 
			we have to reach s. we would divide the number s into two equal length number 
			s1 and s2. For odd length s2 would have length one greater than s1. s1 is the
			MSB half and s2 is the LSB half of s. lets s3 a reverse string of s1. So now,
			we would count s3 from p. Then we would reverse it with	cost 1 and then we 
			would count one less than s2. If s3 is equal to 1, then	there is no need to 
			play with s3 as well as reversing.
			Not clear, right?
			Example may clear the scene: Say s = 46787751231. p = 10000000000.
			s1 = 46787, s2 = 751231. So, s3 = 78764.
			Now, count s3 times, p = 10000000000 to 10000078764, cost = 78764.
			reverse with cost 1, p = 10000078764 to 46787000001, cost = 78765.
			count s2 times, p = 46787000001 to 46787751231, cost = 829995.
			Another example: s = 100552, p = 100000.
			s1 = 100, s2 = 552. So, s3 = 001 = 1.
			s3 is equal to 1, so only the last operation:
			count s2 times, p = 100000 to 100552, cost = 552.
			
			Hope all things we have covered. What do you thing? could we cover all cases?
			i think no! what do you do for s = 1100 or 11000?
			The case is that, if there exist ceil(n/2) or more trailing zeros in s, 
			then this problem would be taken place. We would handle it now.we would 
			decrease one from s and would calculate the	result. Finally we would add
			one in the result. Remember, we would not handle 10000 or 100000 or such
			cases, one leading one with all other digits equal to 0, because it would
			be handled previously.
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define ll long long
#define fread freopen("A-large-practice.in","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

ll getbydefault(int n)
{
	if(n==3) return 29;
	int m = n/2;
	ll a,b;
	a=b=0;

	if(n%2)
	{
		for (int i = 0; i < m; ++i)
		{
			a*=10;
			a+=9;
		}
		b=a;
	}
	else
	{
		for (int i = 1; i < m; ++i)
		{
			a*=10;
			a+=9;
		}
		b=a*10+9;
	}
	return a+b+1;
}


ll calc(string s)
{
	ll m=0;
	sscanf(s.c_str(),"%lld", &m);
	if(m<=20) return m;
	ll ret = 10, k;
	k = (m-1)/10;
	ret+=(k+1);
	ret+=abs(k*10+1-m);
	return ret;
}

int main(){
	#ifdef ENAM
   	fread;
	fwrite;
#endif // ENAM
    ll n,t, m, cas=1;
    ll  ans;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s, s1;
    bool flag;
	cin>>t;

	while(t--)
	{
		flag = false;
		cin>>s;
		n = s.size();
		ans = 0;
		if(n<=2)
		{
			ans = calc(s);
		}
		else
		{
			if(s[0]=='1')
			{
				flag = true;
				for (int i = 1; i < n; ++i)
				{
					if(s[i]!='0')
					{
						flag = false;
						break;
					}
				}
			}
			else flag = false;
			
			if(flag) flag = false;
			else
			{
				int i,z=0;
				for (i = n-1; i >=0; --i)
				{
					if(s[i]=='0') z++;
					else break;
				}
				if(z>=(n+1)/2) flag = true;
				else flag = false;
			}

			if(flag)
			{
				int z = n - 1;
				while(1)
				{
					if(s[z]=='0') s[z--]='9';
					else
					{
						s[z]--;
						break;
					}
				}
			}


			for (int i = 3; i <= n; ++i)
			{
				ans+=getbydefault(i);
			}
			m=0;
			sscanf(s.substr(n/2).c_str(),"%lld", &m);
			ans+=m;
			m=0;
			for (int i = (n/2)-1; i >=0; --i)
			{
				m*=10;
				m+=(s[i]-'0');
			}
			if(m!=1) ans+=m;
			if(flag) ans++;
		}
		
		cout<<"Case #"<<cas++<<": "<<ans<<"\n";
	}


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
