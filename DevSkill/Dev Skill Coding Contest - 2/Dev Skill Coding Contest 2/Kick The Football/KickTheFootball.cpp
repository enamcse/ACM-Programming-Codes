#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

#define PI acos(-1.0)
#define g 9.8
#define bb(theta) tan(theta * PI / 180.0)
#define cc(iv,theta) (g / (2 * (iv * cos(theta * PI / 180)) * (iv * cos(theta * PI / 180))))
#define Y(b,c,x) (b * x - c * x * x)

struct Player{

    int x,y1,y2;
    string name;

}p[12];


bool checkColusion(double ballHeight, double y1, double y2)
{
    if(y1>ballHeight)
        return false;

    if(y2<ballHeight)
        return false;

    return true;
}

bool operator<(Player A, Player B)
{
    return A.x < B.x;
}

void DrawParabola(double b, double c, double R)
{
    //cout<<"R = "<<R<<endl;
    for(int x=0;x<(int)ceil(R);x++)
    {
        cout<<x<<" "<<Y(b,c,x)<<endl;
    }
}

void DrawPlayer(double x, double y1, double y2)
{
    for(int y=(int)y1; y<=(int)y2; y++)
    {
        cout<<x<<" "<<y<<endl;
    }
}

int main()
{
        freopen("Input.txt","r",stdin);
        freopen("output.txt","w",stdout);

        int dgree, initialVelocity, np;

        int test;
        cin>>test;

        for(int T=1;T<=test;T++)
        {
            cin>>initialVelocity;
            cin>>dgree;
            cin>>np;

            double R, b, c;
            bool isballReceived = false;

            b = bb(dgree);
            c = cc(initialVelocity,dgree);
            R = (initialVelocity*initialVelocity*sin(2*dgree*PI/180.0))/g;
/*
            cout<<"R = "<<R<<endl;
            cout<<"b = "<<b<<endl;
            cout<<"c = "<<c<<endl;
*/

            for(int I=0;I<np;I++)
            {
                cin>>p[I].x>>p[I].y1>>p[I].y2>>p[I].name;
                //DrawPlayer((double)p[I].x, (double)p[I].y1, (double)p[I].y2);
            }

            sort(p, p+np);

            cout<<"Case "<<T<<": ";

            for(int I=0;I<np;I++)
            {
                //cout<<p[I].x<<" "<<p[I].y1<<" "<<p[I].y2<<" "<<p[I].name<<endl;
                if(checkColusion((double)Y(b,c,p[I].x), (double)p[I].y1, (double)p[I].y2))
                {
                    cout<<"Ball is received by " + p[I].name<<endl;
                    isballReceived = true;
                    break;
                }
            }

            if(!isballReceived)
            {
                cout<<"No one received the ball"<<endl;
            }

            //DrawParabola(b, c, R);
        }

	return 0;
}
