/**
* H:\Dropbox\Code\HackerRank\World Cup - University Level CodeSprint 2015\Alien's Age.cpp
* Created on: 2015-09-13-13.17.53, Sunday
* Verdict: Solved
* Author: Enamul Hassan and Khan Mohammad Rumman Mahmud Mahdi Al Masud
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 1005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int grid[4][sz][sz],n,m, row[4], col[4], diag[sz][sz], csum[sz][sz], last[4][sz][sz];
int csumd[4][sz][sz],csumr[4][sz][sz];

void printLast(int cur)
{
    cout<<"Last=================="<<cur<<endl;
    for (int i = 1; i<=row[cur]; i++)
    {
        for (int j = 1; j<=col[cur]; j++)
            cout<<last[cur][i][j];
        cout<<endl;
    }
}

void printCumSum(int cur)
{
    cout<<"CumSum================"<<cur<<endl;
    for (int i = 1; i<=row[cur]; i++)
    {
        for (int j = 1; j<=col[cur]; j++)
            cout<<csum[i][j];
        cout<<endl;
    }
}
void printDiag(int cur)
{
    cout<<"Diag=================="<<cur<<endl;
    for (int i = 1; i<=row[cur]; i++)
    {
        for (int j = 1; j<=col[cur]; j++)
            cout<<diag[i][j];
        cout<<endl;
    }
}

void update(int x, int y, int z, int mid)
{
    csum[y][z]++;
    csum[y+mid][z]--;
    diag[y][z+1]--;
    diag[y+mid][z+mid]++;
}

void calc(int i,int mid)
{
//    cout<<"before ~~~~ i = "<<i<<" mid = "<<mid<<endl;
//    printCumSum(i);
//    printDiag(i);
    for (int j = 1; j<=row[i]; j++)
        for (int k = 1; k<=col[i]; k++)
        {
            csum[j][k] += csum[j-1][k];
        }

    for (int j = 1; j<=row[i]; j++)
        for (int k = 1; k<=col[i]; k++)
        {
            diag[j][k] += diag[j-1][k-1];
        }

    for (int j = 1; j<=row[i]; j++)
        for (int k = 1; k<=col[i]; k++)
        {
            csum[j][k]+=csum[j][k-1]+diag[j][k];
            last[i][j][k] = csum[j][k];
        }
//    cout<<"after ~~~~ i = "<<i<<" mid = "<<mid<<endl;
//    printCumSum(i);
//    printDiag(i);
}



void rotateLast(int pre, int cur)
{
    for (int i = 1; i<=row[pre]; i++)
    {
        for (int j = 1; j<=col[pre]; j++)
            last[cur][j][ row[pre]-i+1] |= last[pre][i][j];
    }
    row[cur]=col[pre];
    col[cur]=row[pre];
}


void print(int cur)
{
    cout<<"======================"<<cur<<endl;
    for (int i = 1; i<=row[cur]; i++)
    {
        for (int j = 1; j<=col[cur]; j++)
            cout<<grid[cur][i][j];
        cout<<endl;
    }
}


bool check(int mid)
{
//    cout<<"mid = "<<mid<<endl;
    int total=((mid*(mid+1))>>1);
    for (int i = 0; i<4; i++)
    {
        clr(csum,0);
        clr(diag,0);
        for (int j = 1; j<=row[i]-mid+1; j++)
            for (int k = 1; k<=col[i]-mid+1; k++)
            {
                int sum = csumd[i][j+mid-1][k+mid-1] - csumd[i][j-1][k-1];
                int sub = csumr[i][j+mid-1][k-1] - csumr[i][j-1][k-1];
                sum-=sub;

//                if(sum==6)cout<<i<<" j = "<<j<<" k = "<<k<<" mid = "<<mid<<" sum = "<<sum<<" total = "<<total<<endl;

                if(total == sum)
                {
                    update(i,j,k,mid);
                }
            }

        calc(i,mid);

    }

//    print(0);
//    printLast(0);
    for (int i = 0; i<3; i++)
    {
//        print(i);
//        printLast(i);
        rotateLast(i,i+1);
    }
    rotateLast(3,0);


//    printLast(0);
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=m; j++)
        {
//            if(!grid[0][i][j])
//            {
////                assert(!last[0][i][j]);
//                cout<<"i = "<<i<<" j = "<<j<<" last = "<<last[0][i][j]<<endl;
//            }
            if(grid[0][i][j] && !last[0][i][j]) return false;
        }
    return true;
}

int solve()
{
    int low=0,high = min(n,m), mid, res=0;

    res=0;
    while(low<=high)
    {
        mid = ((low+high)>>1);
        if(check(mid))
        {
            low = mid+1;
            res=mid;
        }
        else high = mid-1;
    }
    return res;
}


void rotate90(int pre, int cur)
{
    for (int i = 1; i<=row[pre]; i++)
    {
        for (int j = 1; j<=col[pre]; j++)
            grid[cur][j][ row[pre]-i+1] = grid[pre][i][j];
    }
    row[cur]=col[pre];
    col[cur]=row[pre];
}




void preprocess()
{
    for (int i = 0; i<4; i++)
    {
        for (int j = 1; j<=row[i]; j++)
            for (int k = 1; k<=col[i]; k++)
                csumr[i][j][k] = grid[i][j][k]+csumr[i][j][k-1];

        for (int j = 1; j<=row[i]; j++)
            for (int k = 1; k<=col[i]; k++)
                csumd[i][j][k] = csumr[i][j][k] + csumd[i][j-1][k-1];

        for (int k = 1; k<=col[i]; k++)
            for (int j = 1; j<=row[i]; j++)
                csumr[i][j][k] += csumr[i][j-1][k];
    }
}

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    char line[sz];
    scanf("%d %d", &n, &m);
    row[0] =n;
    col[0] =m;

    for (int i = 0; i<n; i++)
    {
        scanf("%s", line);
        for (int j = 0; j<m; j++)
            grid[0][i+1][j+1] = (line[j]=='#');
    }

//    print(0);
    for (int i = 0; i<3; i++)
    {
        rotate90(i,i+1);
//        print(i+1);
    }
    preprocess();
    int ans=solve();
//    assert(ans>0);
    printf("%d",ans);

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
