#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
    map<PII,int>mp;

class PairGameEasy {
public:
    int C,D;

    void rec(int a, int b)
    {
        if(a>C||b>D) return;
        mp[make_pair(a,b)]=1;
        rec(a+b,b);
        rec(a,a+b);
        return;
    }

	string able(int a, int b, int c, int d) {
        C=c;D=d;
        mp.clear();
        rec(a,b);
        if(mp[make_pair(c,d)]) return "Able to generate";
        else return "Not able to generate";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, string p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	PairGameEasy *obj;
	string answer;
	obj = new PairGameEasy();
	clock_t startTime = clock();
	answer = obj->able(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	string p4;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 2;
	p2 = 3;
	p3 = 5;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 2;
	p2 = 2;
	p3 = 1;
	p4 = "Not able to generate";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 2;
	p2 = 2;
	p3 = 999;
	p4 = "Not able to generate";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 2;
	p2 = 2;
	p3 = 1000;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 47;
	p1 = 58;
	p2 = 384;
	p3 = 221;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 1000;
	p1 = 1000;
	p2 = 1000;
	p3 = 1000;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
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
// You have an ordered pair of integers.
// You can now make zero or more steps.
// In each step, you can change your pair into a new pair of integers by adding one of them to the other.
// That is, if your current pair is (x, y), then your next pair will be either (x+y, y), or (x, x+y).
//
//
//
// For example, you can start with (1, 2), change it to (3, 2), change that to (3, 5), and then change that again to (3, 8).
//
//
//
// You are given four ints: a, b, c, and d.
// Return "Able to generate" (quotes for clarity) if it is possible to start with the pair (a, b) and end with the pair (c, d).
// Otherwise, return "Not able to generate".
//
// DEFINITION
// Class:PairGameEasy
// Method:able
// Parameters:int, int, int, int
// Returns:string
// Method signature:string able(int a, int b, int c, int d)
//
//
// CONSTRAINTS
// -a will be between 1 and 1,000, inclusive.
// -b will be between 1 and 1,000, inclusive.
// -c will be between 1 and 1,000, inclusive.
// -d will be between 1 and 1,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 1
// 2
// 3
// 5
//
// Returns: "Able to generate"
//
// (1, 2) -> (3, 2) -> (3, 5).
//
// 1)
// 1
// 2
// 2
// 1
//
// Returns: "Not able to generate"
//
// Note that order matters: (1, 2) and (2, 1) are two different pairs.
//
// 2)
// 2
// 2
// 2
// 999
//
// Returns: "Not able to generate"
//
//
//
// 3)
// 2
// 2
// 2
// 1000
//
// Returns: "Able to generate"
//
//
//
// 4)
// 47
// 58
// 384
// 221
//
// Returns: "Able to generate"
//
//
//
// 5)
// 1000
// 1000
// 1000
// 1000
//
// Returns: "Able to generate"
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!