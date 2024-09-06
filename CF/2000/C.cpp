#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, m, a[N];
static map<char, i32> mp;
static map<i32, char> mp2;
static map<char, i32>::iterator it;
static map<i32, char>::iterator it2;
static vector<string> s;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (i32 i = 0; i < m; ++i) cin >> s.emplace_back();
    for (const string &si: s) {
      if ((i32)si.size() != n) {
        cout << "NO\n";
        continue;
      }
      bool done = 0;
      for (i32 j = 0; j < n; ++j) {
        if ((it = mp.find(si[j])) == mp.end()) {
          mp[si[j]] = a[j];
          if ((it2 = mp2.find(a[j])) == mp2.end()) mp2[a[j]] = si[j];
          else {
            cout << "NO\n";
            done = 1;
            break;
          }
          continue;
        }
        else if (it->second == a[j]) continue;
        cout << "NO\n";
        done = 1;
        break;
      }
      if (!done) cout << "YES\n";
      mp.clear();
      mp2.clear();
    }
    s.clear();
  }
}

