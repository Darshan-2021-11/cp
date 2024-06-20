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

static i32 TC, i, n, a[200'000], b[200'000], dq[200'000], dqb, dqf, q[200'000], qf, qb;
static bool yes, fr;
// fr : From right side, the max element came?

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    yes = true, fr = false;
    dqf = dqb = qb = qf = 0;
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    for (i = 0; i < n; ++i) {
      cin >> b[i];
      if (a[i] > b[i]) yes = false;
    }
    if (!yes) goto print;

    if (a[0] < b[0])
      fr = true, q[qb++] = b[0];

    for (i = 1; i < n; ++i) {
      dq[dqb++] = a[i - 1];
      while (dqb > dqf && dq[dqb - 1] < a[i]) --dqb;
      while (dqb > dqf && dq[dqf] > b[i]) ++dqf;

      if (a[i] == b[i]) {
        if (fr) {
          if (q[qf] != a[i]) {
            yes = false;
            break;
          } else {
            ++qf;
            fr = qf != qb;
            if (fr) break;
          }
        }
      } else {
        if (fr) {
          if (a[i] == q[qf]) {
            ++qf;
          } else if (a[i] > q[qf]) {
            yes = false;
            break;
          }
          if (b[i] < q[qb - 1]) {
            yes = false;
            break;
          } else if (b[i] > q[qb - 1])
            q[qb++] = b[i];
        }
        else if (dqf < dqb && dq[dqf] == b[i]) continue;
        else fr = true, q[qb++] = b[i];
      }
    }
    if (fr) yes = false;

print:
    cout << (yes ? "YES\n" : "NO\n");
  }
}
