#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

bool validity_check(char line[], int base)
{
    if(base<=10)
    {
        char lim = (char)(base - 1 + '0');
        int n;
        n = strlen(line);
        for (int i = 0; i<n; i++)
            if(line[i]>lim||line[i]<'0') return false;
        return true;
    }
    else
    {
        int n, k = base-11;
        n = strlen(line);
        for (int i = 0; i<n; i++)
            if(!((line[i]<='9'&&line[i]>='0')||(line[i]<=('A'+k)&&line[i]>='A')))
            {
                return false;
            }

        return true;
    }
}

ll dig[200];

int main()
{
    _
    int n, base1, base2;
    ll num,sum, factor;
    char line[200], converted[200],ch;

    while(~scanf("%d %d %s", &base1, &base2, line))
    {
        n = (int)strlen(line);
        for (int i =0; i<n; i++)
            line[i]=toupper(line[i]);
        if(validity_check(line, base1))
        {
            factor = 1LL;
            sum=0LL;
            for (int i = n - 1; i>=0; i--)
            {
                if(line[i]<='9')num = (ll)(line[i]-'0');
                else num = (ll)(line[i]-'A'+10);
                sum += (factor*num);
                factor*=(ll)base1;
            }
//            cout<<sum<<endl;
            factor = 1LL;
            num=1LL;
            n=1;
            dig[0] = 1LL;
            while(num)
            {
                num=(sum/factor);
                dig[n]=factor*=base2;
                n++;
            }
            n-=2;
            for (int i =0; i<n; i++)
            {
                num = sum/dig[n-i-1];
                sum%=dig[n-i-1];
                if(num<10) ch = num+'0';
                else ch = num-10+'A';
                converted[i]=ch;
            }
            if(!n)
            {
                converted[0]='0';
                converted[1]='\0';
            }
            else converted[n]='\0';
            printf("%s base %d = %s base %d\n",line,base1,converted,base2);
        }
        else printf("%s is an illegal base %d number\n", line, base1);
    }
    return 0;
}
