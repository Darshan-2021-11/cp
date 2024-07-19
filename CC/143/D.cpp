#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 100'000;
static i64 TC, n, k, diff, cnt[2];
static char a[N], b[N];
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    diff = 0, yes = true;
    cin >> n >> k;
    cnt[0] = cnt[1] = 0;
    for (i32 i = 0; i < n; ++i) { cin >> a[i]; cnt[0] += a[i] == '0'; }
    for (i32 i = 0; i < n; ++i) { cin >> b[i]; cnt[1] += b[i] == '0'; }
    if (cnt[0] != cnt[1]) {
      yes = false;
      goto print;
    }
    for (i32 i = 0; i < n; ++i) {
      if (a[i] != b[i]) ++diff;
    }
    diff >>= 1;
    if (diff > k) yes = false;
    if (((diff - k) & 1) && (n == 2 && cnt[0] == 1)) yes = false;
print:
    cout << (yes ? "YES\n" : "NO\n");
  }
}

