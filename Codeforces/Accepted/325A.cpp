#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>
#include<utility>
#define sz 31405
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

//bool graph[sz][sz];
//int x1,x2,yy,y2;
int p1=inf,p2=0, q1=inf,q2=0;

//void detect()
//{
//    int i,j;
//    bool flag = false;
////    cout<<"x1 = "<<p1<<" x2 = "<<p2<<" y1 = "<<q1<<" y2 = "<<q2<<endl;
//    for (i = q1; i<=q2; i++)
//    {
//        for (j = p1; j<=p2; j++)
//            if(graph[i][j]==true)
//            {
//                x1=j;
//                yy=i;
//                flag = true;
////                cout<<"i = "<<i<<" j = "<<j<<endl;
//                break;
//            }
//        if(flag) break;
//    }

//    for (int m = 0; m<7; m++)
//    {
//        for (int n= 0; n<7; n++)
//            cout<<graph[m][n]<<" ";
//        cout<<endl;
//    }


//    for (; j<=p2+1; j++)
//    {
//
//        if(graph[i][j]==false)
//        {
//            x2=j;
//            y2=i + (x2-x1);
////            cout<<"x1 = "<<i<<" x2 = "<<x2<<" y1 = "<<j<<" y2 = "<<y2<<endl;
//
//            break;
//        }
//    }
////    cout<<"x1 = "<<x1<<" x2 = "<<x2<<" y1 = "<<yy<<" y2 = "<<y2<<endl;
//    return;
//}
//
//bool dofalse()
//{
//    for (int i = yy; i<y2; i++)
//        for (int j = x1; j<x2; j++)
//            if(graph[i][j] == false) return false;
//    return true;
//}
//
//bool dod()
//{
//    for (int i = q1; i<=q2; i++)
//        for (int j = p1; j<=p2; j++)
//            if(graph[i][j] == true) return false;
//    return true;
//}
//
//void d()
//{
//    for (int i = yy; i<y2; i++)
//        for (int j = x1; j<x2; j++)
//            graph[i][j] = false;
//}
ll area, aaa;
int main()
{
    int n, x[2], y[2];
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        cin>>x[0]>>y[0]>>x[1]>>y[1];
        p1 = min(p1,x[0]);
        p2 = max(p2,x[0]);
        q1 = min(q1,y[0]);
        q2 = max(q2,y[0]);
        p1 = min(p1,x[1]);
        p2 = max(p2,x[1]);
        q1 = min(q1,y[1]);
        q2 = max(q2,y[1]);
        area+= ((y[1]-y[0])*(x[1]-x[0]));
    }
        aaa = (p2-p1)*(q2-q1);
        if(aaa==area&&p2-p1==q2-q1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

//        for (int i = y[0]; i<y[1]; i++)
//        {
//            for (int j = x[0]; j<x[1]; j++)
//            {
//                graph[i][j] = true;
//
//            }
//        }
//    }

//    for (int i = 0; i<7; i++)
//    {
//        for (int j = 0; j<7; j++)
//            cout<<graph[i][j]<<" ";
//        cout<<endl;
//    }

//    detect();
//    if(!dofalse()) cout<<"NO"<<endl;
//    else
//    {
//        d();
////        for (int i = 0; i<7; i++)
////        {
////            for (int j = 0; j<7; j++)
////                cout<<graph[i][j]<<" ";
////            cout<<endl;
////        }
//        if(dod()) cout<<"YES"<<endl;
//        else cout<<"NO"<<endl;
//    }
//    cout<<"x1 = "<<x1<<" x2 = "<<x2<<" y1 = "<<yy<<" y2 = "<<y2<<endl;
    return 0;
}
