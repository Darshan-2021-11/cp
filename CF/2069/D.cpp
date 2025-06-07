#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, cnt[26], l, r;
	int cnt1[26], l1, r1;
	string a;
	cin >> TC;
	while (TC--) {
		fill_n(cnt, 26, 0);
		cin >> a;
		n = a.size() >> 1;
		for (int j = 0; j < a.size(); ++j) ++cnt[a[j] - 'a'];
		for (l = 0; l < n; ++l) if (a[l] != a[a.size() - 1 - l]) break;
		if (l == n) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 0; i < l; ++i) cnt[a[i] - 'a'] -= 2;
		r = a.size() - 1 - l;

		l1 = l, r1 = r;
		for (int i = 0; i < 26; ++i) cnt1[i] = cnt[i];

		while (true) {
			if (l < n) {
				if(cnt[a[l] - 'a'] > 1) cnt[a[l] - 'a'] -= 2, ++l;
				else break;
			} else {
				if(a[l] == a[a.size() - 1 - l]) ++l;
				else break;
			}
		}

		while (true) {
			if (r1 < n) {
				if(a[r1] == a[a.size() - 1 - r1]) --r1;
				else break;
			} else {
				if(cnt1[a[r1] - 'a'] > 1) cnt1[a[r1] - 'a'] -= 2, --r1;
				else break;
			}
		}

		cout << min(r - l + 1, r1 - l1 + 1) << '\n';
	}
}
