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


class BBallBoxScore {
public:
	int threesMade(string line) {
		char now[100], tew[50];
        strcpy(now,line.c_str());
        sscanf(now,"%s", tew);
        int n = strlen(tew);
        int a, b,c,d,e;
        sscanf(now+n+1,"%d-%d %d-%d %d", &a, &b, &c, &d, &e);
        e-=c;
        e-=(2*a);
        cerr<<a<<"K"<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
        if(e<0||e>a) return -1;
        return e;
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	BBallBoxScore *obj;
	int answer;
	obj = new BBallBoxScore();
	clock_t startTime = clock();
	answer = obj->threesMade(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	int p1;

	// ----- test 0 -----
	disabled = false;
	p0 = "Bill 3-5 1-1 8";
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = "TheCheat 9-10 5-5 85";
	p1 = -1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = "IDidntPlay 0-0 0-0 0";
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
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
// In the typical basketball box score in the sports pages, the individual player stats will be listed in this format: "NAME FGM-FGA FTM-FTA PTS", where NAME is the player's name, FGM is the number of field goals made, FGA is the number of field goals attempted, FTM is the number of free throws made, FTA is the number of free throws attempted, and PTS is the number of points scored by the player.
//
// For example, the line "Jim 4-7 2-4 14" would mean that Jim made 4 of 7 field goals, 2 of 4 free throws, and scored 14 points in all.  Now, there is some ambiguity here - while free throws are worth one point each, field goals can either be worth two or three points.
//
// Your method will be given a string line, a properly formatted box score line, and your method should return the number of three-point field goals scored by that player. If a player apparently scored an impossible number of points, your method should return -1 (see example 1.)
//
// For example, if you were given line = "Bill 3-5 1-1 8", then your method should return 1, because Bill made two 2-point field goals, one 3-point field goal, and one free throw, for a total of 2x2 + 1x3 + 1x1 = 8 points.
//
// DEFINITION
// Class:BBallBoxScore
// Method:threesMade
// Parameters:string
// Returns:int
// Method signature:int threesMade(string line)
//
//
// CONSTRAINTS
// -line will contain between 11 and 40 characters, inclusive.
// -line will be properly formatted as "NAME FGM-FGA FTM-FTA PTS", each field separated by exactly one space (' ').
// -NAME will be between 1 and 20 characters in length, inclusive, and will contain only lower and uppercase letters ('a'-'z' and 'A'-'Z').
// -FGM will be between 0 and FGA, inclusive.
// -FTM will be between 0 and FTA, inclusive.
// -FGM, FGA, FTM, FTA, and PTS will all be between 0 and 999, inclusive, and will contain no leading zeroes.
//
//
// EXAMPLES
//
// 0)
// "Bill 3-5 1-1 8"
//
// Returns: 1
//
// See problem statement for explanation.
//
// 1)
// "TheCheat 9-10 5-5 85"
//
// Returns: -1
//
// There's no way to score 85 points with that combination.
//
// 2)
// "IDidntPlay 0-0 0-0 0"
//
// Returns: 0
//
// Or, at least, he didn't attempt any sort of shot at all.
//
// END KAWIGIEDIT TESTING