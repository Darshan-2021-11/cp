#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 n, t, n1, n2, dfs, a[(u32)2e5 + 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> t;
  for (u32 i = 1; i < n; ++i) {
    cin >> n1 >> n2;
    a[n1] = n2;
  }
  // starting node n1
  cin >> n1;
  while (a[n1]) ++dfs, n1 = a[n1];
  cout << ((dfs & 1) | ((n - 1 - dfs) & 1) ? "Ron" : "Hermione") << '\n';
}
