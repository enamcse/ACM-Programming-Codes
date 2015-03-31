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

int main()
{
    _
    char aa[20], bb[20], aaa[20], bbb[20], ccc[20], cc[20];
    ll a, b, c, a1,b1,c1;
    scanf("%s %s", aaa, bbb);
    ll len, k,i;

    len = strlen(aaa);
//    cout<<len;
    for (i =0, k =0; i<len; i++)
        if(aaa[i]!='0') aa[k++]=aaa[i];
    aa[k] = '\0';
    len = strlen(bbb);
    for (i =0, k =0; i<len; i++)
        if(bbb[i]!='0') bb[k++]=bbb[i];
    bb[k] = '\0';
    a = atol(aaa);
    b = atol(bbb);
    c = a + b;

    ltoa(c,ccc,10);
    len = strlen(ccc);
    for (i =0, k =0; i<len; i++)
        if(ccc[i]!='0') cc[k++]=ccc[i];
    cc[k] = '\0';
    a1 = atol(aa);
    b1 = atol(bb);
    c1 = atol(cc);
    if(a1+b1==c1) printf("YES");
    else printf("NO");
    return 0;
}
