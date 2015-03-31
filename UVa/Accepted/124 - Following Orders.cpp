#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 26
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int adj[sz][sz], col[sz],element, elements[sz];
string ans;

char line[200];

void topsort_dfs()
{
    if(ans.size()==element)
    {
        printf("%s\n",ans.c_str());
        return;
    }

    for (int i = 0,j; i<element; i++)
    {
        if(col[i]) continue;
        for (j = 0; j<element; j++)
            if(i!=j&&adj[elements[i]][elements[j]]&&!col[j]) break;
        if(j<element) continue;
        col[i]=1;
        ans+=(elements[i]+'a');
        topsort_dfs();
        ans.erase(ans.size()-1);
        col[i]=0;
    }
    return;
}

int main()
{
    int start, len,a,b;
    char ch='\n';
    while(gets(line))
    {
        if(ch!='\n') puts("");
        ans="";
        element=0;
        clr(adj,0);

        start=0; len = strlen(line);
        while(start<len)
        {
            sscanf(line+start,"%c", &ch);
            elements[element++]=ch-'a';
            start+=2;
        }
        gets(line);
        start=0; len = strlen(line);
        while(start<len)
        {
            sscanf(line+start,"%c", &ch);
            a=ch-'a';
            start+=2;
            sscanf(line+start,"%c", &ch);
            b=ch-'a';
            start+=2;
            adj[b][a]=1;
        }
        sort(elements,elements+element);
        topsort_dfs();
    }
	return 0;
}
/*
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
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int adj[sz][sz], col[sz],element, elements[sz];
string ans;

char line[300];

void topsort_dfs()
{
    if(ans.size()==element)
    {
        printf("%s\n",ans.c_str());
        return;
    }
    char c;
    for (int i = 0,j; i<element; i++)
    {
        if(col[i]) continue;
        for (j = 0; j<element; j++)
            if(i!=j&&adj[elements[i]][elements[j]]&&!col[j]) break;
        if(j<element) continue;
        col[i]=1;
        c =(char)(elements[i]+'a');
        ans+=c;
        topsort_dfs();
        ans.erase(ans.size()-1);
        col[i]=0;
    }
    return;
}

int main()
{
    _
    int start, len,a,b;
    char ch='#';
    while(gets(line))
    {
        if(ch!='#') printf("\n");
        ans="";
        element=0;
        clr(adj,0);
//        clr(col,0);
        start=0; len = strlen(line);
        while(start<len)
        {
            sscanf(line+start,"%c", &ch);
            if(ch==' '){start++; continue;}
            elements[element++]=ch-'a';
            start++;
        }
        gets(line);
        start=0; len = strlen(line);
        while(start<len)
        {
            sscanf(line+start,"%c", &ch);
            if(ch==' '){start++; continue;}
            a=ch-'a';
            start++;
            while(start<len){
                sscanf(line+start,"%c", &ch);
                if(ch!=' ') break;
                start++;
            }

            b=ch-'a';
            start++;
            adj[b][a]=1;
        }
        sort(elements,elements+element);
        topsort_dfs();
    }
	return 0;
}
*/
