// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int blocked[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];

int mxsz = 1;
int sz = 0;

void dfs(int u) {
  ++sz;
  if (blocked[u]) return;

  vis[u] = 1;
  for (auto &k : g[u]) {
    if (vis[k]) continue;

    dfs(k);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    cin >> blocked[i];
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i] || blocked[i]) continue;
    sz = 0;
    dfs(i);

    mxsz = max(mxsz, sz);
  }

  cout << mxsz;
}