#include <stdio.h>

int main()
{
    int month[2], day[2], year[2], i, t, age;

    scanf("%d", &t);

    for (i = 1; i <= t; ++i)
    {
        scanf("%d/%d/%d", &day[0], &month[0], &year[0]);
        scanf("%d/%d/%d", &day[1], &month[1], &year[1]);

        if (year[1] > year[0]) printf("Case #%d: Invalid birth date\n", i);
        else if (year[1] == year[0] && month[1] > month[0]) printf("Case #%d: Invalid birth date\n", i);
        else if (year[1] == year[0] && month[1] == month[0] && day[1] > day[0]) printf("Case #%d: Invalid birth date\n", i);
        else
        {
            age = year[0] - year[1];
            if (month[0] < month[1]) age--;
            else if (month[0] == month[1] && day[1] > day[0]) age--;
            if (age > 130) printf("Case #%d: Check birth date\n", i);
            else printf("Case #%d: %d\n", i, age);
        }
    }
    return 0;
}
