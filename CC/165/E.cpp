#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, cnt[2], cn[2];
	char p, c, e;
	bool yes;
	cin >> TC;
	while (TC--) {
		yes = true;
		cnt[0] = cnt[1] = 0;
		cn[0] = cn[1] = 0;
		cin >> n;
		cin >> p;
		e = p;
		++cn[p - '0'];
		for (int i = 1; i < n; ++i) {
			cin >> c;
			++cn[c - '0'];
			if (c == p) ++cnt[c - '0'];
			p = c;
		}
		if (n != 1) {
			if (cnt[0] && cnt[1]) yes &= cnt[0] <= 1 && cnt[1] <= 1;
			else if (cnt[0]) yes &= cnt[0] <= 1 && (e == '1' || c == '1');
			else if (cnt[1]) yes &= cnt[1] <= 1 && (e == '0' || c == '0');
			yes &= (cn[0] != n || cn[1] != n);
		}
		cout << (yes ? "YES\n" : "NO\n");
	}
}
