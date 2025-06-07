#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 10'005'001;
	int TC;
	vector<bool> bad(N);
	const auto has7 = [](int x) -> bool {
		while (x) {
			if (x % 10 == 7) return true;
			x /= 10;
		}
		return false;
	};

	for (int i = 1; i < N; ++i) {
		if (bad[i]) continue;
		if (has7(i)) {
			bad[i] = true;
			for (int j = i << 1; j < N; j += i) {
				bad[j] = true;
			}
		}
	}
	vector <int> v;
	for (int i = 1; i < N; ++i) if (!bad[i]) v.emplace_back(i);
	cin >> TC;
	while (TC--) {
		int x;
		cin >> x;
		if (bad[x]) {
			cout << -1 << '\n';
		} else {
			cout << *upper_bound(v.begin(), v.end(), x) << '\n';
		}
	}
}
