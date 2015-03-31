#include<stdio.h>
#include <math.h>
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output1.txt","w",stdout)
int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int a,x,T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
    scanf("%d",&a);
    if(a<=180000){
         printf("Case %d: 0\n",i);
    }
    else if((a>180000) && (a<480001)){ x=ceil((a-180000)*.10);
        if(x<2001){
           printf("Case %d: 2000\n",i);
        }
        else{
           printf("Case %d: %d\n",i,x);
        }}
    else if((a>480000) && (a<880001)){
        x=(30000+ceil((a-480000)*.15));
       printf("Case %d: %d\n",i,x);
    }
    else if((a>880000) && (a<1180001)){
            x=(90000+ceil((a-880000)*.20));printf("Case %d: %d\n",i,x);
    }
    else if(a>1180000){
         x=150000+ceil((a-1180000)*.25);printf("Case %d: %d\n",i,x);
    }}
    return 0;
}
