#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  char ab, ac, bc;
  cin >> ab >> ac >> bc;
  if (ab == '<') {
    if (bc == '<') cout << 'B';
    else cout << (ac == '<' ? 'C' : 'A');
  } else {
    if (ac == '<') cout << 'A';
    else cout << (bc == '<' ? 'C' : 'B');
  }
}
