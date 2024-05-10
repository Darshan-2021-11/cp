#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 n;
ll t, sum = -1e10, maxsum = -1e10;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (u32 i = 0; i < n; ++i) {
    cin >> t;
    sum = max(sum + t, t);
    maxsum = max(sum, maxsum);
  }
  cout << maxsum;
}

