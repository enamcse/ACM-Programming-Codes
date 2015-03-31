#include <iostream>

using namespace std;

int main()
{
    int deno, nume, i, level, input, dif, equ;

    while(cin>>input)
    {
        level = 0;
        for (i=1; i<=input; i+=level)
        {
            ++level;
        }
        equ = level * (level - 1);
        equ>>=1;
        dif = input - equ;
        if(level%2==0)
        {
            nume = dif;
            deno = level - dif+1;
        }
        else
        {
            deno = dif;
            nume = level - dif+1;
        }
        cout<<"TERM "<<input<<" IS "<<nume<<"/"<<deno<<endl;
    }

    return 0;
}
