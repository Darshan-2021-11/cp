#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, m, t, a[100], b[100];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);

  cin >> n >> m;
  fill_n(b, m, 0);
  for (u32 i = 0; i < m; ++i) cin >> a[i];
  for (u32 i = 0; i < n; ++i) {
    for (u32 j = 0; j < m; ++j) {
      cin >> t;
      b[j] += t;
    }
  }
  for (u32 i = 0; i < m; ++i) {
    if (a[i] > b[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
