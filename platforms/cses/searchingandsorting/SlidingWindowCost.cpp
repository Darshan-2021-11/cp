#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

int n, k, pmedian, cmedian, a[(int)2e5];
ll sum;
ordered_set x;
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
    x.insert(a[i]);
  }
  pmedian = *x.find_by_order((k - 1) >> 1);
  sum = accumulate(a, a + k, u64{}, [](u64 total, int value) {
      return total + abs(pmedian - value);
      });
  for (int i = k; i < n; ++i) {
    cin >> a[i];
    x.erase(x.find_by_order(x.order_of_key(a[i - k])));
    x.insert(a[i]);
    cmedian = *x.find_by_order((k - 1) >> 1);
    sum = sum - abs(pmedian - a[i - k]) + abs(cmedian - a[i]);
    if (!(k & 1)) sum += pmedian - cmedian;
    pmedian = cmedian;
    cout << sum << ' ';
  }
  return 0;
}
