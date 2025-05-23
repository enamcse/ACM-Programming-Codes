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

class OneDimensionalRobotEasy {
public:
	int finalPosition(string commands, int A, int B) {
		int len = commands.size();
		int pos = 0;
		A = -A;
		for (int i = 0; i<len; i++)
        {
            if(commands[i]=='R')
            {
                if(pos!=B) pos++;
            }
            else if(commands[i]=='L')
            {
                if(pos!=A) pos--;
            }
        }
        return pos;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1 << "," << p2;
	cout << "]" << endl;
	OneDimensionalRobotEasy *obj;
	int answer;
	obj = new OneDimensionalRobotEasy();
	clock_t startTime = clock();
	answer = obj->finalPosition(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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

	string p0;
	int p1;
	int p2;
	int p3;

	{
	// ----- test 0 -----
	p0 = "RRLRRLLR";
	p1 = 10;
	p2 = 10;
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "RRRRR";
	p1 = 3;
	p2 = 4;
	p3 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "LLLLLLLLLLR";
	p1 = 2;
	p2 = 6;
	p3 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "RRRRRRRLRRLRRRRRRRRRRRRLRLRRRRRRRRLRRRRRLRRRRRRRRR";
	p1 = 5;
	p2 = 20;
	p3 = 20;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = "RLRLLLLLLLRLLLRLLLLLLLLRLLLLLRLLLRRLLLLLRLLLLLRLLL";
	p1 = 34;
	p2 = 15;
	p3 = -30;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
// A robot is placed on an infinitely long line. Initially the position of the robot is 0. Cat Snuke sends commands to move this robot.
//
//
// You are given a string commands. For each i, the i-th character of commands (0-based index) represents the i-th command Snuke sends. If the i-th character of commands is 'R', the robot moves one unit to the right (i.e., from position x to position x+1). If this character is 'L', the robot moves one unit to the left (i.e., from position x to position x-1). The robot has a built-in safety mechanism that prevents it from going too far and losing the signal. The safety mechanism makes sure that the robot always stays between the positions -A and B, inclusive. If the robot receives the command 'R' when the robot is at B, or the command 'L' when the robot is at -A, the command will be ignored.
//
//
// You are given the string commands and the ints A and B. Return the final position of the robot.
//
// DEFINITION
// Class:OneDimensionalRobotEasy
// Method:finalPosition
// Parameters:string, int, int
// Returns:int
// Method signature:int finalPosition(string commands, int A, int B)
//
//
// CONSTRAINTS
// -commands will contain between 1 and 50 characters, inclusive.
// -Each character in commands will be either 'R' or 'L'.
// -A and B will be between 1 and 50, inclusive.
//
//
// EXAMPLES
//
// 0)
// "RRLRRLLR"
// 10
// 10
//
// Returns: 2
//
// The robot will move as follows: 0 -> 1 -> 2 -> 1 -> 2 -> 3 -> 2 -> 1 -> 2.
//
// 1)
// "RRRRR"
// 3
// 4
//
// Returns: 4
//
// The robot will move as follows: 0 -> 1 -> 2 -> 3 -> 4 -> 4.
//
// 2)
// "LLLLLLLLLLR"
// 2
// 6
//
// Returns: -1
//
// The robot will move as follows: 0 -> -1 -> -2 -> -2 -> -2 -> -2 -> -2 -> -2 -> -2 -> -2 -> -2 -> -1.
//
// 3)
// "RRRRRRRLRRLRRRRRRRRRRRRLRLRRRRRRRRLRRRRRLRRRRRRRRR"
// 5
// 20
//
// Returns: 20
//
//
//
// 4)
// "RLRLLLLLLLRLLLRLLLLLLLLRLLLLLRLLLRRLLLLLRLLLLLRLLL"
// 34
// 15
//
// Returns: -30
//
//
//
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
