#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC;
static u64 ans, x;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    ans = 1;
    string s;
    cin >> s;
    for (const char &i: s) x = i - '0' + 1, ans *= (x * (x + 1)) >> 1;
    cout << ans << '\n';
  }
}

