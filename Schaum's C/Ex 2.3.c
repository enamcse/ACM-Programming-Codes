#include <stdio.h>

int main()
{
    /*
    int auto, break, case, char, const, continue, default, do, double, else, enum;
    int extern, float, for, goto, if, int, long, register, return, short, signed;
    int sizeof, static, struct, switch, typedef, union, unsigned, void, volatile, while;

    these are the keywords which cant be used as identifier.
    */

    int const_cast, size_t, static_cast, typeid, typename;
    /*these five words became blue while writing, but they can be used as identifier.*/
    int ada, far, near, /*asm,*/ fortran, pascal, entry, huge;
    /*asm makes error in this compilier*/
    const_cast = 1;
    size_t = 2;
    static_cast = 3;
    typeid = 4;
    typename = static_cast * typeid;
    ada = 6;
    far = 7;
    near = 8;
    fortran = 9;
    pascal = 10;
    entry = 11;
    huge = 12;

    printf("%d\n%d\n%d\n%d\n%d\n", const_cast, size_t, static_cast, typeid, typename);
    printf("%d\n%d\n%d\n%d\n%d\n", ada, far, near, /*asm,*/ fortran, pascal);
    printf("%d\n%d\n", entry, huge);

    return 0;
}
