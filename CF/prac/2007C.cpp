#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 100'000;
  i32 TC = 1, n;
  i64 c[N], a, b, ans;
  cin >> TC;
  while (TC--) {
    // `diff` is the minimum non-zero value attainable by the equation ax + by,
    // for integer value of x and y
    // if gcd of a and b is gcd(a, b), then we remove it from both and we know any
    // two co-primes have a^(b - 1) = 1 (mod b),
    // so the minimum difference we can acheive is that multiplied by gcd(a, b);
    cin >> n >> a >> b;
    for (i32 i = 0; i < n; ++i) cin >> c[i];
    i64 diff = a == b ? a : gcd(a, b), mx = *max_element(c, c + n);
    for (i32 i = 0; i < n; ++i) c[i] += ((mx - c[i] + diff - 1) / diff) * diff;
    sort(c, c + n); ans = c[n - 1] - c[0], mx = c[n - 1];
    for (i32 i = 0; i < n; mx = c[i] + diff, ++i) ans = min(ans, mx - c[i]);
    cout << ans << '\n';
  }
}
