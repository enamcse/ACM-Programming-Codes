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


class TopFox {
public:
	int possibleHandles(string familyName, string givenName) {
		long long i, j, p, q, l;
		string a, b, c;
		vector<string>v;
		v.clear();
		bool flag;
		p = familyName.size();
		q = givenName.size();
		for (i=0; i<p; i++)
        {
            a = familyName.substr(0,i+1);
            for (j=0; j<q; j++)
            {
                b = givenName.substr(0,j+1);
                c = a + b;
                l = v.size();
                flag = true;
                for (long long k = 0; k<l; k++)
                {
                        if(v[k]==c)
                        {
                            flag = false;
                            break;
                        }
                }
                if(flag) v.push_back(c);
            }
        }
//        for (int m = 0; m<v.size(); m++)
//            cout<<v[m]<<endl;
        return v.size();
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	TopFox *obj;
	int answer;
	obj = new TopFox();
	clock_t startTime = clock();
	answer = obj->possibleHandles(p0, p1);
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

	string p0;
	string p1;
	int p2;

	{
	// ----- test 0 -----
	p0 = "ab";
	p1 = "cd";
	p2 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "abb";
	p1 = "bbc";
	p2 = 7;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "fox";
	p1 = "ciel";
	p2 = 12;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "abbbb";
	p1 = "bbbbbbbc";
	p2 = 16;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = "abxy";
	p1 = "xyxyxc";
	p2 = 21;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = "ababababab";
	p1 = "bababababa";
	p2 = 68;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
// Fox Ciel is planning to register on TopFox. Her family name is familyName and her given name is givenName.
//
// She will choose a TopFox handle according to the following rule. Let s be a non-empty prefix of her family name and let t be a non-empty prefix of her given name. Now Fox Ciel may choose the concatenation of s and t as her handle.
//
// For example, suppose Fox Ciel's family name is "fox" and her given name is "ciel". She may choose the handle "foxciel", "fc", or "foxc". She may not choose "ox", "ciel", or "jiro".
//
// You are told Fox Ciel's family name and given name. Return the number of possible handles Fox Ciel may choose.
//
// DEFINITION
// Class:TopFox
// Method:possibleHandles
// Parameters:string, string
// Returns:int
// Method signature:int possibleHandles(string familyName, string givenName)
//
//
// CONSTRAINTS
// -familyName will contain between 2 and 10 characters, inclusive.
// -Each character in familyName will be a lowercase English letter, i.e., 'a'-'z'.
// -givenName will contain between 2 and 10 characters, inclusive.
// -Each character in givenName will be a lowercase English letter, i.e., 'a'-'z'.
//
//
// EXAMPLES
//
// 0)
// "ab"
// "cd"
//
// Returns: 4
//
// There are 4 possible handles: "a" + "c" = "ac", "a" + "cd" = "acd", "ab" + "c" = "abc" and "ab" + "cd" = "abcd".
//
// 1)
// "abb"
// "bbc"
//
// Returns: 7
//
// There are 7 possible handles: "ab", "abb", "abbc", "abbb", "abbbc", "abbbb", "abbbbc".
//
// 2)
// "fox"
// "ciel"
//
// Returns: 12
//
//
//
// 3)
// "abbbb"
// "bbbbbbbc"
//
// Returns: 16
//
//
//
// 4)
// "abxy"
// "xyxyxc"
//
// Returns: 21
//
//
//
// 5)
// "ababababab"
// "bababababa"
//
// Returns: 68
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!