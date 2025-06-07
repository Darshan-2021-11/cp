#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 400'001;
	int64_t ans;
	int TC = 1, n, first, last;
	char a[N];
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n;
		first = 1, last = n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = n; i; --i) {
			if (a[i] == '1') continue;
			else {
				while (last > i && a[last] == '0') --last;
				a[last] = '0';
				ans += i;
			}
		}
		while (first <= last) {
			if (a[first] == '0') { ++first; continue; }
			if (a[last] == '0') { --last; continue; }
			ans += first;
			++first, --last;
		}
		cout << ans << '\n';
	}
}
