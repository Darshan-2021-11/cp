#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  string s;
  map<int, int> cnt;
  int a[26] = { 0 };
  cin >> s;
  for (u32 i = 0; i < s.size(); ++i) ++a[s[i] - 'a'];
  for (auto &i: a) if (i != 0) ++cnt[i];
  for (auto &i: cnt) {
    if (i.second != 2) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}

