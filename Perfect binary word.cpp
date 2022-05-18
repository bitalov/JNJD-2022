// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      ans += cnt / 3;
      cnt = 0;
    } else
      ++cnt;
  }

  cout << ans + (cnt / 3) << '\n';
}