#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, k;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
		cin >> n >> k;
		if (k == 1) {
			for (u32 i = 1; i <= n; ++i) cout << i << ' ';
		} else if (k == n) {
			for (u32 i = 1; i <= n; ++i) cout << 1 << ' ';
		} else cout << -1;
		cout << '\n';
	}
}

