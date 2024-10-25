#include <bits/stdc++.h>
using namespace std;

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
  int64_t TC = 1, n, ans, last;
  cin >> TC;
  while (TC--) {
    last = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i], --b[i];
    BIT<int64_t> bit(a);
    set<pair<int, int>> s;
    s.insert({ b[0], 0 });
    ans = a[0];
    while (s.size()) {
      pair<int, int> t = *s.rbegin();
      s.erase(std::prev(s.end()));
      bit.update(t.second, -a[t.second]);
      int64_t x = bit.sum(0, t.first);
      ans = max({ x, ans });
      if (t.second < last) continue;
      for (int i = last + 1; i <= t.first; ++i) s.insert({ b[i], i });
      last = t.first;
    }
    cout << ans << '\n';
  }
}
