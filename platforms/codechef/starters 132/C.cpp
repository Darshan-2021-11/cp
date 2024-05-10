#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, t, toddadj, oddadj, a[(u32)2e5];
u64 total;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    total = t = oddadj = toddadj = 0;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      if (!(a[i] & 1))
        t = i + 1, toddadj = 0;
      else ++toddadj, oddadj = max(oddadj, toddadj);
      total += t;
    }
    cout << total + ((oddadj >> 1) + 1) * ((oddadj + 1) >> 1) << '\n';
  }
}

