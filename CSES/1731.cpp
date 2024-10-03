#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1'000'001;
  int dp[5001], n, k;
  struct node {
    int to[26];
    node() {
      fill_n(to, 26, -1);
    }
    int& operator[] (const int idx) {
      return to[idx];
    }
  } trie[N];
  char s[5001];
}
