#include <stdio.h>
#include <string.h>

int main() {

    double sal, nsal, earn;
    int per;

    scanf("%lf", &sal);

    if(sal<=400.00) nsal = sal*1.15, earn = sal*0.15, per = 15;
    else if(sal<=800.00) nsal = sal*1.12, earn = sal*0.12, per = 12;
    else if(sal<=1200.00) nsal = sal*1.1, earn = sal*0.1, per = 10;
    else if(sal<=2000.00) nsal = sal*1.07, earn = sal*0.07, per = 7;
    else nsal = sal*1.04, earn = sal*0.04, per = 4;

    printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", nsal, earn, per);
    return 0;
}
