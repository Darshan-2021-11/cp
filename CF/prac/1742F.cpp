#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static string s;
static i64 cnt[2][26], tcnt[26];
static i32 TC, n, t, k, i1, i2;
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    yes = true;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    cnt[0][0] = cnt[1][0] = 1;
    for (i32 i = 0; i < n; ++i) {
      yes = false;
      cin >> t >> k >> s;
      --t;
      for (const auto &c: s) ++tcnt[c - 'a'];
      for (i32 j = 0; j < 26; ++j) {
        cnt[t][j] += tcnt[j] * k;
      }
      for (i2 = 25; !cnt[1][i2]; --i2);
      if (i2) yes = true;
      else {
        for (i1 = 25; !cnt[0][i1]; --i1);
        if (!i1) yes = cnt[0][0] < cnt[1][0];
      }
      cout << (yes ? "YES\n" : "NO\n");
      memset(tcnt, 0, sizeof(tcnt));
    }
    cout << '\n';
  }
}
