#include <bits/stdc++.h>
using namespace std;

int64_t findXOR(int64_t n)
{
  int64_t mod = n % 4;
  // If n is a multiple of 4
  if (mod == 0)
    return n;
  // If n % 4 gives remainder 1
  else if (mod == 1)
    return 1;
  // If n % 4 gives remainder 2
  else if (mod == 2)
    return n + 1;
  // If n % 4 gives remainder 3
  else
    return 0;
}
// Function to return the XOR of elements
// from the range [l, r]
int64_t findXOR(int64_t l, int64_t r) {
  return (findXOR(l - 1) ^ findXOR(r));
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, l, r, i, k, res, lk, rk;
  cin >> TC;
  while (TC--) {
    cin >> l >> r >> i >> k;
    res = findXOR(l, r);
    lk = (l & (~((1LL << i) - 1))) + k;
    if (lk < l) lk += 1LL << i;
    if (lk > r) goto print;
    lk >>= i;
    rk = (r & (~((1LL << i) - 1))) + k;
    if (rk > r) rk -= 1LL << i;
    rk >>= i;
    res ^= findXOR(lk, rk) << i;
    if (!((lk - rk) & 1)) res ^= k;
print:
    cout << res << '\n';
  }
}
