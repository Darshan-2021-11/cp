#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int n, q, t, u1, u2, v1, v2;

template <typename T> struct BIT {
  vector<T> tree;
  u32 n;

  BIT(u32 size) {
    initialize(size);
  }
  BIT(vector<T> const &arr) {
    initialize(arr);
  }

  void initialize(u32 size) {
    n = size;
    tree.assign(n, T{});
  }

  void initialize(vector<T> const &arr) {
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
  cin >> n >> q;
  BIT<int> x(n), y(n);
  vector<int> xc(n), yc(n);
  for (int i = 0; i < q; ++i) {
    cin >> t;
    switch(t) {
      case 1:
        cin >> u1 >> v1;
        --u1, --v1;
        if (!xc[u1])
          x.update(u1, 1);
        if (!yc[v1])
          y.update(v1, 1);
        ++xc[u1];
        ++yc[v1];
        break;
      case 2:
        cin >> u1 >> v1;
        --u1, --v1;
        --xc[u1];
        --yc[v1];
        if (!xc[u1])
          x.update(u1, -1);
        if (!yc[v1])
          y.update(v1, -1);
        break;
      case 3:
        cin >> u1 >> v1 >> u2 >> v2;
        --u1, --v1, --u2, --v2;
        int dx = u2 - u1 + 1, dy = v2 - v1 + 1;
        int t1 = x.sum(u1, u2), t2 = y.sum(v1, v2);
        cout << (t1 == dx || t2 == dy ? "YES\n": "NO\n");
        break;
    }
  }
}

