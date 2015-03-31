#include<stdio.h>

int main()
{
    int TC,tc,F,f,A,a1,a2;
    scanf("%d",&TC);
    for(tc=1; tc<=TC; tc++){
        scanf("%d", &A);
        scanf("%d", &F);
        for(f=1; f<=F; f++){
            for(a1=1; a1<=A; a1++){
                for(a2=1; a2<=a1; a2++)
                    printf("%d", a1);
                printf("\n");
            }
            for(a1=A-1; a1>=1; a1--){
                for(a2=1; a2<=a1; a2++)
                    printf("%d", a1);
                printf("\n");
            }
            printf("\n");
        }
}
}



