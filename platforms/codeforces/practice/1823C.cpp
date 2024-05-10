#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 a[1000], T = 1, n, remaining, ans;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
		ans = remaining = 0;
		map<u32, u32> m;
		cin >> n;
		for (u32 i = 0; i < n; ++i) cin >> a[i];
		for (u32 i = 0; i < n; ++i) {
			for (u32 j = 2; j * j <= a[i]; ++j) {
				while (a[i] % j == 0) ++m[j], a[i] /= j;
			}
			if (a[i] != 1) ++m[a[i]];
		}
		for (auto &[i,j]: m) {
			if (j & 1) ++remaining;
			ans += j >> 1;
		}
		cout << ans + (remaining / 3) << '\n';
	}
}

