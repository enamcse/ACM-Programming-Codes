#include <iostream>

using namespace std;

int main()
{
    int e, f, c, t;

    cin>>t;

    while(t--)
    {
        int drunk=0;
        cin>>e>>f>>c;
        int total = e+f;
        while(total>=c)
        {
            int empty = total % c;
            drunk += total/c;
            total = total/c + empty;
        }
        cout<<drunk<<endl;
    }

    return 0;
}
