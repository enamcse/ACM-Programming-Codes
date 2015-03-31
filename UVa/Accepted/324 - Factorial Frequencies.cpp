#include <bits/stdc++.h>

#define sz 1055
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int fact[367][10];

char resNow[sz] = {"1"};

void stringAdd(char str1[], char str2[])
{
    int carry = 0,len1 = strlen(str1), len2 = strlen(str2), res;
    char result[(len1>len2?len1:len2)+2];
    stack<char>s;
    for (int i = len1 - 1, j = len2 - 1; i>=0 || j>=0; i--, j--)
    {
        res = (i>=0?str1[i]-'0':0) + (j>=0?str2[j]-'0':0) + carry;
        s.push((res%10)+'0');
        carry=res/10;
    }
    if(carry) s.push('1');
    res = 0;
    bool flag = true;
    while(!s.empty() && s.top()=='0') s.pop();
    while(!s.empty())
    {
        flag = false;
        result[res++] = s.top();
        s.pop();
    }
    result[res]='\0';
    if(flag) strcpy(result,"0");
    strcpy(str1,result);
}


void Mult(char now[], char str[], int n, int shift)
{
    char result[sz];
    int carry = 0, mult;
    stack<char>s;

    for (int i = 0; i<shift; i++)
        s.push('0');

    for (int i =  strlen(str)-1; i>=0; i--)
    {
        mult = n * (int) (str[i]-'0') + carry;
        s.push((mult%10)+'0');
        carry = mult/10;
    }
    if(carry) s.push(carry+'0');

    mult = 0;
    while(!s.empty() && s.top()=='0') s.pop();
    while(!s.empty())
    {
        result[mult++] = s.top();
        s.pop();
    }
    result[mult]='\0';
    stringAdd(now,result);
}

void stringMult( char str1[], char str2[], int n)
{
    char added[sz];
    strcpy(added, "0");
    int len;
    if(strlen(str1)>=strlen(str2))
    {
        len = strlen(str2);
        for (int i = len-1; i>=0; i--)
            Mult(added, str1,str2[i]-'0', len - i - 1);
    }
    else
    {
        len = strlen(str1);
        for (int i = len-1; i>=0; i--)
            Mult(added, str2,str1[i]-'0', len - i - 1);
    }
    strcpy(resNow,added);
    len = strlen(added);
    for (int i = 0; i<len; i++)
        fact[n][ added[i] - '0' ]++;
}

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int n;
    bool flag = false;
    char convert[sz];
    stringstream ss;
    fact[0][1]=fact[1][1]=1;

    for (int i = 2; i<=366; i++)
    {
        ss<<i;
        ss>>convert;
        ss.clear();
        stringMult(resNow,convert,i);
    }

    while(scanf("%d", &n)==1&&n)
    {
        if(flag) printf("\n");
        else flag = true;

        printf("%d! --\n", n);

        printf("   (%d)%5d", 0, fact[n][0]);
        for (int i = 1; i<5; i++)
            printf("    (%d)%5d", i, fact[n][i]);
        printf("\n");

        printf("   (%d)%5d", 5, fact[n][5]);
        for (int i = 6; i<10; i++)
            printf("    (%d)%5d", i, fact[n][i]);

    }
    return 0;
}
