#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static int a[(u32)2e5], n, k;
static ll x;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> k;
  for (u32 i = 0; i < n; ++i) cin >> a[i];
  if (k > 0) {
    cout << "Yes\n";
    sort(a, a + n);
    for (u32 i = 0; i < n; ++i) cout << a[i] << ' ';
  } else if (accumulate(a, a + n, 0LL) >= k) {
    cout << "Yes\n";
    sort(a, a + n, greater<int>());
    for (u32 i = 0; i < n; ++i) cout << a[i] << ' ';
  } else cout << "No";
}

