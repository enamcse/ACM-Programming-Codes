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
#define PI acos(-1)
using namespace std;


struct data{
    int a,b;
    bool operator< (const data &z) const{
        if(z.b==b) return z.a>a;
        else return z.b>b;
    }
    data(int x, int y){
    a = x;
    b = y;
    }
};

priority_queue<data> pq;

int main()
{
    _
    int n, p,q, k = 1, point=0;
    scanf("%d", &n);
    for (int i =0;i<n; i++)
    {
        scanf("%d %d", &p, &q);
        pq.push(data(p,q));
    }
    while(!pq.empty()&&k)
    {
        point+= pq.top().a;
        k+= pq.top().b;
        k--;
//        cout<<pq.top().a<<" "<<pq.top().b<<" "<<k<<endl;
        pq.pop();
    }
    cout<<point;
    return 0;
}
