#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, unhappiness[(u32)1e5], n, fpairs, t1, t2, minUnhappiness;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    minUnhappiness = UINT32_MAX;
    cin >> n >> fpairs;
    for (u32 i = 0; i < n; ++i) cin >> unhappiness[i];
    vector<vector<u32>> friends(n + 1);
    for (u32 i = 0; i < fpairs; ++i) {
      cin >> t1 >> t2;
      friends[--t1].emplace_back(--t2);
      friends[t2].emplace_back(t1);
      //cout << t1 << ' ' << t2 << '\n';
    }
    if (!(fpairs & 1)) {
      cout << 0 << '\n';
      continue;
    }
    /*
    for (u32 i = 0; i < friends.size(); ++i) {
      cout << i << ':' << ' ';
      for (auto &&j: friends[i]) {
        cout << j << ' ';
      }
      cout << '\n';
    }
    */
    for (u32 i = 0; i < n; ++i) {
      if (friends[i].size() & 1) minUnhappiness = min(unhappiness[i], minUnhappiness);
      else {
        t1 = unhappiness[i];
        //cout << t1 << '\n';
        for (u32 j = 0; j < friends[i].size(); ++j)
          if (!(friends[friends[i][j]].size() & 1))
            minUnhappiness = min(t1 + unhappiness[friends[i][j]], minUnhappiness);//, cout << unhappiness[friends[i][j]] << ' ';
        //cout << '\n';
      }
    }
    cout << minUnhappiness << '\n';
  }
}

