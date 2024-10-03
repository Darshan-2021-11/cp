#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2'000'005;

struct arr {
  int a[10];
  arr() {}
  void clear() { memset(a,-1,sizeof(a)); }
  int& operator[](int i) { return a[i]; }
};

int get(char c) {
  if (c >= 'a' && c <= 'c') return 2;
  if (c >= 'd' && c <= 'f') return 3;
  if (c >= 'g' && c <= 'i') return 4;
  if (c >= 'j' && c <= 'l') return 5;
  if (c >= 'm' && c <= 'o') return 6;
  if (c >= 'p' && c <= 's') return 7;
  if (c >= 't' && c <= 'v') return 8;
  return 9;
}
int get2(char c) {
  return c - '0';
}

struct trie {
  int cnt, prefix_cnt[MAXN], word_cnt[MAXN];
  arr to[MAXN];

  trie() { cnt = MAXN-1; }

  void clear() { for(int i = 0; i < cnt; i++) prefix_cnt[i] = word_cnt[i] = 0, to[i].clear(); cnt = 1; }

  void add(const string& s) {
    int u = 0;
    for(const char& c: s)  {
      const int symbol = get(c);
      if(to[u][symbol] == -1) to[u][symbol] = cnt++;
      u = to[u][symbol];
      prefix_cnt[u]++;
    }
    word_cnt[u]++;
  }

  int prefix_count(const string& s) {
    int u = 0;
    for (const char& c: s) {
      const int symbol = get2(c);
      if (to[u][symbol] == -1) return 0;
      u = to[u][symbol];
    }
    return prefix_cnt[u];
  }
} tr;


int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int n, m;
  tr.clear();
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    tr.add(s);
  }
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    cout << tr.prefix_count(s) << '\n';
  }
}
