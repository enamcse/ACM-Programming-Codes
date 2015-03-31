#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>

#define clrall(name,val) memset(name,(val),sizeof(name));
#define SF scanf
#define PF printf
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("outputR.txt","w",stdout)

using namespace std;

int set1[54],set2[54];
int n;

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int test,cas=0,col1[54],col2[54];
    SF("%d",&test);
    while(test--)
    {
        SF("%d",&n);
        for(int i=0; i<n; i++) SF("%d",&set1[i]);
        for(int i=0; i<n; i++) SF("%d",&set2[i]);
        sort(set1,set1+n);
//        reverse(set1,set1+n);
        sort(set2,set2+n);
        reverse(set2,set2+n);
        int res=0;
        clrall(col1,0);
        clrall(col2,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!col2[j]&&set1[i]>set2[j])
                {
                    res+=2;
                    col1[i]=1;
                    col2[j]=1;
                    break;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            if(!col1[i])
                for(int j=0; j<n; j++)
                {
                    if(!col2[j]&&set1[i]==set2[j])
                    {
                        res++;
                        col1[i]=1;
                        col2[j]=1;
                        break;
                    }
                }
        }
//        clrall(dp,-1);
//        PF("Case %d: %d\n",++cas,rec(0,0,0,0));
        PF("Case %d: %d\n",++cas,res);
    }
    return 0;
}














