#include <bits/stdc++.h>
using namespace std;

template <typename T, int SIZE>
struct mp {
  T data[SIZE];
  int freq[SIZE];
  int _n;

  void input(const int n) {
    for (int i = 0; i < n; ++i) cin >> data[i];
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

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, n, r, sum, ans;
  mp<int, N> m;
  cin >> TC;
  while (TC--) {
    ans = INT_MAX;
    sum = r = 0;
    cin >> n;
    m.input(n);
    for (int i = 0; i < m._n; ++i) {
      while (r < m._n) {
        if (
            r < n &&
            m.data[r] < (m.data[i] << 1)
           )
          sum += m.freq[r], ++r, ans = min(ans, n - sum);
        else if (
            i + 1 < n &&
            r < n &&
            m.data[r] < m.data[i] + m.data[i + 1]
            ) {
          sum += m.freq[r], ++r, ans = min(ans, n - sum + m.freq[i] - 1);
        } else break;
      }
      sum -= m.freq[i];
    }
    cout << ans << '\n';
  }
}
