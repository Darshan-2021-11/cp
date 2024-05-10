#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int n, k, movies;
pair<int, int> rngs[(int)2e5];
multiset<int> rngends;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  movies = 1;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> rngs[i].first >> rngs[i].second;
  }
  sort(rngs, rngs + n);
  rngends.insert(rngs[0].second);
  multiset<int>::iterator it;
  for (int i = 1; i < n; ++i) {
    while (rngends.size() && rngs[i].first >= *rngends.begin()) rngends.erase(rngends.begin());
    if (rngends.size() == k) {
      if (rngs[i].second < *(it = --rngends.end())) rngends.erase(it), rngends.insert(rngs[i].second);
    } else {
      rngends.insert(rngs[i].second), ++movies;
    }
  }
  cout << movies << '\n';
}
