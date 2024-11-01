#include<bits/stdc++.h>
template <typename T, int SIZE>
struct mp {
  T data[SIZE];
  int freq[SIZE];
  int _n;

  void input(const int n) {
    for (int i = 0; i < n; ++i) std::cin >> data[i];
    _n = n;
    build();
  }
  void make(const T (&arr)[SIZE], const int n) {
    for (int i = 0; i < n; ++i) data[i] = arr[i];
    _n = n;
    build();
  }
  void build() {
    int n = _n;
    sort(data, data + n, std::less<T>());
    freq[_n = 0] = 1;
    for (int i = 1; i < n; ++i)
      if (data[i] == data[i - 1]) ++freq[_n];
      else data[++_n] = data[i], freq[_n] = 1;
    ++_n;
  }
  int get(const T n) const {
    int idx = lower_bound(data, data + _n, n) - data;
    if (idx == _n || data[idx] != n) return 0;
    return freq[idx];
  }
  int operator[](const T n) {
    return get(n);
  }
  int64_t size() const {
    return _n;
  }
};
