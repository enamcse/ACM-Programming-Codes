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

class AccountBalance {
public:
	int processTransactions(int startingBalance, vector <string> transactions) {
		int bal=startingBalance, n, k;
		char c;
		n = transactions.size();
		for (int i =0; i<n; i++)
        {
                sscanf(transactions[i].c_str(), "%c %d", &c, &k);
                if(c=='D') bal-=k;
                else bal+=k;
        }
        return bal;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	AccountBalance *obj;
	int answer;
	obj = new AccountBalance();
	clock_t startTime = clock();
	answer = obj->processTransactions(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	vector <string> p1;
	int p2;

	{
	// ----- test 0 -----
	p0 = 100;
	string t1[] = {"C 1000","D 500","D 350"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 250;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 100;
	p1.clear() /*{}*/;
	p2 = 100;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 100;
	string t1[] = {"D 50","D 20","D 40"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -10;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 53874;
	string t1[] = {"D 1234","C 987","D 2345","C 654","D 6789","D 34567"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 10580;
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
// You are working for the financial institution TopBank, and you have been tasked with writing a module that will take an initial account balance, along with a list of that day's transactions, and return the ending balance for the day.
//
// Each transaction will be either a credit, which adds funds to the account, or a debit, which removes funds from the account.  If a debit exceeds the available funds at the time, then the account balance will go negative.  You will be given an int startingBalance, the initial account balance.  You will also be given a vector <string> transactions, the list of transactions for the day.  Each element of transactions will be in the form "type amount" (quotes added for clarity).  Each type will be 'C' or 'D', for credit or debit, respectively.  Each amount will be an integer between 1 and 1000000, inclusive, with no leading zeros.  You are to return an int representing the ending balance after processing all of the transactions.
//
//
//
// DEFINITION
// Class:AccountBalance
// Method:processTransactions
// Parameters:int, vector <string>
// Returns:int
// Method signature:int processTransactions(int startingBalance, vector <string> transactions)
//
//
// CONSTRAINTS
// -startingBalance will be between 0 and 1000000, inclusive.
// -transactions will have between 0 and 50 elements, inclusive.
// -Each element of transactions will be formatted as "type amount" (quotes added for clarity).
// -Each type will be 'C' or 'D'.
// -Each amount will represent an integer between 1 and 1000000, inclusive, with no leading zeros.
//
//
// EXAMPLES
//
// 0)
// 100
// {"C 1000", "D 500", "D 350"}
//
// Returns: 250
//
// This person had 100 dollars, got their paycheck, then went shopping at two different stores.  100 + 1000 - 500 - 350 = 250.
//
// 1)
// 100
// {}
//
// Returns: 100
//
// With no transactions, the balance doesn't change by the end of the day.
//
// 2)
// 100
// {"D 50", "D 20", "D 40"}
//
// Returns: -10
//
// Uh oh!  This person's account is overdrawn.
//
// 3)
// 53874
// {"D 1234", "C 987", "D 2345", "C 654", "D 6789", "D 34567"}
//
// Returns: 10580
//
// Several transactions of both types.
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!