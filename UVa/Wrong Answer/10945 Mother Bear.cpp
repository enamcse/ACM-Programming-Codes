#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;

int main()
{
    string in, done = "DONE",process;
    bool pal=true;
    int cnt, j, n, i;

    getline(cin, in);
    while(in!=done)
    {
        j = 0;
        pal = true;
        cnt = in.size();
        for(i = 0; i<cnt; i++)
        {
            if((toupper(in[i])>='A'&&toupper(in[i])<='Z')||((toupper(in[i])>='a'&&toupper(in[i])<='z')))
               {
                   process[j++] = toupper(in[i]);
               }
        }
        process[j++] = '\0';

        n = j/2;
        j = strlen(process);
        for (i = 0; i<n; i++)
        {
            if(process[i]!=process[j-i-1])
            {
                pal = false;
                break;
            }
        }

        if(pal==true) cout<<"You won't be eaten!"<<endl;
        else cout<<"Uh oh.."<<endl;

//        cout<<in<<endl;
        getline(cin, in);
    }
}
