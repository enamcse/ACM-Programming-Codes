#include <bits/stdc++.h>

#define sz 55
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

int pres[200];  ///presedence of operators

string infix_to_postfix(string P)
{
    stack<char>s;
    string Q;
    int i =0;
    char element;
    while(i<P.size())
    {
        element = P[i++];
        if(isalpha(element)) Q=Q+element;   ///operand
        else if(element == '(' || s.empty()) s.push(element);    ///parenthesis start or nothing in stack
        else if(element == ')')     ///parenthesis end
        {
            while(s.top()!='(')
            {
                Q=Q+s.top();
                s.pop();
            }
            s.pop();    ///poping up the first parenthesis
        }
        else
        {
            while(!s.empty() && pres[s.top()]>=pres[element])   ///wating for lower presedence or stack to be empty
            {
                Q=Q+s.top();
                s.pop();
            }
            s.push(element);
        }
    }

    while(!s.empty())   ///rest
    {
        Q=Q+s.top();
        s.pop();
    }
    return Q;
}

int eval_postfix(string &exp, int val[])
{
    stack<int>s;
    int len = exp.size();
    for (int i = 0; i<len; i++)
    {
        if(isalpha(exp[i])) s.push(val[exp[i]]);
        else if(exp[i]=='!')
        {
            int a = s.top();
            s.pop();
            s.push(!a);
        }
        else if(exp[i]=='&')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a&b);
        }
        else if(exp[i]=='|')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a|b);
        }
    }
    return s.top();
}

string simplify(string s)
{
    string f;
    int len=s.size();
    for (int i = 0; i<len; i++)
    {
        if(s[i]=='!')
        {
            int cnt = 0;
            while(i<len)
            {
                if(s[i]=='!') cnt++;
                else break;
                i++;
            }
            if(cnt%2) f=f+"!";
            if(i!=len)i--;
        }
        else f=f+s[i];
    }
    return f;
}



int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n, m, cas=1, val[200];
    char line[200];
    string s1,s2;

    pres['|'] = 1;
    pres['&'] = 2;
    pres['!'] = 3;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", line);
        s1 = line;
        s1 = simplify(s1);
        s1 = infix_to_postfix(s1);

        scanf("%s", line);
        s2 = line;
        s2 = simplify(s2);
        s2 = infix_to_postfix(s2);

        set<char>ss;
        int len = s1.size();
        for (int i = 0; i<len; i++) if(isalpha(s1[i]))ss.insert(s1[i]);
        len = s2.size();
        for (int i = 0; i<len; i++) if(isalpha(s2[i]))ss.insert(s2[i]);

        vector<char>v(ss.begin(), ss.end());
        bool flag = true;
        len = (1<<v.size());
        int n = v.size();
        for (int i = 0; i<len; i++)
        {
            for (int j = 0; j<n; j++)
                if(i&(1<<j)) val[ v[j] ] = 1;
                else val[ v[j] ] = 0;

            if(eval_postfix(s1,val)!=eval_postfix(s2,val))
            {
                flag = false;
                break;
            }
        }
        if(flag) printf("Case %d: Equivalent\n", cas++);
        else printf("Case %d: Not Equivalent\n", cas++);

    }


    return 0;
}
