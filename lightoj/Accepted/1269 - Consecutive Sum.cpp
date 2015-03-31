#include <cstdio>
#include <cstring>
#include <bitset>

#define sz 1600010
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (int)((1LL<<31)-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

// TRIE starts array
#define trie_sz 2
struct node
{
    int next[trie_sz];
    node()
    {
        for (int i = 0; i<trie_sz; i++) next[i] = 0;
    }
} data[sz];
int counter=1;

void insert_in_trie(char *str)
{
    int n = 0, now;
//    cout<<"ins: "<<str<<endl;
    for (int i = 0; i<32; i++)
    {
        now = (str[i]=='0'?0:1);
        if(data[n].next[now]==0)
        {
            data[n].next[now] = counter++;
        }
        n=data[n].next[now];
    }
    return;
}

bitset<32> search_in_trie(char *str, bitset<32> num)
{
    int n = 0, now;
//    cout<<"src: "<<str<<endl;
    for (int i = 0; i<32; i++)
    {
        now = (str[i]=='0'?0:1);
        if(data[n].next[now]==0)
        {
            num.flip(31-i);
            n=data[n].next[now==0?1:0];
        }
        else n=data[n].next[now];
    }
    return num;
}

bool delete_from_trie() // this is for memset only
{
    clr(data,0);
}
// TRIE ends using array

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    int mx, mn, x, y;
    bitset<32>num(0), mm(0), bb(0);
    scanf("%d", &t);

    char local[50];
    while(t--)
    {
        counter = 1;
        x=mx = 0LL;
        mn = inf;
        num = 0;
        strcpy(local,num.to_string().c_str());
        insert_in_trie(local);
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &y);
            x^= y;
            bb = num = x;

            strcpy(local,num.to_string().c_str());

            {
                mm = search_in_trie(local,num);
                mm ^= bb;
                mn = min(mn, (int) mm.to_ulong());
                num.flip();
                strcpy(local,num.to_string().c_str());
                mm = search_in_trie(local,num);
                mm ^= bb;
                mx = max(mx, (int) mm.to_ulong());
                strcpy(local,bb.to_string().c_str());
            }
            insert_in_trie(local);
        }
        printf("Case %d: %ld %d\n",cas++,mx,mn);
        if(t) delete_from_trie();
    }

    return 0;
}
