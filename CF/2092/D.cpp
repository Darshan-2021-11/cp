#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 300;
	vector<int> a, ans;
	int TC = 1, n, t, steps, idx, cnt[3], mxcnt;
	cin >> TC;
	char c;
	a.reserve(N), ans.reserve(N);
	const auto other = [&a] (int id) -> int {
		int b[2] = { a[id - 1], b[1] = a[id] }, res = 0;
		if (b[0] > b[1]) swap(b[0], b[1]);
		while (res < 2 && b[res] == res) ++res;
		return res;
	};
	while (TC--) {
		mxcnt = t = steps = 0;
		fill_n(cnt, 3, 0);
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			if (c == 'I')      a.emplace_back(0), ++cnt[0];
			else if (c == 'L') a.emplace_back(1), ++cnt[1];
			else               a.emplace_back(2), ++cnt[2];
		}
		for (int i = 0; i < 3; ++i) t += cnt[i] > 0, mxcnt = max(mxcnt, cnt[i]);
		if (t < 2) { cout << -1 << '\n'; goto end; }

		c = cnt[0] == cnt[1] && cnt[1] == cnt[2], n <<= 1;
		if (c) { cout << 0 << '\n'; goto end; }

		while (steps < n) {
			for (idx = 1; idx < a.size(); ++idx) {
				if (a[idx - 1] == a[idx]) continue;
				t = other(idx);
				if (cnt[t] == mxcnt) continue;
				++steps, ++cnt[t], a.insert(a.begin() + idx, t), ans.push_back(idx);
				goto next;
			}
			for (idx = 1; idx < a.size(); ++idx) {
				if (a[idx - 1] == a[idx]) continue;
				t = other(idx);
				++mxcnt, ++steps, ++cnt[t], a.insert(a.begin() + idx, t), ans.push_back(idx);
				break;
			}
next:
			c = cnt[0] == cnt[1] && cnt[1] == cnt[2];
			if (c) break;
		}

		c = cnt[0] == cnt[1] && cnt[1] == cnt[2];
		if (steps < n && c) {
			cout << ans.size() << '\n';
			for (const auto &i: ans)
				cout << i << '\n';
		} else cout << -1 << '\n';

end:
		a.clear(), ans.clear();
	}
}
