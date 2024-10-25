#include <bits/stdc++.h>
using namespace std;

template <int SIZE>
struct bs {
  const static uint32_t IDX_RS = 5;
  const static uint32_t MASK = (sizeof(uint32_t) << 3) - 1;
  uint32_t data[(SIZE + MASK) >> IDX_RS];
  void init(int n) {
    fill_n(data, (n + MASK) >> IDX_RS, 0);
  }
  void set(int idx) {
    data[idx >> IDX_RS] |= (1U << (idx & MASK));
  }
  void reset(int idx) {
    data[idx >> IDX_RS] &= ~(1U << (idx & MASK));
  }
  void flip(int idx) {
    data[idx >> IDX_RS] ^= (1U << (idx & MASK));
  }
  int get(int idx) {
    return (data[idx >> IDX_RS] >> (idx & MASK)) & 1U;
  }
};
template <int SIZE>
struct Trie {
  int last = 0;
  struct node {
    int to[26];
    node() {
      fill_n(to, 26, -1);
    }
    int& operator[] (const int idx) {
      return to[idx];
    }
  } trie[SIZE];
  int assign() {
    return ++last;
  }
  node& operator[] (const int idx) {
    return trie[idx];
  }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1'000'001, MOD = 1e9 + 7;
  Trie<N> trie;
  bs<N> b;
  int dp[5001], n = 0, curr = 0, k = 0;
  char s[5001], c;
  while ((s[n] = getchar_unlocked()) != '\n') s[n] -= 'a', ++n;
  reverse(s, s + n);
  while ((c = getchar_unlocked()) != '\n') k = k * 10 + (c ^ '0');
  while (k--) {
    curr = 0;
    c = getchar_unlocked();
    do {
      c -= 'a';
      if (trie[curr][c] == -1)
        trie[curr][c] = trie.assign();
      curr = trie[curr][c];
      c = getchar_unlocked();
    } while (c != '\n');
    b.set(curr);
  }
  dp[n] = 1;
  for (int i = n - 1; ~i; --i) {
    if (!dp[i + 1]) continue;
    curr = 0;
    for (int j = i; ~j; --j) {
      if (trie[curr][s[j]] == -1) break;
      curr = trie[curr][s[j]];
      if (b.get(curr)) {
        dp[j] += dp[i + 1];
        if (dp[j] >= MOD) dp[j] -= MOD;
      }
    }
  }
  cout << dp[0];
}
