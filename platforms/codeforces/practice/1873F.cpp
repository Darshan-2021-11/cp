#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using u32 = unsigned int;
using ll = long long;
using ld = long double;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);

	u32 T = 1;
	cin >> T;

	while (T--) {
		u32 n, k, ans = 0; 
		bool possible = false;
		cin >> n >> k;
		u32 a[n], h[n];
		for (u32 i = 0; i < n; ++i) {
			cin >> a[i];
			possible = possible || a[i] <= k;
		}
		for (u32 i = 0; i < n; ++i) {
			cin >> h[i];
		}

		if (possible) {
			++ans;
		} else {
			cout << ans << '\n';
			continue;
		}

		u32 sum, l = 0;
		sum = a[0];
		for (u32 i = 1; i < n; ++i) {
			if (h[i - 1] % h[i] == 0) {
				while (sum + a[i] > k) {
					sum -= a[l++];
				}
				sum += a[i];
				ans = max(ans, i - l + 1);
			} else {
				sum = a[i];
				l = i;
			}
		}
		cout << ans << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

