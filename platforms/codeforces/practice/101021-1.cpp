#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

string s;
u32 leftm, mid, rightm, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  leftm = 1, rightm = 1e6, t = -1;
  while (rightm - leftm > 1) {
    mid = (leftm + rightm) >> 1;
    cout << mid << endl;
    cin >> s;
    if (s != "<") leftm = mid;
    else rightm = mid - 1;
  }
  cout << rightm << endl;
  cin >> s;
  if (s == "<") cout << "! " << leftm << endl;
  else cout << "! " << rightm << endl;
}

