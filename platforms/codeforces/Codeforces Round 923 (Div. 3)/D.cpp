#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);

	u32 T = 1, n, p, t, m, q;
	cin >> T;

	while (T--) {
		cin >> n;
		u32 a[n], diff[n];
		cin >> a[0];
		diff[0] = 0;
		for (u32 i = 1; i < n; ++i) {
			cin >> a[i];
			diff[i] = diff[i - 1] + (a[i] != a[i - 1]);
		}
		cin >> q;
		for (u32 i = 0; i < q; ++i) {
			cin >> p >> t;
			--p, --t;
			if (diff[t] - diff[p]) {
				if (a[t] != a[p]) {
					cout << p + 1 << ' ' << t + 1 << '\n';
					continue;
				}
				while (t > p) {
					m = (t + p) >> 1;
					if (diff[m] - diff[p]) {
						if (a[m] != a[p]) {
							cout << p + 1 << ' ' << m + 1 << '\n';
							break;
						} else {
							t = m;
						}
					} else {
						if (a[m] != a[t]) {
							cout << m + 1 << ' ' << p + 1 << '\n';
							break;
						} else {
							p = m;
						}
					}
				}
			} else {
				cout << -1 << ' ' << -1 << '\n';
			}
		}
		cout << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

