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


class TaroFillingAStringDiv2
{
public:
    int now[55],n;
    string s;
    int cntNow(int pos, int cnt, char A)
    {
        if(pos==n) return 0;
        int ret;
        if(s[pos]=='?')
        {
            cntNow(pos+1,0,0);
            return 0;
        }
        else if(s[pos]==A)ret=cntNow(pos+1,cnt+1,A)+1;
        else
        {
            ret=cntNow(pos+1,0,s[pos]);
            now[pos] = ret+1;
            return 0;
        }
        now[pos] = ret+cnt+1;
        return ret;
    }

    int getNumber(string S)
    {
        s = S;
        n = S.size();
        clr(now,0);
        cntNow(0,0,0);

        vector<pair<int,int> >v;

        for (int i = 0; i<n; i++)
        {
            if(s[i]=='?')
            {
                int k = i;
                for (i++; i<n; i++)
                    if(s[i]!='?') break;
                v.pb({k,i});
            }
        }
        int len = v.size();
        bool flag;
        for (int i = 0; i<len; i++)
        {
            if(v[i].first==0)
            {

                if(s[ v[i].second ]=='B') flag = true;
                else flag = false;

                for (int j = v[i].second-1; j>=v[i].first; j--, flag^=1)
                    if(flag) s[j] = 'A';
                    else s[j] = 'B';

            }
            else
            {
                if(now[ v[i].first-1 ] > now[ v[i].second ])
                {
                    if(s[ v[i].first-1 ]=='B') flag = true;
                    else flag = false;

                    for (int j = v[i].first; j<v[i].second; j++, flag^=1)
                        if(flag) s[j] = 'A';
                        else s[j] = 'B';
                }
                else
                {
                    if(s[ v[i].second ]=='B') flag = true;
                    else flag = false;

                    for (int j = v[i].second-1; j>=v[i].first; j--, flag^=1)
                        if(flag) s[j] = 'A';
                        else s[j] = 'B';
                }
            }
        }
        int ans = 0;
        for (int i = 0; i<n;)
        {
            char ch = s[i];
            int k = i;
            for (i++; i<n; i++)
                if(ch!=s[i]) break;
            k=i-k;
            if(k-->1)ans+=k;
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1)
{
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
    cout << "]" << endl;
    TaroFillingAStringDiv2 *obj;
    int answer;
    obj = new TaroFillingAStringDiv2();
    clock_t startTime = clock();
    answer = obj->getNumber(p0);
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
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    string p0;
    int p1;

    // ----- test 0 -----
    disabled = false;
    p0 = "ABAA";
    p1 = 1;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = "?" "?";
    p1 = 0;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = "A?A";
    p1 = 0;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = "A?" "?B?" "?" "?AAB?A?" "?" "?A";
    p1 = 3;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = "?BB?BAAB?" "?" "?BAB?B?AAAA?ABBA?" "?" "?" "?A?AAB?BBA?A?";
    p1 = 10;
    all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    if (all_right)
    {
        if (tests_disabled)
        {
            cout << "You're a stud (but some test cases were disabled)!" << endl;
        }
        else
        {
            cout << "You're a stud (at least on given cases)!" << endl;
        }
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// PROBLEM STATEMENT
//
// Cat Taro likes strings.
// You are given a string S.
// Each character of S is 'A', 'B', or '?'.
//
//
//
//
// To Taro, the ugliness of a string is the number of pairs of equal consecutive characters.
// For example, the ugliness of "ABABAABBB" is 3: there is one pair "AA" and two (overlapping) pairs "BB".
//
//
//
//
// Taro now wants to change each question mark in S either to 'A' or to 'B'.
// His goal is to minimize the ugliness of the resulting string.
// Return the smallest ugliness that can be achieved.
//
//
// DEFINITION
// Class:TaroFillingAStringDiv2
// Method:getNumber
// Parameters:string
// Returns:int
// Method signature:int getNumber(string S)
//
//
// CONSTRAINTS
// -S will contain between 1 and 50 characters, inclusive.
// -S will consist only of characters 'A', 'B' and '?'.
//
//
// EXAMPLES
//
// 0)
// "ABAA"
//
// Returns: 1
//
// There is initially one pair of consecutive digits that are equal in this case. There is no characters that Taro has to replace, hence the answer is 1.
//
// 1)
// "??"
//
// Returns: 0
//
//
//
// 2)
// "A?A"
//
// Returns: 0
//
//
//
// 3)
// "A??B???AAB?A???A"
//
// Returns: 3
//
//
//
// 4)
// "?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?"
//
// Returns: 10
//
//
//
// END KAWIGIEDIT TESTING