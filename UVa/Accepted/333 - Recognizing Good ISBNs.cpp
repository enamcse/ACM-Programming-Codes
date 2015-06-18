/**
* H:\Dropbox\Code\UVa\333 - Recognizing Good ISBNs.cpp
* Created on: 2015-04-18-22.06.51, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,sp,i;
    bool flag,ten;
    string s;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    while(getline(cin,s))
    {
        flag = false;
        ten = false;
        vector<int>v;
        n = s.size();
        i=0;
        while(n&&s[n-1]==' ')n--;
        while(i<n&&s[i]==' ')i++;
        for (; i<n; i++)
        {
            cout<<s[i];
            if(isdigit(s[i])) {v.pb(s[i]-'0');if(ten)flag=true;}
            else if(s[i]=='X') {v.pb(10);if(ten)flag=true;else ten=true;}
            else if(s[i]!='-') flag=true;

        }
        if(v.size()!=10 || flag) cout<<" is incorrect.\n";
        else
        {
            for (i = 1; i<v.size(); i++) v[i]+=v[i-1];
            for (i = 1; i<v.size(); i++) v[i]+=v[i-1];
            if(v[9]%11==0) cout<<" is correct.\n";
            else cout<<" is incorrect.\n";
        }

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
