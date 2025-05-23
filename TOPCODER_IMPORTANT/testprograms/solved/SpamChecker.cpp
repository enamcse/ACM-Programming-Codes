//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(a,b,c)      for(int I=0;I<b;I++)    a[I] = c
#define BE(a)           a.begin(),a.end()
#define chng(a,b)       a^=b^=a^=b;
#define clr(y,z)        memset(y,z,sizeof(y))
#define cntbit(mask)     __builtin_popcount(mask)
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define EQ(a,b)         (fabs(a-b)<ERR)
#define ERR             1e-5
#define FORE(i,a)       for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define fr(i,a,b)       for(i=a;i<=b;i++)
#define fread           freopen("input.txt","r",stdin)
#define fri(a,b)        for(int i=a;i<=b;i++)
#define frj(a,b)        for(int j=a;j<=b;j++)
#define frk(a,b)        for(int k=a;k<=b;k++)
#define frl(a,b)        for(int l=a;l<=b;l++)
#define frin(a,b)       for(int i=a;i>=b;i--)
#define frjn(a,b)       for(int j=a;j>=b;j--)
#define frkn(a,b)       for(int k=a;k>=b;k--)
#define frln(a,b)       for(int l=a;l>=b;l--)
#define frn(i,a,b)      for(i=a;i>=b;i--)
#define fwrite          freopen("output.txt","w",stdout)
#define inf             (1e9)
#define inpow(a,x,y)    int i; a=x;fri(2,y)  a*=x
#define makeint(n,s)    istringstream(s)>>n
#define mod             1000000007
#define ISS             istringstream
#define ll              long long
#define oo              (1<<30)
#define OSS             ostringstream
#define pb              push_back
#define PI              3.141592653589793
#define pi              (2*acos(0))
#define pp              pop_back
#define PRE             1e-8
#define print1(a)       cout<<a<<endl
#define print2(a,b)     cout<<a<<" "<<b<<endl
#define print3(a,b,c)   cout<<a<<" "<<b<<" "<<c<<endl
#define rev(a)          reverse(BE(a));
#define round(i,a)      i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define SI              set<int>
#define SII             set<int>::iterator
#define SIZE(s)         ((int)s.size())
#define saja(a)        sort(BE(a))
#define sqr(a)          ((a)*(a))
#define SZ              50005
#define SZ1             55
#define typing(j,b)     typeof((b).begin()) j=(b).begin();
#define VD              vector<double>
#define VI              vector<int>
#define VLL             vector<long long>
#define VS              vector<string>

using namespace std;


class SpamChecker {
public:
	string spamCheck(string judgeLog, int good, int bad) {
		int len = judgeLog.size();
		int k = 0;
		for (int i = 0; i<len; i++)
        {
            if(judgeLog[i]=='o') k+=good;
            else if(judgeLog[i]=='x') k-=bad;
            if(k<0) return "SPAM";
        }

        return "NOT SPAM";
	}

};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, int p1, int p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1 << "," << p2;
	cout << "]" << endl;
	SpamChecker *obj;
	string answer;
	obj = new SpamChecker();
	clock_t startTime = clock();
	answer = obj->spamCheck(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p3;

	{
	// ----- test 0 -----
	p0 = "ooooxxxo";
	p1 = 2;
	p2 = 3;
	p3 = "SPAM";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "ooooxxxo";
	p1 = 3;
	p2 = 4;
	p3 = "NOT SPAM";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "xooooooooooooooooooooooooooo";
	p1 = 1000;
	p2 = 1;
	p3 = "SPAM";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "oxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	p1 = 1000;
	p2 = 1;
	p3 = "NOT SPAM";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = "ooxoxoxooxoxxoxoxooxoxoxoxxoxx";
	p1 = 15;
	p2 = 17;
	p3 = "SPAM";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = "oooxoxoxoxoxoxooxooxoxooxo";
	p1 = 16;
	p2 = 18;
	p3 = "NOT SPAM";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
// Wolf Sothe was troubled with e-mail spam every day, so he decided to make his own spam filter.
//
// Sothe's approach starts by looking at each line of the e-mail separately and classifying it either as good or bad.
// The more bad lines an e-mail contains, the more likely it is a spam.
//
// Sothe already implemented the above part, and you are given its output as a string judgeLog.
// The characters of judgeLog correspond to the lines of an e-mail, in order.
// The character 'o' represents a good line and the character 'x' represents a bad line.
// For example, judgeLog="oxooo" corresponds to an e-mail with 5 lines.
// The second line of this e-mail is bad and the other four lines are good.
//
// Sothe now came up with an algorithm to decide whether an e-mail is spam. Pseudocode of the algorithm is shown below.
//
//
// At the beginning, set the score of the e-mail to 0.
// For each line of the e-mail, in order:
//     If the line is good, increase the score by G.
//     If the line is bad, decrease the score by B.
//     If the score is now negative (i.e., smaller than 0):
//         Classify the e-mail as "SPAM" and terminate.
// If the score was never negative:
//     Classify the e-mail as "NOT SPAM" and terminate.
//
//
// In the pseudocode, G and B are positive integers. You are given their values as ints good and bad.
//
// Return "SPAM" (quotes for clarity) if the e-mail described by judgeLog is a spam, and "NOT SPAM" otherwise.
//
// DEFINITION
// Class:SpamChecker
// Method:spamCheck
// Parameters:string, int, int
// Returns:string
// Method signature:string spamCheck(string judgeLog, int good, int bad)
//
//
// CONSTRAINTS
// -judgeLog will contain between 1 and 50 characters, inclusive.
// -Each character in judgeLog will be 'o' or 'x'.
// -good will be between 1 and 1000, inclusive.
// -bad will be between 1 and 1000, inclusive.
//
//
// EXAMPLES
//
// 0)
// "ooooxxxo"
// 2
// 3
//
// Returns: "SPAM"
//
// After the 7th line of this e-mail the score is 2+2+2+2-3-3-3 = -1. Hence, at that moment the e-mail gets classified as spam.
//
// 1)
// "ooooxxxo"
// 3
// 4
//
// Returns: "NOT SPAM"
//
// In this case, the score of the e-mail will never be negative, so it gets classified as not spam. Note that after 7 lines of this e-mail the score is 0, but that does not make it a spam.
//
// 2)
// "xooooooooooooooooooooooooooo"
// 1000
// 1
//
// Returns: "SPAM"
//
//
//
// 3)
// "oxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
// 1000
// 1
//
// Returns: "NOT SPAM"
//
//
//
// 4)
// "ooxoxoxooxoxxoxoxooxoxoxoxxoxx"
// 15
// 17
//
// Returns: "SPAM"
//
//
//
// 5)
// "oooxoxoxoxoxoxooxooxoxooxo"
// 16
// 18
//
// Returns: "NOT SPAM"
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
