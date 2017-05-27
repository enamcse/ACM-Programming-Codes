/**
* E:\PE\Problem 35 Circular primes.cpp
* Created on: 2015-06-16-00.33.48, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define pb push_back
#define all(a) a.begin(),a.end()
#define fread freopen("primes.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

vector<string>v;
set<string>ans;
int main()
{
#ifdef ENAM
    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;
    while(cin>>s)
    {
        if(s.size()>6) break;
        v.pb(s);
    }
    sort(all(v));
    for (int i = 0; i<v.size(); i++)
    {
        string temp=v[i];
//        if(i==4)cout<<temp<<":"<<endl;
        if(ans.find(temp)!=ans.end()) continue;
        vector<string>now;
        m = temp.size()-1;
        now.pb(temp);
        while(m--)
        {
            temp = temp.substr(1,temp.size()-1)+temp[0];
//            if(i==4)cout<<temp<<" ok"<<endl;
            now.pb(temp);
            if(!binary_search(all(v), temp)) break;
        }
//        if(i==4)cout<<m<<" ?"<<endl;
        if(m==-1)
        {
            for(auto x : now)
            {
                ans.insert(x);
            }
        }
    }
    cout<<ans.size()<<"\n";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
