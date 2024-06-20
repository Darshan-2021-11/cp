#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, a[(u32)2e5];
static array<u32, 3> tri[(u32)2e5], t;
static u64 ans;

void compute() {
  sort(tri, tri + n);
  for (u32 i = 0, j = 1, cnt = 0, lclcnt = 1; i < n; j = i + 1) {
    t[0] = tri[i][0], t[1] = tri[i][1];
    while (j < n && (tri[j][0] == t[0] & tri[j][1] == t[1])) {
      if (tri[j][2] == tri[j - 1][2]) ++lclcnt;
      else cnt += lclcnt, lclcnt = 1;
      ans += cnt, ++j;
    }
    cnt = 0, lclcnt = 1, i = j;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    ans = 0;
    cin >> n >> a[0] >> a[1];
    n -= 2;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i + 2];
      tri[i] = { a[i], a[i + 1], a[i + 2] };
    }
    compute();
    for (u32 i = 0; i < n; ++i) swap(tri[i][1], tri[i][2]);
    compute();
    for (u32 i = 0; i < n; ++i) swap(tri[i][0], tri[i][2]);
    compute();

//   for (u32 i = 0; i < n - 2; ++i) {
//     cout << i << ':' << ' ' << t[i][0] << ',' << t[i][1] << ',' << t[i][2] << '\t';
//   }
    cout << ans << '\n';
  }
}
