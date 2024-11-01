#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC;
  cin >> TC;
  int x = 0;
  while (TC--) {
    string s;
    cin >> s;
    if (s[1] == '+') ++x;
    else --x;
  }
  cout << x << '\n';
}
