//Verdict: AC
//#include <bits/stdc++.h>

int no[10];

    for (int i = 0; i<6; i++)
    {
        scanf("%d", &now);
        no[ now ]++;
    }

    n = 0;
    for (int i  = 0; i<10; i++)
        if(n<no[i])
        {
            n = no[i];
            m = i;
        }
    if(n==6) printf("Elephant");
    else if(n==5) printf("Bear");
    else if(n==4)
    {
        n = 0;
        for (int i  = 0; i<10; i++)
        if(i!=m)
        {
            n = max(no[i],n);
        }
        if(n==1) printf("Bear");
        else printf("Elephant");
    }
    else printf("Alien");




    return 0;
}
