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

class Soccer {
public:
	int maxPoints(vector <int> wins, vector <int> ties) {
		    int n = wins.size(),mx=0,k;
    for (int i = 0; i<n; i++)
    {
        k = (wins[i]*3) + (ties[i]);
        mx = k>mx?k:mx;
    }
    return mx;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	Soccer *obj;
	int answer;
	obj = new Soccer();
	clock_t startTime = clock();
	answer = obj->maxPoints(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1,4,3,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {3,1,5,3,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 14;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {12,45,20,17,48,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {48,10,53,94,0,100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 145;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {35,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,76};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 105;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,0,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {13,79,26,73,14,89,71,37,89,71,19,59,39};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {88,27,5,70,84,94,20,50,2,11,31,22,50};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 361;
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
// In soccer leagues, the winner of a match is awarded with 3 points and the loser 0 points. In case of a tie, both teams are awarded with 1 point each.
// 
// Create a class Soccer containing the method maxPoints which takes a vector <int> wins, the number of wins for each team in the league, and a vector <int> ties, the number of ties for each team in the league and returns an int, the maximum points a team in the league has. The
// i'th elements of wins and ties correspond to the number of wins and ties respectively for team i.
// 
// DEFINITION
// Class:Soccer
// Method:maxPoints
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int maxPoints(vector <int> wins, vector <int> ties)
// 
// 
// NOTES
// -Two or more teams may have the same number of points.
// 
// 
// CONSTRAINTS
// -wins will contain between 1 and 50 elements, inclusive.
// -ties will contain between 1 and 50 elements, inclusive.
// -wins will contain the same number of elements as ties.
// -Each element in wins will be between 0 and 100, inclusive.
// -Each element in ties will be between 0 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,4,3,0,0}
// {3,1,5,3,1}
// 
// Returns: 14
// 
// The number of points for each team are:
// 
// Team 0: 3*1 + 1*3 = 6 points
// Team 1: 3*4 + 1*1 = 13 points
// Team 2: 3*3 + 1*5 = 14 points
// Team 3: 3*0 + 1*3 = 3 points
// Team 4: 3*0 + 1*1 = 1 point
// 
// So team 2 has the most number of points, 14. The method should thus return 14.
// 
// 
// 1)
// {12,45,20,17,48,0}
// {48,10,53,94,0,100}
// 
// Returns: 145
// 
// Both team 1 and team 3 got 145 points, which is the maximum.
// 
// 2)
// {35,0}
// {0,76}
// 
// Returns: 105
// 
// 3)
// {0,0,0,0}
// {0,0,0,0}
// 
// Returns: 0
// 
// 4)
// {13,79,26,73,14,89,71,37,89,71,19,59,39}
// {88,27,5,70,84,94,20,50,2,11,31,22,50}
// 
// Returns: 361
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!