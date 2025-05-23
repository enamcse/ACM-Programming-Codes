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


class DecipherabilityEasy {
public:
	string check(string s, string t) {
		int n = s.size();

		for (int i = 0; i<n; i++)
        {
            string k = s.substr(0,i)+s.substr(i+1);
            if(k==t) return "Possible";
        }
		return "Impossible";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	DecipherabilityEasy *obj;
	string answer;
	obj = new DecipherabilityEasy();
	clock_t startTime = clock();
	answer = obj->check(p0, p1);
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
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;

	string p0;
	string p1;
	string p2;

	// ----- test 0 -----
	disabled = false;
	p0 = "sunuke";
	p1 = "snuke";
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = "snuke";
	p1 = "skue";
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = "snuke";
	p1 = "snuke";
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = "snukent";
	p1 = "snuke";
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = "aaaaa";
	p1 = "aaaa";
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = "aaaaa";
	p1 = "aaa";
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 6 -----
	disabled = false;
	p0 = "topcoder";
	p1 = "tpcoder";
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 7 -----
	disabled = false;
	p0 = "singleroundmatch";
	p1 = "singeroundmatc";
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// You had a non-empty string s but you lost it.
// Cat Snuke found the string and removed one character from the string.
// Later, Snuke gave you the string t.
// Can this be the string created from your string s?
//
// You are given the strings s and t.
// Return "Possible" (quotes for clarity) if t can be obtained from s by erasing exactly one character.
// Otherwise, return "Impossible".
// Note that the return value is case-sensitive.
//
// DEFINITION
// Class:DecipherabilityEasy
// Method:check
// Parameters:string, string
// Returns:string
// Method signature:string check(string s, string t)
//
//
// CONSTRAINTS
// -The number of characters in s will be between 1 and 50, inclusive.
// -Every character in s will be a lowercase letter ('a'-'z').
// -The number of characters in t will be between 1 and 50, inclusive.
// -Every character in t will be a lowercase letter ('a'-'z').
//
//
// EXAMPLES
//
// 0)
// "sunuke"
// "snuke"
//
// Returns: "Possible"
//
// If Cat Snuke erase the first 'u' from s, it will equal to t.
//
// 1)
// "snuke"
// "skue"
//
// Returns: "Impossible"
//
// Swapping characters is not allowed.
//
// 2)
// "snuke"
// "snuke"
//
// Returns: "Impossible"
//
// Erasing nothing is not allowed.
//
// 3)
// "snukent"
// "snuke"
//
// Returns: "Impossible"
//
// Cat Snuke can erase exactly one character.
//
// 4)
// "aaaaa"
// "aaaa"
//
// Returns: "Possible"
//
//
//
// 5)
// "aaaaa"
// "aaa"
//
// Returns: "Impossible"
//
//
//
// 6)
// "topcoder"
// "tpcoder"
//
// Returns: "Possible"
//
//
//
// 7)
// "singleroundmatch"
// "singeroundmatc"
//
// Returns: "Impossible"
//
//
//
// END KAWIGIEDIT TESTING
