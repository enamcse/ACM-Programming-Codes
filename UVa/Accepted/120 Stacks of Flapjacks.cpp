#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int num[102], s;

void flip(int n)
{
    int i, t, k, l;
    cout<<n<<" ";

    k = s - n;
    l = k / 2;
    for (i = 0; i<=l; i++)
    {
        t = num[i];
        num[i] = num[k-i];
        num[k-i] = t;
    }

//    cout<<"s = "<<s<<" k = "<<k<<" l = "<<l<<endl;
//    for (i = 0; i< s; i++)
//            cout<<num[i]<<" ";
//        cout<<endl;

    return;
}

int main()
{
    int  i, len, j, max, max_id;
    char word[10], input[1000];



    while(gets(input))
    {
        len = strlen(input);
//        cout<<input<<endl;
        s = 0;
        for (i=0; i<len; i++)
        {
            for (j=0; i <len; i++)
            {
//                cout<<"i = "<<i<<" and j = "<<j<<" ";
                if(input[i]>='0'&&input[i]<='9')
                {
                    word[j++] = input[i];
                }
                else break;
            }
            word[j] = '\0';
            num[s++] = atoi(word);
//            cout<<":"<<word<<":"<<endl;
        }
        for (i = 0; i< s; i++)
        {
            cout<<num[i];
            if(i != s-1) cout<<" ";
        }

        cout<<endl;
        for(i = 0; i < s; i++)
        {
            max = 0;
            max_id = 0;
            for (j = s-i-1; j >=0; j--)
            {
                if(num[j]>max)
                {
                    max = num[j];
                    max_id = j;
                }
            }
//            cout<<" max = "<<max<<" and max_id = "<<max_id<<endl;
            if(max_id == 0&&i!=s-1) flip(i+1);
            else if(max_id == s-i-1) ;
            else
            {
                flip(s-max_id);
                flip(i+1);
            }
        }
        cout<<"0"<<endl;
    }
    return 0;
}
