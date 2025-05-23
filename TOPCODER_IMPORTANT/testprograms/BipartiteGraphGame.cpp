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


class BipartiteGraphGame {
public:
	vector <int> getMoves(vector <int> red, vector <int> blue) {
		
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, vector <int> p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	BipartiteGraphGame *obj;
	vector <int> answer;
	obj = new BipartiteGraphGame();
	clock_t startTime = clock();
	answer = obj->getMoves(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p2[i];
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
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {0,1};
	p1 = {0,1};
	p2 = {};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,0};
	p1 = {0,1};
	p2 = {0,0,1,0,0,0};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,0,3,2};
	p1 = {1,0,3,2};
	p2 = {0,0,1,1,1,0,0,1,2,2,3,3,3,2,2,3};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,2,0};
	p1 = {2,0,1};
	p2 = {0,0,0,2,1,0,2,1,2,0,0,1};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {3,2,1,0};
	p1 = {1,0};
	p2 = {0,0,3,1,3,0,0,1,1,0,2,0,1,0};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
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
// You have a bipartite graph.
// One partition of the graph consists of n red nodes, labeled 0 through n-1.
// The other partition consists of m blue nodes, labeled 0 through m-1.
// There are at least two nodes of each color.
// There are exactly n*m edges: each red vertex is connected to each blue vertex.
// 
// 
// 
// There is exactly one token on each node.
// Each token has a color and a number.
// At the beginning, each red node contains a red token and each blue node contains a blue token.
// The numbers on the red tokens are given in the vector <int> red with n elements.
// For each i, the token on the red node i has the number red[i].
// The numbers on red tokens are a permutation of 0 through n-1.
// Similarly, the numbers on the blue tokens are a permutation of 0 through m-1 and they are given in the vector <int> blue.
// 
// 
// 
// You would like to move the tokens so that each token matches its node both in color and in number.
// That is, for each valid i the red node i should contain the red token i, and for each valid j the blue node j should contain the blue token j.
// 
// 
// 
// You can only move the tokens in a single way:
// In each turn, you can select one edge of the bipartite graph and exchange the tokens in the two nodes it connects.
// 
// 
// 
// For a while you played this game with the following additional rule:
// "During the game, you may only use each edge at most once."
// However, you then noticed that for some initial configurations it is not possible to win the game.
// Hence, you relaxed the rule slightly: you have allowed yourself to use at most one edge twice.
// In this new version of the game it can be shown that any valid test case (i.e., one conforming to the constraints specified below) has a solution that consists of at most 1,000 turns.
// Find and return any such solution.
// 
// 
// 
// More precisely, find and return any sequence of edges such that if you select those edges in that order you will reach the state in which each token is on its corresponding node.
// Note that this sequence does not have to be the shortest sequence possible: any valid sequence of at most 1,000 edges will be accepted.
// If your sequence contains X edges, return a vector <int> with 2X elements: for each edge, in order, write the number of the red node followed by the number of the blue node connected by the edge.
// 
// 
// DEFINITION
// Class:BipartiteGraphGame
// Method:getMoves
// Parameters:vector <int>, vector <int>
// Returns:vector <int>
// Method signature:vector <int> getMoves(vector <int> red, vector <int> blue)
// 
// 
// CONSTRAINTS
// -n,m will be between 2 and 100, inclusive.
// -red will be a permutation of {0,...,n-1}.
// -blue will be a permutation of {0,...,m-1}.
// 
// 
// EXAMPLES
// 
// 0)
// {0,1}
// {0,1}
// 
// Returns: { }
// 
// Nothing needs to be done here.
// 
// 1)
// {1,0}
// {0,1}
// 
// Returns: {0, 0, 1, 0, 0, 0 }
// 
// 
// In the example output we selected the edges in the following order:
// 
// red node 0 - blue node 0
// red node 1 - blue node 0
// red node 0 - blue node 0
// 
// Note that the edge 0-0 was used twice during the game.
// Here is a picture showing the moves made.
// 
// 
// 
// 
// 
// 
// 
// The purple edge denotes which edge we chose in the current move. The color and numbers shown are the token value and colors. The background color represents the actual node colors, with the top row being nodes labeled 0, and bottom row being nodes labeled 1.
// 
// 
// 2)
// {1,0,3,2}
// {1,0,3,2}
// 
// Returns: {0, 0, 1, 1, 1, 0, 0, 1, 2, 2, 3, 3, 3, 2, 2, 3 }
// 
// 
// 
// 3)
// {1,2,0}
// {2,0,1}
// 
// Returns: {0, 0, 0, 2, 1, 0, 2, 1, 2, 0, 0, 1 }
// 
// 
// 
// 4)
// {3,2,1,0}
// {1,0}
// 
// Returns: {0, 0, 3, 1, 3, 0, 0, 1, 1, 0, 2, 0, 1, 0 }
// 
// 
// 
// END KAWIGIEDIT TESTING
