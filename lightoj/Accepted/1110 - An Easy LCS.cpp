#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 109
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int data[sz][sz], len_a, len_b;
string a, b, dp[sz][sz];

int LCS(int x,int y)
{
    if(x >= len_a || y>= len_b) return 0;
    int &ret = data[x][y];
    if(ret!=-1) return ret;
    ret = max(LCS(x+1,y),LCS(x,y+1));
    if(a[x]==b[y])ret = max(ret, LCS(x+1,y+1)+1);
    return ret;
}

string find_path(int i, int j)
{
    if(i>= len_a || j >= len_b) return "";
    string &ret = dp[i][j];
    if(ret!="-") return ret;
    ret = "";
    if(a[i]==b[j])
    {
        ret = a[i];
        ret += find_path(i+1,j+1);
        return ret;
    }
    if(LCS(i+1,j)==LCS(i,j+1))
    {
        string s1,s2;
        s1 = find_path(i+1,j);
        s2 = find_path(i,j+1);
        if(s1<s2) return ret=s1;
        return ret=s2;
    }
    if(LCS(i+1,j)>LCS(i,j+1))
    {
        return ret=find_path(i+1,j);
    }
    return ret=find_path(i,j+1);
}



int main()
{
    _
    int n,cas=1;
    char line[sz];
    scanf("%d", &n);


    while(n--)
    {
        clr(data,-1);

        scanf(" %s", line);
        a = line;
        scanf(" %s", line);
        b = line;
        len_a = a.size();
        len_b = b.size();
        for (int i = 0; i<=len_a; i++)
            for (int j = 0; j<=len_b; j++)
                dp[i][j] = "-";
        LCS(0,0);
        a = find_path(0,0);
        if(a.size()) printf("Case %d: %s\n",cas++,a.c_str());
        else printf("Case %d: :(\n",cas++);
    }


    return 0;
}
/*
3

ab
ba

zxcvbn
hjgasbznxbzmx

you
kjhs
*/
