#include<iostream>
#define LEFT 'L'
#define RIGHT 'R'

using namespace std;

typedef struct
{
    int nume;
    int deno;
} previous;

int main()
{
    previous left, right, input, stand, forward_left, forward_right;
    double fraction[2];

    while(cin>>input.nume>>input.deno)
    {
        if(input.nume==1&&input.deno==1) break;
        left.nume = right.deno = 0;
        left.deno = right.nume = stand.nume = stand.deno = 1;
        fraction[0] = (double)input.nume / (double)input.deno;
        if(fraction[0]>1)
        {
            cout<<RIGHT;
            left.nume = stand.nume;
            left.deno = stand.deno;
            stand.nume+= right.nume;
            stand.deno+= right.deno;
        }
        else
        {
            cout<<LEFT;
            right.nume = stand.nume;
            right.deno = stand.deno;
            stand.nume+= left.nume;
            stand.deno+= left.deno;
        }

        while(stand.nume!=input.nume || stand.deno!=input.deno)
        {
            forward_left.nume = stand.nume + left.nume;
            forward_right.nume = stand.nume + right.nume;
            forward_left.deno = stand.deno + left.deno;
            forward_right.deno = stand.deno + right.deno;
            fraction[1] = (double)stand.nume / (double)stand.deno;

            if(fraction[0]>fraction[1])
            {
                cout<<RIGHT;
                left.nume = stand.nume;
                left.deno = stand.deno;
                stand.nume+= right.nume;
                stand.deno+= right.deno;
            }
            else
            {
                cout<<LEFT;
                right.nume = stand.nume;
                right.deno = stand.deno;
                stand.nume+= left.nume;
                stand.deno+= left.deno;
            }
        }
        cout<<endl;
    }
    return 0;
}
