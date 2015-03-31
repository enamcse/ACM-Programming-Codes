#include <stdio.h>
#include <string.h>

int main()
{
    int i, flag, exit;
    char country[][30] = {{"Canada"}, {"England"},{"France"},{"Germany"},{"India"},
        {"Israel"},{"Italy"},{"Japan"},{"Mexico"}, {"People\'s Republic of China"}, {"Russia"},{"United States"}};
    char capital[][20] = {{"Ottawa"}, {"London"},{"Paris"},{"Bonn"},{"New Delhi"},
        {"Jerusalem"},{"Rome"},{"Tokyo"},{"Mexico City"}, {"Beijing"}, {"Moscow"},{"Washington"}};
    char input[30];

    do
    {
        printf("Enter the name of the country:\n");
        scanf("%s", input);
        if (toupper(input[0]) == 'U')
        {
            input[6] = ' ';
            scanf("%s", &input[7]);
        }
        else if (toupper(input[0]) == 'P')
        {
            input[8] = ' ';
            scanf("%s", &input[9]);
            input[17] = ' ';
            scanf("%s", &input[18]);
            input[20] = ' ';
            scanf("%s", &input[21]);
        }


        for (i = 0; i < 12; ++i)
        {
            flag = strcmpi(input, country[i]);
            if (flag == 0) printf("\n\nThe capital of %s is %s.\n\n\n", country[i], capital[i]);
        }

        printf("Press 0 to exit and 1 to continue.\n");
        scanf("%d", &exit);

    }
    while(exit != 0);

    return 0;
}
