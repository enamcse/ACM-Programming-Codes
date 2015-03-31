#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, j, n, k, len;
    string seq, line;

    while(cin>>seq>>line)
    {
        n = seq.size();
        len = line.size();
        for (i=0, j = 0; n&&i<len; i++)
        {
            if(seq[j]==line[i])
            {
                n--;
                j++;
            }
        }
        if(n) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }

    return 0;
}
