#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <fstream>

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)

using namespace std;

class TrafficCongestionDivTwo {
public:
    ll dp[70];
    ll rec(ll n)
    {
        ll &ret = dp[n];
        if(dp[n]!=-1) return ret;
        ret = rec(n-1) + 2 * rec(n-2);
        return ret;
    }
	long long theMinCars(int treeHeight) {
		clr(dp,-1);
		dp[0] = 1;
        dp[1] = 1;
        return rec(treeHeight);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	TrafficCongestionDivTwo *obj;
	long long answer;
	obj = new TrafficCongestionDivTwo();
	clock_t startTime = clock();
	answer = obj->theMinCars(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	long long p1;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 3ll;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 5ll;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 10;
	p1 = 683ll;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 60;
	p1 = 768614336404564651ll;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// There are some cities and some roads connecting them together.
// The road network has the topology of a perfect binary tree (see below for a picture), in which the cities are nodes and the roads are edges.
//
// You are given the int treeHeight giving the height of the tree.
// (The height of a perfect binary tree is the number of edges on the path between the root node and any leaf node.)
// Thus, there are 2^(treeHeight+1)-1 cities and 2^(treeHeight+1)-2 roads in total.
//
// The picture below shows how the road network looks like when treeHeight = 2.
//
//
//
// We want to send some cars into the road network.
// Each car will be traveling from its starting city to its destination city without visiting the same city twice.
// (Note that the route of each car is uniquely determined by its starting and its destination city.)
// It is possible for the starting city to be equal to the destination city, in that case the car only visits that single city.
//
// Our goal is to send out the cars in such a way that each city will be visited by exactly one car. Compute and return the smallest number of cars we need in order to do so.
//
//
// DEFINITION
// Class:TrafficCongestionDivTwo
// Method:theMinCars
// Parameters:int
// Returns:long long
// Method signature:long long theMinCars(int treeHeight)
//
//
// NOTES
// -The answer will always fit into a 64-bit signed integer data type.
//
//
// CONSTRAINTS
// -treeHeight will be between 0 and 60, inclusive.
//
//
// EXAMPLES
//
// 0)
// 1
//
// Returns: 1
//
// In this case, one car can visit all the cities.
//
//
//
//
//
// 1)
// 2
//
// Returns: 3
//
// Here is one way to visit all cities exactly once by three cars:
//
//
//
//
// 2)
// 3
//
// Returns: 5
//
//
//
// 3)
// 10
//
// Returns: 683
//
//
//
// 4)
// 60
//
// Returns: 768614336404564651
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
