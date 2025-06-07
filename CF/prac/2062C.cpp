#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int64_t N = 50;
	int64_t TC = 1, n, a[50];
	const auto compute = [](const auto self, int64_t x[N], int64_t sz) -> int64_t {
		if (sz == 1) return x[0];
		int64_t t[N], ans;
		for (int64_t i = 1; i < sz; ++i)
			t[i - 1] = x[i] - x[i - 1];
		ans = accumulate(t, t + sz - 1, int64_t{});

		ans = max(abs(ans), self(self, t, sz - 1));
		return ans;
	};
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int64_t i = 0; i < n; ++i) cin >> a[i];
		cout << max(accumulate(a, a + n, int64_t{}), compute(compute, a, n)) << '\n';
	}
}
