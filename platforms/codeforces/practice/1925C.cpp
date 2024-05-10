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
	char ans[1000], c;
	u32 T = 1, n, k, m, i, mask, cnt, loop;
	cin >> T;

	while (T--) {
		cnt = loop = 0;
		cin >> n >> k >> m;
		mask = (1 << k) - 1;
		for (i = 0; i < m; ++i) {
			cin >> c;
			cnt |= 1 << (c - 'a');
			if (mask == cnt)
				cnt = 0, ans[loop++] = c;
		}
		if (n > loop) {
			cout << "NO\n";
			for (i = 0; i < k; ++i) {
				if ((cnt >> i & 1) == 0) {
					c = 'a' + i;
					break;
				}
			}
			for (i = 0; i < loop; ++i) {
				cout << ans[i];
			}
			for (; i < n; ++i) {
				cout << c;
			}
			cout << '\n';
		} else {
			cout << "YES\n";
		}
	}

		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
}

