#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 n, t, u;
static bool palin(i32 i) {
  const string s = to_string(i);
  bool p = true;
  for (i32 i = 0; i < s.size() - 1 - i; ++i) p &= s[i] == s[s.size() - 1 - i];
  return p;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  //for (i32 i = 0; i < 1e7; ++i) if(palin(i)) cout << i << '\n';
  if (n <= 10) cout << n - 1;
  else if (n < 20) n -= 10, cout << n << n;
  else {
    n -= 20, t = 10, u = t * 10;
    bool flag = true;
    while (n > u - t) {
      n -= u - t;
      flag = !flag;
      if (flag) t *= 10, u *= 10;
    }
    string s = to_string(n + t);
    cout << s;
    if (flag) s.pop_back();
    reverse(s.begin(), s.end());
    cout << s;
  }
}
