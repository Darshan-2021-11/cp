#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 101;
static i64 n, a[N], mx[2];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (i32 i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] > a[mx[0]]) mx[1] = mx[0], mx[0] = i;
    else if (a[i] > a[mx[1]]) mx[1] = i;
  }
  cout << mx[1];
}

