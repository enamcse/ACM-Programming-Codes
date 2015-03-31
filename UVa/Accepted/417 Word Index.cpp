#include <iostream>
#include <cstring>
using namespace std;

struct sz1
{
    char word[2];
    int numb;
};

struct sz2
{
    char word[3];
    int numb;
};

struct sz3
{
    char word[4];
    int numb;
};

struct sz4
{
    char word[5];
    int numb;
};

struct sz5
{
    char word[6];
    int numb;
};

int main()
{
    int i, j , k, l , m, cnt=1, temp=0;
    sz1 a[26];
    sz2 b[325];
    sz3 c[2600];
    sz4 d[14950];
    sz5 e[65780];
    for (i = 0; i<='z'-97; i++)
    {
        a[i].word[0] = 97+i;
        a[i].word[1] = '\0';
        a[i].numb = cnt++;
    }

    for (i = 0; i<='z'-97; i++)
    {
        for (j = i+1; j<='z'-97; j++)
        {
            b[temp].word[0] = 97+i;
            b[temp].word[1] = 97+j;
            b[temp].word[2] = '\0';
            b[temp++].numb = cnt++;
        }
    }
    temp = 0;
    for (i = 0; i<='z'-97; i++)
    {
        for (j = i+1; j<='z'-97; j++)
        {
            for (k = j+1; k<='z'-97; k++)
            {
                c[temp].word[0] = 97+i;
                c[temp].word[1] = 97+j;
                c[temp].word[2] = 97+k;
                c[temp].word[3] = '\0';
                c[temp++].numb = cnt++;
            }
        }
    }
    temp = 0;
    for (i = 0; i<='z'-97; i++)
    {
        for (j = i+1; j<='z'-97; j++)
        {
            for (k = j+1; k<='z'-97; k++)
            {
                for (l = k+1; l<='z'-97; l++)
                {
                    d[temp].word[0] = 97+i;
                    d[temp].word[1] = 97+j;
                    d[temp].word[2] = 97+k;
                    d[temp].word[3] = 97+l;
                    d[temp].word[4] = '\0';
                    d[temp++].numb = cnt++;
                }
            }
        }
    }
    temp = 0;
    for (i = 0; i<='z'-97; i++)
    {
        for (j = i+1; j<='z'-97; j++)
        {
            for (k = j+1; k<='z'-97; k++)
            {
                for (l = k+1; l<='z'-97; l++)
                {
                    for (m = l+1; m<='z'-97; m++)
                    {
                        e[temp].word[0] = 97+i;
                        e[temp].word[1] = 97+j;
                        e[temp].word[2] = 97+k;
                        e[temp].word[3] = 97+l;
                        e[temp].word[4] = 97+m;
                        e[temp].word[5] = '\0';
                        e[temp++].numb = cnt++;
                    }
                }
            }
        }
    }

    int sizeword;
    char input[10], p, q;
    bool flag = true;

    while(cin>>input)
    {
        sizeword = strlen(input);
        flag = true;
        p = input[0];
        for(i = 1; i<sizeword; i++)
        {
            q = input[i];
            if(q<=p)
            {
                flag = false;
                break;
            }
            p = q;
        }

        if(flag==true)
            switch (sizeword)
            {
            case 1:
                for (i = 0; i<26; i++)
                {
                    if(strcmp(a[i].word, input)==0)
                    {
                        cout<<a[i].numb<<endl;
                        break;
                    }
                }
                break;

            case 2:
                for (i = 0; i<325; i++)
                {
                    if(strcmp(b[i].word, input)==0)
                    {
                        cout<<b[i].numb<<endl;
                        break;
                    }
                }
                break;

            case 3:
                for (i = 0; i<2600; i++)
                {
                    if(strcmp(c[i].word, input)==0)
                    {
                        cout<<c[i].numb<<endl;
                        break;
                    }
                }
                break;

            case 4:
                for (i = 0; i<14950; i++)
                {
                    if(strcmp(d[i].word, input)==0)
                    {
                        cout<<d[i].numb<<endl;
                        break;
                    }
                }
                break;

            case 5:
                for (i = 0; i<65780; i++)
                {
                    if(strcmp(e[i].word, input)==0)
                    {
                        cout<<e[i].numb<<endl;
                        break;
                    }
                }
                break;
            }
        else cout<<"0"<<endl;
    }

    return 0;
}
