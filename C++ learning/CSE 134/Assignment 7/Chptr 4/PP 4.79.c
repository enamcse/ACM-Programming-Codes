#include <stdio.h>

int main()
{
    float a = 2.5, b = 0.0005, c = 3000;

    printf("%f %f %f\n", a, b, c);
    printf("%3f %3f %3f\n", a, b, c);
    printf("%8f %8f %8f\n", a, b, c);
    printf("%8.4f %8.4f %8.4f\n", a, b, c);
    printf("%8.3f %8.3f %8.3f\n", a, b, c);
    printf("%e %e %e\n", a, b, c);
    printf("%3e %3e %3e\n", a, b, c);
    printf("%12e %12e %12e\n", a, b, c);
    printf("%12.4e %12.4e %12.4e\n", a, b, c);
    printf("%8.2e %8.2e %8.2e\n", a, b, c);
    printf("%-8f %-8f %-8f\n", a, b, c);
    printf("%+8f %+8f %+8f\n", a, b, c);
    printf("%08f %08f %08f\n", a, b, c);
    printf("%#8f %#8f %#8f\n", a, b, c);
    printf("%g %g %g\n", a, b, c);
    printf("%#g %#g %#g\n", a, b, c);


    return 0;
}
