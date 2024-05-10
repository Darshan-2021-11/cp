#include <bits/stdc++.h>

using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u64 n, result, t, cnt;
u32 amap[(u32)3e5 + 1];
u32 solve() {
	result = 0;
	cin >> n;
	for (u32 i = 0; i < n; ++i) {
		cin >> t;
		++amap[t];
	}
	t = 0;
	for (u32 i = 0; i <= n; ++i) {
		cnt = amap[i];
		if(cnt > 1) {
			result += (cnt * (cnt - 1) * t) >> 1;
			result += cnt * (cnt - 1) * (cnt - 2) / 6;
		}
    t += cnt;
	}
	cout << result << '\n';
	for (u32 i = 0; i <= n; ++i) {
		amap[i] = 0;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	for (int i = 0; i < T; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << '\n';
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}
