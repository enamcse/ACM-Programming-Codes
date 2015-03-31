#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main()
{
    int count = 0, flag = TRUE;
    double guess, root, test, error;

    printf("Initial guess : ");
    scanf("%lf", &guess);

    while (flag)
    {
        ++count;
        if(count == 50) flag = FALSE;

        test = 10. - 3. * guess *guess;

        if (test > 0)
        {
            root = pow(test, 0.2);
            printf("\nIteration number : %2d", count);
            printf("    x = %7.5f", root);

            error = fabs(root - guess);

            if (error > 0.00001) guess = root;
            else
            {
                flag = FALSE;
                printf("\n\nRoot = %7.5f", root);
                printf("    No of iteration : %2d", count);
            }
        }

        else
        {
            flag = FALSE;
            printf("\nNumbers out of range - try another initial guess");
        }
    }

    if (( count == 50 ) && ( error > 0.00001))
        printf("\n\nConvergence not obtained after 50 iterations");

    return 0;
}
