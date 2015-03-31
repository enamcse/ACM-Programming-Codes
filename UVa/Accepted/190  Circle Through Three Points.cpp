#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a[3],b[3],c[3],m,n,o,p,x,y,r,q;
    int x1, y1, q1, r1;
    while(cin>>a[0]>>b[0]>>a[1]>>b[1]>>a[2]>>b[2])
    {
        if(a[0]==a[1])
        {
            y = (b[0]+b[1])/2;
        }
        else if (a[1]==a[2])
        {
            y = (b[2]+b[1])/2;
        }
        else
        {
            m = 2*(((a[1]-a[2])*(b[0]-b[1]))-((a[0]-a[1])*(b[1]-b[2])));
            n = (((a[0]-a[1])*((a[2]*a[2])-(a[1]*a[1])+(b[2]*b[2])-(b[1]*b[1])))-((a[1]-a[2])*((a[1]*a[1])-(a[0]*a[0])+(b[1]*b[1])-(b[0]*b[0]))));
            if(m) y = n/m;
            else y = 0;
        }

        if(b[0]==b[1])
        {
            x = (a[0]+a[1])/2;
        }
        else if (b[1]==b[2])
        {
            x = (a[2]+a[1])/2;
        }
        else
        {
            o = ((2*y*(b[1]-b[0]))-((a[1]*a[1])-(a[0]*a[0])+(b[1]*b[1])-(b[0]*b[0])));
            p = 2*(a[0]-a[1]);
            if(p) x = o/p;
            else
            {
                o = ((2*y*(b[2]-b[1]))-((a[2]*a[2])-(a[1]*a[1])+(b[2]*b[2])-(b[1]*b[1])));
                p = 2*(a[1]-a[2]);
                if(p) x = o/p;
                else x = 0;
            }
        }


        r = sqrt(((a[0]-x)*(a[0]-x))+((b[0]-y)*(b[0]-y)));
        q = (x*x+y*y-r*r);
        cout << setiosflags(ios::fixed) << setprecision(3);
        x1 = (1000*x);
        y1 = (1000*y);
        q1 = (1000*q);
        r1 = (1000*r);
        if(x1==0) cout<<"x^2 + ";
        else if(x<0) cout<<"(x + "<<-x<<")^2 + ";
        else cout<<"(x - "<<x<<")^2 + ";

        if(y==0) cout<<"y^2 = ";
        else if(y<0) cout<<"(y + "<<-y<<")^2 = ";
        else cout<<"(y - "<<y<<")^2 = ";
        if(r1==0) cout<<"0"<<endl;
        cout<<r<<"^2"<<endl;

        cout<<"x^2 + y^2";
        if(x1==0) ;
        else if(x<0) cout<<" + "<<-2*x<<"x";
        else cout<<" - "<<2*x<<"x";
        if(y1==0) ;
        else if(y<0) cout<<" + "<<-2*y<<"y";
        else cout<<" - "<<2*y<<"y";
        if(q1==0) ;
        else if(q<0) cout<<" - "<<-q;
        else cout<<" + "<<q;
        cout<<" = 0"<<endl<<endl;

    }
    return 0;
}
/*
int main()
{
    double a[3],b[3],c[3],d[3],x,y,z, e[2],f[2],g[2],h,i,p[2],q[2],r[2];
    double eq1[3], eq2[3];

    while(cin>>p[0]>>p[1]>>q[0]>>q[1]>>r[0]>>r[1])
    {
        a[0] = p[0];
        a[1] = q[0];
        a[2] = r[0];
        b[0] = p[1];
        b[1] = q[1];
        b[2] = r[1];
        c[1] = c[2] = c[3] = 1;
        d[0] = -((p[0]*p[0])+(p[1]*p[1]));
        d[1] = -((q[0]*q[0])+(q[1]*q[1]));
        d[2] = -((r[0]*r[0])+(r[1]*r[1]));


//    cout<<"eq 1: a1x + b1y + c1z = d1"<<endl;
//    cin>>a[0]>>b[0]>>c[0]>>d[0];
//    cout<<"eq 2: a2x + b2y + c2z = d2"<<endl;
//    cin>>a[1]>>b[1]>>c[1]>>d[1];
//    cout<<"eq 3: a3x + b3y + c3z = d3"<<endl;
//    cin>>a[2]>>b[2]>>c[2]>>d[2];

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

        eq2[0] = x;
        eq2[1] = y;
        eq2[2] = z;

        eq1[0] = x/2;
        eq1[1] = y/2;
        eq1[2] = sqrt((eq2[0]*eq2[0])+(eq2[1]*eq2[1])-z);

        cout << setiosflags(ios::fixed) << setprecision(3);

        if(eq1[0]<0) cout<<"(x - "<<-eq1[0];
        else cout<<"(x + "<<eq1[0];
        if(eq1[1]<0) cout<<")^2 + (y - "<<-eq1[1]<<")^2 = ";
        else cout<<")^2 + (y + "<<eq1[1]<<")^2 = ";
        cout<<eq1[2]<<"^2"<<endl;

        cout<<"x^2 + y^2";
        if(eq2[0]<0) cout<<" - "<<-eq2[0];
        else cout<<" + "<<eq2[0];
        if(eq2[1]<0) cout<<"x - "<<-eq2[1];
        else cout<<"x + "<<eq2[1];
        if(eq2[2]<0) cout<<"y - "<<-eq2[2];
        else cout<<"y + "<<eq2[2];
        cout<<" = 0"<<endl<<endl;
    }
    return 0;
}
*/
