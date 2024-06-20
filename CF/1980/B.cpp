#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, f, k, a[100], t, fc, fcm;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    fc = 0;
    cin >> n >> f >> k;
    f--;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    t = a[f];
    for (u32 i = 0; i < n; ++i) if (a[i] == t) ++fc;
    fcm = fc;
    sort(a, a + n, greater<u32>());
    for (u32 i = 0; i < k; ++i) if (a[i] == t) --fc;
    if (fc == 0) cout << "YES\n";
    else if (fc < fcm) cout << "MAYBE\n";
    else cout << "NO\n";
  }
}

