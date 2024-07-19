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

static i64 x[2], y[2];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> x[0] >> y[0];
  cin >> x[1] >> y[1];
  if (y[0] & 1) x[0] += !(x[0] & 1);
  else x[0] += x[0] & 1;
  if (y[1] & 1) x[1] += !(x[1] & 1);
  else x[1] += x[1] & 1;
  cout << max(abs(x[1] - x[0]) >> 1, abs(y[1] - y[0]));
}
