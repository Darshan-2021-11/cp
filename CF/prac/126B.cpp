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

static int n, z[1'000'000], i, mid, last;
static char a[1'000'001];

void z_function() {
  int l = 0, r = 0;
  for(int i = 1; i < n; i++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while(i + z[i] < n && a[z[i]] == a[i + z[i]]) {
      z[i]++;
    }
    if(i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  while ((a[n] = getchar()) != '\n') ++n;
  z_function();
  for (i = 1; i < n; ++i) {
    if (z[i] + i == n) { mid = max(mid, z[i] - 1); break; }
    mid = max(mid, z[i]);
  }
  for (i = n - mid; i < n; ++i) {
    if (i + z[i] != n) continue;
    last = z[i];
    break;
  }
  if (last == 0 || mid == 0) {
    cout << "Just a legend";
    return 0;
  }
  for (i = 0; i < min(last, mid); ++i) cout << a[i];
}
