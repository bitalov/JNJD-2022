// Source: https://usaco.guide/general/io
// No need for MITM
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int n;
vector<int> a, b;
vector<pair<int, int> > info1, info2;
void solve1(int i, int cnt, int sum) {
  if (i == a.size()) {
    info1.push_back({cnt, sum});
    return;
  }
  solve1(i + 1, cnt, sum);
  solve1(i + 1, cnt + 1, sum + a[i]);
}

void solve2(int i, int cnt, int sum) {
  if (i == b.size()) {
    info2.push_back({cnt, sum});
    return;
  }
  solve2(i + 1, cnt, sum);
  solve2(i + 1, cnt + 1, sum + b[i]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.tie(0);

  cin >> n;
  int sum = 0;
  for (int i = 0; i < n / 2; i++) {
    int x;
    cin >> x;
    a.push_back(x);
    sum += x;
  }

  for (int i = n / 2; i < n; i++) {
    int x;
    cin >> x;
    b.push_back(x);
    sum += x;
  }
  solve1(0, 0, 0);
  solve2(0, 0, 0);

  for (int i = 0; i < info1.size(); i++) {
    for (int j = 0; j < info2.size(); j++) {
      int g1_cnt = info1[i].first + info2[j].first;
      int g1_sum = info1[i].second + info2[j].second;

      int g2_cnt = n - g1_cnt;
      int g2_sum = sum - g1_sum;

      if (g1_cnt == 0 || g2_cnt == 0) {
        continue;
      }

      double g1 = (double)(g1_cnt) / (double)(g1_sum);
      double g2 = (double)(g2_cnt) / (double)(g2_sum);

      if (g1 == g2) {
        cout << "YES";
        return 0;
      }
    }
  }

  cout << "NO\n";
}