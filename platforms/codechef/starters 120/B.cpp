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

	u32 T = 1, n, last, lastc;
	u64 sum, t;
	cin >> T;

	while (T--) {
		last = 0;
		cin >> n;
		u32 a[n], ans[n];
		memset(ans, 0, sizeof(u32) * n);
		cin >> a[0];
		sum = a[0];
		for (u32 i = 1; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
			while (sum > n) {
				sum -= a[last++];
			}
			t = sum, lastc = last;
			while (i > lastc) {
				++ans[t - 1];
				t -= a[lastc++];
			}
		}
		for (u32 i = 0; i < n; ++i) {
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

