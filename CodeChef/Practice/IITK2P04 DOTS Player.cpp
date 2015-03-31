/**
* H:\Dropbox\Code\CodeChef\Practice\IITK2P04 DOTS Player.cpp
* Created on: 2015-03-04-22.04.49, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
* Problem link: http://www.codechef.com/problems/IITK2P04
* Concept: At first, lets think the problem if n and m both ranges from
           1 to 100 instead of 1 to 1000. For every cell (i,j), a dfs
           would find the farthest node of this color and another dfs
           from that farthest node would find the maximum point from
           the current node. A global maximum variable can be updated
           each time. If we get any cycle, then global maximum would be
           compared with the number of items of this color.
           But here, it would cross the stack limit if this approach is
           used on the original constraint. So, the same thing should be
           implement using bfs instead of dfs.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1005
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

int rr[] = {0,0,1,-1};
int cc[] = {1,-1,0,0};
int conv[] = {1,0,3,2};

int t, n, m, arr[sz][sz], coll,res,cas=1,visited[sz][sz];
map<int ,int>mpp;
queue< pair<pair<int ,int>,pair<int,int> > >st;
void bfs(int x, int y,int ex)
{
    while(!st.empty()) st.pop();
    st.push({{x,y},{1,-1}});
    int now, level,u,v,fx,fy,mxlvl=-1;
    cas++;
    while(!st.empty())
    {
        x = st.front().first.first;
        y = st.front().first.second;
        visited[x][y] = cas;
        level = st.front().second.first;
        now = st.front().second.second;
        st.pop();
        if(level>mxlvl)
        {
            mxlvl = level;
            fx = x;
            fy = y;
        }
        for (int i = 0; i<4; i++)
        {
            if(now==i) continue;
            u = x+rr[i];
            v = y+cc[i];
            if(u<0||v<0||u>=n||v>=m||arr[u][v]!=coll) continue;
            if(visited[u][v]==cas)
            {
                res = max(res,mpp[coll]);
                return;
            }
            visited[u][v] = cas;
            st.push({{u,v},{level+1,conv[i]}});
        }

    }
    if(ex) bfs(fx,fy,0);
    res = max(res,mxlvl);
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM

    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>m;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
        {
            cin>>arr[i][j];
            mpp[ arr[i][j] ]++;
        }
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
        {
            coll = arr[i][j];
            if(!visited[i][j]) bfs(i,j,1);
        }
        if(res==1) res = 0;
        cout<<res<<"\n";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
