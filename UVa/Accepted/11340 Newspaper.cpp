#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
    int n, k,t,count, m,len,i,j;
    char letter[102], string[10020];
    double val_letter[102],money;
    cin>>n;
    while(n--)
    {
        count= money= 0;
        cin>>k;
        t=k;
        while(t--)
        {
            cin>>letter[count]>>val_letter[count];
            val_letter[count]/=100;
            count++;
        }
        cin>>m;
        m++;
        while(m--)
        {
            cin.getline(string,10020,'\n');
            len = strlen(string);
            for (i=0; i<len; i++)
            {
                for (j=0; j<k; j++)
                {
                    if(string[i]==letter[j]) money+= val_letter[j];
                }
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(2);
        cout<<money<<"$"<<endl;
    }
    return 0;
}
