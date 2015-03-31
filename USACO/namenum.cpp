/*
ID: manetsus
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#define sz 100
#define input_file "namenum.in"
#define output_file "namenum.out"
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen(input_file,"r",stdin)
#define fwrite freopen(output_file,"w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define chng(a,b) a^=b^=a^=b;
#define PI acos(-1)
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}
using namespace std;


map<char,char>mp;

int main()
{
    #if !defined ENAM
        fread;
    fwrite;
    #endif // ENAM
//    ofstream fout (input_file);
//    ifstream fin (output_file);
    char line[100];
    string s, w, word;

    FILE *file = fopen("dict.txt", "r");
    int n, nn;
    for (int i = 'A', j = '2', k =0; i<'Z'; i++)
    {
        if(i=='Q') continue;
        mp[i]=j;
        k++;
        if(k%3==0) j++;
    }


    scanf("%s", line);
    w= line;
    nn = w.size();
    bool flag = true;

    while(~fscanf(file,"%s", line))
    {
        n = strlen(line);
        if(n!=nn) continue;
        s = line;

        word ="";
        for (int i = 0; i<n; i++)
        word+=mp[ s[i] ];
//        cout<<"now = "<<line<<" :"<< w<<": : "<<word<<endl;
        if(word==w) {printf("%s\n", line);flag=false;}
    }
    fclose(file);
    if(flag) printf("NONE\n");
    return 0;
}

