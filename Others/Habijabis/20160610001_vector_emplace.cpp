/**
* E:\Dropbox\Code\Others\Habijabis\20160610001_vector_emplace.cpp
* Created on: 2016-06-10-01.28.17, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
#define sz 200005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
    _
    int cas = 1,t,n,m,x,y,z[] = {1,2,3,4};
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    // String to tokenize
    std::string str ="This is a string";
char line[100];
strncpy(line,str.c_str(),sizeof(line)); //strncpy function needs to include header file cstring
std::cout<<line<<std::endl;
// separator
    char sep = ',';

// vector to store tokens
    std::vector<std::string> tokens;

// tokenize
    std::istringstream is(str);
    std::string word;
    while (std::getline(is, word, sep))
        tokens.push_back(word);

for(auto &xx:tokens)
        cout<<xx<<endl;
//        vector<int> v(z,z+4);

        //Using front
//        int b = v.front(); //4

        //Using back
//        int c = v.back(); //6
//        cout<<b<<" "<<c<<endl;
//    v.assign(7,100);
std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
    v.erase(v.begin()+2, v.begin()+4); //1 2 6
for(auto &xx:v)
            cout<<xx<<endl;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

            return 0;
        }
