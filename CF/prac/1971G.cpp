#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, a[(u32)2e5];
static map<u32, vector<u32>> val;
static const u32 mask = UINT32_MAX - 0b11;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      val[a[i] & mask].push_back(a[i]);
    }
    for (auto &[i, j]: val) sort(j.begin(), j.end(), greater<u32>());
    for (u32 i = 0; i < n; ++i) {
      cout << val[a[i] & mask].back() << ' ';
      val[a[i] & mask].pop_back();
    }
    cout << '\n';
    val.clear();
  }
}

