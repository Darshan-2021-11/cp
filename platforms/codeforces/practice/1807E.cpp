#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 b[u32(2e5) + 1], a[u32(2e5)], T = 1, n, lft, rght, mid, sum, inpsum;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    lft = 1, rght = n;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    partial_sum(a, a + n, b + 1);
    while (lft + 1 < rght) {
      mid = (lft + rght + 1) >> 1;
      cout << "? " << mid - lft;
      for (u32 i = lft; i < mid; ++i) cout << ' ' << i;
      cout << endl;

      sum = b[mid - 1] - b[lft - 1];
      cin >> inpsum;
      if (sum == inpsum)
        lft = mid;
      else rght = mid;
    }
    cout << "? " << 1 << ' ' << lft << endl;
    sum = b[lft] - b[lft - 1];
    cin >> inpsum;
    if (inpsum == sum)
      cout << "! " << rght << endl;
    else
      cout << "! " << lft << endl;
  }
}

