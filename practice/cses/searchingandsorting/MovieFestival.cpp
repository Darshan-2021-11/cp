#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int n, rngend, movies;
pair<int, int> rngs[(int)2e5];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  movies = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> rngs[i].first >> rngs[i].second;
  }
  sort(rngs, rngs + n);
  rngend = rngs[0].second;
  for (int i = 1; i < n; ++i) {
    if (rngs[i].second < rngend) rngend = rngs[i].second;
    else if (rngs[i].first >= rngend) ++movies, rngend = rngs[i].second;
  }
  cout << movies << '\n';
}

