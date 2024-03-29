#include <bits/stdc++.h>
using namespace std;


class RollingDiceDivTwo {
public:
	int minimumFaces(vector <string> rolls) {
		int arr[60];
		int n = rolls.size(), len = rolls[0].size();
		for (int i =0; i<len; i++)
		    arr[i]= rolls[0][i]-'0';
		sort(arr,arr+len);
        reverse(arr,arr+len);

		for (int i = 1; i<n; i++)
        {
            sort(rolls[i].rbegin(), rolls[i].rend());
            for (int j =0; j<len; j++)
		    arr[j]= max(arr[j],rolls[i][j]-'0');
        }
        for (int i =1; i<len; i++)
		    arr[0]+= arr[i];
        return arr[0];
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
	RollingDiceDivTwo *obj;
	int answer;
	obj = new RollingDiceDivTwo();
	clock_t startTime = clock();
	answer = obj->minimumFaces(p0);
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
	string t0[] = {"137","364","115","724"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 14;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"1112","1111","1211","1111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"24412","56316","66666","45625"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 30;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"931","821","156","512","129","358","555"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 19;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {"3","7","4","2","4"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	string t0[] = {"281868247265686571829977999522","611464285871136563343229916655","716739845311113736768779647392","779122814312329463718383927626","571573431548647653632439431183","547362375338962625957869719518","539263489892486347713288936885","417131347396232733384379841536"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 176;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
// Byteasar is playing a tabletop role-playing game with his friends. To determine the effectiveness of their heroes' actions the players use a rather unique set of dice which may have nonequal number of faces. Each die has between 1 and 9 faces, inclusive. If a die has m faces, they contain precisely all the values between 1 and m, inclusive. More precisely, for each k between 1 and m, inclusive, there is one face that shows exactly k pips. When a die is cast, every face has equal probability to come out on top.
//
//
// Every time all the dice were thrown at once, Byteasar wrote down the numbers of pips visible on each of the topmost faces (in any order). The results of the i-th throw are given in throws[i]; the length of throws[i] is equal to the number of dice and each character of throws[i] denotes the number of pips visible on one of the topmost faces. For example, if throws[3][0]='7', this means that in throw 3 (0-based index) one of the dice showed exactly 7 pips on the top. Please note that the ordering of dice may be different for different throws.
//
//
// Given the vector <string> throws containing Byteasar's notes, return the minimum possible total number of faces of all dice.
//
// DEFINITION
// Class:RollingDiceDivTwo
// Method:minimumFaces
// Parameters:vector <string>
// Returns:int
// Method signature:int minimumFaces(vector <string> rolls)
//
//
// NOTES
// -Please note that a die can have as few as one or two faces.
//
//
// CONSTRAINTS
// -rolls will contain between 1 and 50 elements, inclusive.
// -rolls[0] will contain between 1 and 50 characters, inclusive.
// -All elements of rolls will contain the same number of characters.
// -Each character in each element of rolls will be one of '1'-'9'.
//
//
// EXAMPLES
//
// 0)
// {"137", "364", "115", "724"}
//
// Returns: 14
//
// In the first throw the numbers of pips on the topmost faces of the dice were 1, 3 and 7; in the second throw they were 3, 6 and 4, in the third they were 1, 1 and 5 and in the fourth roll they were 7, 2 and 4. The players may have used dice with 3, 4 and 7 faces, giving a total of 14 faces. No other possible set of dice has less faces in total.
//
// 1)
// {"1112", "1111", "1211", "1111"}
//
// Returns: 5
//
// The players could have used three dice with one face each and one die with two faces.
//
// 2)
// {"24412", "56316", "66666", "45625"}
//
// Returns: 30
//
// The players could have used five dice with six faces each.
//
// 3)
// {"931", "821", "156", "512", "129", "358", "555"}
//
// Returns: 19
//
//
//
// 4)
// {"3", "7", "4", "2", "4"}
//
// Returns: 7
//
//
//
// 5)
// {"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",
// "571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"}
//
// Returns: 176
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
