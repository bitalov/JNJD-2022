#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
/* #pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
typedef long long ll;
const ll MAXN = 1e7 + 2;
const ll MAXK = 5e2 + 2;
const ll MOD = 1e9 + 7;
const ll MODH = 1e9 + 9;
const int MAXLG = 20;
const long double PI = acos(-1);
const ll sp = 41;
const long double EPS = 1e-4;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {
  ll c = rng();
  return a + ((ll)abs(c)) % (b - a + 1);
}
ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int m;
struct mat {
  vector<ll> a[10];
  mat() {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        a[i].push_back(0);
      }
    }

    for (int i = 0; i < m; i++) {
      a[0][i] = 1;
    }
    for (int i = 1; i < m; i++) {
      a[i][i - 1] = 1;
    }
  }
  mat operator*(const mat &other) const {
    mat ret;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) {
        ll &sum = ret.a[i][j];
        sum = 0;
        for (int k = 0; k < m; k++) {
          sum += (a[i][k] * other.a[k][j]) % MOD;
          sum %= MOD;
        }
      }

    return ret;
  }
};

mat bpow(mat m, ll p) {
  if (p == 1) return m;
  mat t = bpow(m, p / 2);
  t = t * t;
  if (p & 1)
    return t * m;
  else
    return t;
}

int main() {
  ll n;
  cin >> n >> m;
  mat x;
  x = bpow(x, n - 1);
  cout << x.a[0][0];
}