#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static int TC, n;
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    yes = false;
    cin >> n;
    vector<u32> a(n), b(n), prefix(n, 0), suffix(n, 0);
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    for (u32 i = 0; i < n; ++i) cin >> b[i];
    for (u32 i = 0; i < n - 1; ++i) {
      if (a[i] + b[i] >= a[i + 1]) {
        if (i) prefix[i] = prefix[i - 1] + 1;
        else ++prefix[i];
      }
    }
    for (u32 i = 0; i < n; ++i) cout << prefix[i ]<< ' ';
    cout << '\n';
    for (u32 i = n - 2; i > -1; --i) {
      if (a[i] >= a[i + 1] - b[i + 1]) {
        suffix[i + 1] = suffix[i + 1] + 1;
      }
    }
    for (u32 i = 0; i < n; ++i) cout << suffix[i ]<< ' ';
    cout << '\n';
    int c0s = count_if(suffix.begin() + 1, suffix.end(), [](u32 x) { return !x; });
    int c0p = count_if(prefix.begin(), prefix.end() - 1, [](u32 x) { return !x; });
    for (u32 i = 0; i < n - 1; ++i) if (suffix[i] + prefix[i + 1] + 2 >= n) yes = true;
    for (u32 i = 1; i < n; ++i) if (prefix[i - 1] + suffix[i] + 2 >= n) yes = true;
    cout << (yes || c0s < 2 || c0p < 2 ? "YES\n": "NO\n");
  }
}

