#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, t, n, c1;
static u64 sum;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    sum = c1 = 0;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> t;
      [[unlikely]] if (t == 1) ++c1;
      else sum += t;
    }
    cout << (n != 1 && sum + c1 - n >= c1 ? "YES\n" : "NO\n");
  }
}
