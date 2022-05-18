// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int r[MAXN];
int l[MAXN];
ll a[MAXN];

void left(int n) {
  stack<int> mxst;

  for (int i = 1; i <= n; i++) {
    while (mxst.size() and a[i] >= a[mxst.top()]) {
      l[mxst.top()] = abs(mxst.top() - i);
      mxst.pop();
    }

    mxst.push(i);
  }
}

void right(int n) {
  stack<int> mxst;

  for (int i = n; i >= 1; i--) {
    while (mxst.size() and a[i] >= a[mxst.top()]) {
      r[mxst.top()] = abs(mxst.top() - i);
      mxst.pop();
    }

    mxst.push(i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      l[i] = r[i] = 1e9;
    }

    left(n);

    right(n);

    for (int i = 1; i <= n; i++) {
      int best = min(l[i], r[i]);
      if (best == 1e9)
        cout << -1 << ' ';
      else
        cout << best << ' ';
    }
    cout << '\n';
  }
}