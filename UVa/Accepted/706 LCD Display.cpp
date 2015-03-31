#include <iostream>
#include <cstring>
using namespace std;

char lu[10] = {'|', ' ', ' ', ' ', '|', '|', '|', ' ', '|', '|'};
char ru[10] = {'|', '|', '|', '|', '|', ' ', ' ', '|', '|', '|'};
char ld[10] = {'|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' '};
char rd[10] = {'|', '|', ' ', '|', '|', '|', '|', '|', '|', '|'};
char u[10]  = {'-', ' ', '-', '-', ' ', '-', '-', '-', '-', '-'};
char m[10]  = {' ', ' ', '-', '-', '-', '-', '-', ' ', '-', '-'};
char d[10]  = {'-', ' ', '-', '-', ' ', '-', '-', ' ', '-', '-'};

void print(int a, int len, bool flag);

int s;

int main()
{
    char n[50];
    int i, j, k, len, t, loop;
    bool flag;
    while(cin>>s>>n&&s)
    {
        len = strlen(n);
        for (i=0; i<5; i++)
        {
            if(i==1||i==3) loop = s;
            else loop = 1;
            for (k=0; k<loop; k++)
            {
                flag = true;
                for (j=0; j<len; j++)
                {
                    if(j == len-1) flag = false;
                    t = n[j]-'0';
                    print(t, i, flag);
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

void print(int nm, int line, bool flag)
{
    switch(line)
    {
    case 0:
        cout<<" ";
        for (int i=0; i<s; i++)
        {
            cout<<u[nm];
        }
        cout<<" ";
        if(flag) cout<<" ";
        else cout<<endl;
        break;
    case 1:
        cout<<lu[nm];
        for (int i=0; i<s; i++)
        {
            cout<<" ";
        }
        cout<<ru[nm];
        if(flag) cout<<" ";
        else cout<<endl;
        break;
    case 2:
        cout<<" ";
        for (int i=0; i<s; i++)
        {
            cout<<m[nm];
        }
        cout<<" ";
        if(flag) cout<<" ";
        else cout<<endl;
        break;
    case 3:
        cout<<ld[nm];
        for (int i=0; i<s; i++)
        {
            cout<<" ";
        }
        cout<<rd[nm];
        if(flag) cout<<" ";
        else cout<<endl;
        break;
    case 4:
        cout<<" ";
        for (int i=0; i<s; i++)
        {
            cout<<d[nm];
        }
        cout<<" ";
        if(flag) cout<<" ";
        else cout<<endl;
        break;
    }
    return;
}
