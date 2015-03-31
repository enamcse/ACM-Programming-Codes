#include <iostream>
#include <string.h>
#include<stdio.h>
using namespace std;

int l[26];

int main()
{
    char line[1000];
    int len;
    cin>>line;
    len = strlen(line);
    for (int i =0; i<len; i++)
        l[(int)(line[i]-'a')]++;
    len = 0;
    for (int i = 0; i<26; i++)
        if(l[i])len++;
    if(len%2) cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";
    return 0;
}
