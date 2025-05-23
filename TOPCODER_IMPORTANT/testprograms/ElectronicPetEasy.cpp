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


class ElectronicPetEasy {
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
    vector<int>v;

    for (int i = 0; i<t1; i++,st1+=p1)
        v.pb(st1);
    sort(all(v));
    bool flag = true;
    for (int i = 0; i<t2; i++, st2+=p2)
        if(binary_search(all(v),st2)) {flag = false;break;}
    return flag?"Easy":"Difficult";
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, string p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	ElectronicPetEasy *obj;
	string answer;
	obj = new ElectronicPetEasy();
	clock_t startTime = clock();
	answer = obj->isDifficult(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p6 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p6;
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

	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	string p6;

	// ----- test 0 -----
	disabled = false;
	p0 = 3;
	p1 = 3;
	p2 = 3;
	p3 = 5;
	p4 = 2;
	p5 = 3;
	p6 = "Difficult";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = 3;
	p1 = 3;
	p2 = 3;
	p3 = 5;
	p4 = 2;
	p5 = 2;
	p6 = "Easy";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = 1;
	p1 = 4;
	p2 = 7;
	p3 = 1;
	p4 = 4;
	p5 = 7;
	p6 = "Difficult";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = 1;
	p1 = 1000;
	p2 = 1000;
	p3 = 2;
	p4 = 1000;
	p5 = 1000;
	p6 = "Easy";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = 1;
	p1 = 1;
	p2 = 1;
	p3 = 2;
	p4 = 2;
	p5 = 2;
	p6 = "Easy";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
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
//
// Kirino has found a game in which she has to feed electronic pets.
// There are two pets in the game.
// You are given six ints st1,p1,t1,st2,p2,t2.
// To win the game, Kirino must satisfy the following rules:
//
// She must feed her first pet for the first time precisely at the time st1.
// There must be exactly p1 seconds between any two consecutive feedings of the first pet.
// She must feed the first pet exactly t1 times.
// She must feed her second pet for the first time precisely at the time st2.
// There must be exactly p2 seconds between any two consecutive feedings of the second pet.
// She must feed the second pet exactly t2 times.
//
//
//
//
// Feeding the pets is easy if Kirino never needs to feed both pets at the same time.
// Return "Easy" (quotes for clarity) if feeding the pets is easy for the given inputs.
// Otherwise, return "Difficult".
// Note that the return value is case-sensitive.
//
//
// DEFINITION
// Class:ElectronicPetEasy
// Method:isDifficult
// Parameters:int, int, int, int, int, int
// Returns:string
// Method signature:string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
//
//
// CONSTRAINTS
// -st1, p1, t1, st2, p2, and t2 will be between 1 and 1,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 3
// 3
// 3
// 5
// 2
// 3
//
// Returns: "Difficult"
//
// Kirino must feed her first pet at the times 3, 6, and 9.
// She must feed her second pet at the times 5, 7, and 9.
// Feeding these two pets is difficult because she needs to feed both of them at the same time (at time 9).
//
// 1)
// 3
// 3
// 3
// 5
// 2
// 2
//
// Returns: "Easy"
//
// Kirino must feed her first pet at 3, 6, and 9, and her second pet at 5 and 7.
// As all of these times are distinct, feeding these two pets is easy.
//
// 2)
// 1
// 4
// 7
// 1
// 4
// 7
//
// Returns: "Difficult"
//
//
//
// 3)
// 1
// 1000
// 1000
// 2
// 1000
// 1000
//
// Returns: "Easy"
//
//
//
// 4)
// 1
// 1
// 1
// 2
// 2
// 2
//
// Returns: "Easy"
//
//
//
// END KAWIGIEDIT TESTING
