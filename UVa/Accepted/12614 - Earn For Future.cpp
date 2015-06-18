/* 
* @Author: Enamul Hassan
* @Date:   2015-04-21 17:10:48
* @Last Modified by:   Enamul
* @Last Modified time: 2015-04-21 17:11:33
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\Accepted\12614 - Earn For Future.cpp
*/

#include<stdio.h>
int main()
{
        int mx, n,t, m,i, cas=1;
        scanf("%d", &t);
        while(t--)
        {
                mx = 0;
                scanf("%d", &n);
                for(i = 0; i<n; i++)
                {
                        scanf("%d", &m);
                        mx = m>mx?m:mx;
                }
                printf("Case %d: %d\n",cas++, mx );
        }
        return 0;
}