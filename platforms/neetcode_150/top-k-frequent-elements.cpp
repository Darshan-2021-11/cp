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

vector<int> solve(vector<int> nums, int k) {
  vector<int> answer;
  answer.reserve(k);
  unordered_map<int, size_t> frequency;
  for (int i : nums) {
    ++frequency[i];
  }
  sort(nums.begin(), nums.end(), [&](int a, int b) {
    if (frequency[a] == frequency[b])
      return a < b;
    return frequency[a] > frequency[b];
  });
  for (auto i : nums) {
    cout << i << ' ';
  }
  cout << '\n';

  for (size_t i = 0; k-- > 0;) {
    answer.push_back(nums.at(i));
    i += frequency[nums.at(i)];
    cout << answer.back();
  }
  return answer;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
  solve(nums, 2);
}
