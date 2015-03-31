#include <iostream>
using namespace std;

int main()
{
    int n, m, k, v, cnt,i,j, num[100000];
    bool flag = true;

    while(cin>>n>>m)
    {
        for (i=0; i<n; i++)
            cin>>num[i];

        for (i=0; i<m; i++)
        {
            flag = true;
            cnt=0;
            cin>>k>>v;
            for (j=0; j<n; j++)
            {
                if(num[j]==v)
                {
                    cnt++;
                    if(cnt==k)
                    {
                        cout<<j+1<<endl;
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) cout<<0<<endl;
        }
    }

    return 0;
}
