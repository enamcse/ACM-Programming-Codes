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

using namespace std;


class TemperatureScales2 {
public:
	double convert(int f1, int b1, int f2, int b2, int t) {
		double tt;
        tt = ((double) ((b2-f2) *(t - f1)))/ ((double) (b1 - f1)) + (double) f2;
        return tt;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, double p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	TemperatureScales2 *obj;
	double answer;
	obj = new TemperatureScales2();
	clock_t startTime = clock();
	answer = obj->convert(p0, p1, p2, p3, p4);
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
		res = answer == answer && fabs(p5 - answer) <= 1e-9 * max(1.0, fabs(p5));
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
	double p5;

	{
	// ----- test 0 -----
	p0 = 0;
	p1 = 100;
	p2 = 0;
	p3 = 100;
	p4 = 28;
	p5 = 28.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 0;
	p1 = 100;
	p2 = 1;
	p3 = 101;
	p4 = 28;
	p5 = 29.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = -1000;
	p1 = -999;
	p2 = -1000;
	p3 = 1000;
	p4 = 1000;
	p5 = 3999000.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = -10;
	p1 = 0;
	p2 = 1;
	p3 = 2;
	p4 = 17;
	p5 = 3.7;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 17;
	p1 = 98;
	p2 = -123;
	p3 = 12;
	p4 = 22;
	p5 = -114.66666666666667;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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
// Due to historical reasons people measure temperature in different scales, such as Fahrenheit and Celsius. Your task is to convert a temperature from one scale to another. It is known that both scales are linear with respect to each other (i.e.,
// there are real numbers a and b such that temperature t presented in the first scale can be converted to the second by the law t'=a*t+b).
//
//
// You are given 5 ints: f1, the freezing point of water in the first scale; b1, the boiling point of water in the first scale; f2, the freezing point of water in the second scale; b2, the boiling point of water in the second scale; and t, the temperature in the first scale. Return t converted into the second scale.
//
//
//
// DEFINITION
// Class:TemperatureScales2
// Method:convert
// Parameters:int, int, int, int, int
// Returns:double
// Method signature:double convert(int f1, int b1, int f2, int b2, int t)
//
//
// NOTES
// -The return value must be within 1e-9 absolute or relative error of the actual result.
// -Because the boiling and the freezing points of water depend on the atmospheric pressure, you may assume that both the scales are under the same circumstances.
//
//
// CONSTRAINTS
// -f1,b1,f2,b2 and t will each be between -1000 and 1000, inclusive.
// -f1 will be less than b1.
// -f2 will be less than b2.
//
//
// EXAMPLES
//
// 0)
// 0
// 100
// 0
// 100
// 28
//
// Returns: 28.0
//
// These are two identical scales, so temperatures in both of them coincide.
//
//
// 1)
// 0
// 100
// 1
// 101
// 28
//
// Returns: 29.0
//
// The second scale is shifted up 1 degree relative to the first scale.
//
//
// 2)
// -1000
// -999
// -1000
// 1000
// 1000
//
// Returns: 3999000.0
//
//
//
// 3)
// -10
// 0
// 1
// 2
// 17
//
// Returns: 3.7
//
//
//
// 4)
// 17
// 98
// -123
// 12
// 22
//
// Returns: -114.66666666666667
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
