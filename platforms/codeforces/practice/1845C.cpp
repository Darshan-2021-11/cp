#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T, n, m, i, t, cnt;
char a[(int)3e5 + 1], l[10], r[10], c;
bitset<10> present;
bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  T = 0; while ((c = cin.get()) != '\n') T = T * 10 + c - '0';
  while (T--) {
    yes = true, present.reset();
    n = 0; while ((a[n] = cin.get()) != '\n') ++n;
    m = 0; while ((c = cin.get()) != '\n') m = m * 10 + c - '0';
    i = 0; while (i < m) l[i++] = cin.get(); c = cin.get();
    i = 0; while (i < m) r[i++] = cin.get(); c = cin.get();
    for (i = 0, t = 0, cnt = r[0] - l[0] + 1; i < n; ++i) {
      if (a[i] < l[t] || a[i] > r[t]) continue;
      present.set(a[i] - '0');
      if (present.count() != cnt) continue;
      if(++t == m) { yes = false; break; }
      present.reset(), cnt = r[t] - l[t] + 1;
    }
    cout << (yes ? "YES\n" : "NO\n");
  }
}
