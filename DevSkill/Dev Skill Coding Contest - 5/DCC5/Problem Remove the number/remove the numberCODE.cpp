#include<bits/stdc++.h>
using namespace std;
int a[1002];
int b[1002];
int main()
{
    //freopen("renumin.txt", "r", stdin);
    //freopen("renumout.txt", "w", stdout);
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int res=0;
        for(int i=1; i<=n; i++)
        {
            int sz=0;
            for(int j=1; j<=n; j++)
            {
                if(i!=j)
                {
                    b[++sz]=a[j];
                }
            }
            bool fl=0,fl1=0;
            for(int j=2; j<=sz; j++)
            {
                if(b[j]<b[j-1])fl=1;
                if(b[j]>b[j-1])fl1=1;
            }
            if(fl==0||fl1==0)
            {
                res=i;
                break;
            }
        }
        printf("%d\n",res);
    }

    return 0;
}
