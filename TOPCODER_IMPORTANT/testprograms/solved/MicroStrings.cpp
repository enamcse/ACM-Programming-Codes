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

class MicroStrings {
public:
	string makeMicroString(int A, int D) {
		int temp=A;
		string s="";
		char line[10];
		while(temp>=0)
        {
            sprintf(line,"%d",temp);
            s+=line;
            temp-=D;
        }
        return s;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	MicroStrings *obj;
	string answer;
	obj = new MicroStrings();
	clock_t startTime = clock();
	answer = obj->makeMicroString(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	int p1;
	string p2;

	{
	// ----- test 0 -----
	p0 = 12;
	p1 = 5;
	p2 = "1272";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = "31";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 31;
	p1 = 40;
	p2 = "31";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 30;
	p1 = 6;
	p2 = "3024181260";
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
// John couldn't handle long strings so he came up with the idea of MicroStrings.
//
// You are given two positive ints: A and D. These determine an infinite decreasing arithmetic progression: A, A-D, A-2D, and so on. Clearly, only finitely many elements of such a progression are non-negative.
//
// Each such progression defines one MicroString, as follows: You take all the non-negative elements, convert each of them into a string, and then concatenate those strings (in order).
//
// For example, let A=12 and D=5. For these values we get the arithmetic progression (12, 7, 2, -3, -8, ...). The non-negative elements are 12, 7, and 2. The corresponding strings are "12", "7", and "2". Their concatenation is the following MicroString: "1272".
//
// Given A and D, return the MicroString they define.
//
// DEFINITION
// Class:MicroStrings
// Method:makeMicroString
// Parameters:int, int
// Returns:string
// Method signature:string makeMicroString(int A, int D)
//
//
// NOTES
// -When converting a number to a string, the string must not have unnecessary leading zeros.
//
//
// CONSTRAINTS
// -A will be between 1 and 200, inclusive.
// -D will be between 1 and 200, inclusive.
//
//
// EXAMPLES
//
// 0)
// 12
// 5
//
// Returns: "1272"
//
// This is the example from the problem statement.
//
// 1)
// 3
// 2
//
// Returns: "31"
//
//
//
// 2)
// 31
// 40
//
// Returns: "31"
//
//
//
// 3)
// 30
// 6
//
// Returns: "3024181260"
//
// The number 0 is also non-negative. When we convert it into a string, we get the string "0".
//
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
