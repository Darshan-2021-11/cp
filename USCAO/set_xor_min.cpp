#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

template <typename T, int LOG2, bool asSet>
struct Binary_Trie {
  struct Node {
    std::array<int, 2> state;
    int count;
    Node() : count(int{}) {
      state.fill(-1);
    }
  };
  std::vector<Node> trie;
  std::vector<int> removed;
  Binary_Trie() {
    trie.emplace_back(Node());
  }
  bool contains(T n) const {
    int node{};
    for (int i = LOG2; i > -1; --i) {
      node = trie[node].state[n >> i & 1];
      if (node == -1) return false;
    }
    return true;
  }
  T find_min_XOR(T n) const {
    T res{};
    int node{};
    for (int i = LOG2, bit; i > -1; --i) {
      bit = (n >> i) & 1;
      if (trie[node].state[bit] != -1) {
        node = trie[node].state[bit];
        continue;
      }
      res |= static_cast<T>(1) << i;
      node = trie[node].state[!bit];
    }
    return res;
  }
  int create() {
    int index;
    if (removed.size()) {
      index = removed.back();
      removed.pop_back();
      trie[index].state.fill(-1);
      return index;
    }
    index = trie.size();
    trie.emplace_back(Node());
    return index;
  }
  void insert(T n) {
    if (asSet && contains(n)) return;
    int node{};
    ++trie[node].count;
    for (int i = LOG2, prev, bit; i > -1; --i) {
      prev = node, bit = n >> i & 1;
      if ((node = trie[node].state[bit]) == -1) {
        node = trie[prev].state[bit] = create();
      }
      ++trie[node].count;
    }
  }
  void remove(T n) {
    if (!contains(n)) return;
    int node = {};
    --trie[node].count;
    for (int i = LOG2, prev; i > -1; --i) {
      prev = node;
      node = trie[node].state[n >> i & 1];
      --trie[node].count;
      if (trie[node].count == 0)
        trie[prev].state[(n >> i) & 1] = -1, removed.push_back(node);
    }
  }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int n;
  cin >> n;
  Binary_Trie<u32, 29, 1> bt;
  for (int i = 0; i < n; ++i) {
    int op, t;
    cin >> op >> t;
    switch(op) {
      case 0:
        bt.insert(t);
        break;
      case 1:
        bt.remove(t);
        break;
      case 2:
        cout << bt.find_min_XOR(t) << '\n';
        break;
    }
  }
}
