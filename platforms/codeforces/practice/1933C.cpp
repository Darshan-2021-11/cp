#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 binpow(u32 a, u32 b) {
    u32 res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

u32 T = 1, a, b, l, k;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
	  cin >> a >> b >> l;
	  k = l;
    vector<u32> pk = { k };
    u32 maxa = 1;
    while (k % a == 0) maxa *= a, k /= a;
    while (maxa) {
      pk.push_back(k);
      while (k % b == 0) k /= b, pk.push_back(k);
      maxa /= a;
      if (maxa) k = l / maxa;
    }
    sort(pk.begin(), pk.end());
    cout << distance(pk.begin(), unique(pk.begin(), pk.end())) << '\n';
	}
}
