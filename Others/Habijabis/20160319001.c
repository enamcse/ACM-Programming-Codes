    #include<stdio.h>

    int add(int k)
    {
        static int ret = 6;
        ret += k;
        return ret;
    }
    static int adds(int k)
    {
        int ret = 6;
        ret += k;
        return ret;
    }
    int main()
    {
        register int i,z[5];
        for(i = 4; i<10; i++)
        {
            printf("i = %d, sum = %d\n",i,add(i));
            printf("i = %d, ith = %d\n",i,adds(i));
        }

        //for(i=0; i<100;i++) printf("i = %d, z = %d\n", i, z[i]);

        z[0] = 9;
        printf("%d\n", z[0]);

        return 0;
    }
