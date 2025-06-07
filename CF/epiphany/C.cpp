#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 10'000'002;
	int TC;
	vector<int> p(N, true);
	p[0] = false;
	for (int i = 2; i * i < N; ++i) {
		if (!p[i]) continue;
		for (int64_t j = int64_t(i) * i; j < N; j += i) p[j] = false;
	}
	partial_sum(p.begin(), p.end(), p.begin());
	cin >> TC;
	while (TC--) {
		int x, y;
		cin >> x >> y;
		cout << p[y] - p[x - 1] << '\n';
	}
}
