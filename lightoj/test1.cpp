#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

struct state {
  int node, cost;
  state(int nn, int cc) {
    node = nn;
    cost = cc;
  }
};

int n, x;
char grid[2222][2222];
bool vis[2222];
int cost[2222];
void BFS() {
  x--;
  vector<state> queue;
  memset(vis, 0, sizeof vis);
  memset(cost, -1, sizeof cost);
  queue.push_back(state(x, 0));
  vis[x] = 1;
  for (int i = 0; i < int(queue.size()); ++i) {
    state& st = queue[i];
    cout<<(&st)<<endl;
    cout<<st.node<<" *** "<<st.cost<<endl;
    for (int j = 0; j < n; ++j){
      if (grid[st.node][j] == '1' && !vis[j]) {
        vis[j] = 1;
        cout<<"before\n";
        queue.push_back(state(j, st.cost + 1));
        cout<<"after\n";
      }

    cout<<st.node<<" ** "<<st.cost<<endl;
    cout<<(&queue[i])<<endl;
    }
    cost[st.node] = st.cost;
  }
}

int main() {
  int T;
  cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) cin >> grid[i][j];
    BFS();
    for (int i = 0; i < n; ++i) {
      if (i) cout << " ";
      cout << cost[i];
    }
    cout << endl;
  }
  return 0;
}
/*
3
3 1
000
000
000
4 1
1111
1111
1111
1111
6 1
011010
000100
000011
000001
000001
000000
*/
