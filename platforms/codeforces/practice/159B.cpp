#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 a[u32(2e5)], T = 1, n, diff;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	u32 mine = UINT32_MAX, maxe = 0;
	cin >> n;
	for (u32 i = 0; i < n; ++i) {
		cin >> a[i];
		mine = min(a[i], mine), maxe = max(a[i], maxe);
	}
	u32 cmax = count(a, a + n, maxe);
	if (mine == maxe) {
		cout << 0 << ' ' << ((1ll * cmax * (cmax - 1)) >> 1) << '\n';
		return 0;
	}
	u32 cmine = count(a, a + n, mine);
	cout << maxe - mine <<  ' ' << 1ll * cmax * cmine << '\n';
	return 0;
}

