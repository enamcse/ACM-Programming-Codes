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

#define pb              push_back


using namespace std;


class LongWordsDiv2 {
public:
	string find(string word) {
		int len = word.size(),n;
		char c='*';
		vector<int>v[30];

		for (int i = 0; i<len; i++)
        {
            if(c==word[i]) return "Dislikes";
            c=word[i];
            v[c-'A'].pb(i);
        }

        for (int i = 0; i<26; i++)
            if(v[i].size()>=4) return "Dislikes";

        for (int i = 0; i<26; i++)
        {
            if(!v[i].size()) continue;
            int st= v[i][0];
            int ed= v[i][ v[i].size()-1 ];
            for (int j = st; j<=ed; j++)
            {
                n=word[ j ]-'A';
                if(v[n].size()>1 && v[n][ v[n].size()-1  ]>ed) return "Dislikes";
            }
        }
        return "Likes";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	LongWordsDiv2 *obj;
	string answer;
	obj = new LongWordsDiv2();
	clock_t startTime = clock();
	answer = obj->find(p0);
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
	all_right = true;

	string p0;
	string p1;

	{
	// ----- test 0 -----
	p0 = "AAA";
	p1 = "Dislikes";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "ABCBA";
	p1 = "Likes";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "ABCBAC";
	p1 = "Dislikes";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "TOPCODER";
	p1 = "Likes";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = "VAMOSGIMNASIA";
	p1 = "Dislikes";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = "SINGLEROUNDMATCH";
	p1 = "Likes";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	p0 = "DALELOBO";
	p1 = "Likes";
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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
// Fox Ciel likes all the words that have the following properties:
//
// Each letter of the word is an uppercase English letter.
// Equal letters are never consecutive.
// There is no subsequence of the form xyxy, where x and y are (not necessarily distinct) letters. Note that a subsequence doesn't have to be contiguous.
//
// Examples:
//
// Ciel does not like "ABBA" because there are two consecutive 'B's.
// Ciel does not like "THETOPCODER" because it contains the subsequence "TETE".
// Ciel does not like "ABACADA" because it contains the subsequence "AAAA". (Note that here x=y='A'.)
// Ciel likes "A", "ABA", and also "ABCBA".
//
// Given a string word, return "Likes" (quotes for clarity) if Ciel likes word and "Dislikes" if she does not.
//
//
// DEFINITION
// Class:LongWordsDiv2
// Method:find
// Parameters:string
// Returns:string
// Method signature:string find(string word)
//
//
// CONSTRAINTS
// -word will contain between 1 and 100 characters, inclusive.
// -Each character of word will be an uppercase English letter ('A'-'Z').
//
//
// EXAMPLES
//
// 0)
// "AAA"
//
// Returns: "Dislikes"
//
//
//
// 1)
// "ABCBA"
//
// Returns: "Likes"
//
//
//
// 2)
// "ABCBAC"
//
// Returns: "Dislikes"
//
//
//
// 3)
// "TOPCODER"
//
// Returns: "Likes"
//
//
//
// 4)
// "VAMOSGIMNASIA"
//
// Returns: "Dislikes"
//
//
//
// 5)
// "SINGLEROUNDMATCH"
//
// Returns: "Likes"
//
//
//
// 6)
// "DALELOBO"
//
// Returns: "Likes"
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!