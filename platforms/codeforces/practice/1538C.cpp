#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 a[(int)2e5], T = 1, n, l, r;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;
	while (T--) {
		cin >> n >> l >> r;
		for (u32 i = 0; i < n; ++i) cin >> a[i];
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		}
		sort(a, a + n);
		u64 pairs = 0;
		u32 li = n - 1, ri = n;
		for (u32 i = 0; i < n - 1; ++i) {
			while (li > i + 1 && a[i] + a[li] >= l) --li;
			if (a[i] + a[li] < l && li < n - 1) ++li;
			while (ri > i && a[i] + a[ri - 1] > r) --ri;
			if (li == i) ++li;
			if (ri < li)
				break;
			else if(a[i] + a[li] >= l)
				pairs += ri - li;
		}
		cout << pairs << '\n';
	}
}

