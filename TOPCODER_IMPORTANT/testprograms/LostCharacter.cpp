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


class LostCharacter {
public:
	vector <int> getmins(vector <string> str) {
		vector<string>now;
		string temp, s;
		char ch;
		int n = str.size();
		vector<int>ans;
		for (int i = 0; i<n; i++)
        {
            now.clear();
            for (int j = 0; j<n; j++)
            {
                temp = str[j];
                if(i==j) ch = 'a';
                else ch = 'z';
                for (int k = 0; k<temp.size(); k++)
                    if(temp[k]=='?') temp[k]=ch;
                now.pb(temp);
                if(i==j) s= temp;
            }
            sort(all(now));
            for (int j = 0; j<n; j++)
                if(now[j]==s)
                {
                    ans.pb(j);
                    break;
                }
        }
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	LostCharacter *obj;
	vector <int> answer;
	obj = new LostCharacter();
	clock_t startTime = clock();
	answer = obj->getmins(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p1;

	// ----- test 0 -----
	disabled = false;
	p0 = {"abc","bcd","cde","cdf","bbc"};
	p1 = {0,2,3,4,1};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {"?ala","ara","baba"};
	p1 = {0,0,1};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {"a?","a","a","ab","aa"};
	p1 = {2,0,0,3,2};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {"s?nu?ke","sm?" "?eke","?sna?ke","so?th?e","shake?" "?"};
	p1 = {0,1,0,2,0};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {"?","z?","zz?","zzz?","zzzz?","zzzzz?","zzzzzz?"};
	p1 = {0,1,2,3,4,5,6};
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
// In this problem we are dealing with strings of lowercase English letters.
// When comparing our strings, we are using the standard lexicographic order.
// For example, "cat" < "do" < "dog" < "done".
// (See Notes for a formal definition.)
//
// Suppose that L is a list of strings and that S is one of those strings.
// The position of S in L is the 0-based index of the first occurrence of S after L is sorted lexicographically.
// (Equivalently, the position of S in L can be defined as the number of strings in L that are strictly smaller than S.)
//
// For example, for the list L = {"abc", "bcd", "cde", "cdf", "bbc"}, the corresponding positions would be {0, 2, 3, 4, 1}.
// For the list L = {"a", "a", "b", "b", "c", "c"} the positions would be {0, 0, 2, 2, 4, 4}.
//
// Wolf Sothe has found an old list of strings.
// Some characters in the list were damaged beyond recognition.
// You are given the list as a vector <string> str.
// In str, the damaged characters are represented by the character '?' (question mark).
//
// Return a vector <int> with as many elements as str.
// For each valid i, the i-th element of the return value should be the smallest possible position of the i-th element of Sothe's list.
//
// DEFINITION
// Class:LostCharacter
// Method:getmins
// Parameters:vector <string>
// Returns:vector <int>
// Method signature:vector <int> getmins(vector <string> str)
//
//
// NOTES
// -Given two strings A and B, we say that A is smaller than B if either A is a proper prefix of B, or there is a non-negative integer i such that A[i]<B[i] and for all j<i we have A[j]=B[j].
//
//
// CONSTRAINTS
// -str will contain between 1 and 50 elements, inclusive.
// -Each element in str will contain between 1 and 50 characters, inclusive.
// -Each character in str will be either a lowercase English letter ('a'-'z'), or '?'.
//
//
// EXAMPLES
//
// 0)
// {"abc","bcd","cde","cdf","bbc"}
//
// Returns: {0, 2, 3, 4, 1 }
//
// This is the first example from the problem statement.
// As there are no damaged letters, there is only one possible lexicographical order and you should return the corresponding positions.
//
// 1)
// {"?ala","ara","baba"}
//
// Returns: {0, 0, 1 }
//
// In this test case we have one damaged character.
// If the damaged character was an 'a', the positions were {0,1,2}.
// Otherwise, the positions were {2,0,1}.
// Hence, the smallest possible position of "?ala" is 0, the smallest possible position of "ara" is 0, and the smallest possible position of "baba" is 1.
//
// 2)
// {"a?","a","a","ab","aa"}
//
// Returns: {2, 0, 0, 3, 2 }
//
// Sothe's list may contain duplicates.
//
// 3)
// {"s?nu?ke","sm??eke","?sna?ke","so?th?e","shake??"}
//
// Returns: {0, 1, 0, 2, 0 }
//
//
//
// 4)
// {"?","z?","zz?","zzz?","zzzz?","zzzzz?","zzzzzz?"}
//
// Returns: {0, 1, 2, 3, 4, 5, 6 }
//
//
//
// END KAWIGIEDIT TESTING
