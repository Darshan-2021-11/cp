template <typename T> struct BIT {
  using u32 = unsigned int;
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
