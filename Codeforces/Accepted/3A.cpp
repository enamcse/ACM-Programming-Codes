#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

vector<int>v;

int main()
{
    _
    int i_i, i_j, o_i, o_j, dif_i, dif_j, dif,i=0;
    char ch;
    scanf("%c%d",&ch,&i_j);
    i_i = (ch - 'a'+1);
    scanf(" %c%d",&ch,&o_j);
    o_i = (ch - 'a'+1);
    dif_i = i_i>o_i?i_i-o_i:o_i-i_i;
    dif_j = i_j>o_j?i_j-o_j:o_j-i_j;
    dif = dif_i>dif_j?dif_i:dif_j;
    printf("%d\n", dif);
    while(i_i!=o_i||i_j!=o_j)
    {
        i++;if(i==30) break;
        if(i_i==o_i)
        {
            if(i_j>o_j){printf("D\n");i_j--;}
            else {printf("U\n");i_j++;}
        }
        else if(i_j==o_j)
        {
            if(i_i>o_i){printf("L\n");i_i--;}
            else {printf("R\n");i_i++;}
        }
        else
        {
            if(i_i<o_i&&i_j<o_j)
            {
                printf("RU\n");
                i_i++;
                i_j++;
            }
            else if (i_i>o_i&&i_j>o_j)
            {
                printf("LD\n");
                i_i--;
                i_j--;
            }
            else if (i_i<o_i&&i_j>o_j)
            {
                printf("RD\n");
                i_i++;
                i_j--;
            }
            else if (i_i>o_i&&i_j<o_j)
            {
                printf("LU\n");
                i_i--;
                i_j++;
            }
        }
    }
    return 0;
}
