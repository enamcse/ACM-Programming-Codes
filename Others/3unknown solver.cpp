#include <iostream>
using namespace std;

int main()
{
    double a[3],b[3],c[3],d[3],x,y,z, e[2],f[2],g[2],h,i;
    cout<<"eq 1: a1x + b1y + c1z = d1"<<endl;
    cin>>a[0]>>b[0]>>c[0]>>d[0];
    cout<<"eq 2: a2x + b2y + c2z = d2"<<endl;
    cin>>a[1]>>b[1]>>c[1]>>d[1];
    cout<<"eq 3: a3x + b3y + c3z = d3"<<endl;
    cin>>a[2]>>b[2]>>c[2]>>d[2];

    e[0] = b[0]*a[1]-b[1]*a[0];
    f[0] = c[0]*a[1]-c[1]*a[0];
    g[0] = d[0]*a[1]-d[1]*a[0];

    e[1] = b[1]*a[2]-b[2]*a[1];
    f[1] = c[1]*a[2]-c[2]*a[1];
    g[1] = d[1]*a[2]-d[2]*a[1];

    h = e[1]*f[0]-e[0]*f[1];
    i = e[1]*g[0]-e[0]*g[1];

    z = i/h;

    if(e[0]!=0) y = (g[0]-(f[0]*z))/e[0];
    else y = (g[1]-(f[1]*z))/e[1];

    if(a[0]!=0) x = (d[0] - (c[0]*z) - (b[0]*y))/a[0];
    else if (a[1]!=0) x = (d[1] - (c[1]*z) - (b[1]*y))/a[1];
    else  x = (d[2] - (c[2]*z) - (b[2]*y))/a[2];

    cout<<"x = "<<x<<endl<<"y = "<<y<<endl<<"z = "<<z<<endl;

    return 0;
}
