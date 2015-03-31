/**
* H:\Dropbox\Code\CodeChef\Practice\CAKEDOOM Doom Bakes Cakes.cpp
* Created on: 2015-03-18-21.48.03, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: This problem can be solved by path dp, but I solved it using
           greedy concept. In the problem, they already said that what to
           do if n = 1. After this condition, now, we want to filter those
           cases for which the answer would be "NO". They are:
            1. Already invalid, that means there exists same values any of
               the adjacent places.
            2. k = 1 when n>1 where n = |S|. Example: ?? --> 00 (invalid)
            3. k = 2:
                    a. when n is odd. Example: 1???0 --> 10100 (invalid)
                    b. when odd numbers of question marks occur with unequal
                       end values. Example: 1???0 --> 10100 (invalid)
                    c. when even numbers of question marks occur with equal
                       end values.Example: 1??1 --> 1011 (invalid)

            For all other cases a valid solution exists. So, in every places
            where question mark would come, we would try to put lower values
            for getting lexicographically smaller string. I did it
            recursively, but we have to ensure that, no recursion call would
            occur after getting one solution.

            For checking purpose, we would concatenate the replicating string
            of the original string as the positions are cyclic.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

bool got;
string ans,s, tew;
int k,n;

void rec(int pos)
{
    if(got) return;
    if(pos == n)
    {
        if(!got)tew = ans;
        got = true;
        return;
    }
    if(s[pos]!='?')
    {
        rec(pos+1);
        return;
    }

    for (int i = 0; i<k; i++)
    {
        if( (!pos&&s[n-1]!=(i+'0')&&s[pos+1]!=(i+'0')) ||/// pos = 0
                (pos==n-1&&(ans[pos-1]!=(i+'0')&&ans[0]!=(i+'0'))) || /// pos = n-1
                (pos&&pos!=n-1&&ans[pos-1]!=(i+'0')&&s[pos+1]!=(i+'0'))
          )
        {
            ans[pos]=i+'0';
            if(got)return;
            rec(pos+1);
        }
    }
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    int t;
    bool flag;
    string now;
    cin>>t;
    while(t--)
    {
        flag = true;
        got = false;
        cin>>k>>s;
        n = s.size();
        if(n==1)
        {
            if(s=="?") cout<<"0\n";
            else cout<<s<<"\n";
            continue;
        }
        if(k==1)
        {
            cout<<"NO\n";
            continue;
        }
        ///replication
        now = s+s;
        if(k==2)
        {
            if(n%2) flag = false;
            int pum = now.size(), koyta=0, agerta=-1;
            for (int i =1; i<pum; i++)
            {
                if(!got)
                {
                    if(now[i]!='?') got=true;
                    continue;
                }
                if(now[i]=='?')
                    if(!koyta++)
                        agerta = now[i-1];
                else if(koyta)
                {
                    if((koyta%2==1&&agerta!=now[i] ) ///odd # of '?'
                            ||(koyta%2==0&&agerta==now[i]))
                    {
                        flag = false;
                        break;
                    }
                    koyta=0;
                }
            }
        }
        ///checking the existence  of already invalid case
        for (int i = 0; i<n; i++)
            if(now[i]==now[i+1]&&now[i]!='?')
            {
                flag = false;
                break;
            }
        if(!flag)
        {
            cout<<"NO\n";
            continue;
        }
        ans = s;
        got = false;
        rec(0);
        cout<<tew<<"\n";
        assert(got);
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
