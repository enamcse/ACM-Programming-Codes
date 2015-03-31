/**
* H:\Dropbox\Code\Codeforces\488B.cpp
*
* Created on: 2014-11-21-23.13.19, Friday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007

using namespace std;

int arr[4] = {1,1,3,3};
bool ff[4],kk[4];
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
    int t, n, m, cas=1,p[4];
    bool flag=true;
    cin>>n;

    for (int i = 0; i<n; i++)
        cin>>arr[i];
    for (int i = 0; i<n; i++)
        p[i]=arr[i];

    sort(arr,arr+n);
    if(n==4)
    {
        int sum = 0, a, b;
        for (int i = 0; i<n; i++)
            sum+=arr[i];
        if(sum%4!=0) flag = false;
        else
        {
            sum/=4;
            a= arr[1]+arr[2];
            if(a%2!=0) flag = false;
            else
            {
                a/=2;
                b = arr[3] - arr[0];
                if(sum==a&&a==b) flag = true;
                else flag = false;
            }
        }
    }
    else if(n==3)
    {
        flag = false;
        bool tem=true;
        int x = arr[0], y = arr[1], z = arr[2];
        //case 1
        arr[3] = 3*x;
        if(x*4!=y+z) tem = false;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<i; j++)
                if(arr[i]<arr[j] || arr[i]<=0) tem = false;
        }
        if(tem) flag = true;
//        for (int i = 0; i<4; i++)
//        {
//            cout<<arr[i]<<"LL"<<tem<<endl;
//        }
        //case 2
        if(!tem)
        {
            tem = true;
            if(z!=x*3) tem = false;
            arr[3] = z;
            arr[2] = 4*x - y;
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<i; j++)
                    if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
            }
            if(tem) flag = true;
        }

        //case 3
        if(!tem)
        {
            tem = true;
            if(z!=x*3) tem = false;
            arr[3] = z;
            arr[2] = y;
            arr[1] = 4*x - y;
            for (int i = 0; i<4; i++)
            {
//                cout<<arr[i]<<"LL"<<endl;
                for (int j = 0; j<i; j++)
                    if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
            }
            if(tem) flag = true;
        }

        //case 4
        if(!tem)
        {
            tem = true;
            if(z%3!=0) tem = false;
            arr[0] = z/3;
            arr[3] = z;
            arr[2] = y;
            arr[1] = x;
            if((x+y)!=4*arr[0]) tem = false;
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<i; j++)
                    if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
            }
            if(tem) flag = true;
        }

    }
    else if(n==2)
    {
        flag = false;
        bool tem=true;
        int x = arr[0], y = arr[1];
        //case 1
        arr[3] = 3*x;
        arr[2] = 4*x - y;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<i; j++)
                if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
        }
        if(tem) flag = true;

        //case 2
        if(!tem)
        {
            tem = true;
            arr[3] = 3*x;
            arr[2] = y;
            arr[1] = 4*x - y;
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<i; j++)
                    if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
            }
            if(tem) flag = true;
        }

        //case 3
        if(!tem)
        {
            tem = true;
            arr[3] = 3*x;
            arr[1] = arr[2] = 2*x;
            if(3*x!=y) tem = false;
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<i; j++)
                    if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
            }
            if(tem) flag = true;
        }

        //case 4
        if(!tem)
        {
            tem = true;
            arr[1] = x;
            arr[2] = y;
            arr[0] = (x+y)/4;
            if((x+y)%4!=0) tem = false;
            arr[3] = 3*arr[0];
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<i; j++)
                    if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
            }
            if(tem) flag = true;
        }
        //case 5
        if(!tem)
        {
            tem = true;
            arr[1] = x;
            arr[3] = y;
            arr[0] = y/3;
            if(y%3!=0) tem = false;
            arr[2] = arr[0]*4 - arr[1];
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<i; j++)
                    if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
            }
            if(tem) flag = true;
        }

        //case 6
        if(!tem)
        {
            tem = true;
            arr[2] = x;
            arr[3] = y;
            arr[0] = y/3;
            if(y%3!=0) tem = false;
            arr[1] = arr[0]*4 - arr[1];
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<i; j++)
                    if(arr[i]<arr[j]|| arr[i]<=0) tem = false;
            }
            if(tem) flag = true;
        }
    }
    else if(n==1)
    {
        arr[3] = 3*arr[0];
        arr[2]=arr[1]= 2*arr[0];
    }

    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<i; j++)
            if(arr[i]<arr[j]|| arr[i]<=0) flag = false;
    }

    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
            if(!kk[j]&&!ff[i]&&p[j]==arr[i]) ff[i]=kk[j]=true;
    }
//    cout<<flag<<"KK"<<endl;
    if((arr[1]+arr[2])!=(arr[0]*4)) flag = false;
//    cout<<flag<<"KK"<<endl;
    if(arr[3]!=3*arr[0]) flag = false;
//    cout<<flag<<"KK"<<endl;
    if(flag)
    {
        cout<<"YES\n";

        for (int i = 0; i<4; i++)
            if(!ff[i])cout<<arr[i]<<"\n";
    }
    else cout<<"NO\n";


    return 0;
}
