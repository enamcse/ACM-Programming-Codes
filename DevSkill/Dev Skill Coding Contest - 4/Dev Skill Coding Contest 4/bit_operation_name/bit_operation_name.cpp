#include<cstdio>
#include<iostream>
using namespace std;

#define MSB 0x80000000

void showBit(int N)
{
    for(int I = 0; I < 32; I++)
        cout<<(((N<<I)&MSB) != 0);
    cout<<endl;
}

int makeNot(int N)
{
    if(N == 0)
        return 1;

    N = ~N;
    int I = 0;
    for(I = 0; I < 32 && (N&MSB); I++, N<<=1);
    return (N>>I);
}

bool isOR(int a, int b, int r)
{
    return ((a|b) == r);
}
bool isAND(int a, int b, int r)
{
    return ((a&b) == r);
}
bool isXOR(int a, int b, int r)
{
    return ((a^b) == r);
}

bool isNOR(int a, int b, int r)
{
    return (makeNot(a|b) == r);
}
bool isNAND(int a, int b, int r)
{
    return (makeNot(a&b) == r);
}
bool isXNOR(int a, int b, int r)
{
    return (makeNot(a^b) == r);
}

int main()
{
    int test, T, A, B, R;
    bool needComma;

freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);

    cin>>test;
    for(T = 1; T <= test; T++)
    {
        cin>>A>>B>>R;
        needComma = false;
        printf("Case %d:", T);
        if(isAND(A, B, R))
        {
            cout<<" AND";
            needComma = true;
        }
        if(isOR(A, B, R))
        {
            cout<<(needComma ? "," : "")<<" OR";
            needComma = true;
        }
        if(isNAND(A, B, R))
        {
            cout<<(needComma ? "," : "")<<" NAND";
            needComma = true;
        }
        if(isNOR(A, B, R))
        {
            cout<<(needComma ? "," : "")<<" NOR";
            needComma = true;
        }
        if(isXNOR(A, B, R))
        {
            cout<<(needComma ? "," : "")<<" XNOR";
            needComma = true;
        }
        if(isXOR(A, B, R))
        {
            cout<<(needComma ? "," : "")<<" XOR";
            needComma = true;
        }
        cout<<endl;
    }

    return 0;
}
