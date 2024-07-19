#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 n, weight, a[100'000], ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  static vector<vector<i32>> w(n);
  for (i32 i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (i32 i = 0; i < n; ++i) {
    cin >> weight;
    w[a[i] - 1].push_back(weight);
  }
  for (i32 i = 0; i < n; ++i) {
    if (!w.size()) continue;
    sort(w[i].begin(), w[i].end(), greater<i32>());
    for (int j = 1; j < w[i].size(); ++j) ans += w[i][j];
  }
  cout << ans;
}
