#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 n, t, sum;
static vector<string> names;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  names.reserve(n);
  for (u32 i = 0; i < n; ++i, sum += t) cin >> names.emplace_back() >> t;
  sort(names.begin(), names.end());
  cout << names[sum % n];
}

