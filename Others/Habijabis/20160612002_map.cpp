/**
* E:\Dropbox\Code\Others\Habijabis\20160612002_map.cpp
* Created on: 2016-06-12-14.44.05, Sunday
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
	int cas = 1,t,n,m,x,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

//    multimap<int,string>mp;
//
//    mp.insert(make_pair(1,"wow"));
//    mp.insert(make_pair(1,"okay"));
//    cout<<mp.find(1)->second <<endl;

//    std::map <  std::string, int > ranking{ std::make_pair( "stackoverflow", 2), std::make_pair("docs-beta", 1) };
//    std::cout << ranking.at("stackoverflow") << std::endl;

//    std::multimap < int, std::string > mmp { std::make_pair(2, "stackoverflow"), std::make_pair(1, "docs-beta"), std::make_pair(2, "stackexchange")  };
//    auto it = mmp.begin();
//    std::cout<< it->second << std::endl;
//    it++;
//    std::cout<< it->second << std::endl;
//    it++;
//    std::cout<< it->second << std::endl;
//
//    std::map < int, std::string > mp { std::make_pair(2, "stackoverflow"), std::make_pair(1, "docs-beta"), std::make_pair(2, "stackexchange")  };
//    it = mp.begin();
//    std::cout<< it->second << std::endl;
//    it++;
//    std::cout<< it->second << std::endl;
//    it++;
//    std::cout<< "LLL"<<it->second << std::endl;

//    //with begin()
//    std::multimap < int, std::string > mmp { std::make_pair(2, "stackoverflow"),
//                                             std::make_pair(1, "docs-beta"),
//                                             std::make_pair(2, "stackexchange")  };
//    auto it = mmp.begin();
//    std::cout<< it->first << " " << it->second << std::endl; //1 docs-beta
//    it++;
//    std::cout<< it->first << " " << it->second << std::endl; //2 stackoverflow
//    it++;
//    std::cout<< it->first << " " << it->second << std::endl; //2 stackexchange
//
//    //with rbegin()
//    std::map < int, std::string > mp {  std::make_pair(2, "stackoverflow"),
//                                        std::make_pair(1, "docs-beta"),
//                                        std::make_pair(2, "stackexchange")  };
//    auto it2 = mp.rbegin();
//    std::cout<< it2->first << " " << it2->second << std::endl; //2 stackoverflow
//    it2++;
//    std::cout<< it2->first << " " << it2->second << std::endl; //1 docs-beta
//    std::pair<int,int> arr[10];
//    std::vector< std::pair<int,int> > v{ {1, 5}, {5, 1}, {3, 6}, {3, 2} };
//
//    arr[0] = {1, 3};
//    arr[1] = {1, 5};
//    arr[2] = {2, 5};
//    arr[3] = {0, 1};
//    std::multimap< int , int > mmp{ {1, 2} ,{3, 4}, {6, 5}, {8, 9}, {6, 8}, {3, 4}, {6, 7} };
//                                // {1, 2} ,{3, 4}, {3, 4}, {6, 5}, {6, 8}, {6, 7}, {8, 9}
//    auto it = mmp.begin();
//    for(int i = 0; i<3; i++) it++; //moved cursor on first {6, 5}
////    std::cout<< it->first <<" "<< it->second << std::endl;
////    std::map< int , int > mp(it,mmp.end());
////    std::map< int , int > mp(arr,arr+4);
////    std::map< int , int > mp(v.begin(),v.end());
//    std::map< int , int > mp;
//    mp.insert({{3, 4}, {7, 9}, {7, 8}, {6, 7}});
//    mmp.insert({5, 6});
//
//


    std::multimap< int , int > mmp{ {1, 2}, {3, 4}, {6, 5}, {8, 9}, {3, 4}, {6, 7} };
    std::cout<< mmp.size() <<std::endl;
    auto eqr = mmp.equal_range(9);
    auto st = eqr.first, en = eqr.second;
    if(st == mmp.end() && en == mmp.end()) std::cout<<"hehe!\n";
    for(auto it = st; it!=en; it++)
        std::cout<< it->first << ", " << it->second << std::endl;
                                    // {1, 2}, {3, 4}, {3, 4}, {6, 5}, {6, 7}, {8, 9}
//        auto it = mmp.find(6);
//        std::cout<< it->first <<" " << it->second << std::endl;
//        auto it = mmp.begin();
//        mmp.erase(mmp.begin()+3);
//        for(int i = 0; i < 3; i++) it++; //moved cursor on first {6, 5}
//        mmp.erase(it);
//        auto it2 = it;
//    it++; //moved cursor on first {3, 4}
//    for(int i = 0; i < 3; i++) it2++; //moved cursor on first {6, 5}
//    mmp.erase(it,it2); // {1, 2}, {6, 5}, {6, 7}, {8, 9}
        std::map< int , int > mp(mmp.begin(),mmp.end());
//        mp.insert(it, mmp.end()); // {6, 5}, {8, 9}
    mp.erase(1);
    mp[3]=NULL;
    mmp.erase(6);
//    mmp.erase(mmp.begin());
    for(const auto &x: mmp) std::cout<< x.first <<":"<< x.second << std::endl;
    for(auto &x: mp) std::cout<< x.first <<" "<< x.second << std::endl;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
