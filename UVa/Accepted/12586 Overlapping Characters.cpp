#include <iostream>
#include <cstring>
using namespace std;

struct sets
{
    char presentation[16][50];
    char ch;
};

bool ok, test;

int main()
{
    sets aset[38];
    char garb[50], m[20], out[20], ab;
    int n, q, i, j, k, l, len, now, p, r, s, list[20], caseno=1;
    cin>>n>>q;
    for (i=0; i<n; i++)
        cin>>aset[i].ch;
    for (i = 0; i<n; i++)
    {
        for (j=0; j < 16; j++)
            cin>>aset[i].presentation[j];
        cin>>garb;
    }

    for (i = 0; i<q; i++)
    {
        cin>>m;
        len = strlen(m);
        for (k = 0; k < len; k++)
        {
            for (l = 0; l<n; l++)
            {
                if(aset[l].ch==m[k])
                {
                    now = l;
                    break;
                }
            }
            list[k] = now;
        }

        for (j=0; j<len; j++)
        {
            now = list[j];
            ok = false;

            for (r = 0; r < 16; r++)
            {
                for (p = 0; p < 43; p++)
                {
                    if (aset[now].presentation[r][p]=='*')
                    {
                        for (l = 0; l < len; l++)
                        {
                            k = list[l];
                            if(now==k) continue;
                            if (aset[now].presentation[r][p]==aset[k].presentation[r][p])
                            {
                                break;
                            }
                        }
                        if(l==len)
                        {
                            ok = true;
                        }
                    }

                    if(ok)
                    {
                        break;
                    }
                }
                if (ok) break;
            }

            if(ok) out[j] = 'Y';
            else out[j] = 'N';
        }
        out[j] = '\0';
        cout<<"Query "<<caseno++<<": "<<out<<endl;
    }
    return 0;
}
