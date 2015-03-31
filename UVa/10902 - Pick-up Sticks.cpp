/**
* H:\Dropbox\Code\UVa\10902 - Pick-up Sticks.cpp
* Created on: 2015-01-25-19.14.16, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define clr(y,z) memset(y,z,sizeof(y))
#define inf (1e9)
#define mod 1000000007
#define ll long long
#define pb push_back
#define SZ(a) ((int)a.size())
#define sqr(a) ((a)*(a))
#define sz 500005
#define fread freopen("input.txt","r", stdin)
#define fwrite freopen("output.txt","w", stdout)

using namespace std;
double EPS = 1e-12;

struct PT{
    int pos;
    double x, y;PT(){}
    PT(double x, double y, int pos):x(x),y(y), pos(pos){}
    PT(const PT &p) : x(p.x), y(p.y), pos(p.pos){}
    PT operator + (const PT &p) const { return PT(x+p.x,y+p.y, p.pos);}
    PT operator - (const PT &p) const { return PT(x-p.x,y-p.y, p.pos);}
    PT operator * (double c) const {return PT(x*c, y*c, pos);}
    PT operator / (double c) const {return PT(x/c, y/c, pos);}
};

double dot(PT p, PT q) { return p.x*q.x+p.y*q.y;}
double cross(PT p, PT q) { return p.x*q.y-p.y*q.x;}
double dist2(PT p, PT q) {return dot(p-q,p-q);}

bool LinesParallel(PT a, PT b, PT c, PT d){
return fabs(cross(b-a,c-a))<EPS;}

bool LinesCollinear(PT a, PT b, PT c, PT d){
return LinesParallel(a,b,c,d)&&fabs(cross(a-b,a-c))<EPS&&fabs(cross(c-d,c-a))<EPS;}

bool segment(PT a, PT b, PT c, PT d){
    if(LinesCollinear(a,b,c,d)){
        if(dist2(a,c)<EPS || dist2(a,d) < EPS || dist2(b,c)<EPS || dist2(b,d) < EPS) return true;
        if(dot(c-a,c-b)>0 && dot(d-a, d-b)>0 && dot(c-b,d-b)>0) return false;
        return true;
    }
    if(cross(d-a,b-a) * cross(c-a,b-a) > 0) return false;
    if(cross(a-c,d-c) * cross(b-c,d-c) > 0) return false;
    return true;
}



int main()
{
    #ifdef ENAM
//    fread
//    fwrite
    #endif // ENAM
    _

    int n,cn;
    PT a,b, r, s;


    while(cin>>n&&n)
    {
        queue<PT>q, ex;
        for (int i = 0; i<n; i++)
        {
            cin>>a.x>>a.y>>b.x>>b.y;
            a.pos = i+1;
            b.pos = i+1;
            while(!q.empty())
            {
                r = q.front();
                q.pop();
                s = q.front();
                q.pop();

                if(!segment(a,b,r,s))
                {
                    ex.push(r);
                    ex.push(s);
                }
            }
            while(!ex.empty()) {q.push(ex.front());ex.pop();}
            q.push(a);
            q.push(b);
        }

        vector<int>ans;
        while(!q.empty())
        {
            ans.pb(q.front().pos);
            q.pop();q.pop();
        }
        cn = ans.size();
        cout<<"Top sticks:";
        for (int i = 0; i<cn; i++)
            cout<<" "<<ans[i]<<",."[i==cn-1];
        cout<<"\n";
    }


    return 0;
}




