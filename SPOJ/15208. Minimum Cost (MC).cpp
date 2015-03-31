#include <iostream>
#include <string.h>
#include<stdio.h>
using namespace std;
char a[1000],b[1000];
int lcs[1000][1000];

int lcss()
{
    int aa, bb;
    aa=strlen(a);
    bb=strlen(b);
    for (int i =1; i<=aa; i++)
    {
        for (int j = 1; j<=bb; j++)
        {
            if(a[i-1]==b[j-1]) lcs[i][j] = max(lcs[i-1][j-1]+1,max(lcs[i-1][j], lcs[i][j-1])) ;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
//            cout<<lcs[i][j]<<" ";
        }
//        cout<<endl;
    }
    return lcs[aa][bb];
}

int main()
{
    int aa, bb;
    int len, x,y;
    cin>>a;
    while(strcmp(a,"#"))
    {
        cin>>b;
        memset(lcs,0,sizeof(lcs));
        aa=strlen(a);
        bb=strlen(b);
        len = lcss();
        x = (aa-len)*15+(bb-len)*30;
        cout<<x<<endl;
        cin>>a;
    }

    return 0;
}
