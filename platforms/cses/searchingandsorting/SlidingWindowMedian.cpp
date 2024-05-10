#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

u32 n, k, a[(u32)2e5];
ordered_set x;
int main() {
  cin >> n >> k;
  for (u32 i = 0; i < n; ++i) {
    cin >> a[i];
    if (i >= k) {
      cout << *x.find_by_order((k - 1) >> 1) << ' ';
      x.erase(x.find_by_order(x.order_of_key(a[i - k])));
    }
    x.insert(a[i]);
  }
  cout << *x.find_by_order((k - 1) >> 1) << ' ';
  return 0;
}
