#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
    _
    char line[20][2][101], ch[101];
    int n,q;
    scanf("%d ",&n);
    for (int i = 0; i<n; i++)
    {
        gets(line[i][0]);
        gets(line[i][1]);
//        puts(line[i][0]);
//        puts(line[i][1]);

    }
    scanf("%d ",&q);
//    printf("%d ",q);
    for (int j = 0; j<q; j++)
    {
        gets(ch);
        for (int i = 0; i<n; i++)

            if(!strcmp(line[i][0],ch))
            {
                puts(line[i][1]);
                break;
            }
    }
    return 0;
}
/*
3
ko te kader molla
tui rajakar tui rajakar
tumi ke ami ke
garo chakma bangali
jalo re jalo
agun jalo
2
jalo re jalo
ko te kader molla
*/
