// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e4 + 5;

int spy[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m and n and m) {
    vector<pair<int, int> > rng;
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      rng.push_back({l, 0});
      rng.push_back({r + 1, -1});
    }

    for (int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      rng.push_back({x, i});
    }

    sort(rng.begin(), rng.end());
    int guards = 0;
    for (auto &k : rng) {
      if (k.second == 0) {
        ++guards;
      } else if (k.second == -1)
        --guards;
      else {
        spy[k.second] = guards;
      }
    }

    for (int i = 1; i <= m; i++) cout << spy[i] << ' ';
  }
}