#include<cstdio>
#include<algorithm>
using namespace std;

int miin(int a,int b,int c);
int main()
{
    int t, i, ret, r,g,b,w,cs = 1,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&r,&g,&b,&w);

        ans = 0;
        while(1)
        {

            if((r == 0 && w == 0) ||
                    (g == 0 && w == 0) ||
                    (b == 0 && w == 0)) break;
            if(r > 0 && g > 0 && b > 0)
            {
                ret = miin(r,g,b);
                ans =+ ret;
                r-= ret;
                g-= ret;
                b-=ret;
            }
            else if(r == 0 && g > 0 && b > 0)
            {
                ret = miin(g,b,w);
                ans += ret;
                g-=ret;
                b-=ret;
                w-= ret;
            }
            else if(r > 0 && g == 0 && b > 0)
            {
                ret = miin(r,b,w);
                ans += ret;
                b-=ret;
                w-= ret;
                r-=ret;
            }
            else if(r > 0 && g > 0 && b == 0)
            {
                ret = miin(w,r,g);
                ans += ret;
                w-=ret;
                r-=ret;
                g-=ret;
            }
            else if(r == 0 && g == 0 && b > 0)
            {
                if(w >= 2)
                {
                    w -= 2;
                    b--;
                    ans++;
                }
                else break;
            }
            else if(r == 0 && g > 0 && b == 0)
            {
                if(w >= 2)
                {
                    w -= 2;
                    g--;
                    ans++;
                }
                else break;
            }
            else if(r > 0 && g == 0 && b == 0)
            {
                if(w >= 2)
                {
                    w -= 2;
                    r--;
                    ans++;
                }
                else break;
            }
            else if(r == 0 && g == 0 && b == 0)
            {

                ans += (w / 3);
                break;
            }
        }
        printf("Case %d: %d\n",cs++,ans);
    }

    return 0;
}

int miin(int r,int g, int b)
{
    if(r <= g && r <= b) return r;
    if(g <= r && g <= b) return g;
    if(b <= r && b <= g) return b;
}
