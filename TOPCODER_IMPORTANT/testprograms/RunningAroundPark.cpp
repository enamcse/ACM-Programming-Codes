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


class RunningAroundPark {
public:
	int numberOfLap(int N, vector <int> d) {
		int cnt = 1;
		int pre = d[0];
		for (int i = 1; i<d.size(); i++)
        {
            if(d[i]<=pre)
            {
               cnt++;
               pre = d[i];
            }
            else pre = d[i];
        }

		return cnt;
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
	RunningAroundPark *obj;
	int answer;
	obj = new RunningAroundPark();
	clock_t startTime = clock();
	answer = obj->numberOfLap(p0, p1);
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
	p0 = 3;
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 24;
	int t1[] = {6,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 3;
	int t1[] = {3,2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 50;
	int t1[] = {1,3,5,7,9,2,4,6,8,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
// Alice went jogging around the park yesterday.
// There is a circular track around the park, and Alice's house is right next to the track.
// Alice ran in the clockwise direction.
// She both started and ended her run at her house.
// In other words, she completed some positive number of full laps.
//
//
//
// There are N trees along the track.
// The trees are numbered 1 through N in the order in which Alice encounters them when running a single lap.
// You are given the int N.
//
//
//
// Alice remembers some trees she saw during her run.
// She remembers them in the order in which she encountered them.
// You are given this information as a vector <int> d.
//
//
//
// For example, d={6,6,1} has the following meaning:
//
// Alice started running.
// After some time she encountered the tree number 6.
// After some more time she encountered the tree number 6.
// Even later she encountered the tree number 1.
//
//
//
//
// Compute and return the smallest possible number of laps Alice completed.
//
//
// DEFINITION
// Class:RunningAroundPark
// Method:numberOfLap
// Parameters:int, vector <int>
// Returns:int
// Method signature:int numberOfLap(int N, vector <int> d)
//
//
// CONSTRAINTS
// -N will be between 2 and 50, inclusive.
// -d will contain between 1 and 50 elements.
// -Each element of d will be between 1 and N, inclusive.
//
//
// EXAMPLES
//
// 0)
// 3
// {1,2,3}
//
// Returns: 1
//
// It is possible that Alice ran just a single lap and remembered all the trees she saw.
//
// 1)
// 24
// {6,6}
//
// Returns: 2
//
// Alice ran past the tree number 6 at least twice, so there must have been at least two laps.
//
// 2)
// 3
// {3,2,1}
//
// Returns: 3
//
//
//
// 3)
// 50
// {1,3,5,7,9,2,4,6,8,10}
//
// Returns: 2
//
//
//
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!