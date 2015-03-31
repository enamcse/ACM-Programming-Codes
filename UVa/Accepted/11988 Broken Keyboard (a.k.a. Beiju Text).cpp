#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;



int main()
{
    _
    char line[sz], ch;
    deque <string>dq;
    bool flag = false;
    string st="";
    while(gets(line))
    {
        int len = strlen(line);
        for (int i = 0; i<len; i++)
        {
            ch = line[i];
            switch(ch)
            {
            case '[':
                if(flag) dq.push_front(st);
                else dq.pb(st);
                st = "";
                flag = true;
                break;
            case ']':
                if(flag) dq.push_front(st);
                else dq.pb(st);
                st = "";
                flag = false;
                break;
            default:
                st.pb(ch);
                break;
            }
        }
        if(st!="")
        {
            if(flag) dq.push_front(st);
            else dq.pb(st);
            st = "";
        }
        while(!dq.empty())
        {
            printf("%s", dq.front().c_str());
            dq.pop_front();
        }
        puts("");
    }



    return 0;
}
