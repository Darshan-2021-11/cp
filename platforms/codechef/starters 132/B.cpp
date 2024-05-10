#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, k, c1, idx;
bool p[100], possible;
char a;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    possible = true;
    cin >> n >> k;
    memset(p, 0, k);
    for (u32 i = 0; i < n; ++i) {
      c1 = 0;
      for (u32 j = 0; j < k; ++j) {
        cin >> a;
        if (a == '1') idx = j, ++c1;
      }
      if (c1 == 1) p[idx] = true;
    }
    for (u32 i = 0; i < k; ++i) {
      if (!p[i]) possible = false;
    }
    cout << (possible ? "YES\n" : "NO\n");
  }
}

