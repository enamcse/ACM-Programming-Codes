/**
* H:\Dropbox\Code\UVa\12696 - Cabin Baggage.cpp
* Created on: 2015-04-18-19.27.43, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    double a,b,c,d;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;
    m = 0;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        if(d>7.00||(a+b+c>125&&(a>56||b>45||c>25))) cout<<"0\n";
        else m++,cout<<"1\n";
    }
    cout<<m<<"\n";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
