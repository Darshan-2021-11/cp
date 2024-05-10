#define _GLIBCXX_DEBUG
// #include <bits/stdc++.h>
#include "bits/stdc++.h"
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

vector<vector<string>> solve(vector<string> &strs) {
  vector<vector<string>> answer;
  if (strs.size() == 1) {
    answer.emplace_back(strs);
    return answer;
  }
  vector<string> tmp;
  vector<pair<string, int>> ordered_input;
  for (int i = 0; i < strs.size(); ++i) {
    ordered_input.emplace_back(make_pair(strs[i], i));
    sort(ordered_input[i].first.begin(), ordered_input[i].first.end());
  }
  sort(ordered_input.begin(), ordered_input.end(),
       [](pair<string, int> &a, pair<string, int> &b) {
         return a.first < b.first;
       });

  tmp.emplace_back(strs[ordered_input[0].second]);
  for (int i = 1; i < strs.size(); ++i) {
    if (ordered_input[i - 1].first == ordered_input[i].first) {
      tmp.emplace_back(strs[ordered_input[i].second]);
    } else {
      answer.emplace_back(tmp);
      tmp.clear();
      tmp.emplace_back(strs[ordered_input[i].second]);
    }
  }
  answer.emplace_back(tmp);
  ordered_input.clear();
  tmp.clear();
  return answer;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  solve(strs);
}
