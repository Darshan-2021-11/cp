#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, bn, f, sn;
	array<int, 2> a[N], b[N], p1, p2, swaps[N];
	map<array<int, 2>, int> m;
	map<array<int, 2>, multiset<int>> ms;
	bool found, yes;
	cin >> TC;
	while (TC--) {
		sn = bn = found = false, yes = true;
		m.clear();
		ms.clear();
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i][0];
		for (int i = 0; i < n; ++i) cin >> a[i][1];
		for (int i = 0; i < n; ++i) ++m[a[i]];
		while (m.size()) {
			tie(p1, f) = *m.begin();
			p2[0] = p1[1], p2[1] = p1[0];
			auto it = m.find(p2);
			if (it == m.end()) {
				yes = false;
				break;
			}
			int t = abs(it->second - f);
			if (p1[0] == p1[1]) {
				if (f & 1) {
					if (!(n & 1) || found) {
						yes = false;
						break;
					} else {
						found = true;
						b[n >> 1] = p1;
						--f;
						goto next;
					}
				} else {
next:
					while (f) {
						b[bn] = p1;
						b[n - 1 - bn] = p2;
						++bn, --f;
					}
					m.erase(it);
				}
			} else {
				if (t) {
					yes = false;
					break;
				} else {
					while (f) {
						b[bn] = p1;
						b[n - 1 - bn] = p2;
						++bn, --f;
					}
					m.erase(it);
					m.erase(m.begin());
				}
			}
		}
		if (!yes) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i]) continue;
			ms[a[i]].insert(i);
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i])
				continue;
			auto it = ms[b[i]].begin();
			int val;
			swaps[sn++] = { i, (val = *it) };
			ms[b[i]].erase(it);
			ms[a[i]].erase(ms[a[i]].find(i));
			if (b[val] != a[i]) {
				ms[a[i]].insert(swaps[sn - 1][1]);
			}
			swap(a[i], a[val]);
		}
		cout << sn << '\n';
		for (int i = 0; i < sn; ++i) {
			cout << swaps[i][0] + 1 << ' ' << swaps[i][1] + 1 << '\n';
		}
	}
}
