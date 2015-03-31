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

char save[1000001][10];

void process()
{
    char v[50], temp;
    int k=1,i;
    for (i=0; i<50; i++)
        v[i]='@';
    for (int j=0; j<1000001; j++)
    {
        v[0]++;
        if(v[0]=='[')
        {
            v[1]++;
            v[0]='A';
            k=max(2,k);
            if(v[1]=='[')
            {
                v[2]++;
                v[1]='A';
                k=max(3,k);
                if(v[2]=='[')
                {
                    v[3]++;
                    v[2]='A';
                    k=max(4,k);
                    if(v[3]=='[')
                    {
                        v[4]++;
                        v[3]='A';
                        k=max(5,k);
                    }
                }
            }
        }
        for (i = 0; i<k; i++)
        {
            save[j][k-1-i] = v[i];
        }
        save[j][k] = '\0';
    }


}

int main()
{
    _
    int col=0, row=0, len, a,b, i=0, fact=1,n;
    char line[200],c[100],r[100];
    process();
    scanf("%d", &n);
    while(n--)
    {
        fact=1;
        scanf("%s", line);
        len = strlen(line);
        col=a=b=i=0;
        while(line[i]>=65)
        {
            c[a++]=line[i++];
        }
        while(i<len&&line[i]<65)
        {
            r[b++]=line[i++];
        }
        if(i==len)
        {
            c[a] = '\0';
            r[b] = '\0';
            len = strlen(c);
            for (i=len-1; i>=0; i--)
            {
                col+=(fact*(c[i]-'A'+1));
                fact*=26;
            }
            row = atoi(r);
            printf("R%dC%d\n",row,col);
        }
        else
        {
            a=0;
            i++;
            while(i<len)
            {
                c[a++]=line[i++];
            }
            c[a] = '\0';
            r[b] = '\0';
            row = atoi(r);
            col = atoi(c);
            fact = col;
            i=0;
            printf("%s%d\n",save[col-1],row);
        }
    }
    return 0;
}
