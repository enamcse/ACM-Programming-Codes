#include <stdio.h>
#include <string.h>

void string1(char input[], char output1[], int len);
void string2(char input[], char output2[], int len);

int main()
{
    int i, j, k, n, len;
    char input[55], output1[55], output2[55];
    while(gets(input))
    {
        len = strlen(input);
        string1(input, output1, len);
        string2(input, output2, len);
        printf("%s %s\n", output1, output2);
    }
    return 0;
}

void string1(char input[], char output1[], int len)
{
    int i;
    char temp;
    output1[0] = '0';
    if(input[0] == '0') output1[1] = '0';
    else if(input[0] == '1') output1[1] = '1';
    else if(input[0] >= '2')
    {
        strcpy(output1, "NONE");
        return;
    }
    for(i = 1; i < len - 1; ++i)
    {

        temp = output1[i - 1] + output1[i] - '0';
        if(input[i] == temp) output1[i + 1] = '0';
        else if(input[i] == temp+1) output1[i + 1] = '1';
        else if(input[i] > temp+1)
        {
            strcpy(output1, "NONE");
            return;
        }
    }
    temp = output1[i - 1] + output1[i] - '0';
    if(input[i] !=  temp)
    {
        strcpy(output1, "NONE");
        return;
    }
    output1[i + 1] = '\0';
    return;
}

void string2(char input[], char output2[], int len)
{
    int i;
    char temp;
    output2[0] = '1';
    if(input[0] == '1') output2[1] = '0';
    else if(input[0] == '2') output2[1] = '1';
    else if(input[0] > '2')
    {
        strcpy(output2, "NONE");
        return;
    }
    for(i = 1; i < len - 1; ++i)
    {

        temp = output2[i - 1] + output2[i] - '0';
        if(input[i] == temp) output2[i + 1] = '0';
        else if(input[i] == temp+1) output2[i + 1] = '1';
        else if(input[i] > temp+1)
        {
            strcpy(output2, "NONE");
            return;
        }
    }
    temp = output2[i - 1] + output2[i] - '0';
    if(input[i] !=  temp)
    {
        strcpy(output2, "NONE");
        return;
    }
    output2[i + 1] = '\0';
    return;
}
