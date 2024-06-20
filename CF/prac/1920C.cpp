#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, n, ans, a[200000];

bool m_present(i32 i) {
  i32 dgcd = 0;
  for (i32 j = 0; j < i; ++j)
    for (i32 k = j; k < n - i; k += i)
      dgcd = __gcd(dgcd, abs(a[k] - a[k + i]));
  return dgcd != 1;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    ans = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    for (i32 i = 1; i * i <= n; ++i) {
      if (n % i) continue;
      i32 of = n / i;
      ans += m_present(i);
      if (i == of) continue;
      ans += m_present(of);
    }
    cout << ans << '\n';
  }
}
