#include <bits/stdc++.h>
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
