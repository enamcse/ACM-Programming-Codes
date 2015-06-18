//Verdict: SOLVED
#include <bits/stdc++.h>
#define sz 50005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007

using namespace std;

int main()

{
#ifdef ENAM
//        fread;
//    fwrite;
#endif // ENAM
    ll n, cnt = 0, now, counter, sum;

    scanf("%I64d", &n);

    counter = 3 - n%3;
    if(!counter) counter =3;
    while(1)
    {
        now = counter+n;
        now/=3;
        if(counter&1LL) sum = counter * ( (counter+1)>>1LL );
        else sum =  (counter+1)* ( counter>>1LL );
        if(now>=sum) cnt++;
        else break;
        counter+=3;
    }

    printf("%I64d", cnt);


    return 0;
}


