#include <stdio.h>

int main()
{
    int hw, i = 1, pastes, count;

    scanf("%d", &hw);

    while (hw > 0)
    {
        pastes = 1;
        count = 2;
        if (hw == 1) pastes = 0;
        else if (hw == 2) pastes = 1;
             else while (hw > count)
                  {
                      pastes++;
                      count = count * 2;
                  }
        printf("Case %d: %d\n", i++, pastes);

        scanf("%d", &hw);
    }
    return 0;
}
