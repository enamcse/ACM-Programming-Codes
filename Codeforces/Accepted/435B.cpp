#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1,k, p, q, len;
    string s;

    cin>>s>>k;
    len = s.size();

    for (int i = 0; i<len && k; i++)
    {
        m = min(k+i,len-1);
        p=s[i]-'0';
        q=-1;
        for (int j = i+1; j<=m; j++)
        {
            if((s[j]-'0')>p) p = s[j]-'0', q = j;
        }
        if(q!=-1)
        {
            k -= (q-i);
            for (int j = q; j>i; j--)
                swap(s[j], s[j-1]);
        }
    }
    cout<<s<<endl;

    return 0;
}
