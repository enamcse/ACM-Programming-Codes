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

class KiloMan {
public:
	int hitsTaken(vector <int> pattern, string jumps) {
		int n = pattern.size(), hits=0;
		for (int i = 0; i<n; i++)
        {
            if(jumps[i]=='J'&&pattern[i]>2) hits++;
            else if (jumps[i]=='S'&&pattern[i]<=2) hits++;
        }
        return hits;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, string p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	KiloMan *obj;
	int answer;
	obj = new KiloMan();
	clock_t startTime = clock();
	answer = obj->hitsTaken(p0, p1);
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
	string p1;
	int p2;

	{
	// ----- test 0 -----
	int t0[] = {1,3,2,3,3,1,2,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "JJSSSJSSJ";
	p2 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "SSSSSSSSSSSSSSJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ";
	p2 = 49;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {1,2,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "SJJS";
	p2 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "J";
	p2 = 0;
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
// You've reached one of the last bosses in the new hit 2-D side-scrolling action game, KiloMan.  The boss has a large gun that can shoot projectiles at various heights.  For each shot, KiloMan can either stand still or jump.  If he stands still and the shot is at height 1 or 2, then he gets hit.  If he jumps and the shot is at a height above 2, then he is also hit.  Otherwise, he is not hit.  Given the height of each shot and a sequence of jumps, how many hits will KiloMan take?
//
// The input vector <int> pattern is the pattern of heights at which the shots are being fired.  Each element of pattern will be between 1 and 7, inclusive.  The input string jumps is the sequence of jumps that KiloMan will attempt; 'J' means he will jump and 'S' means he will stand still. For example, if element 0 of pattern is 3 and character 0 of jumps is 'J', then KiloMan will jump right as a shot is fired at height 3 (and thus he will be hit).
//
// Your method should return an int representing the number of times KiloMan is hit.
//
// DEFINITION
// Class:KiloMan
// Method:hitsTaken
// Parameters:vector <int>, string
// Returns:int
// Method signature:int hitsTaken(vector <int> pattern, string jumps)
//
//
// CONSTRAINTS
// -pattern will contain between 1 and 50 elements, inclusive.
// -each number in pattern will be between 1 and 7, inclusive.
// -the number of characters in jumps will be the same as the number of elements in pattern
// -each character of jumps will be either 'S' or 'J'.
//
//
// EXAMPLES
//
// 0)
// {1,3,2,3,3,1,2,2,1}
//
// "JJSSSJSSJ"
//
// Returns: 4
//
// The first shot is at height 1, and KiloMan jumps it successfully. Then he jumps into a shot at height 3.  KiloMan takes three more hits while standing against shots at height 2.
//
// 1)
// {1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,
//  4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7}
// "SSSSSSSSSSSSSSJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ"
//
// Returns: 49
//
// KiloMan stands still at all the wrong times and jumps at all the wrong times, taking all 49 hits.
//
// 2)
// {1,2,2,1}
//
// "SJJS"
//
// Returns: 2
//
// Since everything was shot at height 2 or less, he should have jumped everything.
//
// 3)
// {1}
// "J"
//
// Returns: 0
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
