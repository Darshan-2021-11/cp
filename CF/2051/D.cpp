#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t x, y, sum, res;
	int TC = 1, n, a[N], u, d;
	cin >> TC;
	const auto bsy = [&](int i) -> int {
		int l = i + 1, r = n, z;
		while (l < r) {
			z = (l + r) >> 1;
			if (sum - a[z] > y) l = z + 1;
			else r = z;
		}
		return l;
	};
	const auto bsx = [&](int i) -> int {
		int l = i, r = n - 1, z;
		while (l < r) {
			z = (l + r + 1) >> 1;
			if (sum - a[z] >= x) l = z;
			else r = z - 1;
		}
		return l;
	};
	while (TC--) {
		sum = res = 0;
		cin >> n >> x >> y;
		for (int i = 0; i < n; ++i)
			cin >> a[i], sum += a[i];
		sort(a, a + n);

		for (int i = 0; i < n; sum += a[i], ++i) {
			sum -= a[i];
			d = bsy(i);
			if (d == n) continue;
			u = bsx(i);
			if (u == i) continue;
			res += u - d + 1;
		}
		cout << res << '\n';
	}
}
