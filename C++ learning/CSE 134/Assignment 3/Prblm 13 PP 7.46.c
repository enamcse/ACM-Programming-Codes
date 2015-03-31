#include <stdio.h>
#include <math.h>

void iteration (int count, double guess, double error, double root);

int main()
{
    double guess, error = 1, root = 1;

    printf("Initial guess : ");
    while (scanf("%lf", &guess) == 1)
    {
        iteration(1, guess, error, root);
        printf("Initial guess : ");
    }


    return 0;
}

void iteration (int count, double guess, double error, double root)
{
    double test;

    if (count == 50 || error < 0.00001)
    {
        printf("\n\nRoot = %7.5lf", root);
        printf("    No of iteration : %2d\n\n", count - 1);
        return;
    }


    test = 10. - 3. * guess * guess;

    if (test > 0)
    {
        root = pow(test, 0.2);
        printf("\nIteration number : %2d", count);
        printf("    x = %7.5lf", root);

        error = fabs(root - guess);

        if (error > 0.00001) guess = root;
    }
    else
    {
        printf("\nNumbers out of range - try another ");
        return;
    }

    iteration(++count, guess, error, root);
    //if (( count == 50 ) && ( error > 0.00001))
    //printf("\n\nConvergence not obtained after 50 iterations");
}
