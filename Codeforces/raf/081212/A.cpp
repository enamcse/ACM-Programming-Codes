#include <iostream>
using namespace std;

int main()
{
    int n, m, i=0,p;

    while(cin>>n>>m)
    {
        if(n==m)
        {
            for (i = 0; i<n; i++)
                cout<<"BG";
        }
        else if(n>m)
        {
            for (i = 0; i<m; i++)
                cout<<"BG";
            p = n - m;
            for (i = 0; i<p; i++)
                cout<<"B";
        }
        else
        {
            for (i = 0; i<n; i++)
                cout<<"BG";
            p = m - n;
            for (i = 0; i<p; i++)
                cout<<"G";
        }
        cout<<endl;
    }
//    while (i < p)
//    {
//        if(j < n)
//        {
//            cout<<'B';
//            j++;
//        }
//        if(l < m)
//        {
//            cout<<'G';
//            l++;
//        }
//        i++;
//    }
    return 0;
}
