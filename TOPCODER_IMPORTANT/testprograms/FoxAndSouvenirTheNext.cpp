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


class FoxAndSouvenirTheNext {
public:
    int sum,n;
    bool flag;
    vector<int>v;
    int dp[50][30][2505];

    int rec(int pos, int taken, int total)
    {
        if(flag) return true;
        if(taken==n/2)
        {
            if(sum-total==total)
            {
                flag = true;
                return true;
            }
            return false;
        }
        if(pos==n) return false;
        int &ret = dp[pos][taken][total];
        if(ret!=-1) return ret;
        ret = rec(pos+1,taken+1,total-v[pos])|
        rec(pos+1,taken,total);
        return ret;
    }


	string ableToSplit(vector <int> value) {
		sum = 0;
		n = value.size();
		for (int i = 0; i<n; i++)
		    sum+=value[i];
		if(n&1||sum&1) return "Impossible";
		v=value;
		clr(dp,-1);
		flag = false;
        rec(0,0,sum);
		return flag?"Possible":"Impossible";
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	FoxAndSouvenirTheNext *obj;
	string answer;
	obj = new FoxAndSouvenirTheNext();
	clock_t startTime = clock();
	answer = obj->ableToSplit(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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

	vector <int> p0;
	string p1;

	// ----- test 0 -----
	disabled = false;
	p0 = {1,2,3,4};
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {1,1,1,3};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {1,1,2,3,5,8};
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {2,3,5,7,11,13};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
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
// Fox Ciel just returned home from her trip to New Fox City.
// She has brought a bunch of souvenirs.
// You are given their values in a vector <int> value.
//
//
// Now she wants to give each souvenir either to her mother or to her father.
// She would like to divide the souvenirs in a fair way.
// More precisely:
//
// The total number of souvenirs given to her mother must be the same as the total number of souvenirs given to her father.
// At the same time, the total value of souvenirs given to her mother must be the same as the total value of souvenirs given to her father.
//
//
//
// Return "Possible" if she can reach her goal, and "Impossible" otherwise.
//
// DEFINITION
// Class:FoxAndSouvenirTheNext
// Method:ableToSplit
// Parameters:vector <int>
// Returns:string
// Method signature:string ableToSplit(vector <int> value)
//
//
// CONSTRAINTS
// -value will contain between 1 and 50 elements, inclusive.
// -Each element in value will be between 1 and 50, inclusive.
//
//
// EXAMPLES
//
// 0)
// {1,2,3,4}
//
// Returns: "Possible"
//
// One valid solution is to give the souvenirs with values 1 and 4 to her mother and the other two to her father. Each parent receives two souvenirs, and as 1+4 = 2+3, the total value is also the same for both parents.
//
// 1)
// {1,1,1,3}
//
// Returns: "Impossible"
//
// There is no valid solution. Note that {1,1,1} and {3} is not a valid way to split the souvenirs: even though the total value is the same, the number of souvenirs is not.
//
// 2)
// {1,1,2,3,5,8}
//
// Returns: "Possible"
//
// We have 1+1+8 = 2+3+5.
//
// 3)
// {2,3,5,7,11,13}
//
// Returns: "Impossible"
//
// The sum of values is an odd number, so it is impossible.
//
// 4)
// {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}
//
// Returns: "Possible"
//
//
//
// 5)
// {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}
//
// Returns: "Impossible"
//
//
//
// END KAWIGIEDIT TESTING
