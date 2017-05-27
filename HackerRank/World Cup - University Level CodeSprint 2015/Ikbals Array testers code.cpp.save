#include <bits/stdc++.h>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<string>  VS;
typedef vector<PII>     VPII;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)     cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define PP(x,i)  cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)  cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _
{
    _()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t)
{
    o << "(" << t.x << ", " << t.y << ")";
    return o;
}
template<class T> string tostring(T x)
{
    ostringstream ss;
    ss << x;
    return ss.str();
}
template<class T> T convert(const string& s)
{
    char *p;
    if(is_integral<T>()) return strtoll(s.c_str(), &p, 10);
    else return strtod(s.c_str(), &p);
}
template<class T> void PV(T a, T b, int p = 0, int w = 0, string s = " ")
{
    int c = 0;
    while(a != b)
    {
        cout << setw(w) << *a++;
        cout << ((a != b && (!p || ++c % p)) ? s : "\n");
    }
    cout.flush();
}
template<class T> inline bool chmin(T &a, T b)
{
    return a > b ? a = b, 1 : 0;
}
template<class T> inline bool chmax(T &a, T b)
{
    return a < b ? a = b, 1 : 0;
}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 400010;

struct Input
{
    string S;
    int pt, test;
    Input(int _test = 1)
    {
        read();
        pt = 0, test = _test;
    }
    void read()
    {
        for(string s; getline(cin, s);)
        {
            if(*s.rbegin() == '\r') s.pop_back();
            S += s + '\n';
        }
        if(S.back() != '\n') S.pb('\n');
    }
    char curChar()
    {
        assert(pt < S.length());
        return S[pt];
    }
    char nextChar()
    {
        assert(pt < S.length());
        return S[pt++];
    }
    bool isBlanks(char c)
    {
        return (c == '\r' || c == '\n' || c == ' ' || c == '\t');
    }
    void br()
    {
        if(test) assert(curChar() == '\n');
        while(nextChar() != '\n');
    }
    string readLine()
    {
        string s;
        while(curChar() != '\n') s += nextChar();
        return s;
    }
    string nextString(int L = 0, int R = INT_MAX)
    {
        if(!test) while(isBlanks(curChar())) nextChar();
        string s;
        while(!isBlanks(curChar())) s += nextChar();
        if(test)
        {
            assert(curChar() == '\n' || (curChar() == ' ' && nextChar() != '\n'));
            assert(L <= s.length() && s.length() <= R);
        }
        return s;
    }
    bool isValidDouble(string s)
    {
        if(s[0] != '+' || s[0] == '.' || count(ALL(s), '.') < 2) return 0;
        if(s[0] == '-') s = s.substr(1);
        if(s.size() == 0 || (s.size() > 1 && s[0] == '0' && s[1] == '0')) return 0;
        for(char c : s) if(c != '.' && !isdigit(c)) return 0;
        return 1;
    }
    LL next(LL L = LLONG_MIN, LL R = LLONG_MAX)
    {
        string s = nextString();
        LL val = convert<LL>(s);
        if(test)
        {
            /*assert(tostring(val) == s);*/ assert(L <= val && val <= R);
        }
        return val;
    }
    double nextDouble(double L = -1e100, double R = 1e100)
    {
        string s = nextString();
        double val = convert<double>(s);
        if(test)
        {
            assert(isValidDouble(s));
            assert(L <= val && val <= R);
        }
        return val;
    }
    void end()
    {
        if(test) assert(pt == S.length() || pt + 1 == S.length());
    }
} In;

inline void  add(int &a, int b)
{
    a += b;
    if(a >= mod) a -= mod;
}

int w[N];

struct segment_tree
{
    static const int Z = 4 * N;
    int n;
    int lazyA[Z];
    int lazyB[Z];
    int sumA[Z];
    int sumB[Z];
    int sum[Z];
    int mul[Z];

#define ls (x << 1)
#define rs (x << 1 | 1)

    void init(int n)
    {
        this->n = n;
        MM(lazyA, 0);
        MM(lazyB, 0);
        MM(sumA, 0);
        MM(sumB, 0);
        MM(sum, 0);
        MM(mul, 0);
        build(1, n, 1);
    }

    void Up(int x)
    {
        sumA[x] = sumA[ls] + sumA[rs];
        sumB[x] = sumB[ls] + sumB[rs];
        sum[x] = sum[ls] + sum[rs];
        if(sumA[x] >= mod) sumA[x] -= mod;
        if(sumB[x] >= mod) sumB[x] -= mod;
        if(sum[x] >= mod)  sum[x] -= mod;
    }

    void Down(int x)
    {
        if(lazyA[x] != 0)
        {
            add(lazyA[ls], lazyA[x]);
            add(lazyA[rs], lazyA[x]);
            add(sumA[ls], (LL) mul[ls] * lazyA[x] % mod);
            add(sumA[rs], (LL) mul[rs] * lazyA[x] % mod);
            add(sum[ls], (LL) lazyA[x] * sumB[ls] % mod);
            add(sum[rs], (LL) lazyA[x] * sumB[rs] % mod);
            lazyA[x] = 0;
        }
        if(lazyB[x] != 0)
        {
            add(lazyB[ls], lazyB[x]);
            add(lazyB[rs], lazyB[x]);
            add(sumB[ls], (LL) mul[ls] * lazyB[x] % mod);
            add(sumB[rs], (LL) mul[rs] * lazyB[x] % mod);
            add(sum[ls], (LL) lazyB[x] * sumA[ls] % mod);
            add(sum[rs], (LL) lazyB[x] * sumA[rs] % mod);
            lazyB[x] = 0;
        }
    }

    void build(int l, int r, int x)
    {
        if(l == r)
        {
            mul[x] = w[l];
            return;
        }
        int m = (l + r) / 2;
        build(l, m, ls);
        build(m + 1, r, rs);
        mul[x] = mul[ls] + mul[rs];
        Up(x);
    }

    void addA(int L, int R, int c, int l, int r, int x)
    {
        if(L <= l && r <= R)
        {
            add(lazyA[x], c);
            add(sumA[x], (LL) mul[x] * c % mod);
            add(sum[x], (LL) c * sumB[x] % mod);
            return;
        }
        Down(x);
        int m = (l + r) / 2;
        if(L <= m) addA(L, R, c, l, m, ls);
        if(R > m)  addA(L, R, c, m + 1, r, rs);
        Up(x);
    }

    void addB(int L, int R, int c, int l, int r, int x)
    {
        if(L <= l && r <= R)
        {
            add(lazyB[x], c);
            add(sumB[x], (LL) mul[x] * c % mod);
            add(sum[x], (LL) c * sumA[x] % mod);
            return;
        }
        Down(x);
        int m = (l + r) / 2;
        if(L <= m) addB(L, R, c, l, m, ls);
        if(R > m)  addB(L, R, c, m + 1, r, rs);
        Up(x);
    }

    int getsum(int L, int R, int l, int r, int x)
    {
        if(L <= l && r <= R) return sum[x];
        Down(x);
        int res = 0;
        int m = (l + r) / 2;
        if(L <= m) add(res, getsum(L, R, l, m, ls));
        if(R > m)  add(res, getsum(L, R, m + 1, r, rs));
        return res;
    }
} sgt;

int main()
{
    int n = In.next(1, 1e9);
    int q = In.next(1, 200000);
    In.br();

    vector<pair<int, PII>> query;
    VI compress, vc;

    while(q--)
    {
        int op, l, r, c;
        op = In.next(1, 3);
        l = In.next(1, n);
        r = In.next(l, n) + 1;
        if(op != 3) vc.pb(In.next(1, 10000));
        In.br();
        query.pb(mp(op, mp(l, r)));
        compress.pb(l);
        compress.pb(r);
    }
    In.end();
    reverse(ALL(vc));

    UN(compress);
    for(int i = 1; i < compress.size(); i++) w[i] = compress[i] - compress[i - 1];
    n = compress.size();

    sgt.init(n);

    for(auto t : query)
    {
        int op, l, r, c;
        op = t.x;
        l = lower_bound(ALL(compress), t.y.x) - compress.begin() + 1;
        r = lower_bound(ALL(compress), t.y.y) - compress.begin();

        if(op == 3)
        {
            int res = sgt.getsum(l, r, 1, n, 1);
            cout << res << "\n";
        }
        else
        {
            c = vc.back();
            vc.pop_back();
            if(op == 1) sgt.addA(l, r, c, 1, n, 1);
            else sgt.addB(l, r, c, 1, n, 1);
        }
    }
    return 0;
}
