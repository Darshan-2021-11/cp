#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, a[N], cnt[3];
	char c;
	bool pos, tpos;
	cin >> TC;
	while (TC--) {
		pos = true;
		cin >> n;
		fill_n(a, n, 0);
		fill_n(cnt, 3, 0);
		for (int i = 0; i < n; ++i) cin >> c, a[i] += c - '0';
		for (int i = 0; i < n; ++i) cin >> c, a[i] += c - '0';
		for (int i = 0; i < n; ++i) {
			++cnt[a[i]];
			//cout << a[i] << ' ';
		}
		if (n & 1) {
			pos = false;
			for (int j = 0; j < 3; ++j) {
				tpos = true;
				if (!cnt[j]) continue;
				--cnt[j];
				for (int i = 0; i < 3; ++i) {
					if (!cnt[i]) continue;
					tpos &= !(cnt[i] & 1);
				}
				++cnt[j];
				pos |= tpos;
			}
		} else {
			for (int i = 0; i < 3; ++i) {
				if (!cnt[i]) continue;
				pos &= !(cnt[i] & 1);
			}
		}
		cout << (pos ? "YES\n" : "NO\n");
	}
}
