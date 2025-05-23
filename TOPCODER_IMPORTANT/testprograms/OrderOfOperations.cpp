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


class OrderOfOperations {
public:


	int minTime(vector <string> s) {
		int destmask=0,nowmask;
		vector<int>mask;
		for (int i = 0; i<s.size(); i++)
        {
            nowmask=0;
            for (int j = 0; j<s[0].size(); j++)
                if(s[i][j]=='1') nowmask|=(1<<j);
                mask.pb(nowmask);
                destmask|=nowmask;
        }

        vector<int>dp((1<<s[0].size()),inf);
		dp[0]=0;

		for (int i = 0; i<(1<<s[0].size()); i++)
        {
            for (int j = 0; j<mask.size(); j++)
            {
                int unionmask=i|mask[j];
                int k = cntbit(unionmask-i);
                dp[ unionmask ] = min(dp[unionmask],dp[i]+ k*k);
            }

        }
//        cout<<"dest = "<<destmask<<endl;
        return dp[destmask];
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	OrderOfOperations *obj;
	int answer;
	obj = new OrderOfOperations();
	clock_t startTime = clock();
	answer = obj->minTime(p0);
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

	vector <string> p0;
	int p1;

	// ----- test 0 -----
	disabled = false;
	p0 = {"111","001","010"};
	p1 = 3;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {"11101","00111","10101","00000","11000"};
	p1 = 9;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {"11111111111111111111"};
	p1 = 400;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {"1000","1100","1110"};
	p1 = 3;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {"111","111","110","100"};
	p1 = 3;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// Cat Noku has just finished writing his first computer program.
// Noku's computer has m memory cells.
// The cells have addresses 0 through m-1.
// Noku's program consists of n instructions.
// The instructions have mutually independent effects and therefore they may be executed in any order.
// The instructions must be executed sequentially (i.e., one after another) and each instruction must be executed exactly once.
//
//
//
// You are given a description of the n instructions as a vector <string> with n elements.
// Each instruction is a string of m characters.
// For each i, character i of an instruction is '1' if this instruction accesses memory cell i, or '0' if it does not.
//
//
//
// Noku's computer uses caching, which influences the time needed to execute an instruction.
// More precisely, executing an instruction takes k^2 units of time, where k is the number of new memory cells this instruction accesses.
// (I.e., k is the number of memory cells that are accessed by this instruction but have not been accessed by any previously executed instruction.
// Note that k may be zero, in which case the current instruction is indeed executed in 0 units of time.)
//
//
//
// Noku's instructions can be executed in many different orders.
// Clearly, different orders may lead to a different total time of execution.
// Find and return the shortest amount of time in which it is possible to execute all instructions.
//
//
// DEFINITION
// Class:OrderOfOperations
// Method:minTime
// Parameters:vector <string>
// Returns:int
// Method signature:int minTime(vector <string> s)
//
//
// CONSTRAINTS
// -n will be between 1 and 50, inclusive.
// -m will be between 1 and 20, inclusive.
// -s will have exactly n elements.
// -Each element of s will have exactly m characters.
// -Each character of s[i] will be either '0' or '1' for all valid i.
//
//
// EXAMPLES
//
// 0)
// {
//  "111",
//  "001",
//  "010"
// }
//
// Returns: 3
//
// Cat Noku has 3 instructions.
// The first instruction ("111") accesses all three memory cells.
// The second instruction ("001") accesses only memory cell 2.
// The third instruction ("010") accesses only memory cell 1.
// If Noku executes these three instructions in the given order, it will take 3^2 + 0^2 + 0^2 = 9 units of time.
// However, if he executes them in the order "second, third, first", it will take only 1^2 + 1^2 + 1^2 = 3 units of time.
// This is one optimal solution.
// Another optimal solution is to execute the instructions in the order "third, second, first".
//
//
// 1)
// {
//  "11101",
//  "00111",
//  "10101",
//  "00000",
//  "11000"
// }
//
// Returns: 9
//
//
//
// 2)
// {
//   "11111111111111111111"
// }
//
// Returns: 400
//
// A single instruction that accesses all 20 memory cells.
//
// 3)
// {
//   "1000",
//   "1100",
//   "1110"
// }
//
// Returns: 3
//
//
//
// 4)
// {
//   "111",
//   "111",
//   "110",
//   "100"
// }
//
// Returns: 3
//
//
//
// END KAWIGIEDIT TESTING
