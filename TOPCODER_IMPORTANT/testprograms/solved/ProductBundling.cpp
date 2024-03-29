/// SRM 324 Div 2 1000

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


class ProductBundling {
public:
	int howManyBundles(vector <string> data) {
		set<string>s;
		string ss;
		int siz = data.size(), strsiz = data[0].size();

		for (int i = 0; i<strsiz; i++)
        {
            ss = "";
            for (int j = 0; j<siz; j++)
                ss+=data[j][i];
            s.insert(ss);
        }
        return s.size();
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
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
	ProductBundling *obj;
	int answer;
	obj = new ProductBundling();
	clock_t startTime = clock();
	answer = obj->howManyBundles(p0);
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
	all_right = true;

	vector <string> p0;
	int p1;

	{
	// ----- test 0 -----
	string t0[] = {"11100"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"1010","1100"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"1100000000","1100000000","0011000000","0011000000","0000110000","0000110000","0000001100","0000001100","0000000011","0000000011"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
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
// A company wants to generate cost advantage by bundling its products, which means that several products are sold in a package. In order to compose bundles optimally, the company has collected data about which products were bought from customers.
// Your company produces n products.  You will be given a vector <string> data, each element of which contains exactly n characters. The jth character of element i of data will be '1' if customer i bought product j, and '0' otherwise. Two products can be in the same bundle only if every customer bought neither of them or both of them.  It is possible for a bundle to contain just one product.  Return the minimum number of bundles into which the products can be partitioned.  Note that every product must be put in some bundle.
//
//
// DEFINITION
// Class:ProductBundling
// Method:howManyBundles
// Parameters:vector <string>
// Returns:int
// Method signature:int howManyBundles(vector <string> data)
//
//
// CONSTRAINTS
// -data will contain between 1 and 50 elements, inclusive.
// -Each element of data will contain between 1 and 50 characters, inclusive.
// -Each element of data will contain the same number of characters.
//
//
// EXAMPLES
//
// 0)
// {"11100"}
//
// Returns: 2
//
// In this example, only data from one customer is available. Two bundles can be composed, the first containing the first three products, the second containing the last two products.
//
// 1)
// {"1010",
//  "1100"}
//
// Returns: 4
//
// No two products can be put into the same bundle, therefore 4 bundles are needed.
//
// 2)
// {"1100000000",
//  "1100000000",
//  "0011000000",
//  "0011000000",
//  "0000110000",
//  "0000110000",
//  "0000001100",
//  "0000001100",
//  "0000000011",
//  "0000000011"}
//
// Returns: 5
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
