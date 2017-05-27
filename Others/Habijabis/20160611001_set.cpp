/**
* E:\Dropbox\Code\Others\Habijabis\20160611001_set.cpp
* Created on: 2016-06-11-23.08.03, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ std::ios_base::sync_with_stdio(0);std::cin.tie(0);

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

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

//using namespace std;

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    std::multiset<int>ms1{2,2,3,4,5,6,6,6,2,2,9,8,6,6};
    std::set<int>s1{2,2,3,4,5,6,6,6,2,2,9,8,6,6};
    std::set<int>::iterator its = s1.begin();
    std::vector<int>v{450,693,-1,-1};
    std::vector<int>::iterator itv = v.begin();
    itv+=10;
    for(int i = 0; i<5; i++) its++;
    int z[] = {1,2,3,4,2};
    std::multiset<int>ms(ms1);
//    std::set<int>s(z,z+5);
//    s.insert(s1.begin(),s1.end());
//    ms.emplace(10);
    std::multiset<int>::iterator itss = ms.begin();
    for(int j = 0; j<5; j++) itss++;
//    ms.erase(itss,ms.end());
//    ms.erase(2);
//    ms.insert(ms1.begin());
//    std::set<int>s{2,2,3,4,5,6,6,6,2,2,9,8,6,6}; //2 3 4 5 6 8 9
//    std::set<int>::iterator it = s.begin(),it2;
//    it++; //moved first cursor on 3
//    it2 = it; //initialized second cursor on 3
//    for(int j = 0; j<3; j++) it2++; //moved second cursor 3 elements right, on 6
//    s.erase(it,it2);

    std::set<int>s{2,2,3,4,5,6,6,6,2,2,9,8,6,6}; //2 3 4 5 6 8 9
    auto it = s.find(4); //returns the iterator of value 4
    s.erase(it); //2 3 5 6 8 9
    it = s.find(1);
    if(it!=s.end()) std::cout<<"Value exists"<<std::endl;
    else std::cout<<"Value does not exists"<<std::endl;

//    std::set<int>s{0, 1}; //0 1
//    std::multiset<int>::iterator it = ms.begin();
//    for(int j = 0; j<6; j++) it++; //moved the iterator on 5
//    s.insert(it,ms.end());
//    s.insert(its,its);
    for (const auto &x: s)
        std::cout<<x<<" ";
    std::cout<<std::endl;

    for (const auto &x: ms)
        std::cout<<x<<" ";
    std::cout<<std::endl;
//    std::set<int>::reverse_iterator it = s.rbegin();
////    it++;it++;
//    std::cout<<*it<<" "<<*(ms.rbegin())<<std::endl;
//    for( auto it = ms.rbegin(); it != ms.rend(); it++)
//        std::cout<<*it<<" ";
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;
    auto nox = ms.find(20);
    if(nox!=ms.end()) std::cout<<*nox<<std::endl;
   return 0;
}
