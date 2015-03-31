#include <stdio.h>

int main()
{
    int caseno=1, i, j, road, integer, approved, flag, character;

    scanf("%d %d", &road, &integer);

    while(integer>0 && road<10001)
    {
        flag = 0;
        approved = integer;
        for (i = 0; i <=26; ++i)
        {
            if(road <= approved)
            {
                flag = 1;
                character = i;
                break;
            }
            approved += integer;
        }

        if(flag) printf("Case %d: %d\n", caseno++, character);
        else printf("Case %d: impossible\n", caseno++);
        scanf("%d %d", &road, &integer);
    }
    return 0;
}
