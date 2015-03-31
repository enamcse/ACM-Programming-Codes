#include <iostream>
#include <cstring>
#include <cmath>
#define PI (2*acos(0))
#define Ep 1e-7
using namespace std;

int main()
{

    double R, r, n, angle, s;

    cin>>n>>R>>r;
    if(R>=r&&n==1) cout<<"YES"<<endl;
    else if(R==r) cout<<"NO"<<endl;
    else
    {
        angle = n * 360 * asin(((r)/(R-r)))/PI;
//        cout<<angle<<endl;
        if(angle<=360+Ep) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
