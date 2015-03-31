#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI 3.14159
using namespace std;

map<int, string>mp;

int main()
{
    _


        int i;
        mp[61] = "Brasilia";
        mp[71] = "Salvador";
        mp[11] = "Sao Paulo";
        mp[21] = "Rio de Janeiro";
        mp[32] = "Juiz de Fora";
        mp[19] = "Campinas";
        mp[27] = "Vitoria";
        mp[31] = "Belo Horizonte";

        scanf("%d", &i);

        if(mp.find(i)==mp.end()) printf("DDD not found\n");
        else printf("%s\n", mp[i].c_str());

    return 0;
}
