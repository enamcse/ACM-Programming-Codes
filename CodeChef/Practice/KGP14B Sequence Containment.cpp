/**
* H:\Dropbox\Code\CodeChef\Practice\KGP14B Sequence Containment.cpp
* Created on: 2015-03-05-03.55.48, Thursday
* Verdict: Solved
* Author: Enamul Hassan
* Problem Link: http://www.codechef.com/problems/KGP14B
* Concept: Lets the length of two strings are |X| and |Y|. If we merge
           the string X and Y, then we would get a string having length
           |X|+|Y|. To make this string ot Z, we could subtract the
           Longest Common Sequence from |X|+|Y|. Because, these letters
           are double counted in |X|+|Y|.
           So, |Z| = |X| + |Y|  - LCS(X,Y).
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1005
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;


int mag[sz][sz];

int LCS(string &X, string &Y)
{
    int m = X.size(), n = Y.size();

    for (int  i = 1;i<=m ; i++)
        for (int j = 1; j<=n; j++)
        {
            if(X[i-1]==Y[j-1])
            {
                mag[i][j] = mag[i-1][j-1]+1;
            }
            else if(mag[i-1][j]>=mag[i][j-1])
            {
                mag[i][j] = mag[i-1][j];
            }
            else
            {
                mag[i][j] = mag[i][j-1];
            }
        }
        return mag[m][n];
}



int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string a,b;

    cin>>t;

    while(t--)
    {
        clr(mag,0);
        cin>>m>>n>>a>>b;
        cout<<"Case "<<cas++<<": "<<(m+n-LCS(a,b))<<"\n";
    }



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
