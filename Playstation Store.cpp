// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 1e6 + 5;
int v[MAXN];

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  for (int i = 1; i <= a; i++) {
    v[i]++;
  }
  for (int i = n; i > n - b; i--) {
    v[i]++;
  }
  int good = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i] < 2) {
      ++good;
    }
  }

  if (good >= c)
    cout << "possible\n";
  else
    cout << "impossible\n";
}