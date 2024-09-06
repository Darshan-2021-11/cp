#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC;
static string s;
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    yes = true;
    cin >> s;
    if (s.size() < 3) {
      yes = 0;
    }
    if (s[0] == '1' && s[1] == '0') {
      if (s[2] == '0') yes = 0;
      else if (s[2] == '1') yes = s.size() > 3;
    } else yes = 0;
    cout << (yes ? "YES" : "NO") << '\n';
  }
}

