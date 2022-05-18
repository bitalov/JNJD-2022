// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;
int n;
const int MAXN = 4e2 + 5;
int a[MAXN][MAXN];

int trace() {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        ret += a[i][j];
    }

  }
  return ret;
}

int rows() {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    set < int > se;
    for (int j = 0; j < n; j++) {
      se.insert(a[i][j]);
    }
    if (se.size() < n)
      ++ret;
  }
  return ret;
}

int cols() {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    set < int > se;
    for (int j = 0; j < n; j++) {
      se.insert(a[j][i]);
    }
    if (se.size() < n)
      ++ret;
  }
  return ret;
}

int main() {

  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  cout << trace() << ' ' << rows() << ' ' << cols() << '\n';

}