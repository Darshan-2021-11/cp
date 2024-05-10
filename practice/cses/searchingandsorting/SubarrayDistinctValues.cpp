#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 n, k, t, lastidx, tmp, a[(u32)2e5];
u64 subarrays = 0;
map<u32, u32> present;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  t = 1;
  cin >> n >> k;
  for (u32 i = 0; i < n; ++i) {
    cin >> a[i];
    if (present.size() < k || present.count(a[i])) subarrays += t++, ++present[a[i]];
    else {
      while (present.size() == k) {
        tmp = a[lastidx];
        --present[tmp];
        if (!present[tmp]) present.erase(tmp);
        ++lastidx, --t;
      }
      subarrays += t++, ++present[a[i]];
    }
  }
  cout << subarrays << '\n';
}

