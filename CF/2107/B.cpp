#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	int64_t sum, a[N];
	int TC = 1, n, k, r;
	bool tomw;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a + n);
		for (int i = n - 1; i; --i) {
		}
		cout << (!tomw ? "Jerry" : "Tom") << '\n';
	}
}
