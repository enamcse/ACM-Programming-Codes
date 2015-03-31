#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[51], output[100], temp[50];
    int i, j;
    cin>>input;

    if(input[0]=='h')
    {
        strcpy(output, "http://");
        output[7] = input[4];
        j = 8;
        for(i=5; i<strlen(input); i++)
        {
            if(input[i]=='r'&&input[i+1]=='u')
            {
                output[j++] = '.';
                output[j++] = 'r';
                output[j++] = 'u';
                i+=2;
                break;
            }
            else
            {
                output[j++] = input[i];
            }
        }

        if(i!=strlen(input))
        {
            output[j++] = '/';
            for(; i<strlen(input); i++)
            {
                output[j++] = input[i];
            }
        }

        output[j] = '\0';
    }
    else
    {
        strcpy(output, "ftp://");
        output[6] = input[3];
        j = 7;
        for(i=4; i<strlen(input); i++)
        {
            if(input[i]=='r'&&input[i+1]=='u')
            {
                output[j++] = '.';
                output[j++] = 'r';
                output[j++] = 'u';
                i+=2;
                break;
            }
            else
            {
                output[j++] = input[i];
            }
        }

        if(i!=strlen(input))
        {
            output[j++] = '/';
            for(; i<strlen(input); i++)
            {
                output[j++] = input[i];
            }
        }

        output[j] = '\0';
    }
    cout<<output;
    return 0;
}
