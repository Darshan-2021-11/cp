#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC;
static string s;
static bool found;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    found = false;
    cin >> s;
    cout << s[0];
    for (i32 i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        if (!found) {
          found = true;
          cout << char(((s[i - 1] - 'a' + 1) % 26) + 'a');
        }
      }
      cout << s[i];
    }
    if (!found) cout << char(((s.back() - 'a' + 1) % 26) + 'a');
    cout << '\n';
  }
}

