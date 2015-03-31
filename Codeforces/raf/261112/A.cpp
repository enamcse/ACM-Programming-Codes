#include <iostream>
using namespace std;

int main()
{
    int n, in, i, fold=0, foldno=0, neg=0;
    int b[200];
    cin>>n;

    while(n--)
    {
        cin>>in;
        if(in>=0) fold++;
        else
        {
            neg++;
            if(neg%3==0)
            {
                fold++;
                b[foldno++] = fold;
                fold=0;
                if(n==0) break;
            }
            else fold++;
        }
        if(n==0)
        {
            b[foldno++] = fold;
        }
    }
    if(foldno>1)
    {
        i=foldno-1;
        while(i>=0)
        {
            if(b[i]<3)
            {
                b[i]++;
                b[i-1]--;
                continue;
            }
            i--;
        }
    }


    cout<<foldno<<endl;
    for (i=0; i<foldno; i++)
    {
        cout<<b[i];
        if(i!=(foldno-1)) cout<<" ";
    }

    return 0;
}
