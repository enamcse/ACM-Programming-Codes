#include <bits/stdc++.h>

using namespace std;

#define ll              long long
#define pb              push_back
#define VI              vector<int>


using namespace std;


class ChooseTheBestOne
{
public:
    int countNumber(int N)
    {
        int  pos = 0;
        ll n = N,now = 1;
        VI v;
        for (int i = 1; i<=N; i++)
            v.pb(i);


        for (ll i = 1; i<N; i++,n--)
        {
            now = i*i*i;
            now--;
            pos += (now % n);
            pos%=n;
            v.erase(v.begin()+pos);
        }
        return v[0];
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1)
{
    cout << "Test " << testNum << ": [" << p0;
    cout << "]" << endl;
    ChooseTheBestOne *obj;
    int answer;
    obj = new ChooseTheBestOne();
    clock_t startTime = clock();
    answer = obj->countNumber(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p1;
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    int p0;
    int p1;

    {
        // ----- test 0 -----
        p0 = 3;
        p1 = 2;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 6;
        p1 = 6;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 10;
        p1 = 8;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 1234;
        p1 = 341;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// PROBLEM STATEMENT
//
// Shiny wants to give an award to one of the employees in her company.
// However, all her employees are doing perfect work, so it's hard to pick the one that gets the award.
// Therefore Shiny organized a game they will play to determine the winner.
//
// At the beginning of the game, all N employees form a circle.
// Then, they receive t-shirts with numbers 1 through N in clockwise order along the circle.
// These numbers are never used in the game, we will just use them to identify the winner.
//
// The game is played in turns.
// The turns are numbered starting from 1.
// In each turn, Shiny starts by standing in front of some employee (as specified below) and saying "one".
// Then she moves clockwise along the circle to the next employee and says "two".
// And so on, until the number she says reaches the threshold for that particular turn.
// The threshold for turn number t is t^3.
// (That is, the threshold is 1 for turn 1, 8 for turn 2, 27 for turn 3, and so on.)
//
// At the end of each turn, the employee currently standing in front of Shiny (i.e., the one that received the number t^3) is eliminated.
// In the very first round Shiny starts in front of the employee with the number 1 on their t-shirt.
// In each of the following rounds, Shiny starts in front of the next employee clockwise from the one who just got eliminated.
//
// When there is only one employee left in the game, the game ends and the employee wins the award.
//
// You are given the int N.
// Return the t-shirt number of the employee who gets the award.
//
//
// DEFINITION
// Class:ChooseTheBestOne
// Method:countNumber
// Parameters:int
// Returns:int
// Method signature:int countNumber(int N)
//
//
// CONSTRAINTS
// -N will between 1 and 5000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 3
//
// Returns: 2
//
// In the first round, Shiny stands in front of employee 1, says "one" and eliminates him.
// In the second round, Shiny starts in front of employee 2. She says "one" to employee 2, "two" to
// employee 3, "three" to employee 2 again, ..., and "eight" to employee 3. Thus, employee 3
// gets eliminated and employee 2 wins the award.
//
//
// 1)
// 6
//
// Returns: 6
//
//
//
// 2)
// 10
//
// Returns: 8
//
//
//
// 3)
// 1234
//
// Returns: 341
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
