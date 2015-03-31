#include<cstdio>
#include<iostream>
using namespace std;

#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

int main()
{
    FI;
    FO;
    int test, T, current, totalPage;

    cin>>test;
    for(T = 1; T <= test; T++)
    {
        printf("Case %d:\n", T);
        cin >> totalPage;
        while(cin>>current && current)
        {
            int firstStartIndex = (current - 2) > 1 ? (current - 2) : 2;
            int firstEndIndex = (firstStartIndex + 4) < totalPage ? (firstStartIndex + 4) : totalPage;
            firstStartIndex = (firstEndIndex - 4) > 1 ? (firstEndIndex - 4) : 2;
            int lastEndIndex = totalPage;
            int lastStartIndex = (lastEndIndex - 4) > firstEndIndex ? (lastEndIndex - 4) : (firstEndIndex + 1);

            cout<<1;
            for(int I = firstStartIndex; I <= firstEndIndex; I++)
                cout<<" "<<I;
            cout<<((lastEndIndex >= lastStartIndex) ? " ....." : "");
            for(int I = lastStartIndex; I <= lastEndIndex; I++)
                cout<<" "<<I;
            cout<<endl;
        }
    }

    return 0;
}
