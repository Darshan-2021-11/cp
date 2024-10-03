#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;
 
template <typename T> struct BIT {
  using u32 = unsigned int;
  vector<T> tree;
  u32 n;
 
  BIT(u32 size) {
    initialize(size);
  }
 
  template <typename T1>
  BIT(vector<T1> const &arr) {
    initialize(arr);
  }
 
  void initialize(u32 size) {
    n = size;
    tree.assign(n, T{});
  }
 
  template <typename T1>
  void initialize(vector<T1> const &arr) {
    initialize(arr.size());
    for (u32 i = 0; i < n; ++i) {
      tree[i] += arr[i];
      u32 r = i | (i + 1);
      if (r < n) tree[r] += tree[i];
    }
  }
 
  /**
   * @brief Gives the prefix sum of the entire array upto index `r`
   * @param r Rightmost index of prefix sum
   */
  T sum(u32 r) {
    T res{};
    for (u32 i = r++; i < r; i = (i & (i + 1)) - 1)
      res += tree[i];
    return res;
  }
 
  /**
   * @brief Gives the ranged sum from index `l` to `r` inclusive
   * @param l Leftmost index of prefix sum
   * @param r Rightmost index of prefix sum
   */
  T sum(u32 l, u32 r) {
    return sum(r) - sum(l - 1);
  }
 
  /**
   * @brief Updates the BIT to update a particular index
   * @param idx index to change
   * @param val value to add to the element at idx
   */
  void update(u32 idx, T val) {
    while (idx < n) {
      tree[idx] += val;
      idx |= idx + 1;
    }
  }
};
 
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  u32 n, q;
  cin >> n >> q;
  vector<u32> v(n);
  for (u32 i = 0; i < n; ++i) cin >> v[i];
  BIT<u64> bit(v);
  for (u32 i = 0, c; i < q; ++i) {
    cin >> c;
    if (c == 1) {
      u64 u; u32 k;
      cin >> k >> u;
      bit.update(k, u - v[k]);
      v[k] = u;
    } else {
      u32 a, b;
      cin >> a >> b;
      cout << bit.sum(a, b - 1) << '\n';
    }
  }
}
