#include <bits/stdc++.h>

#define all(a)           a.begin(),a.end()
#define chng(a,b)       a^=b^=a^=b;
#define clr(y,z)        memset(y,z,sizeof(y))
#define cntbit(mask)     __builtin_popcount(mask)
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define fr(i,a,b)       for(i=a;i<=b;i++)
#define inf             (1e9)
#define mod             1000000007
#define ll              long long
#define oo              (1<<30)
#define pb              push_back
#define PI              3.141592653589793
#define pi              (2*acos(0))
#define pp              pop_back
#define rev(a)          reverse(all(a));
#define SIZE(s)         ((int)s.size())
#define saja(a)         sort(all(a))
#define sqr(a)          ((a)*(a))
#define SZ              50005
#define V(a)            vector<(a)>

using namespace std;


class GoodSubset {
public:

    vector<int>a;
    ll dp[200];

int coin_change(int n,int target)
{
    for (int i = 0; i<200; i++)
        dp[i]=0ll;

    dp[0]=1ll;
    for (int i = 0,j; i<n; i++)
    {
        j = a[i];
        while(j<=target)
        {
            dp[j]=(dp[j]*dp[(j - a[i])])%mod;
            j++;
        }
    }
    return dp[target]%mod;
}


	int numberOfSubsets(int goodValue, vector <int> d) {
		int n = d.size(), seq=0;
		ll now, cnt=0ll;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	GoodSubset *obj;
	int answer;
	obj = new GoodSubset();
	clock_t startTime = clock();
	answer = obj->numberOfSubsets(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	vector <int> p1;
	int p2;

	{
	// ----- test 0 -----
	p0 = 10;
	int t1[] = {2,3,4,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 6;
	int t1[] = {2,3,4,5,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 1;
	int t1[] = {1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 7;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 12;
	int t1[] = {1,2,3,4,5,6,7,8,9,10,11,12};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 5;
	int t1[] = {1,2,3,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
//
// You have some cards, each containing a positive integer.
// You are given a vector <int> d.
// Each element of d is one of those integers.
// The integers are not necessarily distinct.
//
//
//
// You are also given an int goodValue.
// You are interested in non-empty subsets of cards with the following property:
// The product of integers written on those cards is exactly equal to goodValue.
//
//
//
// Let X be the number of subsets with the above property.
// Compute and return the value (X modulo 1,000,000,007).
//
//
// DEFINITION
// Class:GoodSubset
// Method:numberOfSubsets
// Parameters:int, vector <int>
// Returns:int
// Method signature:int numberOfSubsets(int goodValue, vector <int> d)
//
//
// CONSTRAINTS
// -goodValue will be between 1 and 2,000,000,000, inclusive.
// -d will contain between 1 and 100 elements, inclusive.
// -Each element of d will be between 1 and 2,000,000,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 10
// {2,3,4,5}
//
// Returns: 1
//
// There is only one good subset:{2,5}.
//
// 1)
// 6
// {2,3,4,5,6}
//
// Returns: 2
//
// There are two good subsets: {2,3} and {6}.
//
// 2)
// 1
// {1,1,1}
//
// Returns: 7
//
// All non-empty subsets of this set of cards are good.
//
// 3)
// 12
// {1,2,3,4,5,6,7,8,9,10,11,12}
//
// Returns: 6
//
//
//
// 4)
// 5
// {1,2,3,4}
//
// Returns: 0
//
//
//
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
