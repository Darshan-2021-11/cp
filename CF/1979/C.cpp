#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static u64 TC, s, n, k[50], ans[50], s1;
static bool kp[20];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    memset(k, 0, 20);
    s = 1;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> k[i];
      kp[k[i] - 1] = true;
    }
    for (u32 i = 0; i < 20; ++i) if (kp[i]) s *= i;
  }
}

