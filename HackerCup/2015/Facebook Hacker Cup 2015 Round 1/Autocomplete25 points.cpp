/**
* H:\Dropbox\Code\HackerCup\2015\Facebook Hacker Cup 2015 Round 1\Autocomplete25 points.cpp
* Created on: 2015-01-18-10.41.14, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("autocomplete.txt","r",stdin)
#define fwrite freopen("output2.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

// TRIE starts array
#define trie_sz 26
struct node{
    int cnt;
    int next[trie_sz];
    node()
    {
        cnt = 0;
        for (int i = 0; i<trie_sz; i++) next[i] = 0;
    }
}data[sz];
int counter=1;

void insert_in_trie(string &str, int len)
{
    int n = 0;
    for (int i = 0; i<len; i++)
    {
        int now = str[i]-'a';
        if(data[n].next[now]==0)
        {
            data[n].next[now] = counter++;
        }
        n=data[n].next[now];
        data[n].cnt++;
    }
}

int search_in_trie(string &str, int len)
{
    int n = 0,cnt=1;
    for (int i = 0; i<len; i++)
    {
        int now = str[i]-'a';
        n=data[n].next[now];
        if(data[n].cnt==1) return cnt;
        cnt++;
    }
    return len;
}

void delete_from_trie() // this is for memset only
{
    counter=1;
    clr(data,0);
}
// TRIE ends using array

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1,k;
    _

	string s;
	cin>>t;


	while(t--)
    {
        delete_from_trie();
        cin>>n;
        m=0;
        for (int i = 0; i<n; i++)
        {
            cin>>s;
            insert_in_trie(s,(int)s.size());
            k=search_in_trie(s,(int)s.size());
            m+=k;
        }
        cout<<"Case #"<<cas++<<": "<<m<<"\n";
    }
   return 0;
}
