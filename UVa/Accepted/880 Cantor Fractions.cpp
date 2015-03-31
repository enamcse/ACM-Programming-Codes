#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long equ, dif, p_input, deno, nume, level, input;
    double estimation;
    while(cin>>input)
    {
        p_input=input<<3;
        estimation = ((sqrt(p_input+1)-1)/2);
        level = ceil(estimation);
        equ=level * (level - 1);
        equ>>=1;
        dif = input - equ;
        deno = dif;
        nume = level - dif+1;

        cout<<nume<<"/"<<deno<<endl;
    }

    return 0;
}
