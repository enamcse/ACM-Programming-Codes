 #include <stdio.h>

 int main()
 {
     long long n, s;
     while (scanf("%lld",&n)==1)
     {
         n>>=1;
         n++;
         s = n * n;
         s<<=1;
         s-=3;
         s*=3;
         printf("%lld\n", s);
     }
     return 0;
 }
