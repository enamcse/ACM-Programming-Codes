#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, count, t, j, l, flag1, flag2, flag3, flag;
    double P, U, I, m, k, s;
    char ch = ' ', str[5], line[200];

    scanf("%d ", &n);

    for (t = 0; t < n; ++t)
    {
        flag1 = flag2 = flag3 = flag = 0;
        m = 1;
        k = 1;
        s = 1;
        gets(line);
        l = strlen(line);

        for (j=0; j<l; ++j)
        {
            if(line[j] == 'U' && line[j+1] == '=')
            {
                flag1 = 1;
                j += 2;
                count = 0;
                while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                    str[count++] = line[j++];
                str[count] = '\0';
                U = atof(str);
                if(line[j] == 'M') m *= 1000000;
                else if (line[j] == 'm') m /= 1000;
                else if (line[j] == 'k') m *= 1000;
                if(flag2 || flag3) break;
            }
            else if(line[j] == 'P' && line[j+1] == '=')
            {
                flag2 = 1;
                j += 2;
                count = 0;
                while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                    str[count++] = line[j++];
                str[count] = '\0';
                P = atof(str);
                if(line[j] == 'M') k *= 1000000;
                else if (line[j] == 'm') k /= 1000;
                else if (line[j] == 'k') k *= 1000;
                if(flag1 || flag3) break;
            }
            else if(line[j] == 'I' && line[j+1] == '=')
            {
                flag3 = 1;
                count = 0;
                j += 2;
                while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                    str[count++] = line[j++];
                str[count] = '\0';
                I = atof(str);
                if(line[j] == 'M') s *= 1000000;
                else if (line[j] == 'm') s /= 1000;
                else if (line[j] == 'k') s *= 1000;
                if(flag2 || flag1) break;
            }
        }

        if(flag1  && flag2)
        {
            I = P * k / (U * m);
            printf("Problem #%d\nI=%.2lfA\n\n",t+1,I);

        }
        else if(flag3  && flag2)
        {
            U = P * k / (I * s);
            printf("Problem #%d\nU=%.2lfV\n\n",t+1,U);
        }
        else if(flag1  && flag3)
        {
            P = U * I * m * s;
            printf("Problem #%d\nP=%.2lfW\n\n",t+1,P);
        }
    }
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, count, i, j;
    double P, U, I, m, k;
    char ch = ' ', str[5], line[20];

    scanf("%d", &n);

    for (i = 1; i <= n; ++i)
    {
        while(scanf("%s", line) == 1)
        {
            if((ch = getchar()) == '\n') break;
            for (j=0; j<strlen(line); ++j)
            {
                m = 1;
                k = 1;
                if(line[j] == 'U' && line[j+1] == '=')
                {
                    j += 2;
                    count = 0;
                    while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                        str[count++] = line[j++];
                    str[count] = '\0';
                    U = atof(str);
                    if(line[j] == 'M') m *= 1000000;
                    else if (line[j] == 'm') m /= 1000;
                    else if (line[j] == 'k') m *= 1000;

                    while(scanf(" %s ", line) == 1)
                    {
                        j = 0;
                        if(line[j] == 'I' && line[j+1] == '=')
                        {
                            count = 0;
                            j+=2;
                            while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                                str[count++] = line[j++];
                            str[count] = '\0';
                            I = atof(str);
                            if(line[j] == 'M') k *= 1000000;
                            else if (line[j] == 'm') k /= 1000;
                            else if (line[j] == 'k') k *= 1000;
                            P = U * I * m * k;
                            printf("Problem #%d\nP=%.2lfW\n\n",i,P);
                            j = 100;
                            break;
                        }
                        else if(line[j] == 'P' && line[j+1] == '=')
                        {
                            count = 0;
                            j+=2;
                            while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                                str[count++] = line[j++];
                            str[count] = '\0';
                            P = atof(str);
                            if(line[j] == 'M') k *= 1000000;
                            else if (line[j] == 'm') k /= 1000;
                            else if (line[j] == 'k') k *= 1000;
                            I = P * k / (U * m);
                            printf("Problem #%d\nI=%.2lfA\n\n",i,I);
                            j = 100;
                            break;
                        }
                    }
                }
                else if(line[j] == 'P' && line[j+1] == '=')
                {
                    j += 2;
                    count = 0;
                    while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                        str[count++] = line[j++];
                    str[count] = '\0';
                    P = atof(str);
                    if(line[j] == 'M') m *= 1000000;
                    else if (line[j] == 'm') m /= 1000;
                    else if (line[j] == 'k') m *= 1000;

                    while(scanf(" %s ", line) == 1)
                    {
                        j = 0;
                        if(line[j] == 'I' && line[j+1] == '=')
                        {
                            count = 0;
                            j+=2;
                            while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                                str[count++] = line[j++];
                            str[count] = '\0';
                            I = atof(str);
                            if(line[j] == 'M') k *= 1000000;
                            else if (line[j] == 'm') k /= 1000;
                            else if (line[j] == 'k') k *= 1000;
                            U = P * m / (I * k);
                            printf("Problem #%d\nU=%.2lfV\n\n",i,U);
                            j = 100;
                            break;
                        }
                        else if(line[j] == 'U' && line[j+1] == '=')
                        {
                            count = 0;
                            j += 2;
                            while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                                str[count++] = line[j++];
                            str[count] = '\0';
                            U = atof(str);
                            if(line[j] == 'M') k *= 1000000;
                            else if (line[j] == 'm') k /= 1000;
                            else if (line[j] == 'k') k *= 1000;
                            I = P * m / (U * k);
                            printf("Problem #%d\nI=%.2lfA\n\n",i,I);
                            j = 100;
                            break;
                        }
                    }
                }
                else if(line[j] == 'I' && line[j+1] == '=')
                {
                    count = 0;
                    j += 2;
                    while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                        str[count++] = line[j++];
                    str[count] = '\0';
                    I = atof(str);
                    if(line[j] == 'M') m *= 1000000;
                    else if (line[j] == 'm') m /= 1000;
                    else if (line[j] == 'k') m *= 1000;

                    while(scanf(" %s ", line) == 1)
                    {
                        j = 0;
                        if(line[j] == 'U' && line[j+1] == '=')
                        {
                            count = 0;
                            j+=2;
                            while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                                str[count++] = line[j++];
                            str[count] = '\0';
                            U = atof(str);
                            if(line[j] == 'M') k *= 1000000;
                            else if (line[j] == 'm') k /= 1000;
                            else if (line[j] == 'k') k *= 1000;
                            P = U * k * I * m;
                            printf("Problem #%d\nP=%.2lfW\n\n",i,P);
                            j = 100;
                            break;
                        }
                        else if(line[j] == 'P' && line[j+1] == '=')
                        {
                            count = 0;
                            j+=2;
                            while((line[j] >= '0' && line[j] <= '9') || (line[j] == '.'))
                                str[count++] = line[j++];
                            str[count] = '\0';
                            P = atof(str);
                            if(line[j] == 'M') k *= 1000000;
                    else if (line[j] == 'm') k /= 1000;
                    else if (line[j] == 'k') k *= 1000;
                            U = P * k / (I * m);
                            printf("Problem #%d\nU=%.2lfV\n\n",i,U);
                            j = 100;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
*/
