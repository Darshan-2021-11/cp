#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, k, cnt[2];
	char c;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		cnt[0] = cnt[1] = 0;
		for (int i = 0; i < n; ++i) cin >> c, ++cnt[c == '1'];
		k -= (abs(cnt[1] - cnt[0]) >> 1);
		cout << (k >= 0 && (cnt[1] >> 1) + (cnt[0] >> 1) >= k && !(k & 1) ? "YES\n" : "NO\n");
	}
}
