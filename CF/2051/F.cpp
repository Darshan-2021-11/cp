#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, m, query, idx;
	vector<pair<int, int>> p, q;
	const auto count = [&]() -> int {
		int res = 0;
		for (const auto &[l, r]: p) {
			if (l == idx && r == idx) {
				q.emplace_back(1, 1);
				q.emplace_back(n, n);
			} else if (idx < l) {
				q.emplace_back(l - 1, r);
			} else if (idx > r) {
				q.emplace_back(l, r + 1);
			} else {
				q.emplace_back(1, 1);
				q.emplace_back(n, n);
				q.emplace_back(l, r);
			}
		}
		sort(q.begin(), q.end());
		p.clear();
		p.emplace_back(q[0]);
		for (int i = 1; i < q.size(); ++i) {
			if (p.back().second == q[i].first) {
				p.back().second = q[i].second;
			} else {
				p.emplace_back(q[i]);
			}
		}
		for (const auto &[l, r]: p) res += r - l + 1;
		q.clear();
		return res;
	};
	cin >> TC;
	while (TC--) {
		cin >> n >> m >> query;
		p.emplace_back(m, m);
		while (query--) {
			cin >> idx;
			cout << count() << ' ';
		}
		p.clear();
		cout << '\n';
	}
}
