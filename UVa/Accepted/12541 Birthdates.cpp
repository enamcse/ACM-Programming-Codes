#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, d[3], m[3], y[3];
    char name[3][20];

    cin>>n;
    cin>>name[0]>>d[0]>>m[0]>>y[0];
//    cout<<n<<name[0]<<d[0]<<m[0]<<y[0];
    strcpy(name[1],name[0]);
    strcpy(name[2],name[0]);
    d[1] = d[2] = d[0];
    m[1] = m[2] = m[0];
    y[1] = y[2] = y[0];
    n--;
    while(n--)
    {
        cin>>name[0]>>d[0]>>m[0]>>y[0];
//        cout<<name[0]<<d[0]<<m[0]<<y[0];
        if((y[0]<y[1])||(y[0] == y[1] && m[0]<m[1])||(y[0] == y[1] && m[0] == m[1] && d[0]<d[1]))
        {
            strcpy(name[1],name[0]);
            d[1] = d[0];
            m[1] = m[0];
            y[1] = y[0];
        }
        if((y[0]>y[2])||(y[0] == y[2] && m[0]>m[2])||(y[0] == y[2] && m[0]==m[2]&& d[0]>d[2]))
        {
            strcpy(name[2],name[0]);
            d[2] = d[0];
            m[2] = m[0];
            y[2] = y[0];
        }
//        cout<<name[0]<<" "<<name[1]<<" "<<name[2]<<endl;
    }

    cout<<name[2]<<endl;
    cout<<name[1]<<endl;
    return 0;
}
