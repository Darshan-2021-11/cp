#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1'000'000;
	int idx[N], mp[N];
	int n, q, a, b, t;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		idx[i] = i;
		mp[i] = i;
	}
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> a >> b;
			--a, --b;
			mp[a] = idx[b];
		} else if (t == 2) {
			cin >> a >> b;
			--a, --b;
			swap(idx[idx[a]], idx[idx[b]]);
		} else {
			cin >> a;
			--a;
			cout << idx[mp[a]] + 1 << '\n';
		}
	}
}
