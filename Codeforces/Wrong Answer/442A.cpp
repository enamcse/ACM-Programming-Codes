#include <bits/stdc++.h>


#define sz 50005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int n, p, mn=10, faka, dhrim[10];

set< pair<int, int> >s;


map<char, int>mp;



int main()
{
#ifdef ENAM
//    	fread;
	fwrite;
#endif // ENAM
    char c,d;
    scanf("%d", &p);

    mp['R']=0;
    mp['G']=1;
    mp['B']=2;
    mp['W']=3;
    mp['Y']=4;


    for (int i = 0; i<p; i++)
    {
        scanf(" %c%c", &c, &d);
        s.insert(make_pair(mp[c],d-'1'));
    }


    vector< pair<int, int> >v(s.begin(),s.end());
    n = v.size();
    vector< int > a[10], b[10];

    for (int i = 0; i<n; i++)
    {
//        cout<< v[i].first <<" :llllllllll: "<< v[i].second+5 <<endl;
        a[ v[i].first ].pb(v[i].second+5);
        a[ v[i].second+5 ].pb(v[i].first);

    }


    for (int i = 30; i<(1<<10); i++)
    {
        vector< pair<int, int> >taken(n,make_pair(-1,-1));
        for (int k = 0; k<10; k++)
            b[k].clear();
        clr(dhrim,-1);

        for (int j = 0; j<5; j++)
        {
            if(i&(1<<j))
            {
                for (int k = 0; k<n; k++)
                    if(v[k].first==j)
                    {
                        taken[k].first=v[k].first;
                    }
            }
            if(i&(1<<(j+5)))
            {
                for (int k = 0; k<n; k++)
                    if(v[k].second==j)
                    {
                        taken[k].second=v[k].second;
                    }
            }
        }

        faka = 0;
        for (int j = 0; j<n; j++)
        {
//            cout<<j<<" "<<taken[j].first<<" : "<<taken[j].second<<endl;
//            cout<<j<<" "<<v[j].first<<" :: "<<v[j].second<<endl;
            if(max(taken[j].first,taken[j].second)==-1) faka++;
        }
//        cout<<"faka: "<<faka<<endl;


        if(faka>1) continue;

        for (int j = 0; j<n; j++)
        {
//            cout<<taken[j].first<<" @ "<<taken[j].second<<endl;
            if(max(taken[j].first,taken[j].second)==-1) continue;

            b[ taken[j].first ].pb(taken[j].second+5);
            b[ taken[j].second+5 ].pb(taken[j].first);
        }

//        set<int>ding;
//        for (int j = 0; j<n; j++)
//        {
//            if(min(taken[j].first,taken[j].second)==-1&&max(taken[j].first,taken[j].second)!=-1)
//            {
//                if(taken[j].first==-1) ding.insert(v[j].first);
//                if(taken[j].second==-1) ding.insert(v[j].second);
//            }
//        }

//        bool flag = false;
//        faka = 0;
//        for (set<int>::iterator it = ding.begin() ; it!=ding.end(); it++)
//        {
//            int cont = 0;
//            int cur = *it;
//            cout<<"@"<<cur<<endl;
//            for (int l = 0; l<a[cur].size(); l++)
//            {
//                if(!((1<<a[cur][l])&i)) cont++;
//            }
//
////            cout<<cont<<":L: "<<cur<<endl;
//            if(cont>1)
//            {
//                flag = true;
//                break;
//            }
//            else
//            {
//                if(cont==1)faka++;
//                dhrim[cur] = a[cur].size();
//            }
//        }
//
//
//        if(flag||faka>1) continue;




        int jj;
        for (jj = 0; jj<10; jj++)
        {
            if(dhrim[jj]==-1) dhrim[jj]=b[jj].size();
//            cout<<"ting: "<<i<<":: "<<jj<<" a: "<<a[jj].size()<<" b: "<<b[jj].size()<<" == "<< dhrim[jj]<<endl;
            if((int)a[jj].size()-dhrim[jj]>1)
            {
//                cout<<"tew! "<<a[jj].size()<<" H "<<dhrim[jj]<<endl;
                break;
            }
        }

        cout<<"ting: "<<i<<":: "<<jj<<endl;

        if(jj<10) continue;



        mn = min(mn,__builtin_popcount(i));

        cout<<i<<">>"<<mn<<endl;

    }

    cout<<mn<<endl;


    return 0;
}
