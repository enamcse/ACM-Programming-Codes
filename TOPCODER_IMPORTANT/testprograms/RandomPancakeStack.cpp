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


class RandomPancakeStack {
public:
    vector <int> v;
    int n;
    double dp[255][255];
    double rec(int pos, int baki)
    {
        double ret = dp[pos][baki];
//        if(ret>-.5) return ret;
        ret = 0;
        if(baki == 1) return ret=v[pos-1];
//        assert(baki-pos>=0);
        ret=(1.0*(baki-pos+1)*v[pos-1])/(1.0*baki);
        for (int i = pos-1; i>=1; i--)
            ret+= ((rec(i,baki-1)+v[pos-1])/(1.0*baki));
        return ret;
    }


	double expectedDeliciousness(vector <int> d) {
		v=d;
		n = v.size();
		clr(dp,-1);
		double ans=rec(n,n-1);
//		for (int i = v.size()-1; i>=1; i--)
//		    ans+=rec(i,0);

		return ans;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	RandomPancakeStack *obj;
	double answer;
	obj = new RandomPancakeStack();
	clock_t startTime = clock();
	answer = obj->expectedDeliciousness(p0);
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
		res = answer == answer && fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	double p1;

	// ----- test 0 -----
	disabled = false;
	p0 = {1,1,1};
	p1 = 1.6666666666666667;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {3,6,10,9,2};
	p1 = 9.891666666666667;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {10,9,8,7,6,5,4,3,2,1};
	p1 = 10.999999724426809;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {1,2,3,4,5,6,7,8,9,10};
	p1 = 7.901100088183421;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1};
	p1 = 19.368705050402465;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	p1 = 1.718281828459045;
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
//
// Charlie has N pancakes.
// He wants to serve some of them for breakfast.
// We will number the pancakes 0 through N-1.
// For each i, pancake i has width i+1 and deliciousness d[i].
//
//
//
// Charlie chooses the pancakes he is going to serve using the following randomized process:
// He starts by choosing the first pancake uniformly at random from all the pancakes he has.
// He places the chosen pancake onto a plate.
// This pancake now forms the bottom of a future stack of pancakes.
// Then, Charlie repeats the following procedure:
//
// If there are no more pancakes remaining, terminate.
// Choose a pancake uniformly at random from the pancakes that have not been chosen yet.
// If the width of this pancake is greater than the width of the pancake on top of the stack, terminate without taking it.
// Place the chosen pancake on top of the stack and go back to step 1.
//
//
//
//
// You are given the vector <int> d with N elements.
// The total deliciousness of a serving of pancakes is the sum of the deliciousness of all pancakes used in the serving.
// Compute and return the expected value of the total deliciousness of the pancakes chosen by Charlie.
//
//
// DEFINITION
// Class:RandomPancakeStack
// Method:expectedDeliciousness
// Parameters:vector <int>
// Returns:double
// Method signature:double expectedDeliciousness(vector <int> d)
//
//
// NOTES
// -Your return value must have an absolute or relative error smaller than or equal to 1e-6
//
//
// CONSTRAINTS
// -The number of elements in d will be between 1 and 250, inclusive.
// -Each element of d will be between 1 and 1,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// {1,1,1}
//
// Returns: 1.6666666666666667
//
// The following scenarios may occur:
//
// With probability 1/3, Charlie chooses pancake 0 first. In this case he won't be able to add any more pancakes and the total deliciousness of his serving of pancakes will be 1.
// With probability 1/3, Charlie chooses pancake 1 first. What happens in the second round? With probability 1/2 he will choose pancake 0 and with probability 1/2 it will be pancake 2. In the first case the total deliciousness of Charlie's pancakes will be 2, in the second case it will be 1.
// With probability 1/3, Charlie chooses pancake 2 first. If he chooses pancake 0 next, the total deliciousness of his pancakes will be 2. If he happens to choose pancake 1 next (followed by pancake 0 in the third round), the total deliciousness will be 3.
//
//
// Summing this up, we get the expected deliciousness to be 1/3 * (1) + 1/3 * (1/2 * 1 + 1/2 * 2) + 1/3 * (1/2 * 2 + 1/2 * 3) = 5/3 = 1.666...
//
// 1)
// {3,6,10,9,2}
//
// Returns: 9.891666666666667
//
//
//
// 2)
// {10,9,8,7,6,5,4,3,2,1}
//
// Returns: 10.999999724426809
//
//
//
// 3)
// {1,2,3,4,5,6,7,8,9,10}
//
// Returns: 7.901100088183421
//
//
//
// 4)
// {2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1}
//
// Returns: 19.368705050402465
//
//
//
// 5)
// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//
// Returns: 1.718281828459045
//
//
//
// END KAWIGIEDIT TESTING