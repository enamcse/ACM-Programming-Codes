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

#define sz 100010
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)

using namespace std;

class PackingBallsDiv1 {
public:
    ll X[sz];
	int minPacks(int K, int A, int B, int C, int D) {
		X[0] = A;
        for (int i = 1;i<K;i++)
            X[i] = (X[i-1] * B + C) % D + 1;
        ll mn = K, ret =0;
        for (int i = 0; i<K; i++)
        {
            ret+=X[i]/K;
            X[i]%=K;

        }

        sort(X,X+K);
        reverse(X,X+K);

        for (int i = 0; i<K; i++)
            mn = min(mn,X[i]+i);

        ret+=mn;
        return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	PackingBallsDiv1 *obj;
	int answer;
	obj = new PackingBallsDiv1();
	clock_t startTime = clock();
	answer = obj->minPacks(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;

	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 4;
	p2 = 2;
	p3 = 5;
	p4 = 6;
	p5 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 58;
	p2 = 23;
	p3 = 39;
	p4 = 93;
	p5 = 58;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 23;
	p1 = 10988;
	p2 = 5573;
	p3 = 4384;
	p4 = 100007;
	p5 = 47743;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 100000;
	p1 = 123456789;
	p2 = 234567890;
	p3 = 345678901;
	p4 = 1000000000;
	p5 = 331988732;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
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
// We have balls of K different colors.
// The colors are numbered 0 through K-1, and the number of balls of color i is X[i].
// We want to divide the balls into as few packages as possible.
// Each package must contain between 1 and K balls, inclusive.
// Additionally, each package must be either a "normal set" (all balls in the package have the same color), or a "variety set" (no two balls have the same color).
//
// You are given the int K.
// You are also given ints A, B, C, and D.
// Use these to generate the array X using the following pseudocode:
//
// X[0] = A
// for i = 1 to K-1:
//     X[i] = (X[i-1] * B + C) % D + 1
//
//
// Compute and return the smallest possible number of packages.
//
// DEFINITION
// Class:PackingBallsDiv1
// Method:minPacks
// Parameters:int, int, int, int, int
// Returns:int
// Method signature:int minPacks(int K, int A, int B, int C, int D)
//
//
// NOTES
// -You can assume that the answer will fit into a signed 32-bit integer.
//
//
// CONSTRAINTS
// -K will be between 1 and 100,000, inclusive.
// -B, C and D will be between 1 and 1,000,000,000, inclusive.
// -A will be between 1 and D, inclusive.
//
//
// EXAMPLES
//
// 0)
// 3
// 4
// 2
// 5
// 6
//
// Returns: 4
//
// There are three colors of balls.
// Using the pseudocode in the problem statement, we can compute that X[0]=4, X[1]=2, and X[2]=4.
// As there are 10 balls and we can only put at most 3 into each package, we need at least 4 packages.
// One possible solution with 4 packages is {0,1,2}, {0,0}, {0,1}, and {2,2,2}.
// (That is, the first package contains one ball of each color, the second package contains two balls of color 0, and so on.)
//
// 1)
// 1
// 58
// 23
// 39
// 93
//
// Returns: 58
//
// All the balls have the same color, and each package can only contain one ball. Thus, the number of packages is the same as the number of balls.
//
// 2)
// 23
// 10988
// 5573
// 4384
// 100007
//
// Returns: 47743
//
//
//
// 3)
// 100000
// 123456789
// 234567890
// 345678901
// 1000000000
//
// Returns: 331988732
//
// Watch out for integer overflow when generating X.
//
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!